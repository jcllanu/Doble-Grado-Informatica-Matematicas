/*Juan Carlos Llamas Núñez
	2º DG FAL*/

#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
#include <climits>

using namespace std;

typedef struct {
	int tab[20][60];
	int filas, columnas;
}tPrecios;

void resuelveCaso();
int estimacion(vector<int> minimos, int k);
void compra(vector<int>& solucion, vector<int>& supers, int& precio, int& mejorPrecio, const tPrecios& precios, int k, const vector<int>& minimos);


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

void resuelveCaso() {
	int numProductos, numSupers;
	cin >> numSupers >> numProductos;
	vector<int> solucion(numProductos);
	vector<int> supers(numSupers);
	tPrecios precios;
	precios.filas = numSupers;
	precios.columnas = numProductos;
	vector<int> minimos(numProductos);
	
	for (int i = 0; i < precios.filas; i++) {
		for (int j = 0; j < precios.columnas; j++) {
			cin >> precios.tab[i][j];
			if (i == 0) {
				
				minimos[j] = precios.tab[i][j];
			}
			else {
				minimos[j] = min(minimos[j], precios.tab[i][j]);
			}
		}
		supers[i] = 0;
	}
	int mejorPrecio = INT_MAX, precio = 0;
	compra(solucion, supers, precio, mejorPrecio, precios, 0, minimos);
	
	cout << mejorPrecio << endl;
}

void compra(vector<int>& solucion, vector<int>& supers,  int& precio, int& mejorPrecio, const tPrecios& precios,int k, const vector<int>& minimos) {

	for (int i = 0; i < precios.filas; i++) {
		solucion[k] = precios.tab[i][k];
		supers[i]++;/*Marcamos*/
		precio += precios.tab[i][k];
		if (!(supers[i] > 3 || precio > mejorPrecio || precio + estimacion(minimos, k+1) > mejorPrecio)) {/*Vemos si la solución es completable y si es prometedora*/
			if (k + 1 == precios.columnas) {/*Si es el hijo del último nivel tenemos una nueva mejor solución*/
				mejorPrecio = precio;
			}else{/*Avanzamos un nivel más en busca de completar la solución*/
				compra(solucion, supers, precio, mejorPrecio, precios, k + 1, minimos);
			}
		}
		supers[i]--;/*Desmarcamos*/
		precio -= precios.tab[i][k];
	}
}


int estimacion(vector<int> minimos, int k) {/*Para una solución en la que se han elegido ya k+1 productos se va a sumar, al menos,
											el precio de cada producto restante (numProductos-k-1) en el supermercado donde está a precio más bajo*/
	int suma = 0;
	for (int i = k; i < minimos.size(); i++) {
			suma += minimos[i];
	}
	return suma;
}