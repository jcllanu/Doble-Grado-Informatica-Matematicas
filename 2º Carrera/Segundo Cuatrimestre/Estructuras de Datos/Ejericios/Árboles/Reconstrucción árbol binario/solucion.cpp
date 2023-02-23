
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"
#include <string>
#include <sstream>
using namespace std;

template<class T>
bintree<T> construir(const vector<T>& preorden, const vector<T>& inorden) {
	T raiz;
	int cont = 0;
	if (preorden.size() > 0) {
		raiz = preorden[0];
		vector<T> preordenIzq, inordenIzq, preordenDer, inordenDer;
		while (inorden[cont] != raiz) {
			inordenIzq.push_back(inorden[cont]);
			preordenIzq.push_back(preorden[cont + 1]);
			cont++;
		}
		for (int i = cont + 1; i < inorden.size(); i++) {
			inordenDer.push_back(inorden[i]);
			preordenDer.push_back(preorden[i]);
		}

		return { construir(preordenIzq, inordenIzq),raiz,construir(preordenDer, inordenDer) };
	}
	else {
		return {};
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

	bintree<int> arbol = construir(preorden,inorden);
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
