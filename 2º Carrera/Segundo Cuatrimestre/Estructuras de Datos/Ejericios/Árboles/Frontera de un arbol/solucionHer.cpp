
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintreeHeredada.h"
#include "bintree.h"
#include <vector>
using namespace std;



void resuelveCaso() {
	bintreeExt<int> arbol = leerArbolExt(-1);
	for(int num: arbol.frontera())
		cout << num << ' ';

	cout << '\n';
}
/*
template <class T>
void front(bintree<T> const& arbol, vector<T> & frontera) {
	if (!arbol.empty()) {
		if (arbol.left().empty() && arbol.right().empty()) {
			frontera.push_back(arbol.root());
		}
		else {
			front(arbol.left(), frontera);
			front(arbol.right(), frontera);
		}
	}
}



void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	vector<int> frontera;
	front(arbol, frontera);
	for (int num : frontera)
		cout << num << ' ';

	cout << '\n';
}
*/

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
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
