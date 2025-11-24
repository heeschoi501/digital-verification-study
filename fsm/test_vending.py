import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer

@cocotb.test
async def test_vending(dut):
    # 1. 클럭 시작
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    # 2. 리셋
    dut.reset.value = 1
    dut.coin_in.value = 0
    await Timer(15, units="ns")
    dut.reset.value = 0
    
    dut._log.info("--- [1] 초기 상태 확인 (0원) ---")
    await RisingEdge(dut.clk)
    # 내부 상태 신호(current_state)는 0이어야 함
    # (시뮬레이션에서는 내부 신호도 볼 수 있습니다)
    assert dut.current_state.value == 0, "초기화 실패!"

    # 3. 첫 번째 동전 투입 (100원)
   # 3. 첫 번째 동전 투입 (100원)
    dut._log.info("--- [2] 100원 투입 ---")
    await FallingEdge(dut.clk)
    dut.coin_in.value = 1
    
    await RisingEdge(dut.clk)   # 자판기가 꿀꺽
    
    # [수정!] 1ns -> 5ns로 늘려보세요. (안정화 대기)
    await Timer(5, units="ns")  
    
    # 확인
    assert dut.coffee_out.value == 0, "100원인데 커피가 나왔습니다!"
    assert dut.current_state.value == 1, "100원 상태로 안 변했습니다!"
    

    
    # 동전 뺌 (센서 초기화)
    await FallingEdge(dut.clk)
    dut.coin_in.value = 0
    await RisingEdge(dut.clk)

    # 4. 두 번째 동전 투입 (200원 -> 커피)
    dut._log.info("--- [3] 200원 투입 (커피 나와라!) ---")
    await FallingEdge(dut.clk)
    dut.coin_in.value = 1       # 동전 또 넣음!
    
    await RisingEdge(dut.clk)   # 자판기가 꿀꺽
    await Timer(1, units="ns")  # 처리 대기
    
    # 확인: 이제는 커피가 나와야 함!
    assert dut.coffee_out.value == 1, "200원 넣었는데 커피 안 줌!"
    dut._log.info("☕ 커피 나옴! (성공)")
    
    # 확인: 상태는 다시 0원으로 돌아갔나?
    assert dut.current_state.value == 0, "커피 주고 0원으로 안 돌아감!"
    
    dut._log.info("PASS: 자판기 동작 완벽함!")