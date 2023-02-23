
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"

using namespace std;

template<class T>
bool sonOpuestos(const bintree <T>& arbolIzq, const bintree <T>& arbolDer) {
	bool opuestos;
	if (arbolIzq.empty()) {
		if (arbolDer.empty()) {
			opuestos = true;
		}
		else {
			opuestos = false;
		}
	}
	else {
		if (arbolDer.empty()) {
			opuestos = false;
		}
		else {
			opuestos = sonOpuestos(arbolIzq.right(), arbolDer.left()) && sonOpuestos(arbolIzq.left(), arbolDer.right());
		}
	}
	return opuestos;
}

template<class T>
bool esSimetrico(const bintree <T>& arbol) {
	return arbol.empty() || sonOpuestos(arbol.left(), arbol.right());
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	if (esSimetrico(arbol)){
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
	
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
