
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "colaHeredada.h"
#include"queue.h"

using namespace std;


bool resuelveCaso() {
	ColaInsertar<int> cola;
	ColaInsertar<int> insert;
	int N, aux,M,P;
	cin >> N;
	if (!cin) {
		return false;
	}
	for (int i = 0; i < N; i++) {
		cin >> aux;
		cola.push(aux);
	}
	cin >> M >> P;
	for (int i = 0; i < M; i++) {
		cin >> aux;
		insert.push(aux);
	}
	cola.insertar(insert,P);
	cola.print();
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
