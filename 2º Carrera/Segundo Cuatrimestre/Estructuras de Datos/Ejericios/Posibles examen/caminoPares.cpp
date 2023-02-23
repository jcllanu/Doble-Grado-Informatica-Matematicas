
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
	int caminoMasLargoConRaiz;
	int caminoMasLargo;
};

template<class T>
tSolucion caminoPares(const bintree<T>& arbol) {
	if (arbol.empty()) {
		return {0,0};
	}
	else {
		tSolucion sI = caminoPares(arbol.left());
		tSolucion sD = caminoPares(arbol.right());
		tSolucion s;
		if (arbol.root() % 2 == 0) {//ES PAR
			s.caminoMasLargoConRaiz = 1;
			s.caminoMasLargoConRaiz+= sD.caminoMasLargoConRaiz;
			s.caminoMasLargoConRaiz += sI.caminoMasLargoConRaiz;
		}
		else {
			s.caminoMasLargoConRaiz = 0;
		}
		
		s.caminoMasLargo = max(s.caminoMasLargoConRaiz,
			max(sD.caminoMasLargo, sI.caminoMasLargo));
		return s;
	}
}


void resuelveCaso() {
	bintree<int> arbol=leerArbol(-1);
	tSolucion sol = caminoPares(arbol);
	cout << sol.caminoMasLargo << endl;
	
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