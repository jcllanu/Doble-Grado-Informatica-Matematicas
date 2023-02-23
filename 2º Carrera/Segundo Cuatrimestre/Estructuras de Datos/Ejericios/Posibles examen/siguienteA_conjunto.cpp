
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintreeHeredada.h"
#include "set.h"
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <queue>
#include <cmath>
#include <list>
using namespace std;




void resuelveCaso() {
	set<int> conjunto;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int aux;
		cin >> aux;
		conjunto.insert(aux);
	}
	int k;
	cin >> k;
	cout << "El siguiente a " << k << " es: ";
	pair<int, bool> sol = conjunto.siguiente_a(k);
	cout << (sol.second ? to_string(sol.first) : "No hay");
	cout << endl;
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
