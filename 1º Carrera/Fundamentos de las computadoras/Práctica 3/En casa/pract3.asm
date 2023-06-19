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

