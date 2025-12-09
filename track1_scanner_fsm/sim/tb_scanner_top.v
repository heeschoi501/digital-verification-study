`timescale 1ns/1ps
/*
 * Testbench : tb_scanner_top
 * 목적:
 *  - reset 이후 ENV_CHECK → LOAD_RET → LOAD_WFR → SETUP → ALIGN → EXPOSE → UNLOAD → IDLE
 *    로 정상 플로우 도는지 확인
 *  - 중간에 interlock_sig 를 올려서 ERROR 상태로 가는지도 확인 가능
 */

module tb_scanner_top;
    // DUT 입력 신호
    reg clk;
    reg reset;
    reg op_start_btn;
    reg interlock_sig;

    // DUT 출력 신호
    wire [3:0] current_process;
    wire       source_status;
    wire       env_status;

    // DUT 인스턴스
    scanner_top dut (
        .clk            (clk),
        .reset          (reset),
        .op_start_btn   (op_start_btn),
        .interlock_sig  (interlock_sig),
        .current_process(current_process),
        .source_status  (source_status),
        .env_status     (env_status)
    );

    // -----------------------------
    // 1) 클럭 생성 (10ns, 100MHz 기준)
    // -----------------------------
    initial clk = 0;
    always #5 clk = ~clk;  // 5ns마다 토글 → 10ns period

    // -----------------------------
    // 2) 자극 신호 생성
    // -----------------------------
    initial begin
        // 초기값
        reset        = 1'b1;
        op_start_btn = 1'b0;
        interlock_sig= 1'b0;

        // 1) 리셋 유지
        #50;
        reset = 1'b0;   // 리셋 해제

        // 2) 조금 기다렸다가 start 버튼 한 번 누르기
        #50;
        op_start_btn = 1'b1;
        #10;
        op_start_btn = 1'b0;

        // 이제부터는 FSM이 알아서
        // ENV_CHECK → LOAD_RET → LOAD_WFR → SETUP → ALIGN → EXPOSE → UNLOAD
        // 순서대로 진행하는지 waveform으로 확인하면 됩니다.

        // (선택) EXPOSE 중에 인터락 발생시키는 시나리오도 넣어볼 수 있음
        // 예: 2000ns 후에 일시적으로 interlock_sig = 1
        #2000;
        interlock_sig = 1'b1;
        #20;
        interlock_sig = 1'b0;

        // 충분히 돌려본 후 시뮬 종료
        #2000;
        $display("Simulation finished.");
        $finish;
    end

    // -----------------------------
    // 3) VCD 덤프 (scanner_top 안에도 있지만,
    //    여기에서 한 번 더 설정해도 문제는 없습니다)
    // -----------------------------
    initial begin
        $dumpfile("tb_scanner_top.vcd");
        $dumpvars(0, tb_scanner_top);
    end

endmodule
