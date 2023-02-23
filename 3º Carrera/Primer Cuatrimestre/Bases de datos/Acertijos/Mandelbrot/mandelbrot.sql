/abolish
/duplicates on

--JUAN CARLOS LLAMAS N��EZ

-- NIVEL DE DIFICULTAD (0-10):   8
-- TIEMPO DE EJECUCI�N:          2 MINUTOS Y MEDIO

--Vamos a construir una ret�cula, es decir, una partici�n del rect�ngulo [x_0, x_1] x [y_0, y_1] en rect�nguloas m�s peque�os y vamos a fijarnos en los v�rtices de los rect�ngulos. Si ese v�rtice pertenece al conjunto de Mandelbrot, escribiremos un 'o' en su posici�n, y si no pertenece, un espacio en blanco.

--En primer lugar definimos una serie de par�metros, algunos ya introducidos (x_0, x_1, y_0, y_1), y otros que van a representar la precisi�n con la que se pinte el conjunto (dx y dy granularidad de la partici�n e it la precisi�n de la condici�n de pertenenecia al conjunto medida en el n�mero de iteraciones de la recursi�n).

/set x_0 -2.0
/set x_1 0.5
/set y_0 -1.0
/set y_1 1.0
/set dx 0.09
/set dy 0.10
/set it 10
--Para estos valores el resultado de la ejecuci�n se muestra a los 2 MINUTOS Y MEDIO y se parece razonablemente a la imagen que tenemos del conjunto de Mandelbrot (est� un poco estirada hacia arriba y abajo pero si disminuyo m�s dx se vuelve muy lento y si aumento dy pierde precisi�n). Para una mayor precisi�n hay que aumentar el valor de it y disminuir dx y dy aunque el tiempo de ejecuci�n aumenta notablemente 

--Consideramos las abscisas y las ordenadas de los v�rtices y las vamos a acompa�ar del n�mero de columna/ fila seg�n corresponda para despu�s poder mostrar la salida con mayor facilidad. Empezamos a numerar en el 1.


CREATE VIEW absc(x,c) AS SELECT $x_0$,1 UNION SELECT x+$dx$,c+1 FROM absc WHERE x<$x_1$;
CREATE VIEW orde(y,f) AS SELECT $y_0$,1 UNION SELECT y+$dy$,f+1 FROM orde WHERE y<$y_1$;

--Calculamos todos los v�rtices como el producto cartesiano de las coordenadas de abscisas y ordenadas
CREATE VIEW region(x,y,c,f) AS SELECT x,y,c,f FROM absc JOIN orde;

--En la recursi�n calculamos para cada punto complejo c = (c_1,c_2) = c_1 + i*c_2:= (x,y) con (x,y) en region 
--el it-�simo t�rmino de la sucesi�n:
--
--      { 0         si n=0
--z_n+1={
--      { z_n^2 +c  si n>=1

--N�tese que esta sucesi�n es de n�meros complejos y si z_n= x + iy para n>=1 entonces z_n+1 = (x + iy)^2 + c =
--  = x^2 -y^2 +i(2xy) +c_1 +ic_2 = (x^2 - y^2 + c_1) + i(2xy + c_2)

CREATE VIEW recursion(x,y,c_1,c_2,n,c,f) AS
SELECT 0.0, 0.0, x, y, 0, c, f FROM region
UNION
SELECT (x*x-y*y+c_1), (c_2+2*x*y), c_1, c_2, n+1, c, f FROM recursion WHERE n<$it$;

--Tras hacer la recursi�n, un punto c pertenece al conjunto de Mandelbrot si la sucesi�n definida m�s arriba est� acotada. En la pr�ctica basta ver que ning�n t�rmino tiene m�dulo mayor que 2. Para los c con m�dulo al cuadrado mayor que cuatro les asociamos un espacio en blanco porque dicho punto no pertenece al conjunto y, en caso contrario, les asociamos un 'o'. Nos quedamos con las filas y columnas para su posterior representaci�n en lugar de las coordenadas en el plano complejo porque va a ser m�s sencillo mostrar la soluci�n de esta manera.

CREATE VIEW region_pertenece(c,f,car) AS SELECT c,f,IIF(x*x+y*y<=4.0,'o',' ') FROM recursion WHERE n=$it$;

--Concatenamos los caracteres de una misma fila, es decir, para una ordenada fija, hacemos variar las abscisas (columnas) de menor a mayor y concatenamos 'o' � ' ' seg�n el punto pertenezca o no al conjunto de Mandelbrot.
CREATE VIEW recursion2(f,cadena,n) AS
SELECT f, car ,1 FROM region_pertenece WHERE c=1
UNION 
SELECT recursion2.f, cadena+car,n+1 FROM recursion2 JOIN region_pertenece ON recursion2.f=region_pertenece.f and n+1=c;

--Por �ltimo mostramos por pantalla la soluci�n
SELECT cadena FROM recursion2 WHERE n=(SELECT MAX(n) FROM recursion2) ORDER BY f;


