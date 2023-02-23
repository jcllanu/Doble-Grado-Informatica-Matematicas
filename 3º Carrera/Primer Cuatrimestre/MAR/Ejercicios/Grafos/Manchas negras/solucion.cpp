
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "Grafo.h"
#include <string>
#include <vector>
using namespace std;


void dfs(Grafo const& g, long long int v, vector<bool> &marcado, long long int anterior, long long int& personasNuevas) {
	if (!marcado[v]) {
		marcado[v] = true;
		personasNuevas++;
		for (long long int w : g.ady(v)) {
			if (w != anterior) {
				dfs(g, w, marcado, v, personasNuevas);
			}
		}
	}
}

bool resuelveCaso() {
	long long int F,C;
	cin >> F >> C;
	if (!cin)
		return false;
	char a;
	
	vector<vector<int>> tabla(F, vector<int>(C));
	long long int V = 0;
	for (long long int i = 0; i < F; i++) {
		cin.get(a);
		for (long long int j = 0; j < C; j++) {
			cin.get(a);
			if (a == '#') {
				tabla[i][j] = V;
				V++;
			}else {
				tabla[i][j] = -1;
			}
		}
	}
	Grafo g(V);
	for (long long int i = 0; i < F; i++) {
		for (long long int j = 0; j < C; j++) {
			if (tabla[i][j] != -1) {
				if (i!=0 && tabla[i - 1][j] != -1) {
					g.ponArista(tabla[i][j], tabla[i - 1][j]);
				}
				if (j!=0 && tabla[i][j - 1] != -1) {
					g.ponArista(tabla[i][j], tabla[i][j - 1]);
				}
			}
		}
	}
	
	/*

	for (long long int i = 0; i < F; i++) {
		cin.get(a);
		for (long long int j = 0; j < C; j++) {
			cin.get(a);
			if (i == 0) {
				fila_anterior.push_back(a);
				if (j != 0) {
					if (a == '#' && fila_anterior[j - 1] == '#') {
						g.ponArista(i*C + j, i*C + j - 1);
					}
				}
			}
			else {
				if (a == '#' && fila_anterior[j]== '#') {
					g.ponArista(i*C + j, (i - 1)*C + j);
				}
				fila_anterior[j] = a;
				if (j != 0) {
					if (a == '#' && fila_anterior[j - 1] == '#') {
						g.ponArista(i*C + j, i*C + j-1);
					}
				}
			}
			
		}
	}*/
	vector<bool> marcado(V, false);
	long long int maxPersonas = 0;
	long long int num_componentes = 0;
	for (int i = 0; i < V; i++) {
		if (!marcado[i]) {
			num_componentes++;
			long long int personasNuevas = 0;
			dfs(g, i, marcado, i, personasNuevas);
			maxPersonas = max(maxPersonas, personasNuevas);
		}
	}
	cout << num_componentes <<' '<< maxPersonas << '\n';
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
