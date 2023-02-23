
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

struct tSolucion {
	bool rentable;
	int renta;
};

tSolucion mejorRenta(bintree<int> const& arbol, int rentaAntecesores) {
	tSolucion solArbol;
	//Arbol no es empty nunca
	int rentaNodo = arbol.root() + rentaAntecesores;
	bool nodoRentable = rentaNodo > 0;

	if (!nodoRentable) {//Si la raiz no es rentable como nodo ninguno de sus descendientes va a ser rentable como nodo. 
		//En concreto ningunna de las hojas va a ser rentable como nodo por lo que el arbol en su conjunto no va a ser rentable
		solArbol.rentable = false;
	}
	else {
		if (arbol.left().empty() && arbol.right().empty()) {//Es una hoja
			solArbol.rentable = true;
			solArbol.renta = rentaNodo;
		}
		else {

			if (!arbol.left().empty() && arbol.right().empty()) {
				solArbol = mejorRenta(arbol.left(), rentaNodo);
				
			}
			else if (arbol.left().empty() && !arbol.right().empty()) {
				solArbol = mejorRenta(arbol.right(), rentaNodo);
				
			}
			else {
				tSolucion solArbolIzq = mejorRenta(arbol.left(), rentaNodo);
				tSolucion solArbolDer = mejorRenta(arbol.right(), rentaNodo);

				if (solArbolIzq.rentable && solArbolDer.rentable) {
					solArbol.rentable = true;
					solArbol.renta = max(solArbolIzq.renta, solArbolDer.renta);
				}
				else if (!solArbolIzq.rentable && solArbolDer.rentable) {
					solArbol.rentable = true;
					solArbol.renta = solArbolDer.renta;
				}
				else if (solArbolIzq.rentable && !solArbolDer.rentable) {
					solArbol.rentable = true;
					solArbol.renta =solArbolIzq.renta;
				}
				else {
					solArbol.rentable = false;
					
				}
			}
		}
	}
	return solArbol;
}

void mejor_renta(bintree<int> const& arbol, bool & es_rentable, int & renta_maxima) {
	if (arbol.empty())
		es_rentable = false;
	else {
		tSolucion sol = mejorRenta(arbol, 0);
		es_rentable = sol.rentable;
		renta_maxima = sol.renta;
		
	}
}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(0);
	bool es_rentable;
	int rentaMax;
	mejor_renta(arbol, es_rentable, rentaMax);
	if (es_rentable) {
		cout << "Arbol rentable con renta: " << rentaMax;
	}
	else {
		cout << "Arbol no rentable ";
	}
	cout << endl;
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
