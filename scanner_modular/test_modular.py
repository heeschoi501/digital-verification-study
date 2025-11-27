import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
import csv
import os

CURRENT_DIR = os.path.dirname(os.path.abspath(__file__))
LOG_FILE = os.path.join(CURRENT_DIR, 'modular_log.csv')

# 상태 이름 매핑 (로그 확인용)
STATE_MAP = {
    0: "IDLE", 1: "LOAD", 2: "SETUP", 3: "ALIGN", 
    4: "FOCUS", 5: "RUN(Expose)", 6: "FINISH", 7: "FAULT"
}

# 안전하게 정수 변환 (x나 z값 처리)
def safe_get(signal):
    try:
        val_str = str(signal.value)
        if 'x' in val_str or 'z' in val_str: return 0
        return int(signal.value)
    except: return 0

@cocotb.test
async def test_modular_system(dut):
    # 1. 클럭 시작
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    
    # 2. 로그 파일 준비 (헤더에 Event_Msg 포함!)
    file = open('modular_log.csv', 'w', newline='', encoding='utf-8', buffering=1)
    #file = open(LOG_FILE, 'w', newline='', encoding='utf-8', buffering=1)
    writer = csv.writer(file)
    writer.writerow(['Time_ns', 'Phase_Code', 'Phase_Name', 'Laser_Active', 'Env_Status', 'Event_Msg'])
    file.flush()
    
    # 3. 초기화
    dut.reset.value = 1
    dut.op_start_btn.value = 0    # 핀 이름 확인: op_start_btn
    dut.interlock_sig.value = 0   # 핀 이름 확인: interlock_sig
    await Timer(20, units="ns")
    dut.reset.value = 0
    
    dut._log.info("🚀 [Scanner Modular] 시뮬레이션 시작")
    
    # 4. 시작 명령
    await FallingEdge(dut.clk)
    dut.op_start_btn.value = 1
    await RisingEdge(dut.clk)
    dut.op_start_btn.value = 0
    
    # 5. 데이터 수집 루프
    prev_phase = -1

    for i in range(600): # 충분히 길게 (600클럭)
        await RisingEdge(dut.clk)
        time_ns = cocotb.utils.get_sim_time(units='ns')
        
        # [출력 핀 이름 일치 확인]
        phase = safe_get(dut.current_process) 
        laser = safe_get(dut.source_status)   
        env   = safe_get(dut.env_status)
        
        phase_name = STATE_MAP.get(phase, "Unknown")
        msg = "-"

        # (조건 1) 상태가 변했을 때 기록
        if phase != prev_phase:
            msg = f"상태 변경: {prev_phase} -> {phase} ({phase_name})"
            dut._log.info(f"   >> [{time_ns}ns] {msg}")
            
            writer.writerow([time_ns, phase, phase_name, laser, env, msg])
            file.flush() # 즉시 저장
            
            prev_phase = phase
        
        # (조건 2) 노광 중일 때 기록 (10클럭마다)
        elif phase == 5 and laser == 1:
            msg = "✨ 레이저 발사 중"
            if i % 10 == 0: 
                writer.writerow([time_ns, phase, phase_name, laser, env, msg])
                file.flush()

        # (조건 3) 완료 체크 (IDLE로 돌아오면)
        if i > 50 and phase == 0:
            msg = "✅ 공정 사이클 완료"
            dut._log.info(msg)
            writer.writerow([time_ns, phase, phase_name, laser, env, msg])
            file.flush()
            break
            
    file.close()
    dut._log.info("💾 modular_log.csv 저장 완료.")
    
    # 뷰어 실행
    os.system("python3 view_simulation.py &")