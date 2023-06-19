/*-----------------------------------------------------------------
**
**  Fichero:
**    pract3a.asm  10/6/2014
**
**    Fundamentos de Computadores
**    Dpto. de Arquitectura de Computadores y Autom�tica
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Ordena de mayor a menor un vector de enteros positivos
**
**  Notas de dise�o:
**    Utiliza una subrutina que devuelve la posici�n del valor
**    m�ximo de un vector de enteros positivos
**
**---------------------------------------------------------------*/
/*
r4 =A
r5 =B
r6 j
r7 A[ind]


max:
r0 indice
r1 i
r2 N
r3 max
r4 =A
r5
r6 A[i]
r7
r8
r9
r10
PAsa el parametro =A en el r0, =ind en r1 y N en r2
*/

.EQU N1, 5
.EQU N2, 8
.EQU N3, 15
.global start
.data
A1:			.word 7,3,25,4,75
A2:			.word 7,3,25,4,75,2,1,1
A3:			.word 8,54,20,18,36,48,51,0,1,6,4,17,36,1,2

.bss
B: 			.space N3*4

.text
start:		ldr r0, =A1@parametro =A1 en r0
			mov r1, #N1 @parametro N1 en r1

			bl ordenar_vector

			ldr r0, =A2 @parametro =A2 en r0
			mov r1, #N2 @parametro N2 en r1

			bl ordenar_vector

			ldr r0, =A3 @parametro =A3 en r0
			mov r1, #N3 @parametro N3 en r1

			bl ordenar_vector

			b .

/*subrutina ordenar*/
ordenar_vector:
			push {r4 - r7, lr} @RELLENAR
			mov r4, r0 @=A
			ldr r5, =B @=B
			mov r7, r1 @constante N
			mov r6, #0 @j = 0

loop_j:		cmp r6, r7
			bge end_loop_j

			mov r0, r4 @=A pasado en el registro 0
			mov r1, r7 @pasado N en registro 1
			bl ind_max @llamada a la funcion

			ldr r2, [r4, r0, lsl#2] @load A[ind]
			str r2, [r5, r6, lsl#2] @str B[j]
			mov r2, #0
			str r2, [r4, r0, lsl#2] @A[ind] = 0

			add r6, r6, #1 @j++
			b loop_j

end_loop_j:	mov r1, r4 @parametro en r0 =A
			mov r0, r5 @parametro en r1 =B
			mov r2, r7 @parametro en r2 #N

			bl copiar @llamada a copiar

			pop {r4 - r7, lr} @RELLENAR
			mov pc, lr





/*primera subrutina*/
ind_max:	push {r4 - r5, lr}
			mov r4, r0 @movemos el parametro =A a r4
			mov r3, #0 @max = 0
			mov r0, #0 @indice = 0

			mov r2, #0 @i = 0
loop_max:	cmp r2, r1 @i >= N
			bge end_loop_max

			ldr r5, [r4, r2, lsl#2] @A[i]
			cmp r5, r3 @A[i] <= max
			ble else_max

			mov r3, r5 @max = A[i]
			mov r0, r2 @ind  i

else_max:	add r2, r2, #1 @i++
			b loop_max

end_loop_max:
			pop {r4 - r5, lr}
			mov pc, lr

/*subrutina copiar*/
copiar: 	push {r4 -r7, lr}
			mov r4, r0 @=B
			mov r5, r1 @=A
			mov r6, r2 @#N
			mov r7, #0 @i = 0

loop_i:		cmp r7, r6
			bge fin_loop_i

			ldr r0, [r4, r7, lsl#2] @B[i]
			str r0, [r5, r7, lsl#2] @str A[i]

			add r7, r7, #1 @i++

			b loop_i

fin_loop_i:	pop {r4 - r7, lr}
			mov pc, lr


.end









/*
.global start

.EQU 	N, 8

.data
A: 		.word 7,3,25,4,75,2,1,1

.bss
B: 		.space N*4
MAX: 	.space 4
.text

start:	MOV R4, #0		@j=0
loopj:	CMP R4, #N		@comparamos j con N
		BGE finprg		@si es mayor o igual terminamos
		MOV R1, #N		@movemos a N la loongitud de A(segundo parametro)
		LDR R0,=A		@cargamos en R0 el registro base de A (primer par�metro)
		BL maximo		@devuelve en R0 el indice donde est� el valor m�ximo
		MOV R3, R0		@movemos el valor de ind a R3
 		LDR R1,=A		@cargamos en R1 el registro base de A
 		LDR R0,[R1, R3, lsl#2]		@cargamos en R0 el valor de A[ind] (ind estaba en R3 y A[] en R1
		LDR R1, =B		@cargamos el registro base de B
		STR R0, [R1, R4, lsl#2]		@guardamos A[ind] (est� en R0) en B[j] (registro base en R1 y j en R4
		MOV R2, #0
		LDR R1,=A		@cargamos en R1 el registro base de A
		STR R2, [R1, R3, lsl#2]  @guardamos un 0 (est� en R2) en A[ind] (A est� en R1 e ind en R3)
		ADD R4, R4, #1
		B loopj
finprg:	B .


maximo:	PUSH {R4,R5,LR}				@prologo
		LDR R2, =MAX
		MOV R3, #0
		STR R3, [R2]	@guardamos 0 en max
		MOV R2, #0		@i=0
		MOv R5, #0		@ind=0
loopi:	CMP R2, R1		@comparamos R2(i) con R1(donde se ha pasado la longitud de A)
		BGE fin		@si i es mayor, saltamos al ep�logo
		LDR R3, [R0, R2, lsl#2]	@cargamos en R3 A[i] (EL registro base de A se ha pasado en R0 y en R2 est� i)
		LDR R4, =MAX	@cargamos en R4 el valor de max
		LDR R4, [R4]
		CMP R3, R4
		BLE finif
		LDR R4, =MAX
		STR R3, [R4]	@guardar en max A[i]
		MOV R5, R2		@ind=i
finif:	ADD R2, R2, #1
		B loopi
fin:    MOV R0, R5		@pasamos el valor de ind de R5 a R0 para devolverlo
		POP {R4,R5,LR}	@epilogo
		MOV PC,LR

.end
*/

