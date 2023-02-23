
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "hashmap.h"
#include <sstream>
using namespace std;



void resuelveCaso() {
	set<int> conjunto;
	int n,aux;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		conjunto.insert(aux);
	}
	auto it = conjunto.busca(5);
	while (it != conjunto.end()) {
		cout << *it << ' ';
		++it;
	}
	cout << endl;
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}