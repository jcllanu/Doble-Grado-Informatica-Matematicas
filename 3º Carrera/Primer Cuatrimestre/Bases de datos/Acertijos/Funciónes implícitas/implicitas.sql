/abolish
/duplicates on

--JUAN CARLOS LLAMAS N��EZ

-- NIVEL DE DIFICULTAD (0-10): 5

--Para representar funciones impl�citas en un intervalo [-x0,x0] nos vamos a limitar a la representaci�n de c�adricas afines con centro del plano af�n, es decir, la elipse, la hip�rbola, la recta doble, las rectas que se cortan...

--Las ecuaciones impl�citas que las definen ser�n de la forma b+ax^2-y^2=0 con a y b en {-1,0,1}

--x0 es el extremo superior del intervalo sobre el que vamos a representar la cu�drica lo fijamos a 1.1
/set x0 1.1

--Para representar la funci�n elegimos puntos en el intervalo [-x0,x0] comenzando en 0 y que distan dx entre s�.
/set dx 0.04




--CLASIFICACI�N DE CU�DRICAS AFINES DEL PLANO AF�N (C�NICAS) CON CENTROS
--            Ecuaci�n        a               b           Nombre c�nica

--			  -y^2 = 0        0               0            Recta doble
--		    -1 - y^2 = 0      0              -1     C�nica vac�a degenerada
--		     1 - y^2 = 0      0               1         Rectas paralelas
--		  - x^2 - y^2 = 0    -1               0            Punto doble
--			x^2 - y^2 = 0     1               0       Rectas que se cortan
--		-1 - x^2 - y^2 = 0   -1              -1    C�nica vac�a no degenerada
--		 1 + x^2 - y^2 = 0    1               1             Hip�rbola
--		 1 - x^2 - y^2 = 0   -1               1      Elipse (Cirucnferencia)       

-- Nota: Esta clasificaci�n es la que estamos dando justo ahora en la asignatura de matem�ticas "Geometr�a Lineal"

/set a -1
/set b 1

--Por la simetr�a de estos objetos respecto a los ejes podemos despejar y de la ecuaci�n y quedarnos con la soluci�n positiva(si la hay) de la ecuaci�n para cada x fijo. Podemos definir entonces una funci�n f(x)=y^2 para cada y positivo calculado como anteriormente. hay algunos valores de x para los que esa funci�n 

--Despejamos de la ecuaci�n y^2 y definimos para cada x la funci�n f(x)=b+a*x^2~y^2

/set y_cuadrado ($b$+($a$)*x*x)

--Calculamos los abscisas de las que vamos a calcular su im�gen por f. Comenzamos por el 0 y nos vamos moviendo dx hacia la derecha hasta llegar a x0
CREATE VIEW abscisas_pos(x) AS 
SELECT 0.0
UNION
SELECT x+$dx$ FROM abscisas_pos WHERE x<$x0$;

--Calculamos los valor opuestos de las abscisas positivas y los juntamos todos
CREATE VIEW abscisas(x) AS SELECT -x FROM abscisas_pos UNION SELECT * FROM abscisas_pos;

--Asosciamos a cada x la raiz positiva de f(x) si f(x) es mayor o igual que cero. En caso contrario le asignamos un -1 que ser� un valor especial que despu�s usaremos para ver que la funci�n no est� definida en ese punto.
CREATE VIEW funcion(x,y) AS SELECT x, IIF($y_cuadrado$ >= 0.0, SQRT($y_cuadrado$),-1) FROM abscisas;

--Calculamos el m�ximo de los valores
CREATE VIEW maximo(y0) AS SELECT max(y) FROM funcion;

--La escala que vamos a seguir es que al punto m�ximo le van a corresponder dy espacios sobre el eje x y al resto siguiendo la proporci�n dy*y/y0
/set dy 50

--Asociamos a cada x el n�mero de espacios que le corresponden seg�n esta proporci�n. Si el valor de la im�gen es -1 ponemos definida a 0 para indicar que la funci�n no est� definida en ese punto y si no lo ponemos a 1.
CREATE VIEW funcion_bis(x,num_espacios, definida) AS SELECT x, IIF(y0>0,FLOOR((y/y0)*$dy$),0), IIF(y=-1, 0, 1) FROM funcion, maximo;

--Para cada punto le asignamosla cadena de carcteres correspondiente con unos sencillos c�lculos
CREATE VIEW sol(x,esp) AS SELECT x, '   ' + IIF(definida=0, SPACE($dy$+1), SPACE($dy$-num_espacios)+ '*' +SPACE(num_espacios) ) + '*' +IIF(definida=0, SPACE($dy$+1), SPACE(num_espacios)+ '*' +SPACE($dy$-num_espacios) )  + '   ' FROM funcion_bis;

SELECT esp FROM sol ORDER BY x;
