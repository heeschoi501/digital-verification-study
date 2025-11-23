import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer

@cocotb.test
async def test_dff(dut):
    # 1. 클럭 시작 (10ns 주기)
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    # 2. 리셋 (비동기)
    dut.reset.value = 1
    dut.d_in.value = 0
    await Timer(15, units="ns") # 15ns 동안 리셋
    dut.reset.value = 0
    
    await Timer(1, units="ns") # 값이 바뀔 찰나의 시간 대기
    assert dut.q_out.value == 0, f"리셋 실패! 0이어야 하는데 {dut.q_out.value}입니다."
    # -------------------------------------------------------
    # [핵심 전략] Falling Edge(내리막)에서 값을 바꾼다!
    # -------------------------------------------------------

    # [테스트 1] 1 저장하기
    await FallingEdge(dut.clk)  # 클럭이 내려갈 때 (안전한 타이밍)
    dut.d_in.value = 1          # 데이터를 미리 '1'로 준비
    
    await RisingEdge(dut.clk)   # 클럭이 올라갈 때 (DFF가 데이터를 먹음)
    await Timer(1, units="ns")  # 1ns만 기다려서 결과가 나오길 대기
    
    # 확인
    assert dut.q_out.value == 1, f"Failed: Expected 1, got {dut.q_out.value}"
    dut._log.info("PASS: 1이 정상적으로 저장되었습니다.")

    # [테스트 2] 0 저장하기
    await FallingEdge(dut.clk)  # 다시 내려갈 때
    dut.d_in.value = 0          # 데이터를 미리 '0'으로 준비
    
    await RisingEdge(dut.clk)   # 올라갈 때
    await Timer(1, units="ns")  # 결과 대기
    
    # 확인
    assert dut.q_out.value == 0, f"Failed: Expected 0, got {dut.q_out.value}"
    dut._log.info("PASS: 0이 정상적으로 저장되었습니다.")

# ... (위쪽 기존 코드 생략) ...

    # -------------------------------------------------------
    # [미션 5-2] 멘티님이 직접 추가하는 '빠른 변화' 테스트
    # -------------------------------------------------------
    dut._log.info("=== [추가 테스트] 빠른 변화 패턴 (1 -> 0 -> 1) 검증 시작 ===")

    # 1. 데이터 '1' 주입 (Falling Edge에서 안전하게)
    await FallingEdge(dut.clk)
    dut.d_in.value = 1
    await RisingEdge(dut.clk)
    await Timer(1, units="ns") # 결과 대기
    assert dut.q_out.value == 1, "추가 테스트 실패: 1이 안 나옵니다!"

    # 2. 데이터 '0' 주입
    await FallingEdge(dut.clk)
    dut.d_in.value = 0
    await RisingEdge(dut.clk)
    await Timer(1, units="ns")
    assert dut.q_out.value == 0, "추가 테스트 실패: 0이 안 나옵니다!"

    # 3. 데이터 '1' 재주입 (복구 확인)
    await FallingEdge(dut.clk)
    dut.d_in.value = 1
    await RisingEdge(dut.clk)
    await Timer(1, units="ns")
    assert dut.q_out.value == 1, "추가 테스트 실패: 1로 복구가 안 됩니다!"
    
    dut._log.info("PASS: 멘티님이 추가한 테스트까지 완벽하게 통과했습니다!")