
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"
#include <string>
using namespace std;
struct tSolucion {
	int talla;
	string completo;
};
/*
template<class T>
void recorrer(const bintree<T>& arbol) {
	if (!arbol.empty()) {
		queue<bintree<T>> pendientes;
		pendientes.push(arbol);
		while (!pendientes.empty()) {
			bintree<T> sig = pendientes.front();
			pendientes.pop();
			
			if (!arbol.left().empty()) {
				pendientes.push(arbol.left());
			}
			if (!arbol.rigth().empty()) {
				pendientes.push(arbol.rigth());
			}
		}
	}
}
*/
template<class T>
tSolucion es_completo_semicompleto(const bintree<T>& arbol) {
	tSolucion sol;
	if (arbol.empty()) {
		sol.talla = 0;
		sol.completo = "COMPLETO";
	}
	else {
		tSolucion solIzq = es_completo_semicompleto(arbol.left());
		tSolucion solDer = es_completo_semicompleto(arbol.right());
		sol.talla = max(solIzq.talla, solDer.talla) + 1;
		if (solIzq.completo == "NADA") {
			sol.completo = "NADA";
		}
		else if (solIzq.completo == "COMPLETO") {
			if (solDer.completo == "COMPLETO") {
				if (solIzq.talla == solDer.talla) {
					sol.completo = "COMPLETO";
				}
				else if (solIzq.talla == solDer.talla + 1) {
					sol.completo = "SEMICOMPLETO";
				}
				else {
					sol.completo = "NADA";
				}
			}
			else if (solDer.completo == "SEMICOMPLETO") {
				if (solIzq.talla == solDer.talla) {
					sol.completo = "SEMICOMPLETO";
				}
				else {
					sol.completo = "NADA";
				}
			}
			else {
				sol.completo = "NADA";
			
			}
		}
		else {//Es SEMICOMPLETO
			if (solDer.completo == "COMPLETO") {
				if (solIzq.talla == solDer.talla+1) {
					sol.completo = "SEMICOMPLETO";
				}
				else {
					sol.completo = "NADA";

				}
			}
			else {
				sol.completo = "NADA";
			}
		}
	}
	
	return sol;
}
void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	tSolucion sol = es_completo_semicompleto(arbol);
	cout << sol.completo << '\n';

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
