
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

bool resuelveCaso() {
	long long int L, N, c;
	cin >> L >> N;
	if (L==0 && N==0)
		return false;

	vector<long long int> cortes;
	cortes.push_back(0);
	for (long long int i = 0; i < N; i++) {
		cin >> c;
		cortes.push_back(c);
	}
	cortes.push_back(L);
	long long int n = N + 2;
	vector<vector<long long int>> MinCostes(n, vector<long long int>(n));
	for (long long int i = 0; i < n-1; i++) {
		MinCostes[i][i+1] = 0;
	}
	for (long long int d = 2; d < n; d++) {
		for (long long int i = 0; i < n - d; i++) {
			long long int j = i + d;
			MinCostes[i][j] = INT_MAX;
			for (long long int k = i + 1; k < j; k++) {
				long long int aux = MinCostes[i][k] + MinCostes[k][j] + 2 * (cortes[j] - cortes[i]);
				if (MinCostes[i][k] == INT_MAX || MinCostes[k + 1][j] == INT_MAX) {
					aux = INT_MAX;
				}
				if (aux < MinCostes[i][j]) {
					MinCostes[i][j] = aux;
				}
			}
		}
	}
	cout << MinCostes[0][n - 1] << '\n';
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