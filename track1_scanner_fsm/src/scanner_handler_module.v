`timescale 1ns/1ps

module scanner_handler_module (
    input  wire clk,
    input  wire reset,

    input  wire cmd_wl_load,
    input  wire cmd_wl_unload,
    input  wire cmd_rl_load,
    input  wire cmd_rl_unload,

    output reg  wl_ready,
    output reg  rl_ready
);
    reg [3:0] wl_timer;
    reg [3:0] rl_timer;

    // 웨이퍼 로더
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            wl_ready <= 1'b0;
            wl_timer <= 4'd0;
        end else if (cmd_wl_load || cmd_wl_unload) begin
            if (wl_timer < 4'd4) begin
                wl_timer <= wl_timer + 1'b1;
                wl_ready <= 1'b0;
            end else begin
                wl_ready <= 1'b1;
            end
        end else begin
            wl_ready <= 1'b0;
            wl_timer <= 4'd0;
        end
    end

    // 레티클 로더
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            rl_ready <= 1'b0;
            rl_timer <= 4'd0;
        end else if (cmd_rl_load || cmd_rl_unload) begin
            if (rl_timer < 4'd3) begin
                rl_timer <= rl_timer + 1'b1;
                rl_ready <= 1'b0;
            end else begin
                rl_ready <= 1'b1;
            end
        end else begin
            rl_ready <= 1'b0;
            rl_timer <= 4'd0;
        end
    end

endmodule
