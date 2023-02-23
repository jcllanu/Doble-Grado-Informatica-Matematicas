// NOMBRE Y APELLIDOS: JUAN CARLOS LLAMAS NÚÑEZ

// Comentario general sobre la solucion,
// explicando como se resuelve el problema
/*Vamos a realizar una recursión dividiendo cada matriz en cuatro submatrices. Utilizaremos la técnica de inmersión para obtener el producto de las cuatro subdiagonales al comprobar si estas son equidiagonales.*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implementa la funcion recursiva
//Analisis del coste de esta funcion


//Esta funcion determina si v es equidiagonal
//y devuelve el producto de la diagonal principal
bool resolver(vector<vector<int>> const& v, int& d, int fila, int columna, int lado) {
	if (lado == 1) {/*Caso base en el que la matriz es 1x1 y es trivialemnte equidiagonal*/
		d = v[fila][columna];/*Devolvemos el producto de las diagonales , es decir, el valor que se encunetra en esa posicion*/
		return true;
	}
	else {
		lado = lado / 2;/*Partimos el problema en cuatro*/
		int d1, d2, d3, d4;/*d1 representa el producto de la mitad superior de la diagonal principal
						     d2 representa el producto de la mitad superior de la diagonal secundaria
						     d3 representa el producto de la mitad inferior de la diagonal secundaria
						     d1 representa el producto de la mitad inferior de la diagonal principal*/
		if (!resolver(v, d1, fila, columna, lado) || !resolver(v, d2, fila + lado, columna, lado) || !resolver(v, d3, fila, columna + lado, lado) || !resolver(v, d4, fila + lado, columna + lado, lado)) {
			/*Realizamos las llamadas recursivas a las cuatro submatrices cuyo vértice superior izquierdo tiene como coordenadas (f,c), (f+l,c),(f, c+l) y (f+l,c+l)*/
			/*Si alguna de ellas no es equidiagonal entonces la matriz que nos dan tampoco lo será y devolvemos false*/
			return false;
		}
		if (d1 * d4 == d2 * d3) {/*Comprobamos que se verifica la condicioón de equidiagonal con los productos de las subdiagonales obtenidas en la inmersión*/
			d = d1 * d4;/*Actualizamos el valor del producto de la diagonal*/
			return true;
		}
		else {
			return false;
		}
	}


  //Invoca aqui a tu funcion recursiva
}
/*La recurrencia es la siguiente:
			   {k_1 si l==1
Subdiagonal(l)={
			   {4*subdiagonal(l/4)+k_2 si l>1
Siendo l el número de elementos de la matriz, es decir, N*N;
Por el Teorema de la División sabemos que el orden de complejidad es lineal respecto de l, es decir, es N^2 siendo N el numero de filas/columnas de la matriz
El tamaño del problema es N^2
 */


void resuelveCaso() {
	int dim = 0; 
	cin >> dim;
	vector<vector<int>> v(dim,vector<int>(dim));
	for (int i = 0; i < dim; i++)
	for (int j = 0; j < dim; j++)
	{
		cin >> v[i][j];
	}
	int d;
	if (resolver(v,d,0,0,dim))
		cout << "SI " << d << "\n";
	else 
		cout << "NO\n";
}

int main() {
	// Para la entrada por fichero
	#ifndef DOMJUDGE
    ifstream in("sample2.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
	#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) 
		resuelveCaso();

	#ifndef DOMJUDGE 
	cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif

	return 0;
}

