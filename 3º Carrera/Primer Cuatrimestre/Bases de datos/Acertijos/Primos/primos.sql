/abolish
/duplicates on

--JUAN CARLOS LLAMAS N��EZ 



/set cota 20

--Calculamos los n�meros candidatos, que en una primera aproximaci�n muy poco fina ser�n todos entre el 1 y la cota que nos dan. Quitamos despu�s el 1 porque sabemos que no es primo.

CREATE VIEW intervalo_1_cota (n) AS SELECT 1 UNION ALL SELECT n+1 FROM intervalo_1_cota WHERE n<$cota$;
CREATE VIEW intervalo_2_cota (n) AS SELECT * FROM intervalo_1_cota EXCEPT SELECT 1;

--Observaci�n: Se incluye el 1 en la recursi�n par� despu�s quitarlo por el caso extremo en el cota = 1 y para el cual, el conjunto de numeros candidatos es el vac�o. Si empezaramos la recursi�n en 2 el conjunto de numeros candidatos ser�a {2}. Si asumimos que cota>=2 podemos sustituir las consultas por

--CREATE VIEW intervalo_2_cota(n) AS SELECT 2 UNION ALL SELECT n+1 FROM intervalo_2_cota WHERE n<$cota$;

--Vamos a realizar una versi�n de la criba de Erat�stenes en las que vamos a calcular los multiplos de los n�meros candidatos menoroes o iguales que la cota. El caso base ser� para cada n�mero candidato n, su m�ltiplo 2*n donde 2*n sea menor o igual que la cota.

CREATE VIEW casosBase(n,multiplos) AS SELECT n, 2*n FROM intervalo_2_cota WHERE 2*n<=$cota$;

--El caso recursivo ser� para cada m�ltiplo m=k*n el siguiente multiplo de n el (k+1)*n = k*n + n= m + n;

CREATE VIEW recursion(n,multiplos) AS SELECT * FROM casosBase UNION ALL SELECT n, multiplos+n FROM recursion WHERE multiplos+n<=$cota$;

--Por �ltimo los n�meros primos ser�n los candidatos salvo los que sean m�ltiplo de otro n�mero candidato

CREATE VIEW primos(x) AS SELECT * FROM intervalo_2_cota EXCEPT SELECT multiplos FROM recursion;

SELECT * FROM primos;













