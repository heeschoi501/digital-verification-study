`timescale 1ns / 1ps  // <--- 이 줄을 추가하세요! (1ns 단위 / 1ps 정밀도)

module counter (
    input clk,
    input reset,
    output reg [3:0] out  // [3:0]은 4비트(0~15)를 의미합니다.
);

    // 파형 기록
    initial begin
        $dumpfile("counter.vcd");
        $dumpvars(0, counter);
    end

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            // out <= 4'b0000; // 리셋 시 0으로 초기화
            out <= 4'b1111;
        end
        else begin
            out <= out - 1; // 클럭마다 1씩 증가 (덧셈)
        end
    end
endmodule