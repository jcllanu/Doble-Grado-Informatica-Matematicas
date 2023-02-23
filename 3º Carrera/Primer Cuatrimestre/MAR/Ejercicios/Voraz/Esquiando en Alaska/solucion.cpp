
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

bool resuelveCaso() {
	long long int N, aux;
	cin >> N;
	if (N==0)
		return false;
	
	vector<long long int> esquis;
	vector<long long int> personas;
	for (long long int i = 0; i < N; i++) {
		cin >> aux;
		personas.push_back(aux);
	}
	for (long long int i = 0; i < N; i++) {
		cin >> aux;
		esquis.push_back(aux);
	}
	sort(personas.begin(), personas.end());
	sort(esquis.begin(), esquis.end());

	long long int sumDiferencias=0;

	for (long long int i = 0; i < N; i++) {
		sumDiferencias += abs(esquis[i] - personas[i]);
	}
	cout << sumDiferencias << '\n';

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
