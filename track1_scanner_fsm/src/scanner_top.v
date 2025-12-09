/*
 * File: scanner_top.v
 * Description: Top-level Module for Scanner FSM (1 lot = LOT_SIZE wafers)
 */

module scanner_top (
    input  wire       clk,
    input  wire       reset,
    input  wire       op_start_btn,
    input  wire       interlock_sig,

    output wire [3:0] current_process,  // FSM 상태 모니터링
    output wire       source_status,    // 광원 상태
    output wire       env_status        // 환경 OK 플래그
);

    //------------------------------------------------------------
    // 내부 연결선 정의
    //------------------------------------------------------------
    // Controller → Handler/Stage/Source 로 나가는 제어 신호
    wire cmd_wl_load;
    wire cmd_wl_unload;
    wire cmd_rl_load;
    wire cmd_rl_unload;

    wire cmd_ws_calib;
    wire cmd_ws_align;
    wire cmd_ws_scan;

    wire cmd_rs_calib;
    wire cmd_rs_scan;

    wire cmd_source_active;

    // Submodule → Controller 로 들어오는 상태 신호
    wire wl_ready;
    wire rl_ready;
    wire ws_done;
    wire rs_done;
    wire env_ok;

    // LOT 내 wafer index (0 ~ LOT_SIZE-1), 디버그용 내부 와이어
    wire [7:0] wafer_index;

    //------------------------------------------------------------
    // 1. Main Controller (LOT 단위 FSM)
    //------------------------------------------------------------
    scanner_main_controller #(
        .LOT_SIZE(25)   // 1 lot = 25장
    ) u_main (
        .clk(clk),
        .reset(reset),
        .start_op(op_start_btn),
        .safety_sensor(interlock_sig),

        // Status from submodules
        .wl_ready(wl_ready),
        .rl_ready(rl_ready),
        .ws_done(ws_done),
        .rs_done(rs_done),
        .env_ok(env_ok),

        // Command outputs
        .cmd_wl_load(cmd_wl_load),
        .cmd_wl_unload(cmd_wl_unload),
        .cmd_rl_load(cmd_rl_load),
        .cmd_rl_unload(cmd_rl_unload),
        .cmd_ws_calib(cmd_ws_calib),
        .cmd_ws_align(cmd_ws_align),
        .cmd_ws_scan(cmd_ws_scan),
        .cmd_rs_calib(cmd_rs_calib),
        .cmd_rs_scan(cmd_rs_scan),
        .cmd_source_active(cmd_source_active),

        // Monitor
        .process_state(current_process),
        .wafer_index(wafer_index)
    );

    //------------------------------------------------------------
    // 2. Handler 모듈 (Wafer/Reticle Loader)
    //------------------------------------------------------------
    scanner_handler_module u_handler (
        .clk(clk),
        .reset(reset),

        .cmd_wl_load(cmd_wl_load),
        .cmd_wl_unload(cmd_wl_unload),
        .cmd_rl_load(cmd_rl_load),
        .cmd_rl_unload(cmd_rl_unload),

        .wl_ready(wl_ready),
        .rl_ready(rl_ready)
    );

    //------------------------------------------------------------
    // 3. Stage 모듈 (Wafer/Reticle Stage)
    //------------------------------------------------------------
    scanner_stage_module u_stage (
        .clk(clk),
        .reset(reset),

        .cmd_ws_calib(cmd_ws_calib),
        .cmd_ws_align(cmd_ws_align),
        .cmd_ws_scan(cmd_ws_scan),

        .cmd_rs_calib(cmd_rs_calib),
        .cmd_rs_scan(cmd_rs_scan),

        .ws_done(ws_done),
        .rs_done(rs_done)
    );

    //------------------------------------------------------------
    // 4. Source + Environment 모듈
    //------------------------------------------------------------
    scanner_source_control u_source (
        .clk(clk),
        .reset(reset),

        .cmd_source_active(cmd_source_active),

        .source_on(source_status),
        .env_ok(env_ok)
    );

    // 환경 상태를 외부 포트로 그대로 전달
    assign env_status = env_ok;

    //------------------------------------------------------------
    // (옵션) VCD 덤프: Verilator에서 --trace를 쓰면 이건 무시될 수도 있음
    //------------------------------------------------------------
    initial begin
        $dumpfile("scanner_top.vcd");
        $dumpvars(0, scanner_top);
    end

endmodule
