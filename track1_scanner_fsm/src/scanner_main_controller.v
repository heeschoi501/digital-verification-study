/*
 * File: scanner_main_controller.v
 * Description: Main Logic for Lithography Process Control (1 lot = LOT_SIZE wafers)
 */

module scanner_main_controller #(
    parameter integer LOT_SIZE = 25  // 1 lot 당 wafer 개수
)(
    input  wire        clk,
    input  wire        reset,
    input  wire        start_op,
    input  wire        safety_sensor,   // Interlock (1이면 즉시 ERROR)

    // [Status] From Submodules
    input  wire        wl_ready,
    input  wire        rl_ready,
    input  wire        ws_done,
    input  wire        rs_done,
    input  wire        env_ok,

    // [Command] To Submodules
    output reg         cmd_wl_load,
    output reg         cmd_wl_unload,
    output reg         cmd_rl_load,
    output reg         cmd_rl_unload,
    output reg         cmd_ws_calib,
    output reg         cmd_ws_align,
    output reg         cmd_ws_scan,
    output reg         cmd_rs_calib,
    output reg         cmd_rs_scan,
    output reg         cmd_source_active,

    // [Debug / Monitoring]
    output reg  [3:0]  process_state,   // 현재 상태 (FSM state)
    output reg  [7:0]  wafer_index      // 현재 lot 내 wafer 번호 (0 ~ LOT_SIZE-1)
);

    //------------------------------------------------------------
    // State Definition
    //------------------------------------------------------------
    localparam [3:0] IDLE      = 4'd0;
    localparam [3:0] ENV_CHECK = 4'd1;
    localparam [3:0] LOAD_RET  = 4'd2;
    localparam [3:0] LOAD_WFR  = 4'd3;
    localparam [3:0] SETUP     = 4'd4;
    localparam [3:0] ALIGN     = 4'd5;
    localparam [3:0] EXPOSE    = 4'd6;
    localparam [3:0] UNLOAD    = 4'd7;
    localparam [3:0] ERROR     = 4'd15;

    // LOT_SIZE 정수 파라미터 → 8비트 로컬 상수로 변환 (폭 경고 방지)
    localparam [7:0] LOT_SIZE_U8 = LOT_SIZE[7:0];

    reg [3:0] state, next_state;
    reg [7:0] next_wafer_index;

    //------------------------------------------------------------
    // Sequential Logic
    //------------------------------------------------------------
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state         <= IDLE;
            process_state <= IDLE;
            wafer_index   <= 8'd0;
        end else begin
            state         <= next_state;
            process_state <= next_state;
            wafer_index   <= next_wafer_index;
        end
    end

    //------------------------------------------------------------
    // Combinational Next-State & Output Logic
    //------------------------------------------------------------
    always @(*) begin
        // 기본값 초기화
        next_state        = state;
        next_wafer_index  = wafer_index;

        cmd_wl_load       = 1'b0;
        cmd_wl_unload     = 1'b0;
        cmd_rl_load       = 1'b0;
        cmd_rl_unload     = 1'b0;
        cmd_ws_calib      = 1'b0;
        cmd_ws_align      = 1'b0;
        cmd_ws_scan       = 1'b0;
        cmd_rs_calib      = 1'b0;
        cmd_rs_scan       = 1'b0;
        cmd_source_active = 1'b0;

        case (state)
            //----------------------------------------------------
            // 대기 상태: Start 버튼을 기다림
            //----------------------------------------------------
            IDLE: begin
                next_wafer_index = 8'd0;
                if (start_op) begin
                    next_state = ENV_CHECK;
                end
            end

            //----------------------------------------------------
            // 환경 체크 (온도, 압력, 진공 등)
            //----------------------------------------------------
            ENV_CHECK: begin
                if (env_ok) begin
                    next_state = LOAD_RET;
                end
            end

            //----------------------------------------------------
            // Reticle Load
            //----------------------------------------------------
            LOAD_RET: begin
                cmd_rl_load = 1'b1;
                if (rl_ready) begin
                    next_state = LOAD_WFR;
                end
            end

            //----------------------------------------------------
            // Wafer Load (현재 wafer_index에 해당하는 wafer)
            //----------------------------------------------------
            LOAD_WFR: begin
                cmd_wl_load = 1'b1;
                if (wl_ready) begin
                    next_state = SETUP;
                end
            end

            //----------------------------------------------------
            // Stage SETUP (Calib)
            //----------------------------------------------------
            SETUP: begin
                cmd_ws_calib = 1'b1;
                cmd_rs_calib = 1'b1;
                if (ws_done && rs_done) begin
                    next_state = ALIGN;
                end
            end

            //----------------------------------------------------
            // ALIGN 단계
            //----------------------------------------------------
            ALIGN: begin
                cmd_ws_align = 1'b1;
                if (ws_done) begin
                    next_state = EXPOSE;
                end
            end

            //----------------------------------------------------
            // EXPOSE 단계 (Scan + Source ON)
            //----------------------------------------------------
            EXPOSE: begin
                cmd_ws_scan       = 1'b1;
                cmd_rs_scan       = 1'b1;
                cmd_source_active = 1'b1;

                if (safety_sensor) begin
                    // 인터락 발생 시 즉시 ERROR
                    next_state = ERROR;
                end else if (ws_done && rs_done) begin
                    // 노광 완료 → UNLOAD 단계
                    next_state = UNLOAD;
                end
            end

            //----------------------------------------------------
            // UNLOAD 단계 (Wafer / Reticle)
            //----------------------------------------------------
            UNLOAD: begin
                cmd_wl_unload = 1'b1;

                // 마지막 wafer에서는 reticle도 같이 언로드
                if (wafer_index == LOT_SIZE_U8 - 1) begin
                    cmd_rl_unload = 1'b1;
                end

                // 언로드 완료 체크
                if (wl_ready && 
                    ((wafer_index == LOT_SIZE_U8 - 1 && rl_ready) ||
                     (wafer_index != LOT_SIZE_U8 - 1))) begin

                    if (wafer_index == LOT_SIZE_U8 - 1) begin
                        // lot 종료 → IDLE 복귀
                        next_state       = IDLE;
                        next_wafer_index = 8'd0;
                    end else begin
                        // 다음 wafer로 진행
                        next_wafer_index = wafer_index + 8'd1;
                        next_state       = LOAD_WFR;  // reticle은 그대로 두고 다음 wafer 로드
                    end
                end
            end

            //----------------------------------------------------
            // ERROR 상태
            //----------------------------------------------------
            ERROR: begin
                // reset 시퀀스로만 복구
                next_state       = ERROR;
                next_wafer_index = wafer_index;
            end

            //----------------------------------------------------
            // 안전 default 절
            //----------------------------------------------------
            default: begin
                next_state       = IDLE;
                next_wafer_index = 8'd0;
            end
        endcase
    end

endmodule
