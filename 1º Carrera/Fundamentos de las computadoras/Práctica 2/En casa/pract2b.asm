/*-----------------------------------------------------------------
**
**  Fichero:
**    pract2b.asm  10/6/2014
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Ordena de mayor a menor un vector de enteros positivos
**
**  Notas de diseño:
**
**---------------------------------------------------------------*/

.EQU 	N, 8

.global start

.data
A: 		.word 7,3,25,4,75,2,1,1

.bss
B: 		.space N*4
MAX: 	.space 4
IND: 	.space 4

.text
start:	MOV R1, #0
		LDR R3, =A
		LDR R4, =B
		LDR R5, =MAX
		LDR R6, =IND
loopj:	CMP R1, #N
		BGE final
		MOV R7, #0
		STR R7, [R5]
		MOV R0, #0
loopi:	CMP R0, #N
		BGE strmax
		LDR R2, [R3, R0, lsl#2]
		LDR R7, [R5]
		CMP R2, R7
		BLE finif
		STR R2, [R5]
		STR R0, [R6]
finif:	ADD R0, R0, #1
		B loopi
strmax: LDR R8, [R6]
		LDR R2, [R3, R8, lsl#2]
		STR R2, [R4, R1, lsl#2]
		MOV R2, #0
		STR R2, [R3, R8, lsl#2]
		ADD R1, R1, #1
		B loopj
final:	B .

		@ Terminar de codificar
