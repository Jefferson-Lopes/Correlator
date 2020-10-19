/*
Decoder

by Jefferson Lopes
*/

module decoder(in, display);
   input [1:0] in;
  
   output reg [6:0] display = 7'b1111111;
  
   always @ (in) begin                         // GFEDCBA 
      if (in == 2'b00) begin            // 0
         display <= 7'b1000000;         // abcdef0
       
      end else if (in == 2'b01) begin   // 1
  	      display <= 7'b1111001;         // 0bc0000
       
      end else if (in == 2'b10) begin   // 2
  	      display <= 7'b0100100;         // ab0de0g
       
      end else if (in == 2'b11) begin   // 3
  	      display <= 7'b0110000;         // abcd00g  
      end
   end

endmodule
