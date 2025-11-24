module vending (
    input  clk,
    input  reset,
    input  coin_in,        // 동전 투입
    output reg coffee_out, // 커피 배출 (콤마 추가!)
    output reg change_out  // [추가됨] 거스름돈
);

    // 1. 상태 정의
    parameter STATE_0   = 1'b0;
    parameter STATE_100 = 1'b1;

    reg current_state; 
    reg next_state;    

    // 2. 시뮬레이션 초기 설정
    initial begin
        $dumpfile("vending.vcd");
        $dumpvars(0, vending);

        current_state = STATE_0;
        coffee_out    = 0;
        change_out    = 0; // [추가됨] 초기화
    end

    // 3. 상태 이동 조합 논리
    always @(*) begin
        next_state = current_state;  // 기본값

        case (current_state)
            STATE_0: begin
                if (coin_in)
                    next_state = STATE_100;
            end

            STATE_100: begin
                if (coin_in)
                    next_state = STATE_0;
            end
        endcase
    end

    // 4. 상태 플립플롭
    always @(posedge clk or posedge reset) begin
        if (reset)
            current_state <= STATE_0;
        else
            current_state <= next_state;
    end

    // 5. 출력 로직 (거스름돈 추가!)
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            coffee_out <= 0;
            change_out <= 0; // [수정] 리셋 시 거스름돈도 0
        end else begin
            // 100원 상태에서 동전을 넣은 그 클럭에만 동작
            if (current_state == STATE_100 && coin_in) begin
                coffee_out <= 1;
                change_out <= 1; // [수정] begin/end로 묶어서 같이 1로 만듦
            end else begin
                coffee_out <= 0;
                change_out <= 0; // [수정] 아닐 때는 다시 0으로 끔
            end
        end
    end

endmodule