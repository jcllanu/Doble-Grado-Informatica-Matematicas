
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "colaHeredada.h"
#include"queue.h"

using namespace std;


void resuelveCaso() {

	ColaMezclar<int> cola1;
	ColaMezclar<int> cola2;
	int aux;
	cin >> aux;
	while (aux != 0) {
		cola1.push(aux);
		cin >> aux;
	}
	cin >> aux;
	while (aux != 0) {
		cola2.push(aux);
		cin >> aux;
	}
	
	cola1.mezclar(cola2);
	cola1.print();
	
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
