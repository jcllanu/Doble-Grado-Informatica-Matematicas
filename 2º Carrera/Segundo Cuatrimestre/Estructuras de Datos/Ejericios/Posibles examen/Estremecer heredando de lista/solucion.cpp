
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "dequeHeredada.h"
#include <string>

using namespace std;


bool resuelveCaso() {
	int N, aux;
	cin >> N;
	ListaEstremecer<int> l;
	if(!cin)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> aux;
		l.push_back(aux);
	}
	l.estremecer();
	l.print();

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
