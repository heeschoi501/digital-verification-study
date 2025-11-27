/*
 * File: scanner_top.v
 * Description: Top-level Module Integration
 */

module scanner_top (
    input clk, input reset,
    input op_start_btn,
    input interlock_sig,
    
    output [3:0] current_process,
    output source_status,
    output env_status
);
    
    // Internal Wires
    wire w_wl_load, w_wl_unload;
    wire w_rl_load, w_rl_unload;
    wire w_ws_calib, w_ws_align, w_ws_scan;
    wire w_rs_calib, w_rs_scan;
    wire w_source;
    
    wire r_wl_ready, r_rl_ready, r_ws_done, r_rs_done, r_env_ok;

    // 1. Main Controller
    main_controller u_main (
        .clk(clk), .reset(reset),
        .start_op(op_start_btn), .safety_sensor(interlock_sig),
        
        .wl_ready(r_wl_ready), .rl_ready(r_rl_ready),
        .ws_done(r_ws_done), .rs_done(r_rs_done),
        .env_ok(r_env_ok),
        
        .cmd_wl_load(w_wl_load), .cmd_wl_unload(w_wl_unload),
        .cmd_rl_load(w_rl_load), .cmd_rl_unload(w_rl_unload),
        .cmd_ws_calib(w_ws_calib), .cmd_ws_align(w_ws_align), .cmd_ws_scan(w_ws_scan),
        .cmd_rs_calib(w_rs_calib), .cmd_rs_scan(w_rs_scan),
        .cmd_source_active(w_source),
        
        .process_state(current_process)
    );

    // 2. Submodules
    wafer_loader     u_wl   (.clk(clk), .reset(reset), .cmd_load(w_wl_load), .cmd_unload(w_wl_unload), .wl_ready(r_wl_ready));
    reticle_loader   u_rl   (.clk(clk), .reset(reset), .cmd_load(w_rl_load), .cmd_unload(w_rl_unload), .rl_ready(r_rl_ready));
    
    wafer_stage      u_ws   (.clk(clk), .reset(reset), 
                             .cmd_calib(w_ws_calib), .cmd_align(w_ws_align), .cmd_scan(w_ws_scan), 
                             .ws_done(r_ws_done));
                             
    reticle_stage    u_rs   (.clk(clk), .reset(reset), 
                             .cmd_calib(w_rs_calib), .cmd_sync(w_rs_scan), 
                             .rs_done(r_rs_done));
                             
    light_source     u_src  (.clk(clk), .reset(reset), .cmd_active(w_source), .source_on(source_status));
    
    env_control      u_env  (.clk(clk), .reset(reset), .env_ok(r_env_ok));
    
    assign env_status = r_env_ok;

    // Waveform Dump
    initial begin
        $dumpfile("scanner_modular.vcd");
        $dumpvars(0, scanner_top);
    end
endmodule