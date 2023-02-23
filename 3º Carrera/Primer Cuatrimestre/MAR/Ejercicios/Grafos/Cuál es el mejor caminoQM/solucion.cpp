
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


void relajar(AristaDirigida<long long int> const& a, vector<long long int> & distancias, IndexPQ<long long int> & pq, vector<long long int> & numCalles) {
	if (distancias[a.hasta()] > distancias[a.desde()] + a.valor()) {//Mejoramos la distancia
		distancias[a.hasta()] = distancias[a.desde()] + a.valor();
		pq.update(a.hasta(), distancias[a.desde()] + a.valor());
		numCalles[a.hasta()] = numCalles[a.desde()] + 1;
		
	}
	else if (distancias[a.hasta()] == distancias[a.desde()] + a.valor()) {//Podemos cambiar de camino manteniendo la distancia
		numCalles[a.hasta()] = min(numCalles[a.hasta()], numCalles[a.desde()] + 1);
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
	for (long long int i = 0; i < E; i++) {
		cin >> ini >> fin >> valor;
		a = AristaDirigida<long long int>(ini-1, fin-1, valor);
		dg.ponArista(a);
		a = AristaDirigida<long long int>(fin - 1, ini - 1, valor);
		dg.ponArista(a);
	}

	
	long long int K;
	cin >> K;
	for (long long int i = 0; i < K; i++) {
		long long int origen, destino;
		cin >> origen >> destino;
		origen--;
		destino--;

		vector<long long int> distancias(V, INT_MAX);
		vector<long long int> numCalles(V, INT_MAX);
		vector<bool> llego_en_min(V, true);
		IndexPQ<long long int> pq(V);

		distancias[origen] = 0;
		numCalles[origen] = 0;
		pq.push(origen, distancias[origen]);

		while (!pq.empty()) {
			auto v = pq.top();
			pq.pop();
			for (auto a : dg.ady(v.elem)) {
				relajar(a, distancias, pq, numCalles);
			}
		}
		
		if (distancias[destino] == INT_MAX) {
			cout << "SIN CAMINO";
		}
		else {
			cout << distancias[destino];

			vector<bool> visitado(V, false);
			queue<pair<long long int,long long int>> cola;//El primero es el vértice y el segundo la distancia al origen en numero de calles
			cola.push({ origen,0 });
			bool salir = false;
			while (!cola.empty() && !salir) {
				auto v = cola.front();
				cola.pop();
				visitado[v.first] = true;
				if (v.first == destino) {
					salir = true;
					if (v.second >= numCalles[destino]) {
						cout << " SI";
					}
					else {
						cout << " NO";
					}
				}
				else {
					for (auto a : dg.ady(v.first)) {
						if (!visitado[a.hasta()]) {
							cola.push({ a.hasta(),v.second + 1 });
						}
					}
				}

			}
		}
		cout << '\n';
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
