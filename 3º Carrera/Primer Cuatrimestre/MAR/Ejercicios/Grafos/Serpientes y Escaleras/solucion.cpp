
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool resuelveCaso() {
	long long int N,K,S,E;
	cin >> N >> K >> S >> E;
	if (N == 0 && K == 0 && S == 0 && E == 0) {
		return false;
	}

	unordered_map<long long int, long long int> serp_esc;
	long long int ini, fin;
	for (long long int i = 0; i < E + S; i++) {
		cin >> ini >> fin;
		serp_esc[ini] = fin;
	}

	vector<bool> visitado(N*N, false);
	queue<pair<long long int,long long int>> cola; // El primer campo es la casilla y el segundo es el numero de tiradas para llegar a ella
	cola.push({ 1,0 });
	while (!cola.empty()) {
		auto par = cola.front();
		cola.pop();
		for (long long int i = 1; i <= K; i++) {
			long long int nuevaCasilla = par.first + i;
			if (nuevaCasilla <= N*N) {
				if (nuevaCasilla == N * N) {
					cout << par.second + 1 << '\n';
					return true;
				}
				if (serp_esc.count(nuevaCasilla) == 0) {
					if (!visitado[nuevaCasilla-1]) {
						cola.push({ nuevaCasilla,par.second + 1 });
						visitado[nuevaCasilla-1] = true;
					}
				}
				else {
					if (!visitado[serp_esc[nuevaCasilla]-1]) {
						cola.push({ serp_esc[nuevaCasilla],par.second + 1 });
						visitado[serp_esc[nuevaCasilla]-1] = true;
					}
				}
			}
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
