
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

bool resuelveCaso() {
	int N, PMin, PMax;
	cin >> N >> PMax >> PMin;
	if (!cin)
		return false;
	vector<int> potencias (N);
	vector<int> costes (N);

	for (int i = 0; i < N; i++) {
		cin >> potencias[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> costes[i];
	}

	vector<int> MinCoste;
	MinCoste.push_back(0);
	for (int j = 1; j <= PMax; j++) {
		MinCoste.push_back(INT_MAX);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= PMax; j++) {
			if (potencias[i - 1] > j) {
				MinCoste[j] = MinCoste[j];
			}
			else {
				if (MinCoste[max(0, j - potencias[i - 1])] == INT_MAX) {
					MinCoste[j] = MinCoste[j];
				}
				else {
					MinCoste[j] = min(MinCoste[j], MinCoste[max(0, j - potencias[i - 1])] + costes[i - 1]);
				}
			}
		}
	}
	int index = PMin;
	int minimo = MinCoste[PMin];
	for (int j = PMin + 1; j <= PMax; j++) {
		if (MinCoste[j] < minimo) {
			minimo = MinCoste[j];
			index = j;
		}
	}
	if (minimo == INT_MAX) {
		cout << "IMPOSIBLE\n";
	}
	else {
		cout << minimo << ' ' << index << '\n';
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