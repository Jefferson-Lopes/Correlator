// Copyright (C) 2020  Intel Corporation. All rights reserved.
// Your use of Intel Corporation's design tools, logic functions 
// and other software and tools, and any partner logic 
// functions, and any output files from any of the foregoing 
// (including device programming or simulation files), and any 
// associated documentation or information are expressly subject 
// to the terms and conditions of the Intel Program License 
// Subscription Agreement, the Intel Quartus Prime License Agreement,
// the Intel FPGA IP License Agreement, or other applicable license
// agreement, including, without limitation, that your use is for
// the sole purpose of programming logic devices manufactured by
// Intel and sold by Intel or its authorized distributors.  Please
// refer to the applicable agreement for further details, at
// https://fpgasoftware.intel.com/eula.

// PROGRAM		"Quartus Prime"
// VERSION		"Version 20.1.0 Build 711 06/05/2020 SJ Lite Edition"
// CREATED		"Mon Oct  5 17:18:04 2020"

module Autocorrelation(
	crystal,
	in,
	clk,
	display_0,
	display_1,
	display_2,
	display_3,
	display_4
);


input wire	crystal;
input wire	in;
input wire	clk;
output wire	[6:0] display_0;
output wire	[6:0] display_1;
output wire	[6:0] display_2;
output wire	[6:0] display_3;
output wire	[6:0] display_4;

wire	SYNTHESIZED_WIRE_0;
wire	SYNTHESIZED_WIRE_1;
wire	SYNTHESIZED_WIRE_2;
wire	[2:0] SYNTHESIZED_WIRE_3;
wire	[1:0] SYNTHESIZED_WIRE_4;
wire	[1:0] SYNTHESIZED_WIRE_5;
wire	[1:0] SYNTHESIZED_WIRE_6;
wire	[1:0] SYNTHESIZED_WIRE_7;
wire	[1:0] SYNTHESIZED_WIRE_8;
wire	SYNTHESIZED_WIRE_11;





slow_clk	b2v_inst(
	.clk_in(crystal),
	.clk_out(SYNTHESIZED_WIRE_11));


shift_register	b2v_inst1(
	.in(SYNTHESIZED_WIRE_0),
	.clk(SYNTHESIZED_WIRE_1),
	.clk_out(SYNTHESIZED_WIRE_2),
	.out(SYNTHESIZED_WIRE_3));


autocorrelator	b2v_inst2(
	.clk(SYNTHESIZED_WIRE_2),
	.in(SYNTHESIZED_WIRE_3),
	.out0(SYNTHESIZED_WIRE_4),
	.out1(SYNTHESIZED_WIRE_5),
	.out2(SYNTHESIZED_WIRE_6),
	.out3(SYNTHESIZED_WIRE_7),
	.out4(SYNTHESIZED_WIRE_8));


decoder	b2v_inst3(
	.in(SYNTHESIZED_WIRE_4),
	.display(display_0));


decoder	b2v_inst4(
	.in(SYNTHESIZED_WIRE_5),
	.display(display_1));


decoder	b2v_inst5(
	.in(SYNTHESIZED_WIRE_6),
	.display(display_2));


decoder	b2v_inst6(
	.in(SYNTHESIZED_WIRE_7),
	.display(display_3));


decoder	b2v_inst7(
	.in(SYNTHESIZED_WIRE_8),
	.display(display_4));


debounce	b2v_inst8(
	.in(in),
	.clk(SYNTHESIZED_WIRE_11),
	.out(SYNTHESIZED_WIRE_0));


debounce	b2v_inst9(
	.in(clk),
	.clk(SYNTHESIZED_WIRE_11),
	.out(SYNTHESIZED_WIRE_1));


endmodule
