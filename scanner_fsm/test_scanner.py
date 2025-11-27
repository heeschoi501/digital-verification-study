import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge
import random
import csv

@cocotb.test
async def test_scanner_random(dut):
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    # Log file setup
    file = open('scanner_log.csv', 'w', newline='')
    writer = csv.writer(file)
    writer.writerow(['Time_ns', 'Wafer_In', 'Error_Sensor', 'State', 'Laser_On', 'Vacuum_On'])

    # Reset
    dut.reset.value = 1
    dut.start_cmd.value = 0
    dut.mech_done.value = 0
    dut.focus_error.value = 0
    await RisingEdge(dut.clk)
    dut.reset.value = 0
    
    # [수정] 일반적인 이름으로 변경
    dut._log.info("🎲 Lithography Scanner Reliability Test Start! (Data Mining)")

    # 1,000 Cycles Simulation
    for i in range(1000):
        # Random Inputs
        cmd_in = 1 if random.random() < 0.1 else 0
        mech_sig = 1 if random.random() < 0.5 else 0
        err_sig = 1 if random.random() < 0.005 else 0 # 0.5% Error Rate

        await FallingEdge(dut.clk)
        dut.start_cmd.value = cmd_in
        dut.mech_done.value = mech_sig
        dut.focus_error.value = err_sig
        
        await RisingEdge(dut.clk)
        
        # Data Collection
        time_ns = cocotb.utils.get_sim_time(units='ns')
        try:
            state = int(dut.current_step.value)
            laser = int(dut.laser_on.value)
            vac = int(dut.vacuum_on.value)
        except:
            state, laser, vac = -1, -1, -1
        
        writer.writerow([time_ns, cmd_in, err_sig, state, laser, vac])

    file.close()
    dut._log.info("💾 Log Saved: scanner_log.csv")