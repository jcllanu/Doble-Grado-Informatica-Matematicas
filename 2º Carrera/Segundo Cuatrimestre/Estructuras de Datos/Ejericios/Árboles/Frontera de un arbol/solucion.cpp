
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"

using namespace std;

template <typename T>
std::vector<T> &operator+(std::vector<T> &A, const std::vector<T> &B) {
	vector<T> v;
	v.reserve(A.size() + B.size());                
	v.insert(v.end(), A.begin(), A.end());
	v.insert(v.end(), B.begin(), B.end());
	return v;                                
}
/*
template<class T>
vector<T> resolver(const bintree<T>& arbol) {
	vector<T> dev;
	if (!arbol.empty()) {

		if (arbol.right().empty() && arbol.left().empty()) {
			dev.push_back(arbol.root());
		}
		else {
			dev = resolver(arbol.left());
			dev += resolver(arbol.right());
		}
		
	}
	return dev;
}
*/
template<class T>
void resolverS(const bintree<T>& arbol, vector<T>& v) {
	
	if (!arbol.empty()) {

		if (arbol.right().empty() && arbol.left().empty()) {
			v.push_back(arbol.root());
		}
		else {
			resolverS(arbol.left(), v);
			resolverS(arbol.right(),v);
			
		}

	}
	
}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	//vector<int> frontera = resolver(arbol);
	vector<int> frontera;
	resolverS(arbol, frontera);
	for (int i = 0; i < frontera.size(); i++) {
		cout << frontera.at(i) << ' ';
	}
	cout << '\n';
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
