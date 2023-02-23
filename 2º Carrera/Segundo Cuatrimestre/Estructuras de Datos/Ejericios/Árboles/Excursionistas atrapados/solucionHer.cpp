
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintreeHeredada.h"
#include "bintree.h"
#include <vector>
#include <climits>
#include <string>
using namespace std;



void resuelveCaso() {
	bintreeExt<int> arbol = leerArbolExt(-1);
	pair<int, int> p = arbol.gruposRescate();
	cout << p.first << ' ' << p.second << '\n';
	
}

/*

pair<int,int> gruposRescate(bintree<int> const& arbol) {
	if (arbol.empty()) {
		return { 0, 0 };
	}
	else {
		pair<int, int> grupIzq = gruposRescate(arbol.left());
		pair<int, int> grupDer = gruposRescate(arbol.right());
		pair<int, int> sol;
		if (arbol.root() == 0) {
			sol.first =grupIzq.first + grupDer.first;
			sol.second = max(grupIzq.second, grupDer.second);
		}
		else {
			if (grupIzq.first == 0 && grupDer.first == 0)
				sol.first=1;
			else
				sol.first = grupIzq.first + grupDer.first;
			sol.second = arbol.root() + max(grupIzq.second, grupDer.second);
		}
		return sol;
	}
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	pair<int, int> p = gruposRescate(arbol);
	cout << p.first << ' ' << p.second << '\n';
}
*/



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
