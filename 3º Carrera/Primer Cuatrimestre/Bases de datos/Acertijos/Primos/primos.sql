/abolish
/duplicates on

--JUAN CARLOS LLAMAS NÚÑEZ 



/set cota 20

--Calculamos los números candidatos, que en una primera aproximación muy poco fina serán todos entre el 1 y la cota que nos dan. Quitamos después el 1 porque sabemos que no es primo.

CREATE VIEW intervalo_1_cota (n) AS SELECT 1 UNION ALL SELECT n+1 FROM intervalo_1_cota WHERE n<$cota$;
CREATE VIEW intervalo_2_cota (n) AS SELECT * FROM intervalo_1_cota EXCEPT SELECT 1;

--Observación: Se incluye el 1 en la recursión pará después quitarlo por el caso extremo en el cota = 1 y para el cual, el conjunto de numeros candidatos es el vacío. Si empezaramos la recursión en 2 el conjunto de numeros candidatos sería {2}. Si asumimos que cota>=2 podemos sustituir las consultas por

--CREATE VIEW intervalo_2_cota(n) AS SELECT 2 UNION ALL SELECT n+1 FROM intervalo_2_cota WHERE n<$cota$;

--Vamos a realizar una versión de la criba de Eratóstenes en las que vamos a calcular los multiplos de los números candidatos menoroes o iguales que la cota. El caso base será para cada número candidato n, su múltiplo 2*n donde 2*n sea menor o igual que la cota.

CREATE VIEW casosBase(n,multiplos) AS SELECT n, 2*n FROM intervalo_2_cota WHERE 2*n<=$cota$;

--El caso recursivo será para cada múltiplo m=k*n el siguiente multiplo de n el (k+1)*n = k*n + n= m + n;

CREATE VIEW recursion(n,multiplos) AS SELECT * FROM casosBase UNION ALL SELECT n, multiplos+n FROM recursion WHERE multiplos+n<=$cota$;

--Por último los números primos serán los candidatos salvo los que sean múltiplo de otro número candidato

CREATE VIEW primos(x) AS SELECT * FROM intervalo_2_cota EXCEPT SELECT multiplos FROM recursion;

SELECT * FROM primos;













