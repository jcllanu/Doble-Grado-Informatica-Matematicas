
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
	if (N==0)
		return false;

	vector<int> cubos(N);
	for (int i = 0; i < N; i++) {
		cin >> cubos[i];
	}

	vector<vector<int>> CantMaxima(N + 1, vector<int>(N + 1));
	
	for (int i = 0; i <= N; i++) {
		CantMaxima[i][i] = 0;
		if (i < N) {
			CantMaxima[i][i + 1] = cubos[i];
		}
	}

	for (int d = 2; d <= N; d++) {
		for (int i = 0; i <= N - d; i++) {
			int j = i + d;
			int comeDerecha;
			int comeIzquierda;
			//Come Izquierda (cubo[i])
			if (cubos[i + 1] >= cubos[j - 1]) {
				//Devoradora come izquierda
				comeIzquierda = CantMaxima[i + 2][j] + cubos[i];
			}
			else {
				//Devoradora come derecha
				comeIzquierda = CantMaxima[i + 1][j - 1] + cubos[i];
			}

			//Come Derecha (cubo[j-1])
			if (cubos[i] >= cubos[j - 2]) {
				//Devoradora come izquierda
				comeDerecha = CantMaxima[i + 1][j - 1] + cubos[j - 1];
			}
			else {
				//Devoradora come derecha
				comeDerecha = CantMaxima[i][j - 2] + cubos[j - 1];
			}

			CantMaxima[i][j] = max(comeDerecha, comeIzquierda);
		}
	}
	cout << CantMaxima[0][N] << '\n';
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
