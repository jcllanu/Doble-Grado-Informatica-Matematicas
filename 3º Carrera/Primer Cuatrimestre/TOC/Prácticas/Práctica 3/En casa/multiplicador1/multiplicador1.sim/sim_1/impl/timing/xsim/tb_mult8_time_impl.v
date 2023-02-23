// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
// Date        : Sun Nov 22 11:41:08 2020
// Host        : DESKTOP-NJO422N running 64-bit major release  (build 9200)
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               C:/ProyectosVivaldo/multiplicador1/multiplicador1.sim/sim_1/impl/timing/xsim/tb_mult8_time_impl.v
// Design      : multiplicador_sumador
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

(* ECO_CHECKSUM = "41f96e68" *) 
(* NotValidForBitStream *)
module multiplicador_sumador
   (X,
    Y,
    S);
  input [3:0]X;
  input [3:0]Y;
  output [7:0]S;

  wire [7:0]S;
  wire [7:0]S_OBUF;
  wire \S_OBUF[3]_inst_i_2_n_0 ;
  wire \S_OBUF[3]_inst_i_3_n_0 ;
  wire \S_OBUF[4]_inst_i_2_n_0 ;
  wire \S_OBUF[4]_inst_i_3_n_0 ;
  wire \S_OBUF[4]_inst_i_4_n_0 ;
  wire \S_OBUF[7]_inst_i_2_n_0 ;
  wire \S_OBUF[7]_inst_i_3_n_0 ;
  wire \S_OBUF[7]_inst_i_4_n_0 ;
  wire \S_OBUF[7]_inst_i_5_n_0 ;
  wire \S_OBUF[7]_inst_i_6_n_0 ;
  wire [3:0]X;
  wire [3:0]X_IBUF;
  wire [3:0]Y;
  wire [3:0]Y_IBUF;

initial begin
 $sdf_annotate("tb_mult8_time_impl.sdf",,,,"tool_control");
