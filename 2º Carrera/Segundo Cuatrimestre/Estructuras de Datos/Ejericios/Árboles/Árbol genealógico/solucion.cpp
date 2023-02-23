
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"

using namespace std;

typedef struct {
	bool esGenealogico;
	int niveles;
}tSolucion;

template<class T>
tSolucion es_genealogico(const bintree<T>& arbol) {
	tSolucion sol;
	if (arbol.empty()) {
		sol.esGenealogico = true;
		sol.niveles = 0;
	}
	else {
		tSolucion solIzq = es_genealogico(arbol.left());
		tSolucion solDer = es_genealogico(arbol.right());
		
		bool esGeanea = solIzq.esGenealogico && solDer.esGenealogico;

		if (!arbol.left().empty() && !arbol.right().empty()) {//Tiene dos hijos
			esGeanea = esGeanea && arbol.left().root() + 18 <= arbol.root() && arbol.right().root() + 18 <= arbol.root() && arbol.right().root() + 2 <= arbol.left().root();
		
		}
		else if (arbol.left().empty() && !arbol.right().empty()) {//Tiene solo hijo derecho
			esGeanea = false;//No puede tener segundo hijo sin tener primero
		}
		else if (!arbol.left().empty() && arbol.right().empty()) {//Tiene solo hijo izquierdo
			esGeanea = esGeanea && arbol.left().root() + 18 <= arbol.root();
		}
		else {//No tiene hijos
			//Nada
		}

		sol.esGenealogico = esGeanea;
		sol.niveles = max(solIzq.niveles, solDer.niveles) + 1;
	}
	return sol;
}



void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	tSolucion solucion = es_genealogico(arbol);
	if (solucion.esGenealogico) {
		cout << "SI "<< solucion.niveles << '\n';
	}
	else {
		cout << "NO" << '\n';
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
