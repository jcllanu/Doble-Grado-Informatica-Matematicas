
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;

	PriorityQueue<long long int> monticulo;
	int aux;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		monticulo.push(aux);
	}

	long long int resultado=0;
	if (n != 1) {
		while (!monticulo.empty()) {
			long long int dato1 = monticulo.top();
			monticulo.pop();
			long long int dato2 = monticulo.top();
			monticulo.pop();
			long long int suma = dato1 + dato2;
			if (!monticulo.empty()) {
				monticulo.push(suma);
			}
			resultado += suma;
		}
	}
	
	cout << resultado << '\n';
	return true;
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());



	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
