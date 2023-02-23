
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "colaHeredada.h"
#include"queue.h"

using namespace std;


bool resuelveCaso() {
	ColaInvertir<int> cola;
	int aux;
	cin >> aux;
	if (!cin) {
		return false;
	}
	while (aux != 0) {
		cola.push(aux);
		cin >> aux;
	}
	cola.invertir();
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
