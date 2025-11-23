import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer

@cocotb.test
async def test_counter(dut):
    # 1. 클럭 시작
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    # 2. 리셋
    dut.reset.value = 1
    await Timer(15, units="ns")
    dut.reset.value = 0
    
    # 3. 카운팅 검증 (자동화!)
    dut._log.info("카운팅 시작!")
    
    # 0부터 15까지 숫자가 맞게 나오는지 반복문으로 검사
    for i in range(16):
        # 우리는 'Falling Edge'에서 검사합니다 (가장 안전한 타이밍)
        await FallingEdge(dut.clk)
        
        current_val = dut.out.value.integer # 현재 칩의 출력값(정수) 가져오기
        expected_val = (15 - i) % 16

        #dut._log.info(f"현재 카운트: {current_val}, 기대값: {i}")
        
        #assert current_val == i, f"카운트 오류! {i}가 나와야 하는데 {current_val}이 나왔습니다."

    #dut._log.info("PASS: 0부터 15까지 완벽하게 셉니다!")
        dut._log.info(f"현재 카운트: {current_val}, 기대값: {expected_val}")
        assert current_val == expected_val, f"오류! {expected_val}가 나와야 하는데 {current_val}이 나왔습니다."

    dut._log.info("PASS: 15부터 0까지 거꾸로 잘 셉니다!")