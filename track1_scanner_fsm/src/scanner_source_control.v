/*
 * File: scanner_source_control.v
 * Description: Light Source + Environment Control 모델
 *
 * - env_ok : 일정 시간(warm-up) 후 1로 유지
 * - source_on : env_ok == 1 이고 cmd_source_active == 1일 때만 1
 */

module scanner_source_control (
    input  wire clk,
    input  wire reset,

    input  wire cmd_source_active,  // Main Controller에서 오는 광원 On 명령

    output reg  source_on,          // 실제 광원 상태
    output reg  env_ok              // 챔버/환경 OK 플래그
);

    // 환경 WARM-UP 타이머
    reg [3:0] env_timer;

    //-----------------------------------------------//
    // Environment OK 모델
    //-----------------------------------------------//
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            env_ok    <= 1'b0;
            env_timer <= 4'd0;
        end else begin
            if (!env_ok) begin
                // warm-up 중
                if (env_timer < 4'd10) begin
                    env_timer <= env_timer + 4'd1;
                end else begin
                    env_ok <= 1'b1;   // 일정 시간 후 환경 안정화
                end
            end
            // env_ok가 1이 된 이후에는 계속 1 유지
        end
    end

    //-----------------------------------------------//
    // Light Source 제어
    //-----------------------------------------------//
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            source_on <= 1'b0;
        end else begin
            // 환경이 OK일 때만 명령에 따라 ON
            if (cmd_source_active && env_ok) begin
                source_on <= 1'b1;
            end else begin
                source_on <= 1'b0;
            end
        end
    end

endmodule
