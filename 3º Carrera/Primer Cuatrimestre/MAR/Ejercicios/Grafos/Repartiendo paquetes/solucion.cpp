
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
#include <queue>
using namespace std;

void relajar(AristaDirigida<long long int> const& a, vector<long long int> & distancias, IndexPQ<long long int> & pq) {
	if (distancias[a.hasta()] > distancias[a.desde()] + a.valor()) {
		distancias[a.hasta()] = distancias[a.desde()] + a.valor();
		pq.update(a.hasta(), distancias[a.desde()] + a.valor());
	}
}

void dijkstra(DigrafoValorado<long long int> const& dg, long long int origen, vector<long long int> & distancias) {
	distancias = vector<long long int>(dg.V(), INT_MAX);
	IndexPQ<long long int> pq(dg.V());
	distancias[origen] = 0;
	pq.push(origen, distancias[origen]);

	while (!pq.empty()) {
		auto v = pq.top();
		pq.pop();
		for (auto a : dg.ady(v.elem)) {
			relajar(a, distancias, pq);
		}
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
	DigrafoValorado<long long int> dgtrasp(V);
	for (long long int i = 0; i < E; i++) {
		cin >> ini >> fin >> valor;
		a = AristaDirigida<long long int>(ini-1, fin-1, valor);
		dg.ponArista(a);
		a = AristaDirigida<long long int>(fin - 1, ini - 1, valor);
		dgtrasp.ponArista(a);
	}

	long long int origen, P;
	long long int esfuerzoTotal = 0;
	cin >> origen >> P;
	origen--;

	vector<long long int> distancias_desde_origen;
	vector<long long int> distancias_hacia_origen;
	dijkstra(dg, origen, distancias_desde_origen);
	dijkstra(dgtrasp, origen, distancias_hacia_origen);

	bool posible = true;
	for (long long int i = 0; i < P; i++) {
		long long int destino;
		cin >> destino;
		destino--;
		if (posible) {
			if (distancias_desde_origen[destino] == INT_MAX) {
				posible = false;
			}
			else {
				esfuerzoTotal += distancias_desde_origen[destino];
			}
			if (distancias_hacia_origen[destino] == INT_MAX) {
				posible = false;
			}
			else {
				esfuerzoTotal += distancias_hacia_origen[destino];
			}
		}
	}

	if (posible) {
		cout << esfuerzoTotal << '\n';
	}
	else {
		cout << "Imposible\n";
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
