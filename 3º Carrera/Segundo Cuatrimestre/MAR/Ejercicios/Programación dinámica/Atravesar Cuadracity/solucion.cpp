
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;



bool resuelveCaso() {
	long long int N, M;
	cin >> N >> M;
	if (!cin)
		return false;

	char aux;
	vector<vector<bool>> mapa(N, vector<bool>(M));
	vector<vector<long long int>> formas(N, vector<long long int>(M));

	for (int i = 0; i < N; i++) {
		cin.get(aux);
		for (int j = 0; j < M; j++) {
			cin.get(aux);
			mapa[i][j] = (aux == '.');
		}
	}
	formas[N - 1][M - 1] = 1;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 0; j--) {
			if (i != N - 1 || j != M - 1) {
				if (!mapa[i][j]) {
					formas[i][j] = 0;
				}
				else {
					if (i == N - 1) {
						formas[i][j] = formas[i][j + 1];
					}
					else if (j == M - 1) {
						formas[i][j] = formas[i + 1][j];
					}
					else {
						formas[i][j] = formas[i + 1][j] + formas[i][j + 1];
					}
				}
			}
		}
	}
	
	cout << formas[0][0] << '\n';
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
