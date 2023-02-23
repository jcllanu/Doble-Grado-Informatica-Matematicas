
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "TreeSet_AVL.h"

using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	Set<int> conjunto;
	int aux;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		conjunto.insert(aux);
	}
	
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> aux;
		try {
			cout << conjunto.kesimo(aux) << '\n';
		}
		catch (std::domain_error e) {
			cout << "??\n";
		}
	}
	cout << "---\n";
	return true;
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while(resuelveCaso());
	


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
