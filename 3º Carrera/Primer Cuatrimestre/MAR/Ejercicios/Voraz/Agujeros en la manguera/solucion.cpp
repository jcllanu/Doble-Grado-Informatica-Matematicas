
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

bool resuelveCaso() {
	long long int N, L, aux;
	cin >> N >> L;
	if (!cin)
		return false;
	vector<long long int> agujeros;
	for (long long int i = 0; i < N; i++) {
		cin >> aux;
		agujeros.push_back(aux);
	}
	long long int numParches = 0;
	long long int desde = INT_MIN;
	for (auto agujero : agujeros) {
		if (agujero > desde + L) {
			desde = agujero;
			numParches++;
		}
	}
	cout << numParches << '\n';
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
