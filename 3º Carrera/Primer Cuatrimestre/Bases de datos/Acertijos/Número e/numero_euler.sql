/abolish

--JUAN CARLOS LLAMAS NÚÑEZ 

CREATE VIEW recursion (exp,n,factorial) AS
SELECT 1.0, 0, 1
UNION
SELECT exp+1/(factorial*(n+1)), n+1, factorial*(n+1) FROM recursion WHERE exp + 1/( factorial*(n+1)) > exp;

--La recursión es sencilla: guardamos la suma paracial S(n) hasta n, el valor n y n! y en cada paso de la recursión actualizamos estos valores a S(n) + 1/(n+1)!, n+1 y (n+1)*n!

--La condición de parada es que exp + 1/( factorial*(n+1)) > exp lo que será cierto mientras el sistema tenga precisión suficiente

--Llamo a la vista "numero_e" y no "e" porque aparentemente el sistema tiene e como un valor constante 2.71828... y da problemas 

CREATE VIEW numero_e(n) AS SELECT TOP 1 exp FROM recursion ORDER BY exp DESC;

SELECT * FROM numero_e ;







