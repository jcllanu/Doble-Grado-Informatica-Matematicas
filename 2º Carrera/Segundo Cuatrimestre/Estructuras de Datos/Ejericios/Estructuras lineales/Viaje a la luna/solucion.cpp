
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include"persona.h"
#include"listaHeredada.h"
using namespace std;


bool resuelveCaso() {
	int numPersonas, edadMin, edadMax;
	ListaHereda<persona> lista;
	cin >> numPersonas>> edadMin >> edadMax;
	
	if (numPersonas== 0 && edadMin == 0 && edadMax==0) {
		return false;
	}
	persona p;
	for (int i = 0; i < numPersonas; i++) {
		cin >> p;
		lista.push_back(p);
	}
	lista.remove_if([edadMin,edadMax](persona p) {
		return edadMin > p.getedad() || edadMax < p.getedad();
	});

	for (persona p : lista) {
		cout << p << '\n';
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

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
