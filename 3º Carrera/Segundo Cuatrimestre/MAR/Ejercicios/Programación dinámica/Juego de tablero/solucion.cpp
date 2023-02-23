
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
	vector<vector<int>> tablero(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tablero[i][j];
		}
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <N; j++) {
			int maximo = tablero[i - 1][j];
			if (j - 1 >= 0) {
				maximo = max(maximo, tablero[i - 1][j - 1]);
			}
			if (j + 1 < N) {
				maximo = max(maximo, tablero[i - 1][j + 1]);
			}
			tablero[i][j] += maximo;
		}
	}
	int maxSuma = tablero[N - 1][0];
	int index = 0;
	for (int j = 1; j < N; j++) {
		if (tablero[N - 1][j] > maxSuma) {
			maxSuma = tablero[N - 1][j];
			index = j;
		}
	}
	cout << maxSuma << ' ' << index + 1 << '\n';
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