
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
bintree<T> construir(const vector<T>& preorden) {
	if (preorden.size() > 0) {
		int cont = 1;
		vector<T> preordenIzq, preordenDer;
		while (cont< preorden.size() && preorden[cont] < preorden[0]) {
			preordenIzq.push_back(preorden[cont]);
			cont++;
		}
		for (int i = cont; i < preorden.size(); i++) {
			preordenDer.push_back(preorden[i]);
		}

		return { construir(preordenIzq),preorden[0],construir(preordenDer) };
	}
	else {
		return {};
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
	
	bintree<int> arbol = construir(preorden);
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
