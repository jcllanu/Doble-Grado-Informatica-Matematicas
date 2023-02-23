
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
using namespace std;


void relajar(AristaDirigida<long long int> const& a, vector<long long int> & distancias, IndexPQ<long long int> & pq, vector<long long int> & numCaminos) {
	if (distancias[a.hasta()] > distancias[a.desde()] + a.valor()) {
		distancias[a.hasta()] = distancias[a.desde()] + a.valor();
		pq.update(a.hasta(), distancias[a.desde()] + a.valor());
		numCaminos[a.hasta()] = numCaminos[a.desde()];
	}
	else if (distancias[a.hasta()] == distancias[a.desde()] + a.valor()) {
		numCaminos[a.hasta()] += numCaminos[a.desde()];
	}
}

bool resuelveCaso() {
	long long int V, E;
	cin >> V >> E;
	if (!cin)
		return false;
	long long int ini, fin, valor;
	AristaDirigida<long long int> a;
	DigrafoValorado<long long int> dg(V);
	vector<long long int> numCaminos(V,0);
	for (long long int i = 0; i < E; i++) {
		cin >> ini >> fin >> valor;
		a = AristaDirigida<long long int>(ini-1, fin-1, valor);
		dg.ponArista(a);
		a = AristaDirigida<long long int>(fin - 1, ini - 1, valor);
		dg.ponArista(a);
	}
	vector<long long int> distancias(V, INT_MAX);
	distancias[0] = 0;
	numCaminos[0] = 1;
	IndexPQ<long long int> pq(V);
	pq.push(0, distancias[0]);
	while (!pq.empty()) {
		auto v = pq.top();
		pq.pop();
		for (auto a : dg.ady(v.elem)) {
			relajar(a, distancias, pq, numCaminos);
		}
	}
	
	cout << numCaminos[V-1] << '\n';
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
