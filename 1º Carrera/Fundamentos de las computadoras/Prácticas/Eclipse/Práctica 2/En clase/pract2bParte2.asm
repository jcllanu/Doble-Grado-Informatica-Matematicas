/*-----------------------------------------------------------------
**
**  Fichero:
**    pract2b.asm  10/6/2014
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Autom�tica
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Ordena de mayor a menor un vector de enteros positivos
**
**  Notas de dise�o:
**
**---------------------------------------------------------------*/

.EQU 	N, 12

.global start

.data
A: 		.word 7,3,25,4,75,2,1,1,0,40,9,22
Jimpar:	.word 0
Jpar:	.word 0

.bss
Bpar: 	.space N*4
Bimpar:	.space N*4
MIN: 	.space 4
IND: 	.space 4

.text
start:	LDR R5, =MIN
		LDR R6, =IND
loopj:	LDR R2, =Jpar @BASE CONT PAR
		LDR R0, [R2] @JPAR
		LDR R2, =Jimpar
		LDR R1, [R2]
		ADD R9, R1, R0 @J TOTAL
		CMP R9, #N
		BGE final
		MOV R7, #1000
		STR R7, [R5]
		MOV R0, #0
loopi:	CMP R0, #N
		BGE strmin
		LDR R3, =A
		LDR R3, [R3, R0, lsl#2] @A[i]
		LDR R7, [R5]
		CMP R3, R7
		BGE finif
		STR R3, [R5]
		STR R0, [R6]
finif:	ADD R0, R0, #1
		B loopi

strmin: LDR R8, [R6]
		LDR R3, =A
		LDR R3, [R3, R8, lsl#2]
		AND R9, R3, #1 @MASCARA
		CMP R9, #0
		BEQ espar

		LDR R4, =Bimpar
		LDR R2, =Jimpar
		LDR R0, [R2]
		STR R3, [R4, R0, lsl#2]
		MOV R3, #1000
		LDR R4, =A
		STR R3, [R4, R8, lsl#2]
		ADD R0, R0, #1
		STR R0, [R2]
		B loopj

espar:	LDR R4, =Bpar
		LDR R2, =Jpar
		LDR R0, [R2]
		STR R3, [R4, R0, lsl#2]
		MOV R3, #1000
		LDR R4, =A
		STR R3, [R4, R8, lsl#2]
		ADD R0, R0, #1
		STR R0, [R2]
		B loopj

final:	B .

		@ Terminar de codificar
