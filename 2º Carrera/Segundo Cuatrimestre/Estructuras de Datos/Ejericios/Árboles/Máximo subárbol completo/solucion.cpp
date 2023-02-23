
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"

using namespace std;

typedef struct {
	int alturaMaximoTotal;
	int alturaMaximoActual;
	
}tSolucion;

template<class T>
tSolucion maximoSubgrafoCompleto(const bintree<T>& arbol) {
	tSolucion solucion;
	if (arbol.empty()) {
		solucion.alturaMaximoActual = 0;
		solucion.alturaMaximoTotal = 0;
	}
	else {
		tSolucion solIzq = maximoSubgrafoCompleto(arbol.left());
		tSolucion solDer = maximoSubgrafoCompleto(arbol.right());
		if (arbol.left().empty() || arbol.right().empty()) {
			solucion.alturaMaximoActual = 1;
			solucion.alturaMaximoTotal = max(1, max(solDer.alturaMaximoTotal, solIzq.alturaMaximoTotal));
		}
		else {
			solucion.alturaMaximoActual = 1 + min(solDer.alturaMaximoActual, solIzq.alturaMaximoActual);
			solucion.alturaMaximoTotal = max(solucion.alturaMaximoActual, max(solIzq.alturaMaximoTotal, solDer.alturaMaximoTotal));
		}
	}
	return solucion;
}
void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	tSolucion solucion = maximoSubgrafoCompleto(arbol);
	cout << solucion.alturaMaximoTotal << '\n';
	
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
