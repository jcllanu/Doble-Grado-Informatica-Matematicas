/abolish


--JUAN CARLOS LLAMAS NÚÑEZ

-- NIVEL DE DIFICULTAD (0-10): 5
--Conceptualmente, este acertijo me ha parecido de los más sencillos que hemos hecho porque es bastante natural lo que hay que ir haciendo para resolverlo. Si que es verdad que queda muy abultado en tamaño, sobre todo la segunda parte, pero, como digo, no es porque sea especialmente difícil sino más bien porque es extenso. En comparación con otros acertijos, en este me ha costado menos tiempo saber cual iba a ser la estrategia para llegar a la solución. Sin embargo, la resolución se alarga por deconocimiento en algunos casos de la sintaxis u otro tipo de errores propios de no estar acostumbrado a usar este lenguaje.


--Creamos una tabla con los números del 0 al 31 (expresados en binario en una cadena) a modo de ejemplo.

CREATE TABLE binary_numbers(number STRING);

INSERT INTO binary_numbers VALUES ('00000');
INSERT INTO binary_numbers VALUES ('00001');
INSERT INTO binary_numbers VALUES ('00010');
INSERT INTO binary_numbers VALUES ('00011');
INSERT INTO binary_numbers VALUES ('00100');
INSERT INTO binary_numbers VALUES ('00101');
INSERT INTO binary_numbers VALUES ('00110');
INSERT INTO binary_numbers VALUES ('00111');
INSERT INTO binary_numbers VALUES ('01000');
INSERT INTO binary_numbers VALUES ('01001');
INSERT INTO binary_numbers VALUES ('01010');
INSERT INTO binary_numbers VALUES ('01011');
INSERT INTO binary_numbers VALUES ('01100');
INSERT INTO binary_numbers VALUES ('01101');
INSERT INTO binary_numbers VALUES ('01110');
INSERT INTO binary_numbers VALUES ('01111');
INSERT INTO binary_numbers VALUES ('10000');
INSERT INTO binary_numbers VALUES ('10001');
INSERT INTO binary_numbers VALUES ('10010');
INSERT INTO binary_numbers VALUES ('10011');
INSERT INTO binary_numbers VALUES ('10100');
INSERT INTO binary_numbers VALUES ('10101');
INSERT INTO binary_numbers VALUES ('10110');
INSERT INTO binary_numbers VALUES ('10111');
INSERT INTO binary_numbers VALUES ('11000');
INSERT INTO binary_numbers VALUES ('11001');
INSERT INTO binary_numbers VALUES ('11010');
INSERT INTO binary_numbers VALUES ('11011');
INSERT INTO binary_numbers VALUES ('11100');
INSERT INTO binary_numbers VALUES ('11101');
INSERT INTO binary_numbers VALUES ('11110');
INSERT INTO binary_numbers VALUES ('11111');

--Le asignamos a cada cadena su longitud
CREATE VIEW bin_num_length(bin_num, longitud) AS SELECT number, length(number) FROM binary_numbers;

--Planteamos una recursión para calcular el valor decimal de una cadena en binario.
--Recordamos que para pasar de binario a decimal una cadena (x_k-1, x_k-2, ....,x_2 ,x_1, x_0) donde x_i es 0 o 1, su valor en decimal es:
--sum( from i=0 to k-1) (x_i *2^i) = x_0 +x_1*2 + x_2*4 + x_3*8 + ... + x_n-1 * 2^(k-1)
--Por tanto en la recursión vamos a llevar la cadena en binario, la longitud de la cadena, el valor del índice(paso) la potencia de 2 (2^paso) para no tener que usar la exponencial y calcularla recursivamente y el valor de la suma parcial hasta el índice paso.
--La condición de salida es que paso = longitud-1;

