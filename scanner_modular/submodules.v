/*
 * File: submodules.v
 * Description: 6 Key Modules for Generic Lithography Equipment
 * (Simulation Models)
 */

// 1. 웨이퍼 로더 (Wafer Loader)
module wafer_loader (
    input clk, input reset, 
    input cmd_load, input cmd_unload,
    output reg wl_ready
);
    reg [3:0] timer;
    always @(posedge clk or posedge reset) begin
        if (reset) begin wl_ready <= 0; timer <= 0; end
        else if (cmd_load || cmd_unload) begin
            if (timer < 4) timer <= timer + 1;
            else wl_ready <= 1;
        end else begin
            wl_ready <= 0; timer <= 0;
        end
    end
endmodule

// 2. 레티클 로더 (Reticle Loader)
module reticle_loader (
    input clk, input reset, 
    input cmd_load, input cmd_unload,
    output reg rl_ready
);
    reg [3:0] timer;
    always @(posedge clk or posedge reset) begin
        if (reset) begin rl_ready <= 0; timer <= 0; end
        else if (cmd_load || cmd_unload) begin
            if (timer < 3) timer <= timer + 1;
            else rl_ready <= 1;
        end else begin
            rl_ready <= 0; timer <= 0;
        end
    end
endmodule

// 3. 웨이퍼 스테이지 (Wafer Stage)
module wafer_stage (
    input clk, input reset, 
    input cmd_calib, input cmd_align, input cmd_scan,
    output reg ws_done
);
    reg [4:0] timer;
    always @(posedge clk or posedge reset) begin
        if (reset) begin ws_done <= 0; timer <= 0; end
        else if (cmd_calib || cmd_align || cmd_scan) begin
            if (timer < 6) timer <= timer + 1; 
            else ws_done <= 1;
        end else begin
            ws_done <= 0; timer <= 0;
        end
    end
endmodule

// 4. 레티클 스테이지 (Reticle Stage)
module reticle_stage (
    input clk, input reset, 
    input cmd_calib, input cmd_sync,
    output reg rs_done
);
    reg [4:0] timer;
    always @(posedge clk or posedge reset) begin
        if (reset) begin rs_done <= 0; timer <= 0; end
        else if (cmd_calib || cmd_sync) begin
            if (timer < 6) timer <= timer + 1;
            else rs_done <= 1;
        end else begin
            rs_done <= 0; timer <= 0;
        end
    end
endmodule

// 5. 광원 제어기 (Light Source)
module light_source (
    input clk, input reset, 
    input cmd_active,
    output reg source_on
);
    always @(posedge clk or posedge reset) begin
        if (reset) source_on <= 0;
        else if (cmd_active) source_on <= 1;
        else source_on <= 0;
    end
endmodule

// 6. 환경 제어기 (Environment Control)
module env_control (
    input clk, input reset,
    output reg env_ok
);
    reg [3:0] warmup_timer;
    always @(posedge clk or posedge reset) begin
        if (reset) begin env_ok <= 0; warmup_timer <= 0; end
        else begin
            if (warmup_timer < 10) warmup_timer <= warmup_timer + 1;
            else env_ok <= 1; // 환경 안정화 완료 신호
        end
    end
endmodule