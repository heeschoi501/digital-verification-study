import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer

@cocotb.test
async def test_scanner(dut):
    # 1. 클럭 시작
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    
    # 2. 리셋 (초기화)
    dut.reset.value = 1
    dut.start_cmd.value = 0
    dut.mech_done.value = 0
    dut.focus_error.value = 0
    await Timer(20, units="ns")
    dut.reset.value = 0
    
    dut._log.info("=== [1] 스캐너 가동 시작 ===")
    
    # 3. 시작 명령 (IDLE -> LOAD_REQ)
    await FallingEdge(dut.clk)
    dut.start_cmd.value = 1
    await RisingEdge(dut.clk)
    dut.start_cmd.value = 0
    
    # 4. 시퀀스 진행 (기계가 움직이는 과정 시뮬레이션)
    # 상태가 0(IDLE)에서 9(EXPOSE)가 될 때까지 계속 '완료 신호'를 줍니다.
    
    # 목표 상태: 9 (EXPOSE / 노광)
    while dut.current_step.value != 9:
        # 기계가 움직이는 시간 (약간 대기)
        await Timer(50, units="ns")
        
        # 현재 상태 로그 찍기
        current_val = dut.current_step.value.integer
        dut._log.info(f"현재 상태 번호: {current_val} (다음 단계로 이동 중...)")
        
        # "기계 동작 완료!" 신호 보내기
        await FallingEdge(dut.clk)
        dut.mech_done.value = 1
        await RisingEdge(dut.clk)
        
        # 신호 끄기
        await FallingEdge(dut.clk)
        dut.mech_done.value = 0
        await RisingEdge(dut.clk)

    # 5. 노광 상태(9) 도착 확인
    dut._log.info(">>> 📸 노광 상태(9) 도착! 레이저 발사 중 <<<")
    assert dut.laser_on.value == 1, "레이저가 안 켜졌습니다!"

    # 6. [핵심] 노광 중 포커스 에러 발생! (인터락 테스트)
    await Timer(30, units="ns")
    dut._log.info("🚨 [경고] Focus Error 센서 감지! (인터락 테스트)")
    
    await FallingEdge(dut.clk)
    dut.focus_error.value = 1  # 에러 주입!
    await RisingEdge(dut.clk)  # 다음 클럭에 바로 멈춰야 함

    # 7. 결과 확인
    await Timer(10, units="ns")
    # 상태가 15 (ERROR)로 변했는지 확인
    assert dut.current_step.value == 15, "에러 상태(15)로 안 갔습니다!"
    # 레이저가 꺼졌는지 확인
    assert dut.laser_on.value == 0, "위험! 레이저가 계속 켜져 있습니다!"
    
    dut._log.info("✅ [성공] 안전장치 작동 완료: 레이저 차단됨.")