
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

bool resuelveCaso() {
	long long int V, S, puntos;
	cin >> V >> S;
	if (!cin)
		return false;
	vector<int> puntuaciones;
	for (long long int i = 0; i < S; i++) {
		cin >> puntos;
		puntuaciones.push_back(puntos);
	}
	vector<int> minTiradas;

	minTiradas.push_back(0);
	for (int j = 1; j <= V; j++) {
		minTiradas.push_back(INT_MAX);
	}
	
	for (int i = 1; i <= S; i++) {
		for (int j = 1; j <=V; j++) {
			if (puntuaciones[i - 1] > j) {
				minTiradas[j] = minTiradas[j];
			}
			else {
				if (minTiradas[j - puntuaciones[i - 1]] == INT_MAX) {
					minTiradas[j] = minTiradas[j];
				}
				else {
					minTiradas[j] = min(minTiradas[j], 1 + minTiradas[j - puntuaciones[i - 1]]);
				}
			}
		}
	}
	if (minTiradas[V]== INT_MAX) {
		cout << "Imposible\n";
	}
	else {
		cout << minTiradas[V] << ':';
		int j = V;
		int i = S;
		while (j > 0) {
			if (puntuaciones[i - 1] <= j && minTiradas[j] == 1 + minTiradas[j - puntuaciones[i - 1]]) {
				cout << ' ' << puntuaciones[i - 1];
				j -= puntuaciones[i - 1];
			}
			else {
				i--;
			}
		}
		cout<< '\n';
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