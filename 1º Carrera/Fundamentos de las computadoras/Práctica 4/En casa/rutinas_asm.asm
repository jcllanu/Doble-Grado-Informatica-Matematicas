/*-----------------------------------------------------------------
**
**  Fichero:
**    rutinas_asm.asm  10/6/2014
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**
**
**  Notas de diseño:
**
**---------------------------------------------------------------*/

.global contarUnos


.text

contarUnos:
  		push {r4-r9, lr} @prólogo

		mov r4, r0 @Movemos a registros seguros los parametros de entrada
		mov r5, r1
		mov r6, r2
		mov r7, r3
		mov r0, #0 @i=0
loop_i:
		cmp r0,r6	@i>=NFilas?
		bge final_i
		mov r2,#0	@guardamos 0 en VECTOR[i]
		str r2, [r5, r0, lsl#2]
		mov r1, #0	@j=0
loop_j:
		cmp r1, r7	@j>=NColumnas?
		bge final_j
		mul r3, r0, r7 @desplazaamiento = i*Ncolumnas+j
		add r3, r3, r1
		ldr r2,[r4, r3, lsl#2]
		cmp r2, #1	@MAT[i][j]!=1?
		bne final_if
		ldr r2, [r5, r0, lsl#2] @VECTOR[i]++
		add r2, r2, #1
		str r2, [r5, r0, lsl#2]
final_if:
		add r1, r1, #1 @j++
		b loop_j
final_j:
		add r0, r0, #1 @i++
		b loop_i
final_i:

		pop {r4-r9, lr}	@epílogo
  		mov pc, lr

