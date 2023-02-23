
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

bool resuelveCaso() {
	long long int N,aux;
	cin >> N;
	if (!cin)
		return false;
	vector<long long int> ataques;
	vector<long long int> defensas;

	for (long long int i = 0; i < N; i++) {
		cin >> aux;
		ataques.push_back(aux);
	}
	for (long long int i = 0; i < N; i++) {
		cin >> aux;
		defensas.push_back(aux);
	}
	
	sort(ataques.begin(), ataques.end());
	sort(defensas.begin(), defensas.end());
	long long int indexataque = 0;
	long long int numDefendidas = 0;
	for (long long int i = 0; i < N; i++) {
		if (defensas[i] >= ataques[indexataque]) {
			indexataque++;
			numDefendidas++;
		}
	}
	cout << numDefendidas << '\n';
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
