/*
Shift Register

by Jefferson Lopes
*/

module shift_register (in, clk, out, clk_out, led_debug);
   input in;
   input clk;
   output reg [2:0]out;
   output reg clk_out = 0;
	output reg [3:0]led_debug;
  
   integer i = 2;
   integer y = 0;
   reg [2:0]hold;
  
   always @ (negedge clk) begin
		hold[i] = ~in;
      if (i == 1'b0) begin
         i = 2;
         for(y = 0; y < 3; y = y + 1) begin
            out[y] = hold[y];
         end
		   clk_out = 1; 
      end else begin
         i <= i - 1;
		   clk_out <= 0;
      end 
   end
	
	//debug
	always begin
		if (i == 2'b10) begin led_debug = 3'b100; end
		else if (i == 2'b01) begin led_debug = 3'b010; end
		else if (i == 2'b00) begin led_debug = 3'b001; end
		else begin led_debug = 3'b111; end
		led_debug[3] = clk_out;
	end
	
endmodule
