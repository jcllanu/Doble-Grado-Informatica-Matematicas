
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"


using namespace std;
typedef struct {
	int altura, numNodos, hojas;
}tSolucion;

template<class T>
tSolucion resolver(const bintree<T>& arbol) {
	tSolucion solucion;
	if (arbol.empty()) {
		solucion.altura = 0;
		solucion.numNodos = 0;
		solucion.hojas = 0;
	}
	else {
		tSolucion solucionIzq = resolver(arbol.left());
		tSolucion solucionDer = resolver(arbol.right());
		
		if (arbol.right().empty() && arbol.left().empty()) {
			solucion.hojas = 1;
		}
		else {
			solucion.hojas = solucionDer.hojas + solucionIzq.hojas;
		}
		solucion.altura = 1 + max(solucionDer.altura, solucionIzq.altura);
		solucion.numNodos= 1 + solucionDer.numNodos + solucionIzq.numNodos;
	}
	return solucion;
}


void resuelveCaso() {
	bintree<char> arbol=leerArbol('.');
	tSolucion sol = resolver(arbol);
	cout << sol.numNodos << ' ' << sol.hojas << ' ' << sol.altura << '\n';
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
