
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



bool resuelveCaso() {
	char aux;
	cin >> aux;
	if (!cin) {
		return false;
	}

	if (aux == 'N') {
		bintreeExt<int> arbol = leerArbolExt(-1);
		cout << arbol.minimo();
	}
	else {
		bintreeExt<string> arbol = leerArbolExt(string("#"));
		cout <<arbol.minimo();
	}
	cout << '\n';

	return true;
	
}

/*
template <class T>
T minimo(bintree<T> const& arbol) {
	T mini = arbol.root();
	if (!arbol.left().empty()) {
		mini = min(mini, minimo(arbol.left()));
	}
	if (!arbol.right().empty()) {
		mini = min(mini, minimo(arbol.right()));
	}
	return mini;
}



bool resuelveCaso() {
	char aux;
	cin >> aux;
	if (!cin) {
		return false;
	}

	if (aux == 'N') {
		bintree<int> arbol = leerArbol(-1);
		cout << minimo(arbol);
	}
	else {
		bintree<string> arbol = leerArbol(string("#"));
		cout << minimo(arbol);
	}
	cout << '\n';

	return true;
}

*/

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
