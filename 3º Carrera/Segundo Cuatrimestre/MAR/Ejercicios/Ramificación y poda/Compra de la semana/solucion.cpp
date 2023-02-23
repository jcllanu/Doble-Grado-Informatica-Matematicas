
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
#include <climits>
#include "PriorityQueue.h"

using namespace std;
struct nodo {
	vector<int> solucion;
	vector<int> supers;
	int k;
	int coste_optimista;
	int coste_actual;
};
struct Comparator {
	bool operator()(nodo const& a, nodo const& b) {
		return a.coste_optimista < b.coste_optimista;
	}
};
void resuelveCaso();
int costeOptimista(int precio_actual, vector<int> const& supers, int k, vector<vector<int>> const& precios);
int compra(vector<vector<int>> const& precios,int numSupers,int numProductos, vector<int> const& minimos);
int costePesimista(int precio_actual, vector<int> const& supers, int k, vector<vector<int>> const& precios);

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
	vector<vector<int>> precios(numSupers, vector<int>(numProductos));
	vector<int> minimos(numProductos);

	for (int i = 0; i < numSupers; i++) {
		for (int j = 0; j < numProductos; j++) {
			cin >> precios[i][j];
			if (i == 0) {
				if (j > 0) {
					minimos[j] = minimos[j - 1];
				}
				minimos[j] = precios[i][j];
			}
			else {
				minimos[j] = min(minimos[j], precios[i][j]);
			}
		}
	}

	int mejorPrecio = compra(precios,numSupers,numProductos, minimos);

	cout << mejorPrecio << '\n';
}

int compra( vector<vector<int>> const& precios, int numSupers, int numProductos, vector<int> const& minimos) {
	nodo X, Y;
	PriorityQueue<nodo, Comparator> pq;
	Y.k = -1;
	Y.coste_actual = 0;
	Y.supers = vector<int>(numSupers);
	Y.coste_optimista = minimos[numProductos-1];
	Y.solucion = vector<int>(numProductos);
	
	pq.push(Y);
	int coste_mejor = costePesimista(0, Y.supers, 0, precios);
	while (!pq.empty() && pq.top().coste_optimista <= coste_mejor) {
		Y = pq.top();
		pq.pop();
		for (int i = 0; i < numSupers; i++) {
			X = Y;
			X.k++;
			X.solucion[X.k] = precios[i][X.k];
			X.supers[i]++;
			X.coste_actual += precios[i][X.k];
			if (X.k+1== numProductos && X.supers[i] <= 3) {//Si es solucion
				int coste_real = X.coste_actual;
				if (coste_real < coste_mejor){
					coste_mejor = coste_real;
				}
			}
			else {//No es solucion
		
				if (X.supers[i] <= 3) {//Vemos si la solución es completable 
					X.coste_optimista = costeOptimista(X.coste_actual, X.supers, X.k + 1, precios);
					if (X.coste_optimista <= coste_mejor) {//Y si es prometedora
						pq.push(X);
						int coste_pesimista = costePesimista(X.coste_actual, X.supers, X.k + 1, precios);
						if (coste_pesimista < coste_mejor) {
							coste_mejor = coste_pesimista;
						}
					}
				}
			}
		}
	}
	return coste_mejor;
}
/*
void compra(vector<int>& solucion, vector<int>& supers, int& precio, int& mejorPrecio, const tPrecios& precios, int k, const vector<int>& minimos) {

	for (int i = 0; i < precios.filas; i++) {
		solucion[k] = precios.tab[i][k];
		supers[i]++;//Marcamos
		precio += precios.tab[i][k];
		if (!(supers[i] > 3 || precio > mejorPrecio || precio + estimacion(minimos, k + 1) > mejorPrecio)) {//Vemos si la solución es completable y si es prometedora
			if (k + 1 == precios.columnas) {//Si es el hijo del último nivel tenemos una nueva mejor solución
				mejorPrecio = precio;
			}
			else {//Avanzamos un nivel más en busca de completar la solución
				compra(solucion, supers, precio, mejorPrecio, precios, k + 1, minimos);
			}
		}
		supers[i]--;//Desmarcamos
		precio -= precios.tab[i][k];
	}
}
*/

int costeOptimista(int precio_actual, vector<int> const& supers, int k, vector<vector<int>> const& precios) {//Calculamos para cada producto su precio mas barato en los supers que quedan
	int suma = precio_actual;
	for (int j = k; j < precios[0].size(); j++) {
		int min = INT_MAX;
		for (int i = 0; i < supers.size(); i++) {
			if (supers[i] < 3 && precios[i][j] < min) {
				min = precios[i][j];
			}
		}
		suma += min;
	}
	return suma;
}
int costePesimista(int precio_actual, vector<int> const& supers, int k, vector<vector<int>> const& precios) {
	int suma = precio_actual;
	auto supersbis = supers;
	for (int j = k; j < precios[0].size(); j++) {
		int i = 0;
		while (supersbis[i] == 3) {
			i++;
		}
		suma += precios[i][j];
		supersbis[i]++;
	}
	return suma;
}