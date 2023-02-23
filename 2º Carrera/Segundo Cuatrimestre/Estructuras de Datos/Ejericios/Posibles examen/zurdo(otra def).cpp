
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
#include <list>
using namespace std;

struct tSolucion {
	bool es_zurdo;
	int alturaMinima;
};

template<class T>
tSolucion es_zurdo(bintree<T> const& arbol) {
	tSolucion sol;
	if (arbol.empty()) {
		sol.alturaMinima = 0;
		sol.es_zurdo = true;
	}
	else {
		tSolucion solIzq = es_zurdo(arbol.left());
		tSolucion solDer = es_zurdo(arbol.right());

		sol.alturaMinima = 1 + min(solDer.alturaMinima, solIzq.alturaMinima);
		sol.es_zurdo = solIzq.es_zurdo && solDer.es_zurdo && solDer.alturaMinima <= solIzq.alturaMinima;
	}
	return sol;
}


void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	tSolucion sol = es_zurdo(arbol);

	cout << sol.es_zurdo << endl;
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
