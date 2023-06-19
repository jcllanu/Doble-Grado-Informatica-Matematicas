/*-----------------------------------------------------------------
**
**  Fichero:
**    pract1b.asm  10/6/2014
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Divide 2 números mediante el algoritmo de restas parciales
**
**  Notas de diseño:
**
**---------------------------------------------------------------*/

.global start

.data
@ Terminar de codificar
A:	.word 100
B: 	.word 7
.bss
@ Terminar de codificar
C:	.space 4
R:	.space 4
.text
start:
		LDR R3, =A
		LDR R4, =B
		LDR R5, =C
		LDR R6, =R
		LDR R0, [R3]
		LDR R1, [R4]
		CMP R1,#0
		BEQ error
		MOV R2, #0
bucle:	CMP R0, R1
		BLT resto
		ADD R2, R2, #1
		SUB R0, R0, R1
		B bucle
resto:	STR R0,[R6]
		B fin
error:	MOV R2,#-1
fin:	STR R2, [R5]
		B .
		@ Terminar de codificar
		.end
