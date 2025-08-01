
// JUAN CARLOS LLAMAS N��EZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "colaHeredada.h"
#include"queue.h"

using namespace std;


bool resuelveCaso() {
	ColaIntercambiar<int> cola;
	int aux,n;
	cin >> n;
	if (n==0) {
		return false;
	}
	for(int i=0; i<n; i++){
		cin >> aux;
		cola.push(aux);
	}
	cola.intercambiar();
	cola.print();
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