CREATE VIEW recursion(bin_num, longitud, paso, pot_2, dec_num) AS
SELECT bin_num, longitud, 0, 1, IIF(SUBSTR(bin_num,longitud,1)='1',1,0) FROM bin_num_length
UNION
SELECT bin_num, longitud, paso + 1, 2*pot_2, dec_num+2*pot_2*IIF(SUBSTR(bin_num,longitud-paso-1,1)='1',1,0) FROM recursion WHERE paso<longitud-1;

--Finalmente nos quedamos con la suma total que son aquellas tuplas que cumplen longitud-1 = paso

CREATE VIEW base_2_10(n2 , n10) AS SELECT bin_num, dec_num FROM recursion WHERE longitud-1=paso;

-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------

--Para la segunda parte creamos una tabla auxiliar caracteres que asocia a cada número n (0 <= n <= 20) el caracter que le corresponde, es decir, el dígito si 0 <= n <= 9 y la letra (n-9)-ésima del alfabeto si 10 <= n <= 20.
--Esto es extensible una vez fijada una biyección entre símbolos que ocupen un caracter y números para un tamaño arbitrariamente grande.

CREATE TABLE caracteres(caracter STRING, numero INT);

INSERT INTO caracteres VALUES ('0',0);
INSERT INTO caracteres VALUES ('1',1);
INSERT INTO caracteres VALUES ('2',2);
INSERT INTO caracteres VALUES ('3',3);
INSERT INTO caracteres VALUES ('4',4);
INSERT INTO caracteres VALUES ('5',5);
INSERT INTO caracteres VALUES ('6',6);
INSERT INTO caracteres VALUES ('7',7);
INSERT INTO caracteres VALUES ('8',9);
INSERT INTO caracteres VALUES ('A',10);
INSERT INTO caracteres VALUES ('B',11);
INSERT INTO caracteres VALUES ('C',12);
INSERT INTO caracteres VALUES ('D',13);
INSERT INTO caracteres VALUES ('E',14);
INSERT INTO caracteres VALUES ('F',15);
INSERT INTO caracteres VALUES ('G',16);
INSERT INTO caracteres VALUES ('H',17);
INSERT INTO caracteres VALUES ('I',18);
INSERT INTO caracteres VALUES ('J',19);
INSERT INTO caracteres VALUES ('K',20);

--Creamos una tabla con ejemplos de conversión de una cadena en base n a base m con 2 <= n, m <= 21

CREATE TABLE conversion(number STRING, from_base INT, to_base INT);

INSERT INTO conversion VALUES ('00000',2,3);
INSERT INTO conversion VALUES ('00001',2,3);
INSERT INTO conversion VALUES ('00010',2,3);
INSERT INTO conversion VALUES ('00011',2,3);
INSERT INTO conversion VALUES ('00100',2,3);
INSERT INTO conversion VALUES ('00101',2,3);
INSERT INTO conversion VALUES ('00110',2,3);
INSERT INTO conversion VALUES ('01111',2,3);

INSERT INTO conversion VALUES ('00000',2,4);
INSERT INTO conversion VALUES ('00001',2,4);
INSERT INTO conversion VALUES ('00010',2,4);
INSERT INTO conversion VALUES ('00011',2,4);
INSERT INTO conversion VALUES ('00100',2,4);
INSERT INTO conversion VALUES ('00101',2,4);
INSERT INTO conversion VALUES ('00110',2,4);
INSERT INTO conversion VALUES ('01111',2,4);

INSERT INTO conversion VALUES ('0000A',16,3);
INSERT INTO conversion VALUES ('000A1',16,10);
INSERT INTO conversion VALUES ('0001H',20,10);
INSERT INTO conversion VALUES ('0001H',20,3);
INSERT INTO conversion VALUES ('00200',3,20);

--El procedimineto para pasar de base n a m va a ser:
--1.- Pasar la cadena en base n a su valor decimal
--2.- Convertir el valor decimal en una cadena en base m que represente el mismo valor


--Por tanta primero pasamos una cadena en base n a decimal, que es una generalización de lo que habíamos hecho antes

--Además de la longitud guardamos la base
CREATE VIEW n_num_length(number_n, n, longitud) AS SELECT number, from_base, length(number) FROM conversion;

