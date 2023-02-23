/abolish
/duplicates on

--JUAN CARLOS LLAMAS N��EZ
-- NIVEL DE DIFICULTAD (0-10): 4

--Para representar funciones continuas en un intervalo [a,b] se definen los siguiente par�metros:

--f es la funci�n y tiene de argumento x
/set f sin(x)

--x0 es el extremo inferior del intervalo (a)
/set x0 0.0

--x1 es el extremo superior del intervalo (b)
/set x1 12.57

--Para representar la funci�n elegimos puntos en el intervalo [a,b] comenzando en a y que distan dx entre s�.
/set dx 0.2

--Para cada uno de los puntos que hemos elegido calculamos su im�gen por f. Si el m�nimo de las im�genes es y0 entonces si f(x)=y escribir�n n espacios si y0+n*dy=y
/set dy 0.05

--ADVERTENCIA
--Seg�n para que funciones, si dx o dy son muy peqe�os o x1-x0 es muy grande el programa puede tardar un rato en ejecutarse o incluso quedarse colgado.
--Algunos valores probados (  f   ,   x0,    x1    , dx  ,   dy):
--                         (sin(x),   0.0 , 12.57  , 0.2  , 0.05)
--                         (cos(x),   0.0 , 12.57  , 0.2  , 0.05)
--                         (   x*x,  -4.0 ,   4.0  , 0.2  , 0.2 )
--                         ( x*x*x,  -3.0 ,   3.0  , 0.4  , 0.5 )
--                         (     x,  -3.0 ,   3.0  , 0.4  , 0.5 )
--                         (   x/2,  -3.0 ,   3.0  , 0.4  , 0.5 )




--Calculamos los abscisas de las que vamos a calcular su im�gen
CREATE VIEW abscisas(x) AS 
SELECT $x0$
UNION
SELECT x+$dx$ FROM abscisas WHERE x<$x1$;

--Asosciamos a cada x su imagen f(x)=y
CREATE VIEW funcion(x,y) AS SELECT x, $f$ FROM abscisas;

--Calculamos el m�nimo de las im�genes
CREATE VIEW minimo(y0) AS SELECT min(y) FROM funcion;

--Asociamos a cada x el n�meroi de escaios que le correesponden seg�n lo explicado m�s arriba 
CREATE VIEW funcion_bis(x,y,num_espacios) AS SELECT x, y, FLOOR((y-y0)/$dy$) FROM funcion,minimo;

--Planteamos la recursi�n en la que para cada x obtenemos una cadena de caracteres formada solo por n espacios, siendo n el n�mero de espacios que hab�amos asociado a x
CREATE VIEW recursion(x,y,num_espacios,espacios) AS
SELECT x,y,num_espacios,'' FROM funcion_bis
UNION
SELECT x,y,num_espacios,' '+espacios FROM recursion WHERE LENGTH(espacios)<num_espacios;

--Mostramos por pantalla las cadenas de espacios en orden de abscisas 
SELECT espacios FROM recursion WHERE LENGTH(espacios)= num_espacios ORDER BY x;

--... y ya solo queda girar la cabeza para ver la funci�n.

