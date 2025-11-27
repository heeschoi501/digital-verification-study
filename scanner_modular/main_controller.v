/*
 * File: main_controller.v
 * Description: Main Logic for Lithography Process Control
 */

module main_controller (
    input clk, input reset,
    input start_op,
    input safety_sensor, // (Interlock)
    
    // [Status] From Submodules
    input wl_ready, rl_ready, ws_done, rs_done, env_ok,
    
    // [Command] To Submodules
    output reg cmd_wl_load, cmd_wl_unload,
    output reg cmd_rl_load, cmd_rl_unload,
    output reg cmd_ws_calib, cmd_ws_align, cmd_ws_scan,
    output reg cmd_rs_calib, cmd_rs_scan,
    output reg cmd_source_active,
    
    output reg [3:0] process_state
);
    // State Definition
    parameter IDLE      = 0;
    parameter ENV_CHECK = 1; 
    parameter LOAD_RET  = 2; 
    parameter LOAD_WFR  = 3; 
    parameter SETUP     = 4; 
    parameter ALIGN     = 5; 
    parameter EXPOSE    = 6; 
    parameter UNLOAD    = 7;
    parameter ERROR     = 15;

    reg [3:0] state, next_state;

    always @(*) begin
        next_state = state;
        // Reset Commands
        cmd_wl_load=0; cmd_wl_unload=0;
        cmd_rl_load=0; cmd_rl_unload=0;
        cmd_ws_calib=0; cmd_ws_align=0; cmd_ws_scan=0;
        cmd_rs_calib=0; cmd_rs_scan=0;
        cmd_source_active=0;

        case (state)
            IDLE: if (start_op) next_state = ENV_CHECK;
            
            ENV_CHECK: begin
                if (env_ok) next_state = LOAD_RET;
            end
            
            LOAD_RET: begin
                cmd_rl_load = 1;
                if (rl_ready) next_state = LOAD_WFR;
            end
            
            LOAD_WFR: begin
                cmd_wl_load = 1;
                if (wl_ready) next_state = SETUP;
            end
            
            SETUP: begin
                cmd_ws_calib = 1; cmd_rs_calib = 1; 
                if (ws_done && rs_done) next_state = ALIGN;
            end
            
            ALIGN: begin
                cmd_ws_align = 1;
                if (ws_done) next_state = EXPOSE;
            end
            
            EXPOSE: begin
                // Synchronized Scanning
                cmd_ws_scan = 1; 
                cmd_rs_scan = 1;
                cmd_source_active = 1; // Light On
                
                if (safety_sensor) next_state = ERROR; // Interlock
                else if (ws_done && rs_done) next_state = UNLOAD;
            end
            
            UNLOAD: begin
                cmd_wl_unload = 1;
                cmd_rl_unload = 1;
                if (wl_ready && rl_ready) next_state = IDLE;
            end
            ERROR:  if (reset) next_state = IDLE;
        endcase
    end

    always @(posedge clk or posedge reset) begin
        if (reset) begin state <= IDLE; process_state <= IDLE; end
        else       begin state <= next_state; process_state <= state; end
    end
endmodule