
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
//#include "bintreeHeredada.h"
#include "bintree.h"
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <queue>
#include <cmath>
using namespace std;


/*
void resuelveCaso() {
	bintreeExt<int> arbol = leerArbolExt(-1);
	pair<int, int> p = arbol.gruposRescate();
	cout << p.first << ' ' << p.second << '\n';
	
}

*/

bool esPrimo(int n) {
	for (int i = 2; i <= sqrt(n) + 1; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

pair<int,int> mascercano_mult7(const bintree<int>& arbol) {
	if (arbol.empty()) {
		return{ 0,0 };
	}
	else {
		queue<bintree<int>> pendientes;
		queue<int> pendientesProfundidad;
	
		pendientes.push(arbol);
		pendientesProfundidad.push(1);

		while (!pendientes.empty()) {
			bintree<int> sig = pendientes.front();
			pendientes.pop();
			int profundidad = pendientesProfundidad.front();
			pendientesProfundidad.pop();

			if (!esPrimo(sig.root())) {
				if (sig.root() % 7 == 0) {
					return { sig.root(), profundidad };
				}
				else {
					if (!sig.left().empty()) {
						pendientes.push(sig.left());
						pendientesProfundidad.push(profundidad + 1);
					}
					if (!sig.right().empty()) {
						pendientes.push(sig.right());
						pendientesProfundidad.push(profundidad + 1);
					}
					
				}
			}
		}
		return{ 0,0 };
	}
}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	pair<int, int> sol = mascercano_mult7(arbol);
	if (sol.first == 0 && sol.second == 0)
		cout << "NO HAY";
	else
		cout << sol.first << ' ' << sol.second;
	cout << '\n';
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

