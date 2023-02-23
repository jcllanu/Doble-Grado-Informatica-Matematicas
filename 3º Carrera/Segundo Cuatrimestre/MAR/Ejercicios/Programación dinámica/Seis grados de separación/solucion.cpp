
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
	long long int P, R;
	cin >> P >> R;
	if (!cin)
		return false;
	vector<vector<long long int>> relaciones(P, vector<long long int>(P, INT_MAX));
	unordered_map<string, long long int> nombres;
	string nombre1, nombre2;
	
	for (long long int i = 0; i < R; i++) {
		long long int ind1;
		long long int ind2;
		cin >> nombre1 >> nombre2;
		if (nombres.count(nombre1) > 0) {
			ind1 = nombres[nombre1];
		}
		else {
			nombres[nombre1] = nombres.size();
			ind1 = nombres[nombre1];
		}
		if (nombres.count(nombre2) > 0) {
			ind2 = nombres[nombre2];
		}
		else {
			nombres[nombre2] = nombres.size();
			ind2 = nombres[nombre2];
		}
		relaciones[ind1][ind2] = 1;
		relaciones[ind2][ind1] = 1;
	}


	for (int i = 0; i < P; i++) {
		relaciones[i][i] = 0;
	}
	for (int k = 0; k < P; k++) {
		for (int i = 0; i < P; i++) {
			for (int j = 0; j < P; j++) {
				long long int aux = relaciones[i][k] + relaciones[k][j];
				if (aux < relaciones[i][j]) {
					relaciones[i][j] = aux;
				}
			}
		}
	}
	long long int max = 0;
	for (int i = 0; i < P; i++) {
		for (int j = 0; j < P; j++) {
			if (max < relaciones[i][j]) {
				max = relaciones[i][j];
			}
			if (max == INT_MAX) {
				break;
			}
		}
		if (max == INT_MAX) {
			break;
		}
	}
	if (max == INT_MAX) {
		cout << "DESCONECTADA\n";
	}
	else {
		cout << max << '\n';
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