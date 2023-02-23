
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Grafo.h"
#include <string>
#include <vector>
using namespace std;


bool dfs(Grafo const& g, long long int v, vector<bool> &marcado, long long int anterior) {
	if (marcado[v])
		return false;
	marcado[v] = true;
	for (long long int w : g.ady(v)) {
		if (w!=anterior) {
			if (!dfs(g, w, marcado, v)) {
				return false;
			}
		}
	}
	return true;
}
bool resuelveCaso() {
	long long int V, E, ini, fin;

	cin >> V >> E;
	if (!cin)
		return false;

	Grafo g(V);
	for (long long int i = 0; i < E; i++) {
		cin >> ini >> fin;
		g.ponArista(ini, fin);
	}
	vector<bool> marcado(V, false);
	
	if (!dfs(g, 0, marcado, 0)) {
		cout << "NO\n";
		
	}
	else {
		for (bool b : marcado) {
			if (!b) {
				cout << "NO\n";
				return true;
			}
		}
		cout << "SI\n";
	}
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
