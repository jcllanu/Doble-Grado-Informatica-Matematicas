
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
using namespace std;


/*
void resuelveCaso() {
	bintreeExt<int> arbol = leerArbolExt(-1);
	pair<int, int> p = arbol.gruposRescate();
	cout << p.first << ' ' << p.second << '\n';
	
}

*/
template<class T>
bintree<T> construir(vector<T> const& preorden, vector<T> const& inorden, int a, int b, int c, int d) {
	if (b < a || d < c) {
		return {};
	}
	else {
		T raiz = preorden[a];
		int cont = 0;
		while (inorden[c + cont] != raiz) {
			cont++;
		}
		return bintree<T>(construir(preorden, inorden, a + 1, a + cont, c, c + cont - 1),
			raiz,
			construir(preorden, inorden, a + cont + 1, b, c + cont + 1, d));
	}



}

bool resuelveCaso() {
	string pre, in;
	vector<int> preorden, inorden;
	int valor1, valor2;
	getline(cin, pre);
	if (!cin) {
		return false;
	}
	getline(cin, in);
	stringstream ss(pre), ss2(in);
	while (ss >> valor1) {
		preorden.push_back(valor1);
	}
	while (ss2 >> valor2) {
		inorden.push_back(valor2);
	}

	bintree<int> arbol = construir(preorden, inorden, 0, preorden.size() - 1, 0, preorden.size() - 1);
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
