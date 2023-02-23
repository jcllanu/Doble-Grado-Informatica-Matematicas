
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
#include <sstream>
#include <queue>
#include <cmath>
#include <list>
using namespace std;




string princesaAccesibleMasCercana(bintree<string> const& arbol) {
	if (arbol.empty())
		return "No encontrada";
	queue<bintree<string>> cola;
	cola.push(arbol);
	while (!cola.empty()) {
		bintree<string> actual = cola.front();
		cola.pop();

		if (actual.root() == "Dragon") {
			//Nada
		}
		else if (actual.root() == "Libre") {
			if (!actual.left().empty()) {
				cola.push(actual.left());
			}
			if (!actual.right().empty()) {
				cola.push(actual.right());
			}
		}else{
			return actual.root();
		}
	}
	return "No encontrada";

}

int princesasAccesibles(bintree<string> const& arbol) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		if (arbol.root() == "Dragon") {
			return 0;
		}
		else if (arbol.root() == "Libre") {
			return princesasAccesibles(arbol.left()) + princesasAccesibles(arbol.right());
		}
		else {
			return 1 + princesasAccesibles(arbol.left()) + princesasAccesibles(arbol.right());
		}
	}
}


void resuelveCaso() {
	bintree<string> arbol = leerArbol(string("."));
	cout << "Princesas accesibles: " << princesasAccesibles(arbol) << endl;
	cout << "Princesa accesible mas cercana: " << princesaAccesibleMasCercana(arbol) << endl;
	cout << endl;
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
