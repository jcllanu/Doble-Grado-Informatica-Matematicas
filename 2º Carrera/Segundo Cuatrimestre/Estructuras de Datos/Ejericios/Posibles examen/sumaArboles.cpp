
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "hashmap.h"

using namespace std;

bintree<int> operator+(const bintree<int>& arbol1, const bintree<int>& arbol2) {
	if (arbol1.empty()) {
		return arbol2;
	}
	if (arbol2.empty()) {
		return arbol1;
	}
	else {
		return { arbol1.left() + arbol2.left(),arbol1.root() + arbol2.root(),arbol1.right() + arbol2.right() };
	}
}
void escribir(const bintree<int>& arbol) {
	if (arbol.empty()) {
		cout << -1 << " ";
	}
	else {
		cout << arbol.root() << " ";
		escribir(arbol.left());
		escribir(arbol.right());
	}
}
bool resuelveCaso() {
	bintree<int> arbol1 = leerArbol(-1);
	bintree<int> arbol2 = leerArbol(-1);
	if (arbol1.empty() && arbol1.empty()) {
		return false;
	}
	bintree<int> arbolRes = arbol1 + arbol2;
	escribir(arbolRes);
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