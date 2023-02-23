
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Grafo.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



void dfs(Grafo const& g, long long int v, vector<pair<bool, long long int>> &marcado, long long int anterior, long long int& elementos, long long int inicioRecorrido) {
	if (!marcado[v].first) {
		marcado[v].first = true;
		marcado[v].second = inicioRecorrido;
		elementos++;
		for (long long int w : g.ady(v)) {
			if (w != anterior) {
				dfs(g, w, marcado, v, elementos, inicioRecorrido);
			}
		}
	}
}

bool resuelveCaso() {
	long long int V,numGrupos, numParticipantes,ini,fin;
	cin >> V >> numGrupos;
	if (!cin)
		return false;
	
	Grafo g(V);
	for (long long int i = 0; i < numGrupos; i++) {
		cin >> numParticipantes;
		for (int j = 0; j < numParticipantes; j++) {
			cin >> fin;
			if (j != 0) {
				g.ponArista(ini-1, fin-1);
			}
			ini = fin;
		}
	}
	vector<pair<bool, long long int>> marcado(V, { false,-1 });//La primera componente es si el nodo ha sido visitado y la segunda 
	//es el elemento por el que se empezó el recorrido en esa componenete conexa

	unordered_map<int, int> mapa;//indica para cada nodo origen de un recorrido el numero de elemtos de su componente conexa
	for (int i = 0; i < V; i++) {
		long long int elementos = 0;
		if (!marcado[i].first) {
			dfs(g, i, marcado, i, elementos, i);
			mapa[i] = elementos;
			cout << elementos << ' ';
		}
		else {
			cout << mapa[marcado[i].second] << ' ';
		}
	}
	cout << '\n';
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
