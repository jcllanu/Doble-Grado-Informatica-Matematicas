
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include"lista.h"

using namespace std;


bool resuelveCaso() {
	list<int> lista;
	int nAlumnos, nSalta;
	cin >> nAlumnos >> nSalta;
	if (nAlumnos==0 && nSalta==0) {
		return false;
	}
	for (int i = 0; i < nAlumnos; i++) {
		lista.push_back(i+1);
	}
	auto it = lista.begin();
	while (lista.size() != 1) {
		for (int i = 0; i < nSalta; ++i) {
			++it;
			if (it == lista.end()) {
				it = lista.begin();
			}
		}
		it=lista.erase(it);
		if (it == lista.end()) {
			it = lista.begin();
		}
	}
	cout << lista.front() << '\n';
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
