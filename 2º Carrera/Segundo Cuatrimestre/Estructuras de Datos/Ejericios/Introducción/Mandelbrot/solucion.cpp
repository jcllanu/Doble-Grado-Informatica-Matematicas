
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include"comlpejo.h"
using namespace std;

bool mandelbort(const complejo<float> &c, int n) {
	complejo<float> z = complejo<float>(0,0);
	for (int i = 1; i <= n; i++) {
		z = z * z + c;
		if (z.mod() > 2) {
			return false;
		}
	}
	return true;
}



void resuelveCaso() {
	float real, imaginaria;
	int n;
	cin >> real >> imaginaria >> n;
	complejo<float> c = complejo<float>(real, imaginaria);
	if (mandelbort(c,n)) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}

	
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

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
