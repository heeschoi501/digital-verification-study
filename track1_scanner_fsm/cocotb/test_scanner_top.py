import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import csv

# FSM 상태 (Verilog와 동일하게 맞춰야 함)
IDLE      = 0
ENV_CHECK = 1
LOAD_RET  = 2
LOAD_WFR  = 3
SETUP     = 4
ALIGN     = 5
EXPOSE    = 6
UNLOAD    = 7
ERROR     = 15

LOT_SIZE  = 25   # 1 LOT = 25 wafers


async def reset_dut(dut):
    """공통 리셋 시퀀스"""
    dut._log.info("[Setup] System Reset...")
    dut.reset.value        = 1
    dut.op_start_btn.value = 0
    dut.interlock_sig.value = 0
    await Timer(50, units="ns")
    dut.reset.value        = 0
    await RisingEdge(dut.clk)
    dut._log.info("[Setup] Reset Complete.")


# ------------------------------------------------------------------
# 1) 정상 1 LOT 동작 중, 1 wafer 사이클 검증 (예전 테스트 유지)
# ------------------------------------------------------------------
@cocotb.test()
async def test_normal_scan_cycle(dut):
    """
    한 번의 start_op로 공정을 시작했을 때,
    최소 1장의 wafer에 대해 IDLE→...→EXPOSE→UNLOAD→IDLE 순서를 타고,
    EXPOSE 상태에서 source_status가 ON 되었는지 검증.
    (LOT 확장 이후에도 여전히 유효)
    """
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset_dut(dut)

    # Start 버튼 펄스
    await RisingEdge(dut.clk)
    dut.op_start_btn.value = 1
    await RisingEdge(dut.clk)
    dut.op_start_btn.value = 0
    dut._log.info("[Action] Process Started!")

    state_trace = []
    exposed_with_source_on = False

    for _ in range(4000):  # 충분한 사이클 동안 모니터링
        await RisingEdge(dut.clk)
        state  = int(dut.current_process.value)
        source = int(dut.source_status.value)
        state_trace.append(state)

        if state == EXPOSE and source == 1:
            exposed_with_source_on = True

    dut._log.info(f"State trace: {state_trace}")
    assert exposed_with_source_on, "EXPOSE 상태에서 source_status가 1이 된 적이 없습니다."


# ------------------------------------------------------------------
# 2) EXPOSE 중 인터락 발생 시 ERROR 상태로 전이되는지 확인
# ------------------------------------------------------------------
@cocotb.test()
async def test_interlock_error(dut):
    """
    EXPOSE 상태 도중 interlock_sig를 1로 만들어 ERROR 상태로 전이되는지 확인
    """
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset_dut(dut)

    # Start 버튼 펄스
    await RisingEdge(dut.clk)
    dut.op_start_btn.value = 1
    await RisingEdge(dut.clk)
    dut.op_start_btn.value = 0

    interlock_applied = False

    for _ in range(4000):
        await RisingEdge(dut.clk)
        state = int(dut.current_process.value)

        if state == EXPOSE and not interlock_applied:
            dut._log.info("EXPOSE state detected, asserting interlock")
            dut.interlock_sig.value = 1
            interlock_applied = True
        elif interlock_applied:
            # 한 사이클 후 인터락 해제 (Edge 성격의 시그널로 사용)
            dut.interlock_sig.value = 0

        if interlock_applied and state == ERROR:
            # ERROR 상태 도달 확인
            return

    assert False, "인터락을 걸었는데도 ERROR 상태로 전이되지 않았습니다."


# ------------------------------------------------------------------
# 3) 1 LOT = 25장 전체에 대해 EXPOSE가 수행되는지 확인하는 테스트
# ------------------------------------------------------------------
@cocotb.test()
async def test_lot_25_wafers(dut):
    """
    LOT_SIZE(25) 장의 wafer가 연속으로 처리되는지 검증.
    - 각 wafer_index(0~24)에 대해 EXPOSE 상태가 최소 한 번은 발생해야 함
    - 시뮬레이션 종료 시 IDLE 상태 + wafer_index=0 (다음 LOT 대기 상태)
    """
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset_dut(dut)

    # Start 버튼 펄스
    await RisingEdge(dut.clk)
    dut.op_start_btn.value = 1
    await RisingEdge(dut.clk)
    dut.op_start_btn.value = 0
    dut._log.info("[Action] LOT Process Started!")

    visited_expose = [False] * LOT_SIZE

    max_cycles = 50000  # LOT 25장 처리에 충분한 시간
    last_state = IDLE

    for cycle in range(max_cycles):
        await RisingEdge(dut.clk)
        state  = int(dut.current_process.value)
        widx   = int(dut.wafer_index.value)

        # LOT 범위 내에서만 체크
        if 0 <= widx < LOT_SIZE and state == EXPOSE:
            visited_expose[widx] = True

        last_state = state

    # 시뮬레이션 후 검증
    dut._log.info(f"visited_expose flags: {visited_expose}")
    assert all(visited_expose), "25장의 웨이퍼 중 EXPOSE가 수행되지 않은 웨이퍼가 있습니다."

    final_state = int(dut.current_process.value)
    final_widx  = int(dut.wafer_index.value)
    dut._log.info(f"Final state={final_state}, wafer_index={final_widx}")

    assert final_state == IDLE, "LOT 종료 후 IDLE 상태가 아닙니다."
    assert final_widx == 0, "LOT 종료 후 wafer_index가 0이 아닙니다. (다음 LOT 대기 상태가 아님)"


# ------------------------------------------------------------------
# 4) Track2용: LOT 로그를 CSV로 저장하는 로거 테스트
# ------------------------------------------------------------------
@cocotb.test()
async def generate_scanner_lot_log(dut):
    """
    Track 2 분석을 위한 LOT 단위 Scanner 동작 로그(CSV) 생성
    - 각 wafer_index에 대해 EXPOSE 진입 시점의 타임스탬프를 기록
    - (필요에 따라 컬럼은 나중에 확장 가능)
    """
    csv_filename = "scanner_lot_log.csv"
    headers = ["Wafer_Index", "State", "Timestamp_ns"]

    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset_dut(dut)

    # Start 버튼 펄스
    await RisingEdge(dut.clk)
    dut.op_start_btn.value = 1
    await RisingEdge(dut.clk)
    dut.op_start_btn.value = 0
    dut._log.info("[Action] LOT Process Started (for logging)!")

    prev_state = int(dut.current_process.value)

    with open(csv_filename, mode="w", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(headers)

        max_cycles = 50000
        for _ in range(max_cycles):
            await RisingEdge(dut.clk)
            state = int(dut.current_process.value)
            widx  = int(dut.wafer_index.value)

            # EXPOSE 상태로 "진입하는 순간"에만 1번씩 기록
            if prev_state != EXPOSE and state == EXPOSE:
                t_ns = cocotb.utils.get_sim_time(units="ns")
                writer.writerow([widx, state, t_ns])
                dut._log.info(f"📸 Logged EXPOSE entry: wafer_index={widx}, t={t_ns} ns")

            prev_state = state

    dut._log.info(f"[Result] LOT log CSV '{csv_filename}' created.")
