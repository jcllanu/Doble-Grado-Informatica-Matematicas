
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"
#include<cmath>
using namespace std;

typedef struct {
	int profundidad;
	int solucion;
	bool haySolucion;
}tSolucion;


bool esPrimo(int n) {
	for (int i = 2; i <= sqrt(n)+1; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

tSolucion mascercano_mult7(const bintree<int>& arbol, const int profundidad) {
	tSolucion sol;
	if (arbol.empty()) {
		sol.haySolucion = false;
	}
	else {
		if (esPrimo(arbol.root())) {
			sol.haySolucion = false;
		}
		else {
			if (arbol.root() % 7 == 0) {
				sol.haySolucion = true;
				sol.profundidad = profundidad;
				sol.solucion = arbol.root();
			}
			else {
				tSolucion solIzq = mascercano_mult7(arbol.left(), profundidad + 1);
				tSolucion solDer= mascercano_mult7(arbol.right(), profundidad + 1);
				if (solIzq.haySolucion && solDer.haySolucion) {
					sol.haySolucion = true;
					if (solIzq.profundidad > solDer.profundidad) {
						sol.solucion = solDer.solucion;
						sol.profundidad = solDer.profundidad;
					}
					else {
						sol.solucion = solIzq.solucion;
						sol.profundidad = solIzq.profundidad;
					}
					
				}
				else if (solIzq.haySolucion && !solDer.haySolucion) {
					sol.haySolucion = true;
					sol.profundidad = solIzq.profundidad;
					sol.solucion = solIzq.solucion;
				}
				else if (!solIzq.haySolucion && solDer.haySolucion) {
					sol.haySolucion = true;
					sol.profundidad = solDer.profundidad;
					sol.solucion = solDer.solucion;
				}
				else if (!solIzq.haySolucion && !solDer.haySolucion) {
					sol.haySolucion = false;
				}
			}
		}
	}
	return sol;
}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	tSolucion solucion = mascercano_mult7(arbol, 1);
	if (solucion.haySolucion) {
		cout << solucion.solucion << ' ' << solucion.profundidad;
	}
	else {
		cout << "NO HAY";
	}
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