end
  OBUF \S_OBUF[0]_inst 
       (.I(S_OBUF[0]),
        .O(S[0]));
  LUT2 #(
    .INIT(4'h8)) 
    \S_OBUF[0]_inst_i_1 
       (.I0(X_IBUF[0]),
        .I1(Y_IBUF[0]),
        .O(S_OBUF[0]));
  OBUF \S_OBUF[1]_inst 
       (.I(S_OBUF[1]),
        .O(S[1]));
  LUT4 #(
    .INIT(16'h7888)) 
    \S_OBUF[1]_inst_i_1 
       (.I0(Y_IBUF[0]),
        .I1(X_IBUF[1]),
        .I2(Y_IBUF[1]),
        .I3(X_IBUF[0]),
        .O(S_OBUF[1]));
  OBUF \S_OBUF[2]_inst 
       (.I(S_OBUF[2]),
        .O(S[2]));
  LUT6 #(
    .INIT(64'h2777D88878887888)) 
    \S_OBUF[2]_inst_i_1 
       (.I0(Y_IBUF[0]),
        .I1(X_IBUF[2]),
        .I2(Y_IBUF[1]),
        .I3(X_IBUF[1]),
        .I4(Y_IBUF[2]),
        .I5(X_IBUF[0]),
        .O(S_OBUF[2]));
  OBUF \S_OBUF[3]_inst 
       (.I(S_OBUF[3]),
        .O(S[3]));
  LUT6 #(
    .INIT(64'h6A95956A956A956A)) 
    \S_OBUF[3]_inst_i_1 
       (.I0(\S_OBUF[3]_inst_i_2_n_0 ),
        .I1(Y_IBUF[2]),
        .I2(X_IBUF[1]),
        .I3(\S_OBUF[3]_inst_i_3_n_0 ),
        .I4(Y_IBUF[3]),
        .I5(X_IBUF[0]),
        .O(S_OBUF[3]));
  LUT6 #(
    .INIT(64'hC7FF3800F000F000)) 
    \S_OBUF[3]_inst_i_2 
       (.I0(X_IBUF[0]),
        .I1(X_IBUF[1]),
        .I2(X_IBUF[2]),
        .I3(Y_IBUF[1]),
        .I4(X_IBUF[3]),
        .I5(Y_IBUF[0]),
        .O(\S_OBUF[3]_inst_i_2_n_0 ));
  LUT6 #(
    .INIT(64'hA280808000000000)) 
    \S_OBUF[3]_inst_i_3 
       (.I0(Y_IBUF[2]),
        .I1(Y_IBUF[0]),
        .I2(X_IBUF[2]),
        .I3(Y_IBUF[1]),
        .I4(X_IBUF[1]),
        .I5(X_IBUF[0]),
        .O(\S_OBUF[3]_inst_i_3_n_0 ));
  OBUF \S_OBUF[4]_inst 
       (.I(S_OBUF[4]),
        .O(S[4]));
  LUT4 #(
    .INIT(16'h956A)) 
    \S_OBUF[4]_inst_i_1 
       (.I0(\S_OBUF[4]_inst_i_2_n_0 ),
        .I1(X_IBUF[1]),
        .I2(Y_IBUF[3]),
        .I3(\S_OBUF[4]_inst_i_3_n_0 ),
        .O(S_OBUF[4]));
  LUT6 #(
    .INIT(64'h8008080808808080)) 
    \S_OBUF[4]_inst_i_2 
       (.I0(Y_IBUF[3]),
        .I1(X_IBUF[0]),
        .I2(\S_OBUF[3]_inst_i_2_n_0 ),
        .I3(Y_IBUF[2]),
        .I4(X_IBUF[1]),
        .I5(\S_OBUF[3]_inst_i_3_n_0 ),
        .O(\S_OBUF[4]_inst_i_2_n_0 ));
  LUT6 #(
    .INIT(64'hE817777717E88888)) 
    \S_OBUF[4]_inst_i_3 
       (.I0(\S_OBUF[3]_inst_i_3_n_0 ),
        .I1(\S_OBUF[3]_inst_i_2_n_0 ),
        .I2(X_IBUF[1]),
        .I3(X_IBUF[2]),
        .I4(Y_IBUF[2]),
        .I5(\S_OBUF[4]_inst_i_4_n_0 ),
        .O(\S_OBUF[4]_inst_i_3_n_0 ));
  LUT6 #(
    .INIT(64'h0F7F0000A0000000)) 
    \S_OBUF[4]_inst_i_4 
       (.I0(X_IBUF[1]),
        .I1(X_IBUF[0]),
        .I2(Y_IBUF[0]),
        .I3(X_IBUF[2]),
        .I4(Y_IBUF[1]),
        .I5(X_IBUF[3]),
        .O(\S_OBUF[4]_inst_i_4_n_0 ));
  OBUF \S_OBUF[5]_inst 
       (.I(S_OBUF[5]),
        .O(S[5]));
  LUT4 #(
    .INIT(16'h956A)) 
    \S_OBUF[5]_inst_i_1 
       (.I0(\S_OBUF[7]_inst_i_3_n_0 ),
        .I1(X_IBUF[2]),
        .I2(Y_IBUF[3]),
        .I3(\S_OBUF[7]_inst_i_4_n_0 ),
        .O(S_OBUF[5]));
  OBUF \S_OBUF[6]_inst 
       (.I(S_OBUF[6]),
        .O(S[6]));
  LUT6 #(
    .INIT(64'hE817777717E88888)) 
    \S_OBUF[6]_inst_i_1 
       (.I0(\S_OBUF[7]_inst_i_3_n_0 ),
        .I1(\S_OBUF[7]_inst_i_4_n_0 ),
        .I2(X_IBUF[2]),
        .I3(X_IBUF[3]),
        .I4(Y_IBUF[3]),
        .I5(\S_OBUF[7]_inst_i_2_n_0 ),
        .O(S_OBUF[6]));
  OBUF \S_OBUF[7]_inst 
       (.I(S_OBUF[7]),
        .O(S[7]));
  LUT6 #(
    .INIT(64'hF8A8A880F8808080)) 
    \S_OBUF[7]_inst_i_1 
       (.I0(Y_IBUF[3]),
        .I1(X_IBUF[3]),
        .I2(\S_OBUF[7]_inst_i_2_n_0 ),
        .I3(\S_OBUF[7]_inst_i_3_n_0 ),
        .I4(\S_OBUF[7]_inst_i_4_n_0 ),
        .I5(X_IBUF[2]),
        .O(S_OBUF[7]));
  LUT4 #(
    .INIT(16'hF880)) 
    \S_OBUF[7]_inst_i_2 
       (.I0(Y_IBUF[2]),
        .I1(X_IBUF[3]),
        .I2(\S_OBUF[7]_inst_i_5_n_0 ),
        .I3(\S_OBUF[7]_inst_i_6_n_0 ),
        .O(\S_OBUF[7]_inst_i_2_n_0 ));
  LUT4 #(
    .INIT(16'hF880)) 
    \S_OBUF[7]_inst_i_3 
       (.I0(Y_IBUF[3]),
        .I1(X_IBUF[1]),
        .I2(\S_OBUF[4]_inst_i_3_n_0 ),
        .I3(\S_OBUF[4]_inst_i_2_n_0 ),
        .O(\S_OBUF[7]_inst_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h956A)) 
    \S_OBUF[7]_inst_i_4 
       (.I0(\S_OBUF[7]_inst_i_6_n_0 ),
        .I1(X_IBUF[3]),
        .I2(Y_IBUF[2]),
        .I3(\S_OBUF[7]_inst_i_5_n_0 ),
        .O(\S_OBUF[7]_inst_i_4_n_0 ));
  LUT6 #(
    .INIT(64'hF000800000000000)) 
    \S_OBUF[7]_inst_i_5 
       (.I0(X_IBUF[1]),
        .I1(X_IBUF[0]),
        .I2(X_IBUF[3]),
        .I3(Y_IBUF[0]),
        .I4(X_IBUF[2]),
        .I5(Y_IBUF[1]),
        .O(\S_OBUF[7]_inst_i_5_n_0 ));
  LUT6 #(
    .INIT(64'hF8A8A880F8808080)) 
    \S_OBUF[7]_inst_i_6 
       (.I0(Y_IBUF[2]),
        .I1(X_IBUF[2]),
        .I2(\S_OBUF[4]_inst_i_4_n_0 ),
        .I3(\S_OBUF[3]_inst_i_3_n_0 ),
        .I4(\S_OBUF[3]_inst_i_2_n_0 ),
        .I5(X_IBUF[1]),
        .O(\S_OBUF[7]_inst_i_6_n_0 ));
  IBUF \X_IBUF[0]_inst 
       (.I(X[0]),
        .O(X_IBUF[0]));
  IBUF \X_IBUF[1]_inst 
       (.I(X[1]),
        .O(X_IBUF[1]));
  IBUF \X_IBUF[2]_inst 
       (.I(X[2]),
        .O(X_IBUF[2]));
  IBUF \X_IBUF[3]_inst 
       (.I(X[3]),
        .O(X_IBUF[3]));
  IBUF \Y_IBUF[0]_inst 
       (.I(Y[0]),
        .O(Y_IBUF[0]));
  IBUF \Y_IBUF[1]_inst 
       (.I(Y[1]),
        .O(Y_IBUF[1]));
  IBUF \Y_IBUF[2]_inst 
       (.I(Y[2]),
        .O(Y_IBUF[2]));
  IBUF \Y_IBUF[3]_inst 
       (.I(Y[3]),
        .O(Y_IBUF[3]));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule
`endif
