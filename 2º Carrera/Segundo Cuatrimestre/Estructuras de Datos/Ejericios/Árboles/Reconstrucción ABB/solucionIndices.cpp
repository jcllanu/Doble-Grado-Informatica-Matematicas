
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
//#include "bintreeHeredada.h"
#include "bintree.h"
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <queue>
#include <cmath>
using namespace std;


/*
void resuelveCaso() {
	bintreeExt<int> arbol = leerArbolExt(-1);
	pair<int, int> p = arbol.gruposRescate();
	cout << p.first << ' ' << p.second << '\n';
	
}

*/

template <class T>
bintree<T> construir(vector<T> const& preorden, int a, int b) {
	if (b < a) {
		return {};
	}
	else {
		T raiz = preorden[a];
		int cont = 1;
		while (a+cont<preorden.size() && preorden[a + cont] < raiz) {
			cont++;
		}
		return bintree<T>(construir(preorden, a + 1, a + cont - 1),
			raiz,
			construir(preorden, a + cont, b));
	}


}


bool resuelveCaso() {
	string pre;
	vector<int> preorden;
	int valor;
	getline(cin, pre);
	if (!cin) {
		return false;
	}
	stringstream ss(pre);
	while (ss >> valor) {
		preorden.push_back(valor);
	}
	
	bintree<int> arbol = construir(preorden, 0, preorden.size()-1);
	vector<int> postorden = arbol.postorder();
	for (int i = 0; i < postorden.size(); i++) {
		cout << postorden[i] << ' ';
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
