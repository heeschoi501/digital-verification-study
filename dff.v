cat << 'EOF' > dff.v
module dff (
    input clk,
    input reset,
    input d_in,
    output reg q_out
);

    // 파형 기록을 위한 설정 (녹화 장치)
    initial begin
        $dumpfile("dff_waveform.vcd"); // 파일 이름: dff_waveform.vcd
        $dumpvars(0, dff);             // 녹화 대상: dff 모듈의 모든 신호
    end

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            q_out <= 1'b0;
        end
        else begin
            q_out <= d_in;
        end
    end
endmodule
EOF