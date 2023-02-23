
// Juan Carlos Llamas

#include <iostream>
#include <fstream>
#include "set.h"

using namespace std;



bool resuelveCaso() {
	set<int> conjunto;
	int N, aux, M, lower, upper;
	cin >> N >> M;
	if (!cin) {
		return false;
	}
	for (int i = 0; i < N; i++) {
		cin >> aux;
		conjunto.insert(aux);
	}
	for (int i = 0; i < M; i++) {
		cin >> lower >> upper;
		cout << conjunto.count_interval(lower, upper) << '\n';
		
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
	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}