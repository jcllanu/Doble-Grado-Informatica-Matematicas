
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)
		return false;

	vector<vector<int>> precios(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			precios[i][j] = INT_MAX;
		}
		precios[i][i] = 0;
		for (int j = i + 1; j < N; j++) {
			cin >> precios[i][j];
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int aux = precios[i][k] + precios[k][j];
				if (precios[i][k] == INT_MAX || precios[k][j] == INT_MAX) {
					aux = INT_MAX;
				}
				if (aux < precios[i][j]) {
					precios[i][j] = aux;
				}
			}
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			cout << precios[i][j];
			if (j != N - 1) {
				cout << ' ';
			}
		}
		cout << '\n';
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
