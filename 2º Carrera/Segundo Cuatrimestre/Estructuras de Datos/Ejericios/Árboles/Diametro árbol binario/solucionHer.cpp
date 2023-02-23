
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
	bintreeExt<char> arbol = leerArbolExt('.');
	cout << arbol.diametro() << '\n';
	
}

/*
template <class T>
int diametro(bintree<T> const& arbol, int& altura) {
	int diam;
	if (arbol.empty()) {
		altura = 0;
		return 0;
	}
	else {
		int alturaDer, alturaIzq;
		int diamIzq = diametro(arbol.left(), alturaIzq);
		int diamDer = diametro(arbol.right(), alturaDer);
		altura = 1 + max(alturaDer, alturaIzq);

		return max(max(diamIzq, diamDer), 1 + alturaDer + alturaIzq);
	}
}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	int altura;
	cout << diametro(arbol, altura) << '\n';
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
