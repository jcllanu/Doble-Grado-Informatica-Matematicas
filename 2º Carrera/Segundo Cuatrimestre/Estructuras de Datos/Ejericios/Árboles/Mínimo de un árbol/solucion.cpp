
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"
#include <string>
using namespace std;

template<class T>
T minimo(const bintree<T>& arbol) {
	T minim;
	if (arbol.right().empty() && arbol.left().empty()) {
			minim=arbol.root();
	}
	else {
		if (!arbol.right().empty() && !arbol.left().empty()) {
			minim = min(min(minimo(arbol.right()), minimo(arbol.left())), arbol.root());
		}
		else if (arbol.right().empty()) {
			minim = min(minimo(arbol.left()), arbol.root());
		}
		else {
			minim = min(minimo(arbol.right()), arbol.root());
		}
	
	}

	return minim;
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
