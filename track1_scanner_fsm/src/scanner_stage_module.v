/*
 * File: scanner_stage_module.v
 * Description: Wafer / Reticle Stage 동작 모델 (LOT 단위 FSM용)
 *
 * - Wafer Stage: calib / align / scan 명령을 받으면 일정 시간 후 ws_done = 1
 * - Reticle Stage: calib / scan 명령을 받으면 일정 시간 후 rs_done = 1
 */

module scanner_stage_module (
    input  wire clk,
    input  wire reset,

    // Wafer Stage 제어
    input  wire cmd_ws_calib,
    input  wire cmd_ws_align,
    input  wire cmd_ws_scan,

    // Reticle Stage 제어
    input  wire cmd_rs_calib,
    input  wire cmd_rs_scan,

    // 완료 플래그
    output reg  ws_done,
    output reg  rs_done
);

    // Wafer / Reticle Stage 각각의 타이머
    reg [4:0] ws_timer;
    reg [4:0] rs_timer;

    //-----------------------------------------------//
    // Wafer Stage 모델
    //-----------------------------------------------//
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            ws_done  <= 1'b0;
            ws_timer <= 5'd0;
        end else begin
            // 어떤 Wafer Stage 명령이든 하나라도 올라오면 "동작 중"으로 가정
            if (cmd_ws_calib || cmd_ws_align || cmd_ws_scan) begin
                if (ws_timer < 5'd6) begin
                    ws_timer <= ws_timer + 5'd1;
                    ws_done  <= 1'b0;
                end else begin
                    ws_done <= 1'b1;    // 설정된 시간 후 완료
                end
            end else begin
                // 명령이 내려가면 다음 동작을 위해 초기화
                ws_done  <= 1'b0;
                ws_timer <= 5'd0;
            end
        end
    end

    //-----------------------------------------------//
    // Reticle Stage 모델
    //-----------------------------------------------//
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            rs_done  <= 1'b0;
            rs_timer <= 5'd0;
        end else begin
            // Reticle Stage는 calib / scan 두 종류만 사용
            if (cmd_rs_calib || cmd_rs_scan) begin
                if (rs_timer < 5'd6) begin
                    rs_timer <= rs_timer + 5'd1;
                    rs_done  <= 1'b0;
                end else begin
                    rs_done <= 1'b1;
                end
            end else begin
                rs_done  <= 1'b0;
                rs_timer <= 5'd0;
            end
        end
    end

endmodule
