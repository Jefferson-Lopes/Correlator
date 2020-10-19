/*
Slow clock

by Jefferson Lopes
*/

module slow_clk(clk_in, clk_out);
	input clk_in;
	output clk_out;
	
	reg [25:0] counter = 0;
	
	always @ (posedge clk_in) begin // 50 MHz  -->  50 Hz
		counter <= counter + 1;
		if (counter == 500_000) begin
			counter <= 0;
			clk_out <= ~clk_out;
		end 
	end
	
endmodule
