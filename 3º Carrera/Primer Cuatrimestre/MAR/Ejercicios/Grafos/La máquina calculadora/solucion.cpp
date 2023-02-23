
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

bool resuelveCaso() {
	long long int origen, objetivo;
	cin >> origen >> objetivo;
	if (!cin) {
		return false;
	}
	if (origen == objetivo) {
		cout << "0\n";
		return true;
	}
	vector<bool> visitado(10000, false);
	queue<pair<long long int, long long int>> cola; // El primer campo es el número y el segundo es el numero de operaciones para llegar a él
	cola.push({ origen,0 });
	while (!cola.empty()) {
		auto par = cola.front();
		cola.pop();
		for (long long int i = 1; i <= 3; i++) {
			long long int nuevoNum;
			if (i == 1) {
				nuevoNum = (par.first + 1)%10000;
			}
			else if (i == 2) {
				nuevoNum = (2*par.first) % 10000;
			}
			else if (i == 3) {
				nuevoNum = (par.first/3) % 10000;
			}
			if (nuevoNum == objetivo) {
				cout << par.second + 1 << '\n';
				return true;
			}
			if (!visitado[nuevoNum]) {
				cola.push({ nuevoNum,par.second + 1 });
				visitado[nuevoNum] = true;
			}
		}
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
