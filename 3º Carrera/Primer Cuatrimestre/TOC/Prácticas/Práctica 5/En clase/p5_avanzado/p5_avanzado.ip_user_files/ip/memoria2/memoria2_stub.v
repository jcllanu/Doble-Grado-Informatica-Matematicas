// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
// Date        : Mon Dec 14 10:28:51 2020
// Host        : DESKTOP-NJO422N running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/ProyectosVivaldo/p5_avanzado/p5_avanzado.srcs/sources_1/ip/memoria2/memoria2_stub.v
// Design      : memoria2
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "blk_mem_gen_v8_4_3,Vivado 2019.1" *)
module memoria2(clka, wea, addra, dina, douta)
/* synthesis syn_black_box black_box_pad_pin="clka,wea[0:0],addra[3:0],dina[3:0],douta[3:0]" */;
  input clka;
  input [0:0]wea;
  input [3:0]addra;
  input [3:0]dina;
  output [3:0]douta;
endmodule
