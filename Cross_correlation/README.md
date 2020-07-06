# Cross-correlation project

## Top-level entity
![](../Output_files/Cross-correlation.png)

This entity was assembled in a .BDF file from other blocks, such as ***Shift Register***, ***Cross-Correlator***, and ***Decoder***.

RTL view:

![](../Output_files/Top-level-Cross.png)

## Shift Register

The ***Shift Register*** transforms a serial input into 3 separate outputs, where ***out[0]*** receives the least significant bit and ***out[2]*** receives the most significant bit.

The output is released after every 3 inputs clocks.

In this project, two ***Shift Registers*** were used. One for each input signal.

***Clk_out*** is activated each time the output is loaded, serving as a clock for the next blocks.

NOTE: the ***always*** block is sensitive to the falling edge of the clock because, in the FPGA used for the tests, the button used to represent the clock has a ***pull-up resistor***, keeping it in **HIGH** when not pressed.

~~~verilog
module shift_register (in, clk, out, clk_out);
    input in;
    input clk;
    output reg [2:0]out;
    output reg clk_out;
  
    integer i = 2;
    integer y = 0;
    reg [2:0]hold;
  
    always @ (negedge clk) begin
        hold[i] <= in;
        if (i == 1'b0) begin
            i = 2;
            for(y = 0; y < 3; y = y + 1) begin
                out[y] <= hold[y];
            end
	    clk_out <= 1;
        end else begin
            i <= i - 1;
	    clk_out <= 0;
        end 
    end
endmodule
~~~

RTL view:

![](../Output_files/ShiftRegister.png)

## Cross-correlator

This block correlates two input signals.

The inputs are two vectors of 3 bits, which represent the signals of the serial input, and the outputs are 5 vectors of 2 bits each, which represent the cross-correlation in binary.

NOTE: the logic used was made in C++ and then adapted for Verilog, to facilitate the writing of ideas.

~~~verilog
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
~~~

RTL view:

![](../Output_files/Cross-correlator.png)

## Decoder

The ***Decoder*** is used to transform the output in bits from the ***Cros-correlator*** to a seven-segment display.

For each 2-bit output of the ***Cross-correlator***, one ***Decoder*** is used.

~~~verilog
module decoder(in, display);
    input [1:0] in;
  
    output reg [6:0] display;
  
    always @ (in) begin
        if (in == 2'b00) begin             // 0
            display <= 7'b1111110;         // abcdef0
       
        end else if (in == 2'b01) begin    // 1
  	    display <= 7'b0110000;         // 0bc0000
       
        end else if (in == 2'b10) begin    // 2
  	    display <= 7'b1101101;         // ab0de0g
       
        end else if (in == 2'b11) begin    // 3
  	    display <= 7'b1111001;         // abcd00g  
        end
    end

endmodule
~~~

RTL view:

![](../Output_files/Decoder.png)

## Contact me
[![](../Output_files/gmail.png)](mailto:jefferson.lopes@ee.ufcg.edu.br?subject=[GitHub]%20FPGA%20-%20cross-correlation) ![](../Output_files/separador.png) [![](../Output_files/insta.png)](https://instagram.com/jeff.777.lopes?igshid=1i5gr7ch0bvkd)
