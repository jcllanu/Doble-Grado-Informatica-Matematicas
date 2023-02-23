
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "polinomio.h"

using namespace std;

bool resuelveCaso() {
	polinomio p;
	int grado, coeficiente;
	cin >> coeficiente;
	if (!cin) {
		return false;
	}
	cin >> grado;
	while (coeficiente != 0 || grado != 0) {
		p.annadir(grado, coeficiente);
		cin >> coeficiente;
		cin >> grado;
	}
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		/*cout << p.evaluar2(x) << " ";*/
		cout << p.evaluar(x) << " ";
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
