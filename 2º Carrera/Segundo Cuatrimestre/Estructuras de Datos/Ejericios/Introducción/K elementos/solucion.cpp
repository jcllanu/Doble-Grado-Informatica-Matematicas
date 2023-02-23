
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "conjunto.h"

using namespace std;

template <class T>
void resolver(T centinela, int k) {
	T aux;
	set<T> conjunto;
	cin >> aux;
	while (aux != centinela) {
		conjunto.insert(aux);
		if (conjunto.size() > k) {
			conjunto.eliminar_menor();
		}
		cin >> aux;
	}
	for (int i = 0; i < k; i++) {
		cout << conjunto.ver_menor() << " ";
		conjunto.eliminar_menor();
	}
}
bool resuelveCaso() {
	char a;
	int k;
	cin >> a;
	if (!cin) {
		return false;
	}
	cin >> k;

	if (a == 'N') {
		resolver(-1, k);
	}
	else if (a == 'P') {
		resolver(string("FIN"),k);
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
