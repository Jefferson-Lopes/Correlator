/*
Autocorrelator

by Jefferson Lopes
*/

module autocorrelator (in, clk, out0, out1, out2, out3, out4);
   input wire [2:0] in;
   input wire clk;
   output reg [1:0]out0;
	output reg [1:0]out1;
	output reg [1:0]out2;
	output reg [1:0]out3;
	output reg [1:0]out4;
	
	reg [1:0] hold;
	reg [1:0] hold2[5];
  
   integer i;
   integer diffe;
   integer y;
  
  
   always @ (posedge clk) begin
      for(i = 0; i < 5; i = i+1) begin
         hold = 0;
         diffe = 0;
       
         if(i < 3) begin
            diffe = 2 - i;
            for(y = 0; y <= i; y = y + 1) begin
               hold = hold + (in[y] * in[diffe]);
               diffe = diffe + 1;
            end
         end else begin
            hold = hold2[4 - i];
         end
       
         hold2[i] = hold;
         hold = 0;
      end
		out0 = hold2[0];
		out1 = hold2[1];
		out2 = hold2[2];
		out3 = hold2[3];
		out4 = hold2[4];
   end
	
endmodule
