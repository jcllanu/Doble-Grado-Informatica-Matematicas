
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "stack_eda.h"

using namespace std;

typedef struct{
	string fecha;
	int victimas;
}tAccidente;

bool resuelveCaso() {
	stack<tAccidente> pila;
	int N, vict;
	string fecha;

	cin >> N;
	if (!cin) {
		return false;
	}
	for (int i = 0; i < N; i++) {
		cin >> fecha >> vict;
		while (!pila.empty() && pila.top().victimas <= vict) {
			pila.pop();
		}
		if (pila.empty()) {
			cout << "NO HAY\n";
		}
		else {
			cout << pila.top().fecha << '\n';
		}
		pila.push({fecha, vict});
	}
	cout << "---\n";
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	while(resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
