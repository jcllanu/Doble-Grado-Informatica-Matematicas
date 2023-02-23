
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Grafo.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef enum Cruce{Guardia, NoGuardia, NoVisitado};
void dfs(Grafo const& g, long long int v, vector<Cruce> & cruces, bool & esPosible, long long int & numGuardias, Cruce anterior, long long int & visitados) {
	if ((cruces[v] == Guardia && anterior == Guardia) || (cruces[v] == NoGuardia && anterior == NoGuardia)) {
		esPosible = false;
		return;
	}
	if ((cruces[v] == Guardia && anterior == NoGuardia) || (cruces[v] == NoGuardia && anterior == Guardia)) {
		return;
	}
	if (cruces[v] == NoVisitado) {
		visitados++;
		Cruce actual;
		if (anterior == Guardia) {
			actual = NoGuardia;
		}
		else {
			actual = Guardia;
			numGuardias++;
		}
		cruces[v] = actual;
		for (auto w : g.ady(v)) {
			dfs(g, w, cruces, esPosible, numGuardias, actual, visitados);
		}
	}
}

bool resuelveCaso() {
	long long int V, E, ini, fin;
	cin >> V >> E;
	if (!cin)
		return false;

	Grafo g(V);
	for (long long int i = 0; i < E; i++) {
		cin >> ini >> fin;
		g.ponArista(ini - 1, fin - 1);
	}
	vector<Cruce> cruces(V, NoVisitado);
	long long int numTotalGuardias = 0;
	long long int numGuardias = 0;
	long long int visitados = 0;
	bool esPosible = true;
	for (int i = 0; i < V; i++) {
		if (cruces[i] == NoVisitado) {
			dfs(g, i, cruces, esPosible, numGuardias, Guardia, visitados);
			if (!esPosible) {
				cout << "IMPOSIBLE\n";
				return true;
			}
			numTotalGuardias += min(numGuardias, visitados - numGuardias);
			numGuardias = 0;
			visitados = 0;
		}
	}
	cout << numTotalGuardias << '\n';
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
