
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Grafo.h"
#include <string>
#include <vector>
using namespace std;


void dfs(Grafo const& g, long long int v, vector<bool> &marcado, long long int anterior, long long int& personasNuevas) {
	if (!marcado[v]) {
		marcado[v] = true;
		personasNuevas++;
		for (long long int w : g.ady(v)) {
			if (w != anterior) {
				dfs(g, w, marcado, v, personasNuevas);
			}
		}
	}
}

void resuelveCaso() {
	long long int V, E, ini, fin;
	cin >> V >> E;
	Grafo g(V);
	for (long long int i = 0; i < E; i++) {
		cin >> ini >> fin;
		g.ponArista(ini-1, fin-1);
	}
	vector<bool> marcado(V, false);
	long long int maxPersonas = 0;
	for (int i = 0; i < V; i++) {
		if (!marcado[i]) {
			long long int personasNuevas = 0;
			dfs(g, i, marcado, i, personasNuevas);
			maxPersonas = max(maxPersonas, personasNuevas);
		}
	}
	cout << maxPersonas << '\n';
	
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
