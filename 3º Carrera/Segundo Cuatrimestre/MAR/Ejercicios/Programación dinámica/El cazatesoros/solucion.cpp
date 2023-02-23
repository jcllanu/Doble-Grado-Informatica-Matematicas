
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

bool resuelveCaso() {
	int T, N;
	cin >> T >> N;
	if (!cin)
		return false;

	vector<int> profundidad (N);
	vector<int> oro (N);

	for (int i = 0; i < N; i++) {
		cin >> profundidad[i] >> oro[i];
	}

	vector<vector<int>> MaxOro(N+1, vector<int>(T+1));
	for (int j = 0; j <= T; j++) {
		MaxOro[0][j] = 0;
	}
	for (int i = 0; i <= N; i++) {
		MaxOro[i][0] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = T; j >=1; j--) {
			if (3 * profundidad[i - 1] > j) {
				MaxOro[i][j] = MaxOro[i-1][j];
			}
			else {
				MaxOro[i][j] = max(MaxOro[i-1][j], MaxOro[i-1][j - 3 * profundidad[i - 1]] + oro[i - 1]);
			}
		}
	}
	cout << MaxOro[N][T] << '\n';
	int j = T;
	int i = N;
	vector<int> aux;
	while (j > 0 && i > 0) {
		if (3* profundidad[i - 1] <= j && MaxOro[i][j] == MaxOro[i-1][j - 3 * profundidad[i - 1]] + oro[i - 1]) {
			aux.push_back(i);
			j -= 3*profundidad[i - 1];
		}
		i--;
	}
	cout << aux.size() << '\n';
	for (int k = aux.size() - 1; k >= 0; k--) {
		int i = aux[k];
		cout << profundidad[i - 1] << ' ' << oro[i - 1] << '\n';
	}
	cout << "---\n";
	
	
	
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