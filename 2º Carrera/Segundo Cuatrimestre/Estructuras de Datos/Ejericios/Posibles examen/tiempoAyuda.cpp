
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







int tiempoAyuda(const bintree<char> &arbol, bool& hay) {
	if (arbol.empty()) {
		hay = false;
		return 0;
	}
	else {
		bool hayDer, hayIzq;
		int tIzq = tiempoAyuda(arbol.left(), hayIzq);
		int tDer = tiempoAyuda(arbol.right(), hayDer);

		hay = hayDer || hayIzq || arbol.root() == 'x';
		return tIzq + tDer + (hay ? 2 : 0);
	}
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	bool a;
	int sol=tiempoAyuda(arbol, a);
	if (a)
		sol -= 2;
	cout << sol << endl;
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
