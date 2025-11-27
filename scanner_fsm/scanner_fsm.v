/*
 * Module: scanner_fsm
 * Description: Generic Lithography Scanner Sequence Controller (FSM)
 * Author: [Your Name]
 * [Reference] 
 * This design implements a standard Step-and-Scan sequence 
 * (Load -> Align -> Leveling -> Expose -> Unload) based on 
 * general semiconductor equipment control logic.
 */

module scanner_fsm (
    input clk,
    input reset,
    
    // [Input] Equipment Sensor Signals
    input start_cmd,        // Operation Start
    input mech_done,        // Mechanical Action Complete (Stage/Robot)
    input focus_error,      // [Safety] Focus Error Detected (Interlock)
    
    // [Output] Equipment Control Signals
    output reg [3:0] current_step, // Current Process Step
    output reg laser_on,           // Laser Trigger
    output reg vacuum_on,          // Wafer Chuck Vacuum
    output reg stage_move          // Stage Motion Enable
);

    // State Definition (Standard Industry Terms)
    parameter S_IDLE          = 4'd0;
    parameter S_LOAD_REQ      = 4'd1;
    parameter S_PRE_CHECK     = 4'd2;
    parameter S_LOAD_STAGE    = 4'd3;
    parameter S_CALIBRATION   = 4'd4; // Calibration
    parameter S_ALIGN_GLOBAL  = 4'd5;
    parameter S_LEVELING      = 4'd6; // LEVELING
    parameter S_ALIGN_FINE    = 4'd7;
    parameter S_SYNC_CHECK    = 4'd8; // Reticle Synchronization
    parameter S_EXPOSE        = 4'd9; // Main Process
    parameter S_UNLOAD        = 4'd10;
    parameter S_ERROR         = 4'd15; // Emergency Stop

    reg [3:0] state, next_state;

    // Waveform Dump
    initial begin
        $dumpfile("scanner.vcd");
        $dumpvars(0, scanner_fsm);
    end

    // 1. State Transition Logic
    always @(*) begin
        next_state = state;
        case (state)
            S_IDLE:          if (start_cmd) next_state = S_LOAD_REQ;
            S_LOAD_REQ:      if (mech_done) next_state = S_PRE_CHECK;
            S_PRE_CHECK:     if (mech_done) next_state = S_LOAD_STAGE;
            S_LOAD_STAGE:    if (mech_done) next_state = S_CALIBRATION;
            S_CALIBRATION:   if (mech_done) next_state = S_ALIGN_GLOBAL;
            S_ALIGN_GLOBAL:  if (mech_done) next_state = S_LEVELING;
            
            S_LEVELING: begin
                if (focus_error) next_state = S_ERROR;
                else if (mech_done) next_state = S_ALIGN_FINE;
            end
            
            S_ALIGN_FINE:    if (mech_done) next_state = S_SYNC_CHECK;
            S_SYNC_CHECK:    if (mech_done) next_state = S_EXPOSE;

            // [Safety Interlock] Stop immediately upon Focus Error
            S_EXPOSE: begin
                if (focus_error) next_state = S_ERROR;
                else if (mech_done) next_state = S_UNLOAD;
            end

            S_UNLOAD:        if (mech_done) next_state = S_IDLE;
            S_ERROR:         if (reset)     next_state = S_IDLE;
            
            // [수정 완료] Verilator 에러 방지용 default 추가
            default:         next_state = state; 
        endcase
    end

    // 2. State Update
    always @(posedge clk or posedge reset) begin
        if (reset) state <= S_IDLE;
        else       state <= next_state;
    end

    // 3. Output Logic
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            laser_on <= 0;
            vacuum_on <= 0;
            stage_move <= 0;
            current_step <= S_IDLE;
        end else begin
            current_step <= state;

            // Vacuum Control: ON during stage operations
            if (state >= S_LOAD_STAGE && state <= S_EXPOSE) vacuum_on <= 1;
            else vacuum_on <= 0;

            // Laser Control: ON only during EXPOSE (Safety Interlocked)
            if (state == S_EXPOSE && !focus_error) laser_on <= 1;
            else laser_on <= 0;

            // Stage Control
            if (state >= S_CALIBRATION && state <= S_EXPOSE) stage_move <= 1;
            else stage_move <= 0;
        end
    end
endmodule