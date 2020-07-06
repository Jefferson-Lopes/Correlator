/*
Shift Register

by Jefferson Lopes
*/

module shift_register (in, clk, out, clk_out);
   input in;
   input clk;
   output reg [2:0]out;
   output reg clk_out;
  
   integer i = 2;
   integer y = 0;
   reg [2:0]hold;
  
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
