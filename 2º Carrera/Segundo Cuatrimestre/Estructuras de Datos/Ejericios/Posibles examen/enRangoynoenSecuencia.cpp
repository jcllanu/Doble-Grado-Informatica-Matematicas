
//JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <list>

using namespace std;

list<int> enRangoYNoEnSecuencia(list<int> const& sec, int const& inf, int const& sup) {
	list<int> dev;
	unordered_set<int> conjuntoSecuenciaEnRango;
	for (int numero : sec) {
		if (numero >= inf && numero <= sup)
			conjuntoSecuenciaEnRango.insert(numero);
	}
	for (int i = inf; i <= sup; i++) {
		if (conjuntoSecuenciaEnRango.count(i) == 0)
			dev.push_back(i);
	}
	return dev;
}


bool resuelveCaso() {
	list<int> sec;
	sec.push_back(3);
	sec.push_back(9);
	sec.push_back(1);
	sec.push_back(3);
	sec.push_back(7);
	sec.push_back(2);
	for (int i : enRangoYNoEnSecuencia(sec, 3, 8))
		cout << i << ' ';
	cout << '\n';
	return false;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
