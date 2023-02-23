
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
//#include "bintreeHeredada.h"
#include "bintree.h"
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

struct tSolucion {
	int sumaDescendientes;
	int numSingulares;
};

tSolucion nodosSingulares(bintree<int> const& arbol, int sumaAntepasados) {
	tSolucion sol;
	if (arbol.empty()) {
		sol.numSingulares = 0;
		sol.sumaDescendientes = 0;
	}
	else {
		tSolucion solIzq = nodosSingulares(arbol.left(), arbol.root() + sumaAntepasados);
		tSolucion solDer = nodosSingulares(arbol.right(), arbol.root() + sumaAntepasados);

		sol.numSingulares = solIzq.numSingulares + solDer.numSingulares + (sumaAntepasados == solIzq.sumaDescendientes + solDer.sumaDescendientes ? 1 : 0);
		sol.sumaDescendientes = arbol.root() + solIzq.sumaDescendientes + solDer.sumaDescendientes;

	}
	return sol;
}



int nodosSingulares(bintree<int> const& arbol) {
	return nodosSingulares(arbol, 0).numSingulares;
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(0);
	cout << nodosSingulares(arbol) << endl;
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
