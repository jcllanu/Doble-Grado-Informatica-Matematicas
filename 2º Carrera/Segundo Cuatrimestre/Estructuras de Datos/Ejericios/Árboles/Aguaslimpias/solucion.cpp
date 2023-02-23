
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"

using namespace std;
typedef struct {
	int numTramosNavegables;
	int caudalDeSalida;
}tSolucion;
tSolucion numTramosNavegables(const bintree<int>& arbol) {
	tSolucion solucion;
	if (arbol.empty()) {
		solucion.caudalDeSalida = 0;
		solucion.numTramosNavegables = 0;
	}
	else {
		if (arbol.left().empty() && arbol.right().empty()) {
			if (arbol.root() > 0) {//La hoja es un embalse
				solucion.caudalDeSalida = 0;
			}
			else {//La hoja es un afluente naciente
				solucion.caudalDeSalida = 1;
			}
			
			solucion.numTramosNavegables = 0;
		}
		else {
			tSolucion solIzq = numTramosNavegables(arbol.left());
			tSolucion solDer = numTramosNavegables(arbol.right());

			solucion.numTramosNavegables = solIzq.numTramosNavegables + solDer.numTramosNavegables + (solIzq.caudalDeSalida >= 3 ? 1 : 0) + (solDer.caudalDeSalida >= 3 ? 1 : 0);

			solucion.caudalDeSalida = solIzq.caudalDeSalida + solDer.caudalDeSalida;
			if (arbol.root() > 0) {
				solucion.caudalDeSalida -= arbol.root();
				if (solucion.caudalDeSalida < 0) {
					solucion.caudalDeSalida = 0;
				}
			}
		}
	}
	return solucion;
}
void resuelveCaso() {
	bintree<int> rio = leerArbol(-1);
	tSolucion solucion = numTramosNavegables(rio);
	cout << solucion.numTramosNavegables <<'\n';
	
	
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
