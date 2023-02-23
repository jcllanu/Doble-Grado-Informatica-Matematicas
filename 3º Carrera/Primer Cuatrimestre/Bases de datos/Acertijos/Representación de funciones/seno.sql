/abolish
/duplicates on

--JUAN CARLOS LLAMAS NÚÑEZ
-- NIVEL DE DIFICULTAD (0-10): 4

--Para representar funciones continuas en un intervalo [a,b] se definen los siguiente parámetros:

--f es la función y tiene de argumento x
/set f sin(x)

--x0 es el extremo inferior del intervalo (a)
/set x0 0.0

--x1 es el extremo superior del intervalo (b)
/set x1 12.57

--Para representar la función elegimos puntos en el intervalo [a,b] comenzando en a y que distan dx entre sí.
/set dx 0.2

--Para cada uno de los puntos que hemos elegido calculamos su imágen por f. Si el mínimo de las imágenes es y0 entonces si f(x)=y escribirán n espacios si y0+n*dy=y
/set dy 0.05

--ADVERTENCIA
--Según para que funciones, si dx o dy son muy peqeños o x1-x0 es muy grande el programa puede tardar un rato en ejecutarse o incluso quedarse colgado.
--Algunos valores probados (  f   ,   x0,    x1    , dx  ,   dy):
--                         (sin(x),   0.0 , 12.57  , 0.2  , 0.05)
--                         (cos(x),   0.0 , 12.57  , 0.2  , 0.05)
--                         (   x*x,  -4.0 ,   4.0  , 0.2  , 0.2 )
--                         ( x*x*x,  -3.0 ,   3.0  , 0.4  , 0.5 )
--                         (     x,  -3.0 ,   3.0  , 0.4  , 0.5 )
--                         (   x/2,  -3.0 ,   3.0  , 0.4  , 0.5 )




--Calculamos los abscisas de las que vamos a calcular su imágen
CREATE VIEW abscisas(x) AS 
SELECT $x0$
UNION
SELECT x+$dx$ FROM abscisas WHERE x<$x1$;

--Asosciamos a cada x su imagen f(x)=y
CREATE VIEW funcion(x,y) AS SELECT x, $f$ FROM abscisas;

--Calculamos el mínimo de las imágenes
CREATE VIEW minimo(y0) AS SELECT min(y) FROM funcion;

--Asociamos a cada x el númeroi de escaios que le correesponden según lo explicado más arriba 
CREATE VIEW funcion_bis(x,y,num_espacios) AS SELECT x, y, FLOOR((y-y0)/$dy$) FROM funcion,minimo;

--Planteamos la recursión en la que para cada x obtenemos una cadena de caracteres formada solo por n espacios, siendo n el número de espacios que habíamos asociado a x
CREATE VIEW recursion(x,y,num_espacios,espacios) AS
SELECT x,y,num_espacios,'' FROM funcion_bis
UNION
SELECT x,y,num_espacios,' '+espacios FROM recursion WHERE LENGTH(espacios)<num_espacios;

--Mostramos por pantalla las cadenas de espacios en orden de abscisas 
SELECT espacios FROM recursion WHERE LENGTH(espacios)= num_espacios ORDER BY x;

--... y ya solo queda girar la cabeza para ver la función.

