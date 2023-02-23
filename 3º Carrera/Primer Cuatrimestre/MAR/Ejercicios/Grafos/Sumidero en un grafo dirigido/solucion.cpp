
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Digrafo.h"
#include <string>
#include <vector>
#include <stack>
using namespace std;


/*
void dfs(Digrafo const& g, long long int v, vector<bool> &marcado, stack<long long int>& pila) {
	marcado[v] = true;
	for (long long int w : g.ady(v)) {
		if (!marcado[w]) {
			dfs(g, w, marcado, pila);
		}
	}
	pila.push(v);
}
bool tiene_ciclos(Digrafo const& g, long long int v, vector<bool> &marcado, vector<bool>& visitado) {
	visitado[v] = true;
	marcado[v] = true;
	for (long long int w : g.ady(v)) {
		if (marcado[w]) {
			return true;
		}
		else{
			if (tiene_ciclos(g, w, marcado, visitado)) {
				return true;
			}
		}

	}
	marcado[v] = false;
	return false;
}
*/
bool resuelveCaso() {
	long long int V,E,ini,fin;
	cin >> V >> E;
	if (!cin)
		return false;
	
	Digrafo g(V);
	for (long long int i = 0; i < E; i++) {
		cin >> ini>> fin;
		g.ponArista(ini, fin);
	}

	long long int sumidero=-1;
	for (long long int i = 0; i < V; i++) {
		if (g.ady(i).empty()) {
			sumidero = i;
			break;
		}
	}
	if (sumidero == -1) {
		cout << "NO\n";
		return true;
	}
	if (g.inverso().ady(sumidero).size() == V - 1) {
		cout << "SI " << sumidero << '\n';
	}
	else {
		cout << "NO\n";
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
