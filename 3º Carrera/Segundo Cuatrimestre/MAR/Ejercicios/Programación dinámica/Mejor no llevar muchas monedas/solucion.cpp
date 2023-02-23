
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

struct tMoneda {
	 int valor, numero;
};

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)
		return false;

	vector<tMoneda> tipos(N);
	for (int i = 0; i < N; i++) {
		cin >> tipos[i].valor;
	}
	
	for (int i = 0; i < N; i++) {
		cin >> tipos[i].numero;	
	}
	reverse(tipos.begin(), tipos.end());
	int C;
	cin >> C;

	vector<vector<int>> monedas(N + 1, vector<int>(C + 1));
	
	for (int i = 0; i <= N; i++) {
		monedas[i][0] = 0;
	}

	for (int j = 1; j <= C; j++) {
		monedas[0][j] = INT_MAX;
	}
	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= C; j++) {
			 int minimoMonedas = INT_MAX;
			for (int k = 0; k <= tipos[i - 1].numero && k*tipos[i - 1].valor <= j; k++) {
				if (monedas[i-1][j- k * tipos[i - 1].valor] != INT_MAX) {
					minimoMonedas = min(monedas[i - 1][j - k * tipos[i - 1].valor] + k, minimoMonedas);
				}
				
			}
			monedas[i][j] = minimoMonedas;
		}
	}
	if (monedas[N][C] == INT_MAX) {
		cout << "NO\n";
	}
	else {
		cout << "SI "<< monedas[N][C] << '\n';
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

/*
bool resuelveCaso() {
	long long int N;
	cin >> N;
	if (!cin)
		return false;

	vector<long long int> valor(N+1), numero(N+1);
	for (long long int i = 0; i < N; i++) {
		cin >> valor[i+1];
	}
	
	for (long long int i = 0; i < N; i++) {
		cin >> numero[i+1];
	}
	long long int C;
	cin >> C;

	valor[0] = INT_MAX;
	numero[0] = 0;

	vector<vector<vector<long long int>>> monedas;

	for (int i = 0; i <= N; i++) {
		vector<vector<long long int>> aux(C+1, vector<long long int>(numero[i] + 1));
		monedas.push_back(aux);
	}
	
	for (int j = 0; j <= C; j++) {
		for (int k = 0; k <= numero[0]; k++) {
			monedas[0][j][k] = INT_MAX;
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int k = 0; k <= numero[i]; k++) {
			monedas[i][0][k] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 0; k <= numero[i]; k++) {
				if (valor[i] > j || k == 0) {
					monedas[i][j][k] = monedas[i - 1][j][numero[i-1]];
				}
				else {
					if (monedas[i][j - valor[i]][k - 1] == INT_MAX) {
						monedas[i][j][k] = monedas[i - 1][j][numero[i-1]];
					}
					else {
						monedas[i][j][k] = min(monedas[i - 1][j][numero[i-1]], 1 + monedas[i][j - valor[i]][k - 1]);
					}
				}	
			}
		}
	}
	if (monedas[N][C][numero[N]] == INT_MAX) {
		cout << "NO\n";
	}
	else {
		cout << "SI "<< monedas[N][C][numero[N]] << '\n';
	}
	
	return true;
}
*/