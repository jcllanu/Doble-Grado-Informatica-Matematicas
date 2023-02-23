
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>


using namespace std;

void resuelveCaso() {
	long long int N, V, aux;
	cin >> N >> V;
	vector<long long int> voltajes;
	
	for (long long int i = 0; i < N; i++) {
		cin >> aux;
		voltajes.push_back(aux);
	}
	sort(voltajes.begin(), voltajes.end());

	long long int numCoches = 0;
	long long int ini = 0;
	long long int fin = N - 1;
	
	while (ini < fin) {
		if(voltajes[ini] + voltajes[fin] >= V) {
			numCoches++;
			fin--;
		}
		ini++;
	}

	cout << numCoches << '\n';
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}
	//while (resuelveCaso());


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}