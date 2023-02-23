
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Grafo.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;


/*
void dfs(Grafo const& g, long long int v, vector<pair<bool, long long int>> &marcado, long long int anterior, long long int TTL, long long int& alcanzados) {
	if (!marcado[v].first) {
		alcanzados++;
	}
	if (!marcado[v].first || marcado[v].first && marcado[v].second<TTL) {
		marcado[v].first = true;
		marcado[v].second = TTL;
		for (long long int w : g.ady(v)) {
			if (w != anterior) {
				if (TTL != 0) {
					dfs(g, w, marcado, v, TTL-1, alcanzados);
				}
			}
		}
	}
}*/

bool resuelveCaso() {
	long long int V,E,ini,fin;
	cin >> V >> E;
	if (!cin)
		return false;
	
	Grafo g(V);
	for (long long int i = 0; i < E; i++) {
		cin >> ini>> fin;
		g.ponArista(ini-1, fin-1);
			
	}
	long long int K, nodoInicial, TTL;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> nodoInicial >> TTL;
		nodoInicial--;
		vector<bool> marcado(V, false);
		long long int alcanzados = 0;
		queue<pair<long long int,long long int>> cola;//El primer campo es el nodo y el segundoi es la TTL con la que llega
		cola.push({ nodoInicial,TTL });
		marcado[nodoInicial] = true;
		while (!cola.empty()) {
			auto actual = cola.front();
			cola.pop();
			for (long long int w : g.ady(actual.first)) {
				if (!marcado[w] && actual.second!=0) {
					cola.push({ w,actual.second - 1 });
					marcado[w] = true;
				}
			}
			alcanzados++;
		}
		cout << V - alcanzados << '\n';
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
	/*int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}*/
	while (resuelveCaso());


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
