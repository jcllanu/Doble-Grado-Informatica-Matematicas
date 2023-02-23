
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "dequeHeredada.h"
#include "colaDoble.h"

using namespace std;


void resuelveCaso() {

	ColaMezclar<int> cola1;
	ColaMezclar<int> cola2;
	int n, aux;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		cola1.push_back(aux);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		cola2.push_back(aux);
	}
	cola1.entremezclar(cola2);
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
