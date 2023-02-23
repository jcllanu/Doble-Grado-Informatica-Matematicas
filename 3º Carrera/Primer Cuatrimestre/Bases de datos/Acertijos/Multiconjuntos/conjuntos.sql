/abolish
/duplicates on

CREATE TABLE t(x) AS
  SELECT 1 UNION ALL 
  SELECT 1 UNION ALL 
  SELECT 1 UNION ALL 
  SELECT 2 UNION ALL 
  SELECT 3 UNION ALL 
  SELECT 3;

CREATE TABLE s(x) AS
  SELECT 1 UNION ALL 
  SELECT 1 UNION ALL 
  SELECT 2 UNION ALL 
  SELECT 4;



--JUAN CARLOS LLAMAS NÚÑEZ 

--Usamos las siguientes vistas auxiliares que nos ofrecen para cada elemento de cada uno de los conjuntos las veces que aparece en él conjunto

CREATE VIEW t_sin_duplicados AS SELECT x AS elem_t, COUNT(x) AS multiplicidad_t FROM t GROUP BY x;
CREATE VIEW s_sin_duplicados AS SELECT x AS elem_s, COUNT(x) AS multiplicidad_s FROM s GROUP BY x;


--INTERSECCIÓN

--Obtenemos los elementos que hay en la intersección y su multiplicidad con la siguiente consulta. Para que un elemento esté en la intersección tiene que estar en (t_sin_duplicados JOIN s_sin_duplicados ON elem_t = elem_s). Su multiplicidad dentro de la intersección será, según la definición, el mínimo de las multiplicidades.

CREATE VIEW interseccion_sin_duplicados AS SELECT elem_t AS elem_i, MIN(multiplicidad_t,multiplicidad_s) AS multiplicidad_i FROM  t_sin_duplicados JOIN s_sin_duplicados ON elem_t = elem_s;

--Una vez tenemos los elementos de la intersección con su multiplicidad, queremos volver a la expresión de multiconjuntos (con duplicados) para la que planteamos la siguiente recursión.
--Si un elemento k aparece en interseccion_sin_duplicados con una multiplicidad n entonces en interseccionREC aparecerán las tuplas:
--(k, n), (k, n-1), (k, n-2), ... ,(k,2), (k,1)
--Debemos exigir que n>=1, lo que aquí se cumple trivialmente porque el mínimo de las multiplicidades de los elementos de la interseccion es al menos 1 (el elemento está tanto en a t como a en s), pero que veremos que hay que comprobar para el caso de la diferencia

CREATE VIEW interseccionREC(x, multiplicidad) AS 
SELECT * FROM interseccion_sin_duplicados
UNION ALL 
SELECT x, multiplicidad - 1 FROM interseccionREC WHERE multiplicidad > 1;

--Por último las n tuplas (k, n-i) con i=0...n-1 se transforman en n tuplas (k) si nos quedamos solo con x
CREATE VIEW intersect AS SELECT x FROM interseccionREC;

-----------------------------------------------------------------------------
--DIFERENCIA

--La idea general es hacer lo mismo que en el caso anterior:
--Paso 1.- Vamos a construirnos una vista con los elementos de t asociados a su multiplicidad en el conjunto t y su multiplicidad en el conjunto s. Esta última será 0 para los elementos que no estén en s.
--Paso 2.- Calculamos el conjuto T\S con las multiplicidades de cada elemento
--Paso 3.- Traducimos la información de multiplicidades a multiconjunto mediante la función recursiva


--Paso 1

--Calculamos primero los elementos de T intersección S como conjuntos
CREATE VIEW elementos_de_S_en_T AS SELECT elem_t AS elem FROM t_sin_duplicados JOIN s_sin_duplicados ON elem_t=elem_s;
--Les asociamos sus correspondientes multiplicidades en cada conjunto
CREATE VIEW elementos_de_S_en_T_multiplicidades AS SELECT elem, multiplicidad_t, multiplicidad_s FROM (elementos_de_S_en_T JOIN t_sin_duplicados ON elem=elem_t) JOIN s_sin_duplicados ON elem_s=elem;


--Calculamos ahora los elementos de T\S como conjuntos que serán los que al hacer la union externa por la izquierda tienen valores NULL
CREATE VIEW elementos_de_T_menos_S AS SELECT elem_t AS elem FROM t_sin_duplicados LEFT JOIN s_sin_duplicados ON elem_t=elem_s WHERE elem_s IS NULL;
--Les asociamos las correspondientes multiplicidades (la multiplicidad asociada al conjunto S es 0 porque no pertenecen a S)
CREATE VIEW elementos_de_T_menos_S_multiplicidades AS SELECT elem, multiplicidad_t,multiplicidad_s FROM (elementos_de_T_menos_S JOIN t_sin_duplicados ON elem=elem_t),SELECT 0 AS multiplicidad_s;

--Juntamos la informacion anterior y ponemos para cada elemento de t su multiplicidad en t y su multiplicidad en s
CREATE VIEW t_multiplicidades AS SELECT * FROM elementos_de_S_en_T_multiplicidades UNION SELECT * FROM elementos_de_T_menos_S_multiplicidades;


--Paso 2

--Calculamos las multiplicidades de los elementos de la diferencia que, según la definición, son el máximo entre la multiplicidad del elemento en el conjunto t menos la multiplicidad del elemento en el conjunto s y 0. 
CREATE VIEW diferencia_sin_duplicados AS SELECT elem, MAX(multiplicidad_t-multiplicidad_s,0) AS multiplicidad_d FROM t_multiplicidades;

--Eliminamos los elementos que tengan multiplicidad 0 por el comentario hecho anteriormente de que n>=1 en la recursión
CREATE VIEW diferencia_sin_duplicadosBIS AS SELECT * FROM diferencia_sin_duplicados WHERE multiplicidad_d>0;


--Paso 3

--Realizamos la misma recursión para obretener la misma expresión en forma de multiconjunto
CREATE VIEW diferenciaREC(x,multiplicidad) AS 
SELECT * FROM diferencia_sin_duplicadosBIS
UNION ALL 
SELECT x, multiplicidad-1 FROM diferenciaREC WHERE multiplicidad>1;


CREATE VIEW except AS SELECT x FROM diferenciaREC;


-----------------------------------------------------------------

SELECT * FROM intersect;
SELECT * FROM except;
















