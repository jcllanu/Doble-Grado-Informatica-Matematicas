/*-----------------------------------------------------------------
**
**  Fichero:
**    pract2a.asm  10/6/2014
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Automatica
**    Facultad de Informatica. Universidad Complutense de Madrid
**
**  Propósito:
**    Busca el valor maximo de un vector de enteros positivos
**
**  Notas de disenno:
**
**---------------------------------------------------------------*/
.global start

.EQU 	N, 8

.data
A: 		.word 7,3,25,4,75,2,1,1

.bss
max: 	.space 4

.text
start:
		mov r0, #0
		ldr r1,=max		@ Leo la dir. de max
		str r0,[r1]		@ Escribo 0 en max
		ldr r2, =A
		mov r4, #0
loop:	cmp r4, #N
		bge fin
		ldr r3, [r2, r4, lsl#2]
		cmp r3, r0
		ble cont
		mov r0, r3
		str r0, [r1]
cont:	add r4, r4, #1
		b loop
fin:	B .
		.end
@ Terminar de codificar

