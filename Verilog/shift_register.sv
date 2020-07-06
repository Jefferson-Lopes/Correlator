/*
Shift Register

by Jefferson Lopes

Pin Planer

in
KEY[0] - J15

clk
KEY[1] - E1

out
LED[0] - A15
LED[1] - A13
LED[2] - B13
LED[3] - A11
LED[4] - D1

clk_out
LED[7] - L3
*/

module shift_register (in, clk, out, clk_out);
  input in;
  input clk;
  output reg [2:0]out;
  output reg clk_out;
  
  integer i = 2;
  integer y = 0;
  integer hold[2:0];
  
  initial $monitor("i = %b\ny = %b\n", i, y);
  
  always @ (negedge clk) begin //Pull up resistor
    hold[i] <= in;
    if (i == 1'b0) begin
      i = 2;
      for(y = 0; y < 3; y = y + 1) begin
        out[y] <= hold[y];
      end
		clk_out <= 1; //carrega os dados para o _correlator_
    end else begin
      i <= i - 1;
		clk_out <= 0;
    end 
  end
endmodule
