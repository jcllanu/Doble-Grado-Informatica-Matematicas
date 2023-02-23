
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
using namespace std;

bool resuelveCaso() {
	long long int V, E;
	cin >> V >> E;
	if (!cin)
		return false;
	PriorityQueue<Arista<long long int>> pq;
	Arista<long long int> a;
	long long int ini, fin, valor;
	for (long long int i = 0; i < E; i++) {
		cin >> ini >> fin >> valor;
		a = Arista<long long int>(ini-1,fin-1,valor);
		pq.push(a);
	}
	ConjuntosDisjuntos componentes(V);
	long long int i = 0;
	long long int costeTotal = 0;
	while (!pq.empty() && i < V-1) {
		Arista<long long int> a = pq.top();
		pq.pop();
		long long int v = a.uno(), w = a.otro(a.uno());
		if (!componentes.unidos(v,w)){
			componentes.unir(v, w);
			costeTotal += a.valor();
			i++;
		}
	}
	if (componentes.num_cjtos()> 1) {
		cout << "No hay puentes suficientes";
	}
	else {
		cout << costeTotal;
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
