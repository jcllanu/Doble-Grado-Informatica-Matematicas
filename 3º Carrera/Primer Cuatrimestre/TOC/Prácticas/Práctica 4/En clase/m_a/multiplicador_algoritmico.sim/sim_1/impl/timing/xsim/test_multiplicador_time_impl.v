// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
// Date        : Fri Nov 27 20:36:16 2020
// Host        : DESKTOP-NJO422N running 64-bit major release  (build 9200)
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               C:/ProyectosVivaldo/multiplicador_algoritmico/multiplicador_algoritmico.sim/sim_1/impl/timing/xsim/test_multiplicador_time_impl.v
// Design      : modulo
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

module cd
   (acc_reg,
    rst,
    Q,
    seg_OBUF,
    \FSM_sequential_estado_actual_reg[1] ,
    \b_reg[3]_0 ,
    \n_reg[3]_0 ,
    \a_reg[7]_0 ,
    acc_ld,
    CLK,
    DI,
    S,
    \acc_reg[7]_0 ,
    \acc_reg[7]_1 ,
    D,
    \n_reg[2]_0 ,
    \n_reg[3]_1 ,
    L,
    \seg[4] ,
    rst_IBUF,
    E,
    \b_reg[3]_1 ,
    \a_reg[7]_1 );
  output [7:0]acc_reg;
  output rst;
  output [1:0]Q;
  output [6:0]seg_OBUF;
  output \FSM_sequential_estado_actual_reg[1] ;
  output [3:0]\b_reg[3]_0 ;
  output \n_reg[3]_0 ;
  output [7:0]\a_reg[7]_0 ;
  input acc_ld;
  input CLK;
  input [3:0]DI;
  input [3:0]S;
  input [2:0]\acc_reg[7]_0 ;
  input [3:0]\acc_reg[7]_1 ;
  input [1:0]D;
  input [2:0]\n_reg[2]_0 ;
  input \n_reg[3]_1 ;
  input [19:18]L;
  input \seg[4] ;
  input rst_IBUF;
  input [0:0]E;
  input [3:0]\b_reg[3]_1 ;
  input [7:0]\a_reg[7]_1 ;

  wire CLK;
  wire [1:0]D;
  wire [3:0]DI;
  wire [0:0]E;
  wire \FSM_sequential_estado_actual_reg[1] ;
  wire [19:18]L;
  wire [1:0]Q;
  wire [3:0]S;
  wire [7:0]\a_reg[7]_0 ;
  wire [7:0]\a_reg[7]_1 ;
  wire acc_ld;
  wire [7:0]acc_reg;
  wire [2:0]\acc_reg[7]_0 ;
  wire [3:0]\acc_reg[7]_1 ;
  wire [3:0]\b_reg[3]_0 ;
  wire [3:0]\b_reg[3]_1 ;
  wire mux_acc_n_0;
  wire mux_acc_n_1;
  wire mux_acc_n_2;
  wire mux_acc_n_3;
  wire mux_acc_n_4;
  wire mux_acc_n_5;
  wire mux_acc_n_6;
  wire mux_acc_n_7;
  wire [3:2]n;
  wire [2:0]\n_reg[2]_0 ;
  wire \n_reg[3]_0 ;
  wire \n_reg[3]_1 ;
  wire rst;
  wire rst_IBUF;
  wire [3:2]s_mux_n;
  wire \seg[4] ;
  wire [6:0]seg_OBUF;
  wire \seg_OBUF[0]_inst_i_2_n_0 ;
  wire \seg_OBUF[0]_inst_i_3_n_0 ;
  wire \seg_OBUF[0]_inst_i_4_n_0 ;
  wire \seg_OBUF[1]_inst_i_2_n_0 ;
  wire \seg_OBUF[1]_inst_i_3_n_0 ;
  wire \seg_OBUF[1]_inst_i_4_n_0 ;
  wire \seg_OBUF[2]_inst_i_2_n_0 ;
  wire \seg_OBUF[2]_inst_i_3_n_0 ;
  wire \seg_OBUF[2]_inst_i_4_n_0 ;
  wire \seg_OBUF[3]_inst_i_2_n_0 ;
  wire \seg_OBUF[3]_inst_i_3_n_0 ;
  wire \seg_OBUF[3]_inst_i_4_n_0 ;
  wire \seg_OBUF[4]_inst_i_2_n_0 ;
  wire \seg_OBUF[4]_inst_i_3_n_0 ;
  wire \seg_OBUF[4]_inst_i_5_n_0 ;
  wire \seg_OBUF[4]_inst_i_6_n_0 ;
  wire \seg_OBUF[5]_inst_i_2_n_0 ;
  wire \seg_OBUF[5]_inst_i_3_n_0 ;
  wire \seg_OBUF[5]_inst_i_4_n_0 ;
  wire \seg_OBUF[6]_inst_i_10_n_0 ;
  wire \seg_OBUF[6]_inst_i_2_n_0 ;
  wire \seg_OBUF[6]_inst_i_3_n_0 ;
  wire \seg_OBUF[6]_inst_i_4_n_0 ;
  wire \seg_OBUF[6]_inst_i_5_n_0 ;
  wire \seg_OBUF[6]_inst_i_6_n_0 ;
  wire \seg_OBUF[6]_inst_i_7_n_0 ;
  wire \seg_OBUF[6]_inst_i_8_n_0 ;
  wire \seg_OBUF[6]_inst_i_9_n_0 ;

  LUT6 #(
    .INIT(64'h55555557FFFFFFFF)) 
    \FSM_sequential_estado_actual[1]_i_2 
       (.I0(\n_reg[2]_0 [1]),
        .I1(n[2]),
        .I2(Q[0]),
        .I3(Q[1]),
        .I4(n[3]),
        .I5(\b_reg[3]_0 [0]),
        .O(\FSM_sequential_estado_actual_reg[1] ));
  LUT1 #(
    .INIT(2'h1)) 
    \FSM_sequential_estado_actual[2]_i_2 
       (.I0(rst_IBUF),
        .O(rst));
  LUT5 #(
    .INIT(32'h0001FFFF)) 
    \FSM_sequential_estado_actual[2]_i_3 
       (.I0(n[3]),
        .I1(Q[1]),
        .I2(Q[0]),
        .I3(n[2]),
        .I4(\n_reg[2]_0 [1]),
        .O(\n_reg[3]_0 ));
  FDCE #(
    .INIT(1'b0)) 
    \a_reg[0] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\a_reg[7]_1 [0]),
        .Q(\a_reg[7]_0 [0]));
  FDCE #(
    .INIT(1'b0)) 
    \a_reg[1] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\a_reg[7]_1 [1]),
        .Q(\a_reg[7]_0 [1]));
  FDCE #(
    .INIT(1'b0)) 
    \a_reg[2] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\a_reg[7]_1 [2]),
        .Q(\a_reg[7]_0 [2]));
  FDCE #(
    .INIT(1'b0)) 
    \a_reg[3] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\a_reg[7]_1 [3]),
        .Q(\a_reg[7]_0 [3]));
  FDCE #(
    .INIT(1'b0)) 
    \a_reg[4] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\a_reg[7]_1 [4]),
        .Q(\a_reg[7]_0 [4]));
  FDCE #(
    .INIT(1'b0)) 
    \a_reg[5] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\a_reg[7]_1 [5]),
        .Q(\a_reg[7]_0 [5]));
  FDCE #(
    .INIT(1'b0)) 
    \a_reg[6] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\a_reg[7]_1 [6]),
        .Q(\a_reg[7]_0 [6]));
  FDCE #(
    .INIT(1'b0)) 
    \a_reg[7] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\a_reg[7]_1 [7]),
        .Q(\a_reg[7]_0 [7]));
  FDCE #(
    .INIT(1'b0)) 
    \acc_reg[0] 
       (.C(CLK),
        .CE(acc_ld),
        .CLR(rst),
        .D(mux_acc_n_3),
        .Q(acc_reg[0]));
  FDCE #(
    .INIT(1'b0)) 
    \acc_reg[1] 
       (.C(CLK),
        .CE(acc_ld),
        .CLR(rst),
        .D(mux_acc_n_2),
        .Q(acc_reg[1]));
  FDCE #(
    .INIT(1'b0)) 
    \acc_reg[2] 
       (.C(CLK),
        .CE(acc_ld),
        .CLR(rst),
        .D(mux_acc_n_1),
        .Q(acc_reg[2]));
  FDCE #(
    .INIT(1'b0)) 
    \acc_reg[3] 
       (.C(CLK),
        .CE(acc_ld),
        .CLR(rst),
        .D(mux_acc_n_0),
        .Q(acc_reg[3]));
  FDCE #(
    .INIT(1'b0)) 
    \acc_reg[4] 
       (.C(CLK),
        .CE(acc_ld),
        .CLR(rst),
        .D(mux_acc_n_7),
        .Q(acc_reg[4]));
  FDCE #(
    .INIT(1'b0)) 
    \acc_reg[5] 
       (.C(CLK),
        .CE(acc_ld),
        .CLR(rst),
        .D(mux_acc_n_6),
        .Q(acc_reg[5]));
  FDCE #(
    .INIT(1'b0)) 
    \acc_reg[6] 
       (.C(CLK),
        .CE(acc_ld),
        .CLR(rst),
        .D(mux_acc_n_5),
        .Q(acc_reg[6]));
  FDCE #(
    .INIT(1'b0)) 
    \acc_reg[7] 
       (.C(CLK),
        .CE(acc_ld),
        .CLR(rst),
        .D(mux_acc_n_4),
        .Q(acc_reg[7]));
  FDCE #(
    .INIT(1'b0)) 
    \b_reg[0] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\b_reg[3]_1 [0]),
        .Q(\b_reg[3]_0 [0]));
  FDCE #(
    .INIT(1'b0)) 
    \b_reg[1] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\b_reg[3]_1 [1]),
        .Q(\b_reg[3]_0 [1]));
  FDCE #(
    .INIT(1'b0)) 
    \b_reg[2] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\b_reg[3]_1 [2]),
        .Q(\b_reg[3]_0 [2]));
  FDCE #(
    .INIT(1'b0)) 
    \b_reg[3] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(\b_reg[3]_1 [3]),
        .Q(\b_reg[3]_0 [3]));
  mux_8bits_2op mux_acc
       (.DI(DI),
        .\FSM_sequential_estado_actual_reg[1] ({mux_acc_n_4,mux_acc_n_5,mux_acc_n_6,mux_acc_n_7}),
        .O({mux_acc_n_0,mux_acc_n_1,mux_acc_n_2,mux_acc_n_3}),
        .S(S),
        .\acc_reg[7] (\acc_reg[7]_0 ),
        .\acc_reg[7]_0 (\acc_reg[7]_1 ));
  LUT6 #(
    .INIT(64'h0000E10000E10000)) 
    \n[2]_i_1 
       (.I0(Q[0]),
        .I1(Q[1]),
        .I2(n[2]),
        .I3(\n_reg[2]_0 [1]),
        .I4(\n_reg[2]_0 [2]),
        .I5(\n_reg[2]_0 [0]),
        .O(s_mux_n[2]));
  LUT5 #(
    .INIT(32'hFFFEAAAB)) 
    \n[3]_i_2 
       (.I0(\n_reg[3]_1 ),
        .I1(Q[1]),
        .I2(Q[0]),
        .I3(n[2]),
        .I4(n[3]),
        .O(s_mux_n[3]));
  FDCE #(
    .INIT(1'b0)) 
    \n_reg[0] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(D[0]),
        .Q(Q[0]));
  FDCE #(
    .INIT(1'b0)) 
    \n_reg[1] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(D[1]),
        .Q(Q[1]));
  FDCE #(
    .INIT(1'b0)) 
    \n_reg[2] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(s_mux_n[2]),
        .Q(n[2]));
  FDCE #(
    .INIT(1'b0)) 
    \n_reg[3] 
       (.C(CLK),
        .CE(E),
        .CLR(rst),
        .D(s_mux_n[3]),
        .Q(n[3]));
  LUT6 #(
    .INIT(64'h00004747000000FF)) 
    \seg_OBUF[0]_inst_i_1 
       (.I0(\seg_OBUF[0]_inst_i_2_n_0 ),
        .I1(\seg_OBUF[6]_inst_i_3_n_0 ),
        .I2(\seg_OBUF[0]_inst_i_3_n_0 ),
        .I3(\seg_OBUF[0]_inst_i_4_n_0 ),
        .I4(L[19]),
        .I5(L[18]),
        .O(seg_OBUF[0]));
  LUT6 #(
    .INIT(64'hF7FC01ECFFFF3F0F)) 
    \seg_OBUF[0]_inst_i_2 
       (.I0(acc_reg[1]),
        .I1(acc_reg[2]),
        .I2(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I3(acc_reg[3]),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_8_n_0 ),
        .O(\seg_OBUF[0]_inst_i_2_n_0 ));
  LUT6 #(
    .INIT(64'hF07CFF1FC7F0CFFF)) 
    \seg_OBUF[0]_inst_i_3 
       (.I0(acc_reg[1]),
        .I1(acc_reg[2]),
        .I2(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I3(acc_reg[3]),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_8_n_0 ),
        .O(\seg_OBUF[0]_inst_i_3_n_0 ));
  LUT6 #(
    .INIT(64'h6FF6F9FB6FFFBFDB)) 
    \seg_OBUF[0]_inst_i_4 
       (.I0(acc_reg[0]),
        .I1(acc_reg[2]),
        .I2(acc_reg[1]),
        .I3(\seg_OBUF[6]_inst_i_10_n_0 ),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_9_n_0 ),
        .O(\seg_OBUF[0]_inst_i_4_n_0 ));
  LUT6 #(
    .INIT(64'h00CF005500C00055)) 
    \seg_OBUF[1]_inst_i_1 
       (.I0(\seg_OBUF[1]_inst_i_2_n_0 ),
        .I1(\seg_OBUF[1]_inst_i_3_n_0 ),
        .I2(\seg_OBUF[6]_inst_i_3_n_0 ),
        .I3(L[19]),
        .I4(L[18]),
        .I5(\seg_OBUF[1]_inst_i_4_n_0 ),
        .O(seg_OBUF[1]));
  LUT6 #(
    .INIT(64'hDFEDB7B7DBDB7EB7)) 
    \seg_OBUF[1]_inst_i_2 
       (.I0(acc_reg[0]),
        .I1(acc_reg[2]),
        .I2(acc_reg[1]),
        .I3(\seg_OBUF[6]_inst_i_10_n_0 ),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_9_n_0 ),
        .O(\seg_OBUF[1]_inst_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h4200160046001400)) 
    \seg_OBUF[1]_inst_i_3 
       (.I0(\seg_OBUF[6]_inst_i_8_n_0 ),
        .I1(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I2(acc_reg[3]),
        .I3(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I4(acc_reg[2]),
        .I5(acc_reg[1]),
        .O(\seg_OBUF[1]_inst_i_3_n_0 ));
  LUT6 #(
    .INIT(64'hFFF3F010F8FFC0F0)) 
    \seg_OBUF[1]_inst_i_4 
       (.I0(acc_reg[1]),
        .I1(acc_reg[2]),
        .I2(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I3(acc_reg[3]),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_8_n_0 ),
        .O(\seg_OBUF[1]_inst_i_4_n_0 ));
  LUT6 #(
    .INIT(64'h00CF005500C00055)) 
    \seg_OBUF[2]_inst_i_1 
       (.I0(\seg_OBUF[2]_inst_i_2_n_0 ),
        .I1(\seg_OBUF[2]_inst_i_3_n_0 ),
        .I2(\seg_OBUF[6]_inst_i_3_n_0 ),
        .I3(L[19]),
        .I4(L[18]),
        .I5(\seg_OBUF[2]_inst_i_4_n_0 ),
        .O(seg_OBUF[2]));
  LUT6 #(
    .INIT(64'hFFFFFFFFE7BBEEDF)) 
    \seg_OBUF[2]_inst_i_2 
       (.I0(acc_reg[2]),
        .I1(acc_reg[1]),
        .I2(\seg_OBUF[6]_inst_i_10_n_0 ),
        .I3(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I4(\seg_OBUF[6]_inst_i_9_n_0 ),
        .I5(acc_reg[0]),
        .O(\seg_OBUF[2]_inst_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h0008002000280020)) 
    \seg_OBUF[2]_inst_i_3 
       (.I0(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I1(\seg_OBUF[6]_inst_i_8_n_0 ),
        .I2(acc_reg[3]),
        .I3(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I4(acc_reg[2]),
        .I5(acc_reg[1]),
        .O(\seg_OBUF[2]_inst_i_3_n_0 ));
  LUT6 #(
    .INIT(64'h8C88CC8CC4C4C4C4)) 
    \seg_OBUF[2]_inst_i_4 
       (.I0(acc_reg[3]),
        .I1(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I2(acc_reg[2]),
        .I3(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I4(acc_reg[1]),
        .I5(\seg_OBUF[6]_inst_i_8_n_0 ),
        .O(\seg_OBUF[2]_inst_i_4_n_0 ));
  LUT6 #(
    .INIT(64'h00004747000000FF)) 
    \seg_OBUF[3]_inst_i_1 
       (.I0(\seg_OBUF[3]_inst_i_2_n_0 ),
        .I1(\seg_OBUF[6]_inst_i_3_n_0 ),
        .I2(\seg_OBUF[3]_inst_i_3_n_0 ),
        .I3(\seg_OBUF[3]_inst_i_4_n_0 ),
        .I4(L[19]),
        .I5(L[18]),
        .O(seg_OBUF[3]));
  LUT6 #(
    .INIT(64'h070C01ECCF7F3F0F)) 
    \seg_OBUF[3]_inst_i_2 
       (.I0(acc_reg[1]),
        .I1(acc_reg[2]),
        .I2(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I3(acc_reg[3]),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_8_n_0 ),
        .O(\seg_OBUF[3]_inst_i_2_n_0 ));
  LUT6 #(
    .INIT(64'h0F03C87FFFFFFFFF)) 
    \seg_OBUF[3]_inst_i_3 
       (.I0(acc_reg[1]),
        .I1(acc_reg[2]),
        .I2(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I3(acc_reg[3]),
        .I4(\seg_OBUF[6]_inst_i_8_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_7_n_0 ),
        .O(\seg_OBUF[3]_inst_i_3_n_0 ));
  LUT6 #(
    .INIT(64'h1CF3F6CFEFDC3FF7)) 
    \seg_OBUF[3]_inst_i_4 
       (.I0(\seg_OBUF[6]_inst_i_9_n_0 ),
        .I1(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I2(\seg_OBUF[6]_inst_i_10_n_0 ),
        .I3(acc_reg[1]),
        .I4(acc_reg[2]),
        .I5(acc_reg[0]),
        .O(\seg_OBUF[3]_inst_i_4_n_0 ));
  LUT6 #(
    .INIT(64'hF4F4F444F4F44444)) 
    \seg_OBUF[4]_inst_i_1 
       (.I0(\seg_OBUF[4]_inst_i_2_n_0 ),
        .I1(\seg_OBUF[4]_inst_i_3_n_0 ),
        .I2(\seg[4] ),
        .I3(\seg_OBUF[4]_inst_i_5_n_0 ),
        .I4(acc_reg[0]),
        .I5(\seg_OBUF[4]_inst_i_6_n_0 ),
        .O(seg_OBUF[4]));
  LUT5 #(
    .INIT(32'hFF0EFFFF)) 
    \seg_OBUF[4]_inst_i_2 
       (.I0(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I1(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I2(\seg_OBUF[6]_inst_i_3_n_0 ),
        .I3(L[19]),
        .I4(L[18]),
        .O(\seg_OBUF[4]_inst_i_2_n_0 ));
  LUT6 #(
    .INIT(64'hFFF3FEF3388FF0F0)) 
    \seg_OBUF[4]_inst_i_3 
       (.I0(acc_reg[1]),
        .I1(acc_reg[2]),
        .I2(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I3(acc_reg[3]),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_8_n_0 ),
        .O(\seg_OBUF[4]_inst_i_3_n_0 ));
  LUT6 #(
    .INIT(64'hAAA65BB66DDA6555)) 
    \seg_OBUF[4]_inst_i_5 
       (.I0(acc_reg[1]),
        .I1(acc_reg[2]),
        .I2(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I3(acc_reg[3]),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_8_n_0 ),
        .O(\seg_OBUF[4]_inst_i_5_n_0 ));
  LUT6 #(
    .INIT(64'h00E1FF9FFF060018)) 
    \seg_OBUF[4]_inst_i_6 
       (.I0(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I1(acc_reg[3]),
        .I2(\seg_OBUF[6]_inst_i_8_n_0 ),
        .I3(acc_reg[1]),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(acc_reg[2]),
        .O(\seg_OBUF[4]_inst_i_6_n_0 ));
  LUT6 #(
    .INIT(64'h0003005500CF0055)) 
    \seg_OBUF[5]_inst_i_1 
       (.I0(\seg_OBUF[5]_inst_i_2_n_0 ),
        .I1(\seg_OBUF[6]_inst_i_3_n_0 ),
        .I2(\seg_OBUF[5]_inst_i_3_n_0 ),
        .I3(L[19]),
        .I4(L[18]),
        .I5(\seg_OBUF[5]_inst_i_4_n_0 ),
        .O(seg_OBUF[5]));
  LUT6 #(
    .INIT(64'h7C174D4F7CF7F15F)) 
    \seg_OBUF[5]_inst_i_2 
       (.I0(acc_reg[0]),
        .I1(acc_reg[2]),
        .I2(acc_reg[1]),
        .I3(\seg_OBUF[6]_inst_i_10_n_0 ),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_9_n_0 ),
        .O(\seg_OBUF[5]_inst_i_2_n_0 ));
  LUT6 #(
    .INIT(64'hFFFFF1CFFFFFFFFF)) 
    \seg_OBUF[5]_inst_i_3 
       (.I0(acc_reg[1]),
        .I1(acc_reg[2]),
        .I2(acc_reg[3]),
        .I3(\seg_OBUF[6]_inst_i_8_n_0 ),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_6_n_0 ),
        .O(\seg_OBUF[5]_inst_i_3_n_0 ));
  LUT6 #(
    .INIT(64'h7313371177133731)) 
    \seg_OBUF[5]_inst_i_4 
       (.I0(\seg_OBUF[6]_inst_i_8_n_0 ),
        .I1(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I2(acc_reg[3]),
        .I3(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I4(acc_reg[2]),
        .I5(acc_reg[1]),
        .O(\seg_OBUF[5]_inst_i_4_n_0 ));
  LUT6 #(
    .INIT(64'hFFFFB8B8FFFFFF00)) 
    \seg_OBUF[6]_inst_i_1 
       (.I0(\seg_OBUF[6]_inst_i_2_n_0 ),
        .I1(\seg_OBUF[6]_inst_i_3_n_0 ),
        .I2(\seg_OBUF[6]_inst_i_4_n_0 ),
        .I3(\seg_OBUF[6]_inst_i_5_n_0 ),
        .I4(L[19]),
        .I5(L[18]),
        .O(seg_OBUF[6]));
  LUT6 #(
    .INIT(64'h9956669969955669)) 
    \seg_OBUF[6]_inst_i_10 
       (.I0(acc_reg[2]),
        .I1(acc_reg[3]),
        .I2(acc_reg[6]),
        .I3(acc_reg[7]),
        .I4(acc_reg[5]),
        .I5(acc_reg[4]),
        .O(\seg_OBUF[6]_inst_i_10_n_0 ));
  LUT6 #(
    .INIT(64'hF0F00F0F30800F0F)) 
    \seg_OBUF[6]_inst_i_2 
       (.I0(acc_reg[1]),
        .I1(acc_reg[2]),
        .I2(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I3(acc_reg[3]),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_8_n_0 ),
        .O(\seg_OBUF[6]_inst_i_2_n_0 ));
  LUT4 #(
    .INIT(16'h71CF)) 
    \seg_OBUF[6]_inst_i_3 
       (.I0(acc_reg[4]),
        .I1(acc_reg[5]),
        .I2(acc_reg[7]),
        .I3(acc_reg[6]),
        .O(\seg_OBUF[6]_inst_i_3_n_0 ));
  LUT6 #(
    .INIT(64'h0000F0100000C0F0)) 
    \seg_OBUF[6]_inst_i_4 
       (.I0(acc_reg[1]),
        .I1(acc_reg[2]),
        .I2(\seg_OBUF[6]_inst_i_6_n_0 ),
        .I3(acc_reg[3]),
        .I4(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I5(\seg_OBUF[6]_inst_i_8_n_0 ),
        .O(\seg_OBUF[6]_inst_i_4_n_0 ));
  LUT6 #(
    .INIT(64'hF80A00E000830E00)) 
    \seg_OBUF[6]_inst_i_5 
       (.I0(acc_reg[0]),
        .I1(\seg_OBUF[6]_inst_i_9_n_0 ),
        .I2(\seg_OBUF[6]_inst_i_7_n_0 ),
        .I3(\seg_OBUF[6]_inst_i_10_n_0 ),
        .I4(acc_reg[1]),
        .I5(acc_reg[2]),
        .O(\seg_OBUF[6]_inst_i_5_n_0 ));
  LUT5 #(
    .INIT(32'h0BF0C2BC)) 
    \seg_OBUF[6]_inst_i_6 
       (.I0(acc_reg[3]),
        .I1(acc_reg[6]),
        .I2(acc_reg[7]),
        .I3(acc_reg[5]),
        .I4(acc_reg[4]),
        .O(\seg_OBUF[6]_inst_i_6_n_0 ));
  LUT6 #(
    .INIT(64'h0E388F0EF0E338F0)) 
    \seg_OBUF[6]_inst_i_7 
       (.I0(acc_reg[2]),
        .I1(acc_reg[3]),
        .I2(acc_reg[6]),
        .I3(acc_reg[7]),
        .I4(acc_reg[5]),
        .I5(acc_reg[4]),
        .O(\seg_OBUF[6]_inst_i_7_n_0 ));
  LUT5 #(
    .INIT(32'hDB65249A)) 
    \seg_OBUF[6]_inst_i_8 
       (.I0(acc_reg[4]),
        .I1(acc_reg[5]),
        .I2(acc_reg[7]),
        .I3(acc_reg[6]),
        .I4(acc_reg[3]),
        .O(\seg_OBUF[6]_inst_i_8_n_0 ));
  LUT6 #(
    .INIT(64'h1971C69C71679C19)) 
    \seg_OBUF[6]_inst_i_9 
       (.I0(acc_reg[2]),
        .I1(acc_reg[4]),
        .I2(acc_reg[5]),
        .I3(acc_reg[7]),
        .I4(acc_reg[6]),
        .I5(acc_reg[3]),
        .O(\seg_OBUF[6]_inst_i_9_n_0 ));
endmodule

module debouncer
   (XSync,
    state,
    init_IBUF,
    CLK,
    rst_IBUF);
  output XSync;
  output [1:0]state;
  input init_IBUF;
  input CLK;
  input rst_IBUF;

  wire CLK;
  wire \FSM_sequential_state[0]_i_1_n_0 ;
  wire \FSM_sequential_state[1]_i_1_n_0 ;
  wire \FSM_sequential_state[1]_i_2_n_0 ;
  wire \FSM_sequential_state[1]_i_3_n_0 ;
  wire \FSM_sequential_state[1]_i_4_n_0 ;
  wire \FSM_sequential_state[1]_i_5_n_0 ;
  wire \FSM_sequential_state[1]_i_6_n_0 ;
  wire \FSM_sequential_state[1]_i_7_n_0 ;
  wire \FSM_sequential_state[1]_i_8_n_0 ;
  wire XSync;
  wire XSyncAnterior;
  wire \count[0]_i_1_n_0 ;
  wire \count[0]_i_3_n_0 ;
  wire \count[0]_i_4_n_0 ;
  wire \count[0]_i_5_n_0 ;
  wire \count[0]_i_6_n_0 ;
  wire \count[0]_i_7_n_0 ;
  wire \count[12]_i_2_n_0 ;
  wire \count[12]_i_3_n_0 ;
  wire \count[12]_i_4_n_0 ;
  wire \count[12]_i_5_n_0 ;
  wire \count[16]_i_2_n_0 ;
  wire \count[16]_i_3_n_0 ;
  wire \count[16]_i_4_n_0 ;
  wire \count[16]_i_5_n_0 ;
  wire \count[20]_i_2_n_0 ;
  wire \count[20]_i_3_n_0 ;
  wire \count[20]_i_4_n_0 ;
  wire \count[4]_i_2_n_0 ;
  wire \count[4]_i_3_n_0 ;
  wire \count[4]_i_4_n_0 ;
  wire \count[4]_i_5_n_0 ;
  wire \count[8]_i_2_n_0 ;
  wire \count[8]_i_3_n_0 ;
  wire \count[8]_i_4_n_0 ;
  wire \count[8]_i_5_n_0 ;
  wire [22:0]count_reg;
  wire \count_reg[0]_i_2_n_0 ;
  wire \count_reg[0]_i_2_n_4 ;
  wire \count_reg[0]_i_2_n_5 ;
  wire \count_reg[0]_i_2_n_6 ;
  wire \count_reg[0]_i_2_n_7 ;
  wire \count_reg[12]_i_1_n_0 ;
  wire \count_reg[12]_i_1_n_4 ;
  wire \count_reg[12]_i_1_n_5 ;
  wire \count_reg[12]_i_1_n_6 ;
  wire \count_reg[12]_i_1_n_7 ;
  wire \count_reg[16]_i_1_n_0 ;
  wire \count_reg[16]_i_1_n_4 ;
  wire \count_reg[16]_i_1_n_5 ;
  wire \count_reg[16]_i_1_n_6 ;
  wire \count_reg[16]_i_1_n_7 ;
  wire \count_reg[20]_i_1_n_5 ;
  wire \count_reg[20]_i_1_n_6 ;
  wire \count_reg[20]_i_1_n_7 ;
  wire \count_reg[4]_i_1_n_0 ;
  wire \count_reg[4]_i_1_n_4 ;
  wire \count_reg[4]_i_1_n_5 ;
  wire \count_reg[4]_i_1_n_6 ;
  wire \count_reg[4]_i_1_n_7 ;
  wire \count_reg[8]_i_1_n_0 ;
  wire \count_reg[8]_i_1_n_4 ;
  wire \count_reg[8]_i_1_n_5 ;
  wire \count_reg[8]_i_1_n_6 ;
  wire \count_reg[8]_i_1_n_7 ;
  wire init_IBUF;
  wire rst_IBUF;
  wire [1:0]state;
  wire [2:0]\NLW_count_reg[0]_i_2_CO_UNCONNECTED ;
  wire [2:0]\NLW_count_reg[12]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_count_reg[16]_i_1_CO_UNCONNECTED ;
  wire [3:0]\NLW_count_reg[20]_i_1_CO_UNCONNECTED ;
  wire [3:3]\NLW_count_reg[20]_i_1_O_UNCONNECTED ;
  wire [2:0]\NLW_count_reg[4]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_count_reg[8]_i_1_CO_UNCONNECTED ;

  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT4 #(
    .INIT(16'h7447)) 
    \FSM_sequential_state[0]_i_1 
       (.I0(\FSM_sequential_state[1]_i_2_n_0 ),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\FSM_sequential_state[0]_i_1_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT3 #(
    .INIT(8'h78)) 
    \FSM_sequential_state[1]_i_1 
       (.I0(\FSM_sequential_state[1]_i_2_n_0 ),
        .I1(state[0]),
        .I2(state[1]),
        .O(\FSM_sequential_state[1]_i_1_n_0 ));
  LUT6 #(
    .INIT(64'h0000000000000004)) 
    \FSM_sequential_state[1]_i_2 
       (.I0(\FSM_sequential_state[1]_i_3_n_0 ),
        .I1(\FSM_sequential_state[1]_i_4_n_0 ),
        .I2(\FSM_sequential_state[1]_i_5_n_0 ),
        .I3(\FSM_sequential_state[1]_i_6_n_0 ),
        .I4(\FSM_sequential_state[1]_i_7_n_0 ),
        .I5(\FSM_sequential_state[1]_i_8_n_0 ),
        .O(\FSM_sequential_state[1]_i_2_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \FSM_sequential_state[1]_i_3 
       (.I0(count_reg[3]),
        .I1(count_reg[5]),
        .I2(count_reg[13]),
        .I3(count_reg[16]),
        .O(\FSM_sequential_state[1]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h4000)) 
    \FSM_sequential_state[1]_i_4 
       (.I0(count_reg[7]),
        .I1(count_reg[11]),
        .I2(count_reg[9]),
        .I3(count_reg[14]),
        .O(\FSM_sequential_state[1]_i_4_n_0 ));
  LUT3 #(
    .INIT(8'hFB)) 
    \FSM_sequential_state[1]_i_5 
       (.I0(count_reg[2]),
        .I1(count_reg[19]),
        .I2(count_reg[1]),
        .O(\FSM_sequential_state[1]_i_5_n_0 ));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \FSM_sequential_state[1]_i_6 
       (.I0(count_reg[10]),
        .I1(count_reg[12]),
        .I2(count_reg[17]),
        .I3(count_reg[21]),
        .O(\FSM_sequential_state[1]_i_6_n_0 ));
  LUT4 #(
    .INIT(16'hFFEF)) 
    \FSM_sequential_state[1]_i_7 
       (.I0(count_reg[0]),
        .I1(count_reg[4]),
        .I2(count_reg[8]),
        .I3(count_reg[20]),
        .O(\FSM_sequential_state[1]_i_7_n_0 ));
  LUT4 #(
    .INIT(16'hFF7F)) 
    \FSM_sequential_state[1]_i_8 
       (.I0(count_reg[6]),
        .I1(count_reg[18]),
        .I2(count_reg[22]),
        .I3(count_reg[15]),
        .O(\FSM_sequential_state[1]_i_8_n_0 ));
  (* FSM_ENCODED_STATES = "pressiondebouncing:01,waitingdepression:10,waitingpression:00,depressiondebouncing:11" *) 
  FDCE #(
    .INIT(1'b0)) 
    \FSM_sequential_state_reg[0] 
       (.C(CLK),
        .CE(1'b1),
        .CLR(rst_IBUF),
        .D(\FSM_sequential_state[0]_i_1_n_0 ),
        .Q(state[0]));
  (* FSM_ENCODED_STATES = "pressiondebouncing:01,waitingdepression:10,waitingpression:00,depressiondebouncing:11" *) 
  FDCE #(
    .INIT(1'b0)) 
    \FSM_sequential_state_reg[1] 
       (.C(CLK),
        .CE(1'b1),
        .CLR(rst_IBUF),
        .D(\FSM_sequential_state[1]_i_1_n_0 ),
        .Q(state[1]));
  FDPE #(
    .INIT(1'b1)) 
    XSyncAnterior_reg
       (.C(CLK),
        .CE(1'b1),
        .D(init_IBUF),
        .PRE(rst_IBUF),
        .Q(XSyncAnterior));
  FDPE #(
    .INIT(1'b1)) 
    XSync_reg
       (.C(CLK),
        .CE(1'b1),
        .D(XSyncAnterior),
        .PRE(rst_IBUF),
        .Q(XSync));
  LUT4 #(
    .INIT(16'h41FF)) 
    \count[0]_i_1 
       (.I0(state[0]),
        .I1(XSync),
        .I2(state[1]),
        .I3(\FSM_sequential_state[1]_i_2_n_0 ),
        .O(\count[0]_i_1_n_0 ));
  LUT3 #(
    .INIT(8'hBE)) 
    \count[0]_i_3 
       (.I0(state[0]),
        .I1(XSync),
        .I2(state[1]),
        .O(\count[0]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[0]_i_4 
       (.I0(count_reg[3]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[0]_i_4_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[0]_i_5 
       (.I0(count_reg[2]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[0]_i_5_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[0]_i_6 
       (.I0(count_reg[1]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[0]_i_6_n_0 ));
  LUT4 #(
    .INIT(16'h4554)) 
    \count[0]_i_7 
       (.I0(count_reg[0]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[0]_i_7_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[12]_i_2 
       (.I0(count_reg[15]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[12]_i_2_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[12]_i_3 
       (.I0(count_reg[14]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[12]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[12]_i_4 
       (.I0(count_reg[13]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[12]_i_4_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[12]_i_5 
       (.I0(count_reg[12]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[12]_i_5_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[16]_i_2 
       (.I0(count_reg[19]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[16]_i_2_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[16]_i_3 
       (.I0(count_reg[18]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[16]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[16]_i_4 
       (.I0(count_reg[17]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[16]_i_4_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[16]_i_5 
       (.I0(count_reg[16]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[16]_i_5_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[20]_i_2 
       (.I0(count_reg[22]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[20]_i_2_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[20]_i_3 
       (.I0(count_reg[21]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[20]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[20]_i_4 
       (.I0(count_reg[20]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[20]_i_4_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[4]_i_2 
       (.I0(count_reg[7]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[4]_i_2_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[4]_i_3 
       (.I0(count_reg[6]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[4]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[4]_i_4 
       (.I0(count_reg[5]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[4]_i_4_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[4]_i_5 
       (.I0(count_reg[4]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[4]_i_5_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[8]_i_2 
       (.I0(count_reg[11]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[8]_i_2_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[8]_i_3 
       (.I0(count_reg[10]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[8]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[8]_i_4 
       (.I0(count_reg[9]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[8]_i_4_n_0 ));
  LUT4 #(
    .INIT(16'h8AA8)) 
    \count[8]_i_5 
       (.I0(count_reg[8]),
        .I1(state[0]),
        .I2(XSync),
        .I3(state[1]),
        .O(\count[8]_i_5_n_0 ));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[0] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[0]_i_2_n_7 ),
        .Q(count_reg[0]));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[0]_i_2 
       (.CI(1'b0),
        .CO({\count_reg[0]_i_2_n_0 ,\NLW_count_reg[0]_i_2_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,\count[0]_i_3_n_0 }),
        .O({\count_reg[0]_i_2_n_4 ,\count_reg[0]_i_2_n_5 ,\count_reg[0]_i_2_n_6 ,\count_reg[0]_i_2_n_7 }),
        .S({\count[0]_i_4_n_0 ,\count[0]_i_5_n_0 ,\count[0]_i_6_n_0 ,\count[0]_i_7_n_0 }));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[10] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[8]_i_1_n_5 ),
        .Q(count_reg[10]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[11] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[8]_i_1_n_4 ),
        .Q(count_reg[11]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[12] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[12]_i_1_n_7 ),
        .Q(count_reg[12]));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[12]_i_1 
       (.CI(\count_reg[8]_i_1_n_0 ),
        .CO({\count_reg[12]_i_1_n_0 ,\NLW_count_reg[12]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\count_reg[12]_i_1_n_4 ,\count_reg[12]_i_1_n_5 ,\count_reg[12]_i_1_n_6 ,\count_reg[12]_i_1_n_7 }),
        .S({\count[12]_i_2_n_0 ,\count[12]_i_3_n_0 ,\count[12]_i_4_n_0 ,\count[12]_i_5_n_0 }));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[13] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[12]_i_1_n_6 ),
        .Q(count_reg[13]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[14] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[12]_i_1_n_5 ),
        .Q(count_reg[14]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[15] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[12]_i_1_n_4 ),
        .Q(count_reg[15]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[16] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[16]_i_1_n_7 ),
        .Q(count_reg[16]));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[16]_i_1 
       (.CI(\count_reg[12]_i_1_n_0 ),
        .CO({\count_reg[16]_i_1_n_0 ,\NLW_count_reg[16]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\count_reg[16]_i_1_n_4 ,\count_reg[16]_i_1_n_5 ,\count_reg[16]_i_1_n_6 ,\count_reg[16]_i_1_n_7 }),
        .S({\count[16]_i_2_n_0 ,\count[16]_i_3_n_0 ,\count[16]_i_4_n_0 ,\count[16]_i_5_n_0 }));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[17] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[16]_i_1_n_6 ),
        .Q(count_reg[17]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[18] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[16]_i_1_n_5 ),
        .Q(count_reg[18]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[19] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[16]_i_1_n_4 ),
        .Q(count_reg[19]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[1] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[0]_i_2_n_6 ),
        .Q(count_reg[1]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[20] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[20]_i_1_n_7 ),
        .Q(count_reg[20]));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[20]_i_1 
       (.CI(\count_reg[16]_i_1_n_0 ),
        .CO(\NLW_count_reg[20]_i_1_CO_UNCONNECTED [3:0]),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\NLW_count_reg[20]_i_1_O_UNCONNECTED [3],\count_reg[20]_i_1_n_5 ,\count_reg[20]_i_1_n_6 ,\count_reg[20]_i_1_n_7 }),
        .S({1'b0,\count[20]_i_2_n_0 ,\count[20]_i_3_n_0 ,\count[20]_i_4_n_0 }));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[21] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[20]_i_1_n_6 ),
        .Q(count_reg[21]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[22] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[20]_i_1_n_5 ),
        .Q(count_reg[22]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[2] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[0]_i_2_n_5 ),
        .Q(count_reg[2]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[3] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[0]_i_2_n_4 ),
        .Q(count_reg[3]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[4] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[4]_i_1_n_7 ),
        .Q(count_reg[4]));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[4]_i_1 
       (.CI(\count_reg[0]_i_2_n_0 ),
        .CO({\count_reg[4]_i_1_n_0 ,\NLW_count_reg[4]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\count_reg[4]_i_1_n_4 ,\count_reg[4]_i_1_n_5 ,\count_reg[4]_i_1_n_6 ,\count_reg[4]_i_1_n_7 }),
        .S({\count[4]_i_2_n_0 ,\count[4]_i_3_n_0 ,\count[4]_i_4_n_0 ,\count[4]_i_5_n_0 }));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[5] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[4]_i_1_n_6 ),
        .Q(count_reg[5]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[6] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[4]_i_1_n_5 ),
        .Q(count_reg[6]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[7] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[4]_i_1_n_4 ),
        .Q(count_reg[7]));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[8] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[8]_i_1_n_7 ),
        .Q(count_reg[8]));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[8]_i_1 
       (.CI(\count_reg[4]_i_1_n_0 ),
        .CO({\count_reg[8]_i_1_n_0 ,\NLW_count_reg[8]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\count_reg[8]_i_1_n_4 ,\count_reg[8]_i_1_n_5 ,\count_reg[8]_i_1_n_6 ,\count_reg[8]_i_1_n_7 }),
        .S({\count[8]_i_2_n_0 ,\count[8]_i_3_n_0 ,\count[8]_i_4_n_0 ,\count[8]_i_5_n_0 }));
  FDCE #(
    .INIT(1'b0)) 
    \count_reg[9] 
       (.C(CLK),
        .CE(\count[0]_i_1_n_0 ),
        .CLR(rst_IBUF),
        .D(\count_reg[8]_i_1_n_6 ),
        .Q(count_reg[9]));
endmodule

module displays
   (L,
    an_OBUF,
    \contador_refresco_reg[19]_0 ,
    rst_IBUF,
    CLK);
  output [19:18]L;
  output [3:0]an_OBUF;
  output \contador_refresco_reg[19]_0 ;
  input rst_IBUF;
  input CLK;

  wire CLK;
  wire [19:18]L;
  wire [3:0]an_OBUF;
  wire \contador_refresco[0]_i_2_n_0 ;
  wire \contador_refresco_reg[0]_i_1_n_0 ;
  wire \contador_refresco_reg[0]_i_1_n_4 ;
  wire \contador_refresco_reg[0]_i_1_n_5 ;
  wire \contador_refresco_reg[0]_i_1_n_6 ;
  wire \contador_refresco_reg[0]_i_1_n_7 ;
  wire \contador_refresco_reg[12]_i_1_n_0 ;
  wire \contador_refresco_reg[12]_i_1_n_4 ;
  wire \contador_refresco_reg[12]_i_1_n_5 ;
  wire \contador_refresco_reg[12]_i_1_n_6 ;
  wire \contador_refresco_reg[12]_i_1_n_7 ;
  wire \contador_refresco_reg[16]_i_1_n_4 ;
  wire \contador_refresco_reg[16]_i_1_n_5 ;
  wire \contador_refresco_reg[16]_i_1_n_6 ;
  wire \contador_refresco_reg[16]_i_1_n_7 ;
  wire \contador_refresco_reg[19]_0 ;
  wire \contador_refresco_reg[4]_i_1_n_0 ;
  wire \contador_refresco_reg[4]_i_1_n_4 ;
  wire \contador_refresco_reg[4]_i_1_n_5 ;
  wire \contador_refresco_reg[4]_i_1_n_6 ;
  wire \contador_refresco_reg[4]_i_1_n_7 ;
  wire \contador_refresco_reg[8]_i_1_n_0 ;
  wire \contador_refresco_reg[8]_i_1_n_4 ;
  wire \contador_refresco_reg[8]_i_1_n_5 ;
  wire \contador_refresco_reg[8]_i_1_n_6 ;
  wire \contador_refresco_reg[8]_i_1_n_7 ;
  wire \contador_refresco_reg_n_0_[0] ;
  wire \contador_refresco_reg_n_0_[10] ;
  wire \contador_refresco_reg_n_0_[11] ;
  wire \contador_refresco_reg_n_0_[12] ;
  wire \contador_refresco_reg_n_0_[13] ;
  wire \contador_refresco_reg_n_0_[14] ;
  wire \contador_refresco_reg_n_0_[15] ;
  wire \contador_refresco_reg_n_0_[16] ;
  wire \contador_refresco_reg_n_0_[17] ;
  wire \contador_refresco_reg_n_0_[1] ;
  wire \contador_refresco_reg_n_0_[2] ;
  wire \contador_refresco_reg_n_0_[3] ;
  wire \contador_refresco_reg_n_0_[4] ;
  wire \contador_refresco_reg_n_0_[5] ;
  wire \contador_refresco_reg_n_0_[6] ;
  wire \contador_refresco_reg_n_0_[7] ;
  wire \contador_refresco_reg_n_0_[8] ;
  wire \contador_refresco_reg_n_0_[9] ;
  wire rst_IBUF;
  wire [2:0]\NLW_contador_refresco_reg[0]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_contador_refresco_reg[12]_i_1_CO_UNCONNECTED ;
  wire [3:0]\NLW_contador_refresco_reg[16]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_contador_refresco_reg[4]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_contador_refresco_reg[8]_i_1_CO_UNCONNECTED ;

  LUT2 #(
    .INIT(4'hE)) 
    \an_OBUF[0]_inst_i_1 
       (.I0(L[18]),
        .I1(L[19]),
        .O(an_OBUF[0]));
  LUT2 #(
    .INIT(4'hB)) 
    \an_OBUF[1]_inst_i_1 
       (.I0(L[19]),
        .I1(L[18]),
        .O(an_OBUF[1]));
  LUT2 #(
    .INIT(4'hB)) 
    \an_OBUF[2]_inst_i_1 
       (.I0(L[18]),
        .I1(L[19]),
        .O(an_OBUF[2]));
  LUT2 #(
    .INIT(4'h7)) 
    \an_OBUF[3]_inst_i_1 
       (.I0(L[19]),
        .I1(L[18]),
        .O(an_OBUF[3]));
  LUT1 #(
    .INIT(2'h1)) 
    \contador_refresco[0]_i_2 
       (.I0(\contador_refresco_reg_n_0_[0] ),
        .O(\contador_refresco[0]_i_2_n_0 ));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[0] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[0]_i_1_n_7 ),
        .Q(\contador_refresco_reg_n_0_[0] ),
        .R(rst_IBUF));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \contador_refresco_reg[0]_i_1 
       (.CI(1'b0),
        .CO({\contador_refresco_reg[0]_i_1_n_0 ,\NLW_contador_refresco_reg[0]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b1}),
        .O({\contador_refresco_reg[0]_i_1_n_4 ,\contador_refresco_reg[0]_i_1_n_5 ,\contador_refresco_reg[0]_i_1_n_6 ,\contador_refresco_reg[0]_i_1_n_7 }),
        .S({\contador_refresco_reg_n_0_[3] ,\contador_refresco_reg_n_0_[2] ,\contador_refresco_reg_n_0_[1] ,\contador_refresco[0]_i_2_n_0 }));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[10] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[8]_i_1_n_5 ),
        .Q(\contador_refresco_reg_n_0_[10] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[11] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[8]_i_1_n_4 ),
        .Q(\contador_refresco_reg_n_0_[11] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[12] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[12]_i_1_n_7 ),
        .Q(\contador_refresco_reg_n_0_[12] ),
        .R(rst_IBUF));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \contador_refresco_reg[12]_i_1 
       (.CI(\contador_refresco_reg[8]_i_1_n_0 ),
        .CO({\contador_refresco_reg[12]_i_1_n_0 ,\NLW_contador_refresco_reg[12]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\contador_refresco_reg[12]_i_1_n_4 ,\contador_refresco_reg[12]_i_1_n_5 ,\contador_refresco_reg[12]_i_1_n_6 ,\contador_refresco_reg[12]_i_1_n_7 }),
        .S({\contador_refresco_reg_n_0_[15] ,\contador_refresco_reg_n_0_[14] ,\contador_refresco_reg_n_0_[13] ,\contador_refresco_reg_n_0_[12] }));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[13] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[12]_i_1_n_6 ),
        .Q(\contador_refresco_reg_n_0_[13] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[14] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[12]_i_1_n_5 ),
        .Q(\contador_refresco_reg_n_0_[14] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[15] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[12]_i_1_n_4 ),
        .Q(\contador_refresco_reg_n_0_[15] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[16] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[16]_i_1_n_7 ),
        .Q(\contador_refresco_reg_n_0_[16] ),
        .R(rst_IBUF));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \contador_refresco_reg[16]_i_1 
       (.CI(\contador_refresco_reg[12]_i_1_n_0 ),
        .CO(\NLW_contador_refresco_reg[16]_i_1_CO_UNCONNECTED [3:0]),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\contador_refresco_reg[16]_i_1_n_4 ,\contador_refresco_reg[16]_i_1_n_5 ,\contador_refresco_reg[16]_i_1_n_6 ,\contador_refresco_reg[16]_i_1_n_7 }),
        .S({L,\contador_refresco_reg_n_0_[17] ,\contador_refresco_reg_n_0_[16] }));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[17] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[16]_i_1_n_6 ),
        .Q(\contador_refresco_reg_n_0_[17] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[18] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[16]_i_1_n_5 ),
        .Q(L[18]),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[19] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[16]_i_1_n_4 ),
        .Q(L[19]),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[1] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[0]_i_1_n_6 ),
        .Q(\contador_refresco_reg_n_0_[1] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[2] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[0]_i_1_n_5 ),
        .Q(\contador_refresco_reg_n_0_[2] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[3] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[0]_i_1_n_4 ),
        .Q(\contador_refresco_reg_n_0_[3] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[4] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[4]_i_1_n_7 ),
        .Q(\contador_refresco_reg_n_0_[4] ),
        .R(rst_IBUF));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \contador_refresco_reg[4]_i_1 
       (.CI(\contador_refresco_reg[0]_i_1_n_0 ),
        .CO({\contador_refresco_reg[4]_i_1_n_0 ,\NLW_contador_refresco_reg[4]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\contador_refresco_reg[4]_i_1_n_4 ,\contador_refresco_reg[4]_i_1_n_5 ,\contador_refresco_reg[4]_i_1_n_6 ,\contador_refresco_reg[4]_i_1_n_7 }),
        .S({\contador_refresco_reg_n_0_[7] ,\contador_refresco_reg_n_0_[6] ,\contador_refresco_reg_n_0_[5] ,\contador_refresco_reg_n_0_[4] }));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[5] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[4]_i_1_n_6 ),
        .Q(\contador_refresco_reg_n_0_[5] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[6] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[4]_i_1_n_5 ),
        .Q(\contador_refresco_reg_n_0_[6] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[7] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[4]_i_1_n_4 ),
        .Q(\contador_refresco_reg_n_0_[7] ),
        .R(rst_IBUF));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[8] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[8]_i_1_n_7 ),
        .Q(\contador_refresco_reg_n_0_[8] ),
        .R(rst_IBUF));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \contador_refresco_reg[8]_i_1 
       (.CI(\contador_refresco_reg[4]_i_1_n_0 ),
        .CO({\contador_refresco_reg[8]_i_1_n_0 ,\NLW_contador_refresco_reg[8]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\contador_refresco_reg[8]_i_1_n_4 ,\contador_refresco_reg[8]_i_1_n_5 ,\contador_refresco_reg[8]_i_1_n_6 ,\contador_refresco_reg[8]_i_1_n_7 }),
        .S({\contador_refresco_reg_n_0_[11] ,\contador_refresco_reg_n_0_[10] ,\contador_refresco_reg_n_0_[9] ,\contador_refresco_reg_n_0_[8] }));
  FDRE #(
    .INIT(1'b0)) 
    \contador_refresco_reg[9] 
       (.C(CLK),
        .CE(1'b1),
        .D(\contador_refresco_reg[8]_i_1_n_6 ),
        .Q(\contador_refresco_reg_n_0_[9] ),
        .R(rst_IBUF));
  LUT2 #(
    .INIT(4'h1)) 
    \seg_OBUF[4]_inst_i_4 
       (.I0(L[19]),
        .I1(L[18]),
        .O(\contador_refresco_reg[19]_0 ));
endmodule

(* ECO_CHECKSUM = "3e5c0f3" *) 
(* NotValidForBitStream *)
module modulo
   (clk,
    rst,
    init,
    a_in,
    b_in,
    led,
    seg,
    an);
  input clk;
  input rst;
  input init;
  input [3:0]a_in;
  input [3:0]b_in;
  output [7:0]led;
  output [6:0]seg;
  output [3:0]an;

  wire [19:18]L;
  wire XSync;
  wire [3:0]a_in;
  wire [3:0]a_in_IBUF;
  wire [3:0]an;
  wire [3:0]an_OBUF;
  wire [3:0]b_in;
  wire [3:0]b_in_IBUF;
  wire clk;
  wire clk_IBUF;
  wire clk_IBUF_BUFG;
  wire disp_n_6;
  wire init;
  wire init_IBUF;
  wire [7:0]led;
  wire [0:0]led_OBUF;
  wire rst;
  wire rst_IBUF;
  wire [6:0]seg;
  wire [6:0]seg_OBUF;
  wire [1:0]state;

initial begin
 $sdf_annotate("test_multiplicador_time_impl.sdf",,,,"tool_control");
end
  IBUF \a_in_IBUF[0]_inst 
       (.I(a_in[0]),
        .O(a_in_IBUF[0]));
  IBUF \a_in_IBUF[1]_inst 
       (.I(a_in[1]),
        .O(a_in_IBUF[1]));
  IBUF \a_in_IBUF[2]_inst 
       (.I(a_in[2]),
        .O(a_in_IBUF[2]));
  IBUF \a_in_IBUF[3]_inst 
       (.I(a_in[3]),
        .O(a_in_IBUF[3]));
  OBUF \an_OBUF[0]_inst 
       (.I(an_OBUF[0]),
        .O(an[0]));
  OBUF \an_OBUF[1]_inst 
       (.I(an_OBUF[1]),
        .O(an[1]));
  OBUF \an_OBUF[2]_inst 
       (.I(an_OBUF[2]),
        .O(an[2]));
  OBUF \an_OBUF[3]_inst 
       (.I(an_OBUF[3]),
        .O(an[3]));
  IBUF \b_in_IBUF[0]_inst 
       (.I(b_in[0]),
        .O(b_in_IBUF[0]));
  IBUF \b_in_IBUF[1]_inst 
       (.I(b_in[1]),
        .O(b_in_IBUF[1]));
  IBUF \b_in_IBUF[2]_inst 
       (.I(b_in[2]),
        .O(b_in_IBUF[2]));
  IBUF \b_in_IBUF[3]_inst 
       (.I(b_in[3]),
        .O(b_in_IBUF[3]));
  BUFG clk_IBUF_BUFG_inst
       (.I(clk_IBUF),
        .O(clk_IBUF_BUFG));
  IBUF clk_IBUF_inst
       (.I(clk),
        .O(clk_IBUF));
  debouncer deb
       (.CLK(clk_IBUF_BUFG),
        .XSync(XSync),
        .init_IBUF(init_IBUF),
        .rst_IBUF(rst_IBUF),
        .state(state));
  displays disp
       (.CLK(clk_IBUF_BUFG),
        .L(L),
        .an_OBUF(an_OBUF),
        .\contador_refresco_reg[19]_0 (disp_n_6),
        .rst_IBUF(rst_IBUF));
  IBUF init_IBUF_inst
       (.I(init),
        .O(init_IBUF));
  OBUF \led_OBUF[0]_inst 
       (.I(led_OBUF),
        .O(led[0]));
  OBUF \led_OBUF[1]_inst 
       (.I(led_OBUF),
        .O(led[1]));
  OBUF \led_OBUF[2]_inst 
       (.I(led_OBUF),
        .O(led[2]));
  OBUF \led_OBUF[3]_inst 
       (.I(led_OBUF),
        .O(led[3]));
  OBUF \led_OBUF[4]_inst 
       (.I(led_OBUF),
        .O(led[4]));
  OBUF \led_OBUF[5]_inst 
       (.I(led_OBUF),
        .O(led[5]));
  OBUF \led_OBUF[6]_inst 
       (.I(led_OBUF),
        .O(led[6]));
  OBUF \led_OBUF[7]_inst 
       (.I(led_OBUF),
        .O(led[7]));
  multiplicador mult
       (.CLK(clk_IBUF_BUFG),
        .L(L),
        .XSync(XSync),
        .a_in_IBUF(a_in_IBUF),
        .b_in_IBUF(b_in_IBUF),
        .led_OBUF(led_OBUF),
        .rst_IBUF(rst_IBUF),
        .\seg[4] (disp_n_6),
        .seg_OBUF(seg_OBUF),
        .state(state));
  IBUF rst_IBUF_inst
       (.I(rst),
        .O(rst_IBUF));
  OBUF \seg_OBUF[0]_inst 
       (.I(seg_OBUF[0]),
        .O(seg[0]));
  OBUF \seg_OBUF[1]_inst 
       (.I(seg_OBUF[1]),
        .O(seg[1]));
  OBUF \seg_OBUF[2]_inst 
       (.I(seg_OBUF[2]),
        .O(seg[2]));
  OBUF \seg_OBUF[3]_inst 
       (.I(seg_OBUF[3]),
        .O(seg[3]));
  OBUF \seg_OBUF[4]_inst 
       (.I(seg_OBUF[4]),
        .O(seg[4]));
  OBUF \seg_OBUF[5]_inst 
       (.I(seg_OBUF[5]),
        .O(seg[5]));
  OBUF \seg_OBUF[6]_inst 
       (.I(seg_OBUF[6]),
        .O(seg[6]));
endmodule

module multiplicador
   (seg_OBUF,
    led_OBUF,
    CLK,
    a_in_IBUF,
    b_in_IBUF,
    L,
    \seg[4] ,
    state,
    XSync,
    rst_IBUF);
  output [6:0]seg_OBUF;
  output [0:0]led_OBUF;
  input CLK;
  input [3:0]a_in_IBUF;
  input [3:0]b_in_IBUF;
  input [19:18]L;
  input \seg[4] ;
  input [1:0]state;
  input XSync;
  input rst_IBUF;

  wire CLK;
  wire [19:18]L;
  wire XSync;
  wire [7:0]a;
  wire [3:0]a_in_IBUF;
  wire acc_ld;
  wire [7:0]acc_reg;
  wire [3:0]b_in_IBUF;
  wire [2:0]desp_b;
  wire [2:0]estado_actual;
  wire i_cd_n_18;
  wire i_cd_n_22;
  wire i_cd_n_23;
  wire i_cd_n_8;
  wire i_uc_n_0;
  wire i_uc_n_1;
  wire i_uc_n_19;
  wire i_uc_n_2;
  wire i_uc_n_24;
  wire i_uc_n_27;
  wire i_uc_n_28;
  wire i_uc_n_29;
  wire i_uc_n_30;
  wire i_uc_n_31;
  wire i_uc_n_32;
  wire i_uc_n_33;
  wire i_uc_n_34;
  wire i_uc_n_6;
  wire i_uc_n_7;
  wire i_uc_n_8;
  wire i_uc_n_9;
  wire [0:0]led_OBUF;
  wire [1:0]n;
  wire n_ld;
  wire rst_IBUF;
  wire [7:0]s_mux_a;
  wire [3:0]s_mux_b;
  wire [1:1]s_mux_n;
  wire \seg[4] ;
  wire [6:0]seg_OBUF;
  wire [1:0]state;

  cd i_cd
       (.CLK(CLK),
        .D({s_mux_n,i_uc_n_19}),
        .DI({i_uc_n_31,i_uc_n_32,i_uc_n_33,i_uc_n_34}),
        .E(n_ld),
        .\FSM_sequential_estado_actual_reg[1] (i_cd_n_18),
        .L(L),
        .Q(n),
        .S({i_uc_n_27,i_uc_n_28,i_uc_n_29,i_uc_n_30}),
        .\a_reg[7]_0 (a),
        .\a_reg[7]_1 (s_mux_a),
        .acc_ld(acc_ld),
        .acc_reg(acc_reg),
        .\acc_reg[7]_0 ({i_uc_n_0,i_uc_n_1,i_uc_n_2}),
        .\acc_reg[7]_1 ({i_uc_n_6,i_uc_n_7,i_uc_n_8,i_uc_n_9}),
        .\b_reg[3]_0 ({desp_b,i_cd_n_22}),
        .\b_reg[3]_1 (s_mux_b),
        .\n_reg[2]_0 (estado_actual),
        .\n_reg[3]_0 (i_cd_n_23),
        .\n_reg[3]_1 (i_uc_n_24),
        .rst(i_cd_n_8),
        .rst_IBUF(rst_IBUF),
        .\seg[4] (\seg[4] ),
        .seg_OBUF(seg_OBUF));
  uc i_uc
       (.CLK(CLK),
        .D({s_mux_n,i_uc_n_19}),
        .DI({i_uc_n_31,i_uc_n_32,i_uc_n_33,i_uc_n_34}),
        .E(n_ld),
        .\FSM_sequential_estado_actual_reg[0]_0 (i_uc_n_24),
        .\FSM_sequential_estado_actual_reg[0]_1 (i_cd_n_8),
        .\FSM_sequential_estado_actual_reg[1]_0 ({i_uc_n_0,i_uc_n_1,i_uc_n_2}),
        .\FSM_sequential_estado_actual_reg[1]_1 ({i_uc_n_6,i_uc_n_7,i_uc_n_8,i_uc_n_9}),
        .\FSM_sequential_estado_actual_reg[1]_2 (s_mux_b),
        .\FSM_sequential_estado_actual_reg[1]_3 (i_cd_n_18),
        .\FSM_sequential_estado_actual_reg[2]_0 (i_cd_n_23),
        .Q(estado_actual),
        .S({i_uc_n_27,i_uc_n_28,i_uc_n_29,i_uc_n_30}),
        .XSync(XSync),
        .a_in_IBUF(a_in_IBUF),
        .\a_reg[6] (s_mux_a),
        .acc_ld(acc_ld),
        .acc_reg(acc_reg),
        .\acc_reg[7] (a),
        .b_in_IBUF(b_in_IBUF),
        .\b_reg[2] ({desp_b,i_cd_n_22}),
        .led_OBUF(led_OBUF),
        .\n_reg[1] (n),
        .state(state));
endmodule

module mux_8bits_2op
   (O,
    \FSM_sequential_estado_actual_reg[1] ,
    DI,
    S,
    \acc_reg[7] ,
    \acc_reg[7]_0 );
  output [3:0]O;
  output [3:0]\FSM_sequential_estado_actual_reg[1] ;
  input [3:0]DI;
  input [3:0]S;
  input [2:0]\acc_reg[7] ;
  input [3:0]\acc_reg[7]_0 ;

  wire [3:0]DI;
  wire [3:0]\FSM_sequential_estado_actual_reg[1] ;
  wire [3:0]O;
  wire [3:0]S;
  wire [2:0]\acc_reg[7] ;
  wire [3:0]\acc_reg[7]_0 ;
  wire salida_carry_n_0;
  wire [2:0]NLW_salida_carry_CO_UNCONNECTED;
  wire [3:0]NLW_salida_carry__0_CO_UNCONNECTED;

  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 salida_carry
       (.CI(1'b0),
        .CO({salida_carry_n_0,NLW_salida_carry_CO_UNCONNECTED[2:0]}),
        .CYINIT(1'b0),
        .DI(DI),
        .O(O),
        .S(S));
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 salida_carry__0
       (.CI(salida_carry_n_0),
        .CO(NLW_salida_carry__0_CO_UNCONNECTED[3:0]),
        .CYINIT(1'b0),
        .DI({1'b0,\acc_reg[7] }),
        .O(\FSM_sequential_estado_actual_reg[1] ),
        .S(\acc_reg[7]_0 ));
endmodule

module uc
   (\FSM_sequential_estado_actual_reg[1]_0 ,
    Q,
    \FSM_sequential_estado_actual_reg[1]_1 ,
    \a_reg[6] ,
    D,
    \FSM_sequential_estado_actual_reg[1]_2 ,
    \FSM_sequential_estado_actual_reg[0]_0 ,
    E,
    acc_ld,
    S,
    DI,
    led_OBUF,
    acc_reg,
    \acc_reg[7] ,
    a_in_IBUF,
    \n_reg[1] ,
    b_in_IBUF,
    \b_reg[2] ,
    \FSM_sequential_estado_actual_reg[1]_3 ,
    state,
    XSync,
    \FSM_sequential_estado_actual_reg[2]_0 ,
    CLK,
    \FSM_sequential_estado_actual_reg[0]_1 );
  output [2:0]\FSM_sequential_estado_actual_reg[1]_0 ;
  output [2:0]Q;
  output [3:0]\FSM_sequential_estado_actual_reg[1]_1 ;
  output [7:0]\a_reg[6] ;
  output [1:0]D;
  output [3:0]\FSM_sequential_estado_actual_reg[1]_2 ;
  output \FSM_sequential_estado_actual_reg[0]_0 ;
  output [0:0]E;
  output acc_ld;
  output [3:0]S;
  output [3:0]DI;
  output [0:0]led_OBUF;
  input [7:0]acc_reg;
  input [7:0]\acc_reg[7] ;
  input [3:0]a_in_IBUF;
  input [1:0]\n_reg[1] ;
  input [3:0]b_in_IBUF;
  input [3:0]\b_reg[2] ;
  input \FSM_sequential_estado_actual_reg[1]_3 ;
  input [1:0]state;
  input XSync;
  input \FSM_sequential_estado_actual_reg[2]_0 ;
  input CLK;
  input \FSM_sequential_estado_actual_reg[0]_1 ;

  wire CLK;
  wire [1:0]D;
  wire [3:0]DI;
  wire [0:0]E;
  wire \FSM_sequential_estado_actual[0]_i_2_n_0 ;
  wire \FSM_sequential_estado_actual_reg[0]_0 ;
  wire \FSM_sequential_estado_actual_reg[0]_1 ;
  wire [2:0]\FSM_sequential_estado_actual_reg[1]_0 ;
  wire [3:0]\FSM_sequential_estado_actual_reg[1]_1 ;
  wire [3:0]\FSM_sequential_estado_actual_reg[1]_2 ;
  wire \FSM_sequential_estado_actual_reg[1]_3 ;
  wire \FSM_sequential_estado_actual_reg[2]_0 ;
  wire [2:0]Q;
  wire [3:0]S;
  wire XSync;
  wire [3:0]a_in_IBUF;
  wire [7:0]\a_reg[6] ;
  wire acc_ld;
  wire [7:0]acc_reg;
  wire [7:0]\acc_reg[7] ;
  wire [3:0]b_in_IBUF;
  wire [3:0]\b_reg[2] ;
  wire [2:0]estado_siguiente;
  wire [0:0]led_OBUF;
  wire [1:0]\n_reg[1] ;
  wire [1:0]state;

  LUT6 #(
    .INIT(64'h0000000155555555)) 
    \FSM_sequential_estado_actual[0]_i_1 
       (.I0(\FSM_sequential_estado_actual[0]_i_2_n_0 ),
        .I1(Q[1]),
        .I2(state[1]),
        .I3(state[0]),
        .I4(XSync),
        .I5(\FSM_sequential_estado_actual_reg[1]_3 ),
        .O(estado_siguiente[0]));
  LUT2 #(
    .INIT(4'hE)) 
    \FSM_sequential_estado_actual[0]_i_2 
       (.I0(Q[0]),
        .I1(Q[2]),
        .O(\FSM_sequential_estado_actual[0]_i_2_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair10" *) 
  LUT4 #(
    .INIT(16'h11CF)) 
    \FSM_sequential_estado_actual[1]_i_1 
       (.I0(Q[1]),
        .I1(Q[0]),
        .I2(\FSM_sequential_estado_actual_reg[1]_3 ),
        .I3(Q[2]),
        .O(estado_siguiente[1]));
  LUT4 #(
    .INIT(16'h0001)) 
    \FSM_sequential_estado_actual[2]_i_1 
       (.I0(Q[0]),
        .I1(Q[2]),
        .I2(\b_reg[2] [0]),
        .I3(\FSM_sequential_estado_actual_reg[2]_0 ),
        .O(estado_siguiente[2]));
  (* FSM_ENCODED_STATES = "s2:010,s1:001,s0:000,s4:100,s3:011" *) 
  FDCE #(
    .INIT(1'b0)) 
    \FSM_sequential_estado_actual_reg[0] 
       (.C(CLK),
        .CE(1'b1),
        .CLR(\FSM_sequential_estado_actual_reg[0]_1 ),
        .D(estado_siguiente[0]),
        .Q(Q[0]));
  (* FSM_ENCODED_STATES = "s2:010,s1:001,s0:000,s4:100,s3:011" *) 
  FDCE #(
    .INIT(1'b0)) 
    \FSM_sequential_estado_actual_reg[1] 
       (.C(CLK),
        .CE(1'b1),
        .CLR(\FSM_sequential_estado_actual_reg[0]_1 ),
        .D(estado_siguiente[1]),
        .Q(Q[1]));
  (* FSM_ENCODED_STATES = "s2:010,s1:001,s0:000,s4:100,s3:011" *) 
  FDCE #(
    .INIT(1'b0)) 
    \FSM_sequential_estado_actual_reg[2] 
       (.C(CLK),
        .CE(1'b1),
        .CLR(\FSM_sequential_estado_actual_reg[0]_1 ),
        .D(estado_siguiente[2]),
        .Q(Q[2]));
  (* SOFT_HLUTNM = "soft_lutpair10" *) 
  LUT4 #(
    .INIT(16'hA28A)) 
    \a[0]_i_1 
       (.I0(a_in_IBUF[0]),
        .I1(Q[1]),
        .I2(Q[2]),
        .I3(Q[0]),
        .O(\a_reg[6] [0]));
  LUT5 #(
    .INIT(32'hAEBAA28A)) 
    \a[1]_i_1 
       (.I0(a_in_IBUF[1]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(Q[1]),
        .I4(\acc_reg[7] [0]),
        .O(\a_reg[6] [1]));
  LUT5 #(
    .INIT(32'hAEBAA28A)) 
    \a[2]_i_1 
       (.I0(a_in_IBUF[2]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(Q[1]),
        .I4(\acc_reg[7] [1]),
        .O(\a_reg[6] [2]));
  LUT5 #(
    .INIT(32'hAEBAA28A)) 
    \a[3]_i_1 
       (.I0(a_in_IBUF[3]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(Q[1]),
        .I4(\acc_reg[7] [2]),
        .O(\a_reg[6] [3]));
  (* SOFT_HLUTNM = "soft_lutpair11" *) 
  LUT4 #(
    .INIT(16'h0820)) 
    \a[4]_i_1 
       (.I0(\acc_reg[7] [3]),
        .I1(Q[1]),
        .I2(Q[2]),
        .I3(Q[0]),
        .O(\a_reg[6] [4]));
  (* SOFT_HLUTNM = "soft_lutpair12" *) 
  LUT4 #(
    .INIT(16'h0820)) 
    \a[5]_i_1 
       (.I0(\acc_reg[7] [4]),
        .I1(Q[1]),
        .I2(Q[2]),
        .I3(Q[0]),
        .O(\a_reg[6] [5]));
  (* SOFT_HLUTNM = "soft_lutpair12" *) 
  LUT4 #(
    .INIT(16'h0820)) 
    \a[6]_i_1 
       (.I0(\acc_reg[7] [5]),
        .I1(Q[1]),
        .I2(Q[2]),
        .I3(Q[0]),
        .O(\a_reg[6] [6]));
  LUT4 #(
    .INIT(16'h0820)) 
    \a[7]_i_1 
       (.I0(\acc_reg[7] [6]),
        .I1(Q[1]),
        .I2(Q[2]),
        .I3(Q[0]),
        .O(\a_reg[6] [7]));
  LUT2 #(
    .INIT(4'h2)) 
    \acc[7]_i_1 
       (.I0(Q[0]),
        .I1(Q[2]),
        .O(acc_ld));
  LUT5 #(
    .INIT(32'hAEBAA28A)) 
    \b[0]_i_1 
       (.I0(b_in_IBUF[0]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(Q[1]),
        .I4(\b_reg[2] [1]),
        .O(\FSM_sequential_estado_actual_reg[1]_2 [0]));
  LUT5 #(
    .INIT(32'hAEBAA28A)) 
    \b[1]_i_1 
       (.I0(b_in_IBUF[1]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(Q[1]),
        .I4(\b_reg[2] [2]),
        .O(\FSM_sequential_estado_actual_reg[1]_2 [1]));
  LUT5 #(
    .INIT(32'hAEBAA28A)) 
    \b[2]_i_1 
       (.I0(b_in_IBUF[2]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(Q[1]),
        .I4(\b_reg[2] [3]),
        .O(\FSM_sequential_estado_actual_reg[1]_2 [2]));
  (* SOFT_HLUTNM = "soft_lutpair11" *) 
  LUT4 #(
    .INIT(16'hA28A)) 
    \b[3]_i_1 
       (.I0(b_in_IBUF[3]),
        .I1(Q[1]),
        .I2(Q[2]),
        .I3(Q[0]),
        .O(\FSM_sequential_estado_actual_reg[1]_2 [3]));
  LUT3 #(
    .INIT(8'h01)) 
    \led_OBUF[7]_inst_i_1 
       (.I0(Q[1]),
        .I1(Q[2]),
        .I2(Q[0]),
        .O(led_OBUF));
  (* SOFT_HLUTNM = "soft_lutpair8" *) 
  LUT4 #(
    .INIT(16'h0410)) 
    \n[0]_i_1 
       (.I0(\n_reg[1] [0]),
        .I1(Q[1]),
        .I2(Q[2]),
        .I3(Q[0]),
        .O(D[0]));
  (* SOFT_HLUTNM = "soft_lutpair8" *) 
  LUT5 #(
    .INIT(32'h00900900)) 
    \n[1]_i_1 
       (.I0(\n_reg[1] [1]),
        .I1(\n_reg[1] [0]),
        .I2(Q[1]),
        .I3(Q[2]),
        .I4(Q[0]),
        .O(D[1]));
  LUT3 #(
    .INIT(8'h26)) 
    \n[3]_i_1 
       (.I0(Q[0]),
        .I1(Q[2]),
        .I2(Q[1]),
        .O(E));
  LUT3 #(
    .INIT(8'hDB)) 
    \n[3]_i_3 
       (.I0(Q[0]),
        .I1(Q[2]),
        .I2(Q[1]),
        .O(\FSM_sequential_estado_actual_reg[0]_0 ));
  LUT4 #(
    .INIT(16'h0800)) 
    salida_carry__0_i_1
       (.I0(Q[1]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(acc_reg[6]),
        .O(\FSM_sequential_estado_actual_reg[1]_0 [2]));
  LUT4 #(
    .INIT(16'h0080)) 
    salida_carry__0_i_2
       (.I0(acc_reg[5]),
        .I1(Q[1]),
        .I2(Q[0]),
        .I3(Q[2]),
        .O(\FSM_sequential_estado_actual_reg[1]_0 [1]));
  LUT4 #(
    .INIT(16'h0800)) 
    salida_carry__0_i_3
       (.I0(Q[1]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(acc_reg[4]),
        .O(\FSM_sequential_estado_actual_reg[1]_0 [0]));
  LUT5 #(
    .INIT(32'h00080800)) 
    salida_carry__0_i_4
       (.I0(Q[1]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(acc_reg[7]),
        .I4(\acc_reg[7] [7]),
        .O(\FSM_sequential_estado_actual_reg[1]_1 [3]));
  LUT5 #(
    .INIT(32'h10002000)) 
    salida_carry__0_i_5
       (.I0(acc_reg[6]),
        .I1(Q[2]),
        .I2(Q[0]),
        .I3(Q[1]),
        .I4(\acc_reg[7] [6]),
        .O(\FSM_sequential_estado_actual_reg[1]_1 [2]));
  LUT5 #(
    .INIT(32'h10002000)) 
    salida_carry__0_i_6
       (.I0(acc_reg[5]),
        .I1(Q[2]),
        .I2(Q[0]),
        .I3(Q[1]),
        .I4(\acc_reg[7] [5]),
        .O(\FSM_sequential_estado_actual_reg[1]_1 [1]));
  LUT5 #(
    .INIT(32'h10002000)) 
    salida_carry__0_i_7
       (.I0(acc_reg[4]),
        .I1(Q[2]),
        .I2(Q[0]),
        .I3(Q[1]),
        .I4(\acc_reg[7] [4]),
        .O(\FSM_sequential_estado_actual_reg[1]_1 [0]));
  LUT4 #(
    .INIT(16'h0800)) 
    salida_carry_i_1
       (.I0(Q[1]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(acc_reg[3]),
        .O(DI[3]));
  LUT4 #(
    .INIT(16'h0800)) 
    salida_carry_i_2
       (.I0(Q[1]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(acc_reg[2]),
        .O(DI[2]));
  LUT4 #(
    .INIT(16'h0800)) 
    salida_carry_i_3
       (.I0(Q[1]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(acc_reg[1]),
        .O(DI[1]));
  LUT4 #(
    .INIT(16'h0800)) 
    salida_carry_i_4
       (.I0(Q[1]),
        .I1(Q[0]),
        .I2(Q[2]),
        .I3(acc_reg[0]),
        .O(DI[0]));
  LUT5 #(
    .INIT(32'h10002000)) 
    salida_carry_i_5
       (.I0(acc_reg[3]),
        .I1(Q[2]),
        .I2(Q[0]),
        .I3(Q[1]),
        .I4(\acc_reg[7] [3]),
        .O(S[3]));
  LUT5 #(
    .INIT(32'h10002000)) 
    salida_carry_i_6
       (.I0(acc_reg[2]),
        .I1(Q[2]),
        .I2(Q[0]),
        .I3(Q[1]),
        .I4(\acc_reg[7] [2]),
        .O(S[2]));
  LUT5 #(
    .INIT(32'h10002000)) 
    salida_carry_i_7
       (.I0(acc_reg[1]),
        .I1(Q[2]),
        .I2(Q[0]),
        .I3(Q[1]),
        .I4(\acc_reg[7] [1]),
        .O(S[1]));
  LUT5 #(
    .INIT(32'h10002000)) 
    salida_carry_i_8
       (.I0(acc_reg[0]),
        .I1(Q[2]),
        .I2(Q[0]),
        .I3(Q[1]),
        .I4(\acc_reg[7] [0]),
        .O(S[0]));
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
