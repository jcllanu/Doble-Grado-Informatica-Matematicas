
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"

using namespace std;

template<class T>
void diametro(const bintree <T>& arbol, int& altura, int& diam) {
	if (arbol.empty()) {
		altura = 0;
		diam = 0;
	}
	else {
		if (arbol.left().empty() && arbol.right().empty()) {
			altura = 1;
			diam = 1;
		}
		else {
			int alturaDer, alturaIzq, diametroDer, diametroIzq;
			diametro(arbol.left(), alturaIzq, diametroIzq);
			diametro(arbol.right(), alturaDer, diametroDer);
			altura = max(alturaIzq, alturaDer) + 1;
			diam = max(max(diametroIzq, diametroDer), alturaDer + alturaIzq + 1);
		}
	}

}


void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	int altura, diam;
	diametro(arbol, altura, diam);
	cout <<diam<< '\n';
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
