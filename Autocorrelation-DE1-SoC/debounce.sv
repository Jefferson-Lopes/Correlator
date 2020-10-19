/*
Debounce

by Jefferson Lopes
*/

module debounce(in, clk, out);
	input in;
	input clk;
	output reg out;
	
	reg [2:0] ff;
	
	always @ (posedge clk) begin
		ff[2] = ff[1];
		ff[1] = ff[0];
		ff[0] = in;
	end
	
	assign out = 1;
	
	always begin
		if (ff[0] && ff[1] && ff[2]) begin
			out <= 1'b1;
		end else begin
			out <= 1'b0;
		end
	end
	
endmodule

