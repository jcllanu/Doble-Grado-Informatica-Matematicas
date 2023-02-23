
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "hashmap.h"

using namespace std;


template<class T>
bintree<T> espejo(const bintree<T>& arbol) {
	if (arbol.empty()) {
		return {};
	}
	else {
		return{ espejo(arbol.right()), arbol.root(), espejo(arbol.left()) };
	}
}

bool resuelveCaso() {
	bintree<char> arbol= leerArbol('*');
	if (arbol.empty() || !cin) {
		return false;
	}
	bintree<char> arbolEspejo = espejo(arbol);
	for (char a : arbolEspejo.preorder())
		cout << a;
	cout << "\n";


	cout << "\n";
	cout << "\n";
	return true;
}




int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}