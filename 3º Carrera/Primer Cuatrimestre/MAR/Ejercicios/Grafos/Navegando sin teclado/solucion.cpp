
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
#include <unordered_map>
using namespace std;


void relajar(AristaDirigida<long long int> const& a, vector<long long int> & distancias, IndexPQ<long long int> & pq) {
	if (distancias[a.hasta()] > distancias[a.desde()] + a.valor()) {
		distancias[a.hasta()] = distancias[a.desde()] + a.valor();
		pq.update(a.hasta(), distancias[a.desde()] + a.valor());
	}
}

bool resuelveCaso() {
	long long int V, E;
	cin >> V;
	if (V==0)
		return false;
	unordered_map<long long int, long long int> tcarga;
	for (long long int i = 0; i < V; i++) {
		cin >> tcarga[i];
	}
	cin >> E;
	long long int ini, fin, valor;
	AristaDirigida<long long int> a;
	DigrafoValorado<long long int> dg(V);
	for (long long int i = 0; i < E; i++) {
		cin >> ini >> fin >> valor;
		a = AristaDirigida<long long int>(ini-1, fin-1, valor + tcarga[fin - 1]);
		dg.ponArista(a);
	}
	vector<long long int> distancias(V, INT_MAX);
	distancias[0] = tcarga[0];
	IndexPQ<long long int> pq(V);
	pq.push(0, distancias[0]);
	while (!pq.empty()) {
		auto v = pq.top();
		pq.pop();
		for (auto a : dg.ady(v.elem)) {
			relajar(a, distancias, pq);
		}
		if (v.elem == V - 1) {
			cout << distancias[V - 1] << '\n';
			return true;
		}
	}

	cout <<"IMPOSIBLE" << '\n';
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
