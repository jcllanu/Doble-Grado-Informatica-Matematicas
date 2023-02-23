/*Juan Carlos Llamas Núñez
2º DG FAL*/

#include <iostream>
#include<fstream>

using namespace std;

const int N = 14;

typedef struct {
	int sol[N+1];
	int contador;
}tSolucion;
typedef struct {
	bool col[N+1];
	int contador;
}tColumnas;
typedef struct {
	int diag[4*N-1];
	int contador;
}tDiagonales;

int reinas(tSolucion& sol, int k, tColumnas& col, tDiagonales& diag, int n);
int cont = 0;
void resuelveCaso() {
	int n;
	cin >> n;
	tSolucion sol;
	tColumnas col;
	tDiagonales diag;
	sol.contador = n;
	col.contador = n;
	diag.contador=4*n-2;
	for (int i = 0; i <= n; i++) {
		col.col[i] = false;
		diag.diag[i] = false;
	}
	for (int i = n; i <= 4 * n - 2; i++) {
		diag.diag[i] = false;
	}
	
	cout << reinas(sol, 1, col, diag, n)<< endl;
}
int main() {
#ifndef DOMJUDGE 
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


/*Algoritmo de resolución del probelma de las N reinas adaptado para devolver el número de soluciones para cada N dado*/
int reinas(tSolucion& sol, int k, tColumnas& col, tDiagonales& diag, int n) {
	int dev = 0;
	for (int columna = 1; columna <= n; columna++) {
		sol.sol[k] = columna;
		if (!col.col[sol.sol[k]] && !diag.diag[sol.sol[k] - k + n] && !diag.diag[k + sol.sol[k] + 2 * n - 2]) {
			col.col[sol.sol[k]] = true;
			diag.diag[sol.sol[k] - k + n] = true;
			diag.diag[k + sol.sol[k] + 2 * n - 2] = true;
			if (k == n) {
				dev++;
			}
			else {
				dev+=reinas(sol, k + 1, col, diag,n);
			}
			col.col[sol.sol[k]] = false;
			diag.diag[sol.sol[k] - k + n] = false;
			diag.diag[k + sol.sol[k] + 2 * n - 2] = false;
		}
	}
	return dev;
}
/*La única modificación es que cuando hemos encontrado un solución, es decir, k=n, sumamos uno al número de soluciones encontradas y ese número será devuelto hacia arriba 
y sumado  con las soluciones de las demás ramas*/