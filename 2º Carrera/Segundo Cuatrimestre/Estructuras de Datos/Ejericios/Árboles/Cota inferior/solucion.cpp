
// Juan Carlos Llamas

#include <iostream>
#include <fstream>
#include "set.h"

using namespace std;



bool resuelveCaso() {
	set<int> conjunto;
	int N, aux, M;
	cin >> N;
	if (N == 0) {
		return false;
	}
	for (int i = 0; i < N; i++) {
		cin >> aux;
		conjunto.insert(aux);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> aux;
		auto solucion = conjunto.lower_bound(aux);
		if (solucion.first) {
			cout << solucion.second << '\n';
		}
		else {
			cout << "NO HAY\n";
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
	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}