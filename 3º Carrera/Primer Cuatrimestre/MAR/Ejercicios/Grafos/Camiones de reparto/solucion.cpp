
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"

using namespace std;

bool puedoLlegar(long long int ini, long long int dest, GrafoValorado<long long int> const& g, long long int anchCamion, vector<bool>& visitado) {
	if (!visitado[ini]) {
		visitado[ini] = true;
		for (Arista<long long int> a : g.ady(ini)) {
			if (anchCamion <= a.valor()) {
				if (a.otro(ini) == dest) {
					return true;
				}
				else if (puedoLlegar(a.otro(ini), dest, g, anchCamion, visitado)) {
					return true;
				}
			}
		}
	}
	return false;
}


bool resuelveCaso() {
	long long int V, E, ini, fin, anchura;
	cin >> V >> E;
	if (!cin) {
		return false;
	}
	GrafoValorado<long long int> g(V);
	for (long long int i = 0; i < E; i++) {
		cin >> ini >> fin >> anchura;
		g.ponArista(Arista<long long int>(ini-1, fin-1, anchura));
	}
	long long int K,inicio, destino, anchCamion;
	cin >> K;
	for (long long int i = 0; i < K; i++) {
		cin >> inicio >> destino >> anchCamion;
		inicio--;
		destino--;
		vector<bool>visitado(V, false);
		if (puedoLlegar(inicio, destino, g, anchCamion,visitado)) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
	}
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
