
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
struct Edificio {
	long long int west;
	long long int east;

	bool operator<(Edificio const& otro) {
		return this->east < otro.east;
	}
};
bool resuelveCaso() {
	long long int N, este, oeste;
	cin >> N;
	if (N==0)
		return false;
	
	vector<Edificio> edificios;
	
	for (long long int i = 0; i < N; i++) {
		cin >> oeste >> este;
		edificios.push_back({ oeste,este });
	}
	sort(edificios.begin(), edificios.end());

	long long int numTuneles = 0;
	long long int ultimoTunel = INT_MIN;
	for (auto e : edificios) {
		if (e.west >= ultimoTunel) {
			numTuneles++;
			ultimoTunel = e.east;
		}
	}
	cout << numTuneles << '\n';

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
