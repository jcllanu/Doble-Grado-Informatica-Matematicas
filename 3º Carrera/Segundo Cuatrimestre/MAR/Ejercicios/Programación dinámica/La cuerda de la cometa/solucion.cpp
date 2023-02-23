
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

struct cordel {
	long long int longitud;
	long long int coste;
};

bool resuelveCaso() {
	long long int N, L, longitud, coste;
	cin >> N >> L;
	if (!cin)
		return false;
	vector<cordel> cordeles;
	for (long long int i = 0; i < N; i++) {
		cin >> longitud >> coste;
		cordeles.push_back({ longitud,coste });
	}

	vector<bool> esPosible;
	vector<long long int> minCoste;
	vector<long long int> minCuerdas;
	vector<long long int> formas;
	
	esPosible.push_back(true);
	formas.push_back(1);
	minCuerdas.push_back(0);
	minCoste.push_back(0);
	for (long long int j = 1; j <= L; j++) {
		esPosible.push_back(false);
		formas.push_back(0);
		minCuerdas.push_back(INT_MAX);
		minCoste.push_back(INT_MAX);
	}
	for (long long int i = 1; i <= N; i++) {
		for (long long int j = L; j >=1; j--) {
			if (cordeles[i - 1].longitud > j) {
				esPosible[j] = esPosible[j];
				formas[j]=formas[j];
				minCuerdas[j] = minCuerdas[j];
				minCoste[j] = minCoste[j];
			}
			else {
				esPosible[j] = esPosible[j]||esPosible[j- cordeles[i - 1].longitud];
				formas[j] = formas[j] + formas[j - cordeles[i - 1].longitud];
				minCuerdas[j] = (minCuerdas[j] < minCuerdas[j - cordeles[i - 1].longitud]+1)? minCuerdas[j]: (minCuerdas[j - cordeles[i - 1].longitud] + 1);
				minCoste[j] = min(minCoste[j], minCoste[j-cordeles[i - 1].longitud]+ cordeles[i - 1].coste);
			}
		}
	}
	if (esPosible[L]) {
		cout << "SI " << formas[L] << ' ' << minCuerdas[L] << ' ' << minCoste[L] << '\n';
	}
	else {
		cout << "NO\n";
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