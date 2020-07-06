/*
Cross-correlator

by Jefferson Lopes
*/


module cross_correlator(in1, in2, clk, out0, out1, out2, out3, out4);
   input [2:0]in1;
   input [2:0]in2;
   input wire clk;
  
   output reg [1:0]out0;
   output reg [1:0]out1;
   output reg [1:0]out2;
   output reg [1:0]out3;
   output reg [1:0]out4;
  
   reg [1:0]hold[5:0];
  
   integer i = 0;
   integer y = 0;
   integer diffe = 0;
  
   always @ (posedge clk) begin
      for (i = 0; i < 5; i = i + 1) begin
         if (i < 3) begin
            diffe = 2 - i;
            for (y = 0; y <= i; y = y + 1) begin
               hold[i] = hold[i] + (in1[y] * in2[diffe + y]);
            end
         end else begin
            diffe = i - 2;
            for (y = 0; y < (5 - i); y = y + 1) begin
               hold[i] = hold[i] + (in1[diffe + y] * in2[y]);
            end
         end
      end
      out0 = hold[0];
      out1 = hold[1];
      out2 = hold[2];
      out3 = hold[3];
      out4 = hold[4];
   end
  
endmodule
  