--Planteamos una recursión para calcular el valor decimal de una cadena en base n.
--Recordamos que para pasar de base n a decimal una cadena (x_k-1, x_k-2, ....,x_2 ,x_1, x_0) donde x_i pertenece a 0, 1, 2, ... n-1, su valor en decimal es:
--sum( from i=0 to k-1) (x_i *n^i) = x_0 + x_1*n + x_2*n^2 + x_3*n^2 + ... + x_k-1 * n^(k-1)
--Por tanto en la recursión vamos a llevar la cadena en base n, la longitud de la cadena, la base n,  el valor del índice(paso), la potencia de n (n^paso) para no tener que usar la exponencial y calcularla recursivamente y el valor de la suma parcial hasta el índice paso.
--La condición de salida es que paso = longitud-1;

CREATE VIEW recursion1(number_n, longitud, n, paso, pot_n, dec_num) AS
SELECT number_n, longitud, n, 0, 1, numero FROM n_num_length JOIN caracteres WHERE caracter=SUBSTR(number_n,longitud,1)
UNION
SELECT number_n, longitud, n, paso + 1, n*pot_n, dec_num+n*pot_n*numero FROM recursion1 JOIN caracteres WHERE caracter=SUBSTR(number_n,longitud-paso-1,1) and paso<longitud-1;

--Nos quedamos con las tuplas tales que longitud-1=paso que son las que tienen la suma completa

CREATE VIEW base_n_10(num_n, n , num_10) AS SELECT number_n, n, dec_num FROM recursion1 WHERE longitud-1=paso;

--Ya tenemos en base_n_10 para cada cadena en base n, el numero en base 10

--Ahora vemos para cada número decimal a que base m hay que convertirlo
CREATE VIEW base_10_m(num_10,m) AS SELECT num_10, to_base FROM base_n_10 JOIN conversion ON number=num_n;

--Para pasar de un número decimal a una cadena en base m hay que hacer divisiones enteras sucesivas donde el dividendo es el número decimal inicial en el primer caso y el cociente anterior en los casos sucesivos. El divisor es siempre m. Entonces la cadena en base m está formada por los restos de dichas divisiones en orden inverso y "traducidos" a caracteres
--ej.
--20 a heaxadecimal
--20|_16
-- 4 1 |_16      => (20)_10 = (14)_16
--   1   0

--En la recursion llevamos el numero en binario, la base, la cadena que estamos construyendo y el cociente y el resto de la última division.
--Paramos cuando un cociente es 0

CREATE VIEW recursion2(num_10, m, num_m, cociente, resto) AS
SELECT num_10, m, caracter, FLOOR(num_10/m) , num_10 mod m FROM base_10_m JOIN caracteres WHERE numero=num_10 mod m
UNION
SELECT num_10, m, caracter+num_m, FLOOR(cociente/m), cociente mod m FROM recursion2 JOIN caracteres WHERE FLOOR(cociente)>=1 and numero= cociente mod m;

--Nos quedamos con las cadenas completas que son aquellas para las que el cociente es 0
CREATE VIEW base_10_cadena_m AS SELECT num_10, m, num_m FROM recursion2 JOIN caracteres WHERE cociente=0 and resto=numero;

--Por último juntamos con JOIN's la información y proyectamos los datos que nos interesan
CREATE VIEW base_n_m(number_n, n, number_m, m ) AS
SELECT conversion.number,conversion.from_base,base_10_cadena_m.num_m,conversion.to_base 
FROM ((conversion JOIN base_n_10 ON conversion.number=base_n_10.num_n) JOIN base_10_cadena_m ON base_10_cadena_m.num_10=base_n_10.num_10 and base_10_cadena_m.m=conversion.to_base);

-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------

SELECT * FROM base_2_10;
--Para mostrar la información la mostramos de forma más legible orednada por bases y numero
SELECT * FROM base_n_m ORDER BY n,m,number_n;


