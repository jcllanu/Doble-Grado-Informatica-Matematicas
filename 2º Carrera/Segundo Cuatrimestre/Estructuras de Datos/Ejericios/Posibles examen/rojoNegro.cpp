
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "hashmap.h"
#include <sstream>
using namespace std;

struct tSolucion{
	bool es_RN;
	int numNodosN;
};

template<class T>
tSolucion esRojoNegro(const bintree<T>& arbol) {
	if (arbol.empty()) {
		return {true,0};
	}
	else {
		tSolucion sI = esRojoNegro(arbol.left());
		tSolucion sD = esRojoNegro(arbol.right());
		tSolucion s;
		s.numNodosN = sD.numNodosN;
		s.es_RN = (sD.numNodosN == sI.numNodosN) && sD.es_RN && sI.es_RN;
		if (arbol.root() == 'n') {
			s.numNodosN++;
			return s;
		}
		else if(arbol.root() == 'r'){
			s.es_RN = s.es_RN && (arbol.left().empty() || arbol.left().root()=='n') && (arbol.right().empty() || arbol.right().root() == 'n');
			return s;
		}
		else {
			s.es_RN = false;
			return s;
		}
		
	}
}


void resuelveCaso() {
	bintree<char> arbol=leerArbol('.');
	if (!arbol.empty() && arbol.root() != 'n')
		cout << "NO\n";
	else {
		tSolucion sol = esRojoNegro(arbol);
		cout << (sol.es_RN ? "SI\n" : "NO\n");
	}
	
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}