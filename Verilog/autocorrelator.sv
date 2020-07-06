/*
Autocorrelator

by Jefferson Lopes

considerações:
in é um sinal digital que pode ser 0 ou 1;


Pin Planner

clk
KEY[0] - J15

in[2:0]
DIP[0] - M1
DIP[1] - T8
DIP[2] - B9

out[0]
LED[0] - A15
LED[1] - A13

out[1]
LED[2] - B13
LED[3] - A11

out[2]
LED[4] - D1
LED[5] - F3

out[3]
LED[6] - B1
LED[7] - L3

*/

module autocorrelator (in, clk, out);
  input in;
  input clk;
  output out;
  
  integer i;
  integer hold;
  integer diffe;
  integer y;
  
  wire [2:0] in;
  wire clk;
  
  reg [1:0]out[5];//5 elementos com 2 bits
  
  initial $display("Autocorrelator 2 bits \n \n");
  
  always @ (posedge clk) begin
    for(i = 0; i < 5; i = i+1) begin
      hold = 0;
      diffe = 0;
      
      if(i < 3) begin
        diffe = 2 - i;
        for(y = 0; y <= i; y = y+1) begin
          hold = hold + (in[y] * in[diffe]);
          diffe = diffe+1;
        end
      end else begin
        hold = out[4 - i];
      end
    
      out[i] = hold;
      hold = 0;
    end
  end
endmodule
