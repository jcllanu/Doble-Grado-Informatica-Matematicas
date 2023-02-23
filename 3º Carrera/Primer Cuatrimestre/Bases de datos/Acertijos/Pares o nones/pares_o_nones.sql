/abolish
/duplicates off
/multiline on
/type_casting on
-- Base relation
/SET bound 10

CREATE TABLE r(x INT);
INSERT INTO r WITH n(x) AS SELECT 1 UNION SELECT x+1 FROM n WHERE x<$bound$ SELECT * FROM n;

--JUAN CARLLOS LLAMAS NÚÑEZ

--Crwamos una vista donde las filas estan compuestas por dos elementos consecutivos de la tabla original donde menor<mayor;
--Para el elemento máximo M le asignamos la tupla (M, null) porque no tiene ningún elemento mayor. Por tanto la vista tiene el mismo numero de tuplas que la vista original y una columna adicional donde está el elemento siguiente.

CREATE VIEW consecutivos(menor,mayor) AS (SELECT A.x, B.x FROM r AS A JOIN r AS B ON A.x<B.x WHERE B.x <= ALL(SELECT x FROM r WHERE x>A.x)) UNION (SELECT x,NULL FROM r WHERE x>=ALL(SELECT x FROM r));
-- Esta vista quedará si identificamos cada elemnto como su posición al ordenarlos de menor a mayor como:

--(N,NULL)
--(N-1,N)
--(N-2,N-1)
-- *
-- *
-- *
--(3,4)
--(2,3)
--(1,2)

--Nuestro objetivo va a ser subir (de uno en uno) el elemento más pequeño hasta el elemento más grande, es decir, crear las tuplas: (1,2) (1,3) (1,4) (1,5) ... (1, N-1) (1, N)
--Si hacemos esto manera recursiva necesitaremos N-1 pasos (contando como paso 1 el caso base (1,2)) para llegar a nuestro objetivo. Si junto a las tuplas añadimos el paso en el que vamos, cuando lleguemos al final tendremos la tupla (1,N) con paso N-1. Por tanto el número de filas será El paso máximo de todos los que haya más uno.

CREATE VIEW recursion(menor,mayor,paso) AS 
SELECT menor,mayor,1 FROM consecutivos
UNION
SELECT recursion.menor, consecutivos.mayor, recursion.paso+1
FROM recursion JOIN consecutivos ON recursion.mayor=consecutivos.menor WHERE recursion.menor = 1 and consecutivos.mayor IS NOT NULL;

--Extraemos el paso máximo

CREATE VIEW numFilas_menos1 AS SELECT paso FROM ((SELECT paso FROM recursion) EXCEPT (SELECT A.paso FROM recursion AS A JOIN recursion AS B ON A.paso<B.paso));

--Le sumamos uno ...
CREATE VIEW numFilas(n) AS SELECT 1+SELECT paso FROM numFilas_menos1;

--Y ya tenemos el número de filas
--Por último hacemos la distinción de casos para la salida
CREATE VIEW even_or_odd(s) AS SELECT
	CASE
		WHEN n MOD 2 = 0 THEN 'r is even'
		ELSE 'r is odd'
	END
FROM numFilas;

SELECT * FROM even_or_odd;
