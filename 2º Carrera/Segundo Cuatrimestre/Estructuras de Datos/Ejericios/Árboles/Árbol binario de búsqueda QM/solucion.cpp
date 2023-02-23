
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"
#include<climits>
using namespace std;

typedef struct {
	int minimo, maximo;
	bool esArBinBusqueda;
}tSolucion;


tSolucion esArbolBinarioBusqueda(const bintree<int>& arbol) {
	tSolucion solucion;
	if (arbol.empty()) {
		solucion.esArBinBusqueda = true;
		solucion.minimo = INT_MAX;
		solucion.maximo = INT_MIN;
	}
	else {
		tSolucion solIzq = esArbolBinarioBusqueda(arbol.left());
		tSolucion solDer = esArbolBinarioBusqueda(arbol.right());

		solucion.esArBinBusqueda = solIzq.esArBinBusqueda&&solDer.esArBinBusqueda&&arbol.root() > solIzq.maximo&&arbol.root() < solDer.minimo;
		solucion.maximo = max(max(solDer.maximo, solIzq.maximo), arbol.root());
		solucion.minimo = min(min(solDer.minimo, solIzq.minimo), arbol.root());
	}
	return solucion;
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	tSolucion solucion = esArbolBinarioBusqueda(arbol);
	cout << (solucion.esArBinBusqueda ? "SI" : "NO" )<< '\n';
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
