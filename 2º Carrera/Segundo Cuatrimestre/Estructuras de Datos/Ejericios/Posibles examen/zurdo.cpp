
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
	bool es_zurdo;
	int numNodos;
};

template<class T>
tSolucion esZurdo(const bintree<T>& arbol) {
	if (arbol.empty()) {
		return { true,0 };
	}
	else {
		tSolucion solIzq = esZurdo(arbol.left());
		tSolucion solDer = esZurdo(arbol.right());
		tSolucion sol;
		sol.numNodos = solIzq.numNodos + solDer.numNodos + 1;
		sol.es_zurdo = (arbol.left().empty() && arbol.right().empty()) ||
			(solDer.es_zurdo&&solIzq.es_zurdo&& solIzq.numNodos > solDer.numNodos);
		return sol;
	}
}


bool resuelveCaso() {
	bintree<char> arbol=leerArbol('.');
	tSolucion sol=esZurdo(arbol);
	cout << (sol.es_zurdo ? "SI\n" : "NO\n");
	return true;
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