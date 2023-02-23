
// JUAN CARLOS LLAMAS NÚÑEZ Y ADRIÁN SANJUÁN ESPEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "queue_eda.h"
#include "deque_eda.h"

using namespace std;

bool resuelveCaso() {
	queue<int> cola;
	deque<int> dcola;
	int n,aux;
	cin >> n;
	if (n==0) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		cin >> aux;
		cola.push(aux);
	}
	for (int i = 0; i < n; i++) {
		if (cola.front() < 0) {
			dcola.push_front(cola.front());
			cola.pop();
		}
		else {
			dcola.push_back(cola.front());
			cola.pop();
		}

	}
	for (int i = 0; i < n; i++) {
		cout << dcola.front() << ' ';
		dcola.pop_front();
	}
	cout << '\n';
	
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
