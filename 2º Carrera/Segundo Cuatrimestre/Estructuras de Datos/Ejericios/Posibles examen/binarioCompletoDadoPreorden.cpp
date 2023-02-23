
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
#include <map>
using namespace std;

template<class T>
bool esABB(vector<T> const& preorden, int a, int b, T& minimo, T& maximo) {
	if (preorden.size() > 0) {
		if (a == b) {
			T raiz = preorden[a];
			minimo = raiz;
			maximo = raiz;
			return true;
		}
		else {
			T raiz = preorden[a];
			int dos_exp_n = b - a + 2;
			T minimoDer, minimoIzq, maximoIzq, maximoDer;
			bool dev = esABB(preorden, a+1, a+ dos_exp_n/2 -1, minimoIzq, maximoIzq) && esABB(preorden, a + dos_exp_n / 2, b, minimoDer, maximoDer) && maximoIzq<raiz && minimoDer>raiz;
			minimo = min(raiz, min(minimoIzq, minimoDer));
			maximo = max(raiz, max(maximoIzq, maximoDer));
			return dev;
		}
	}
	else {
		return true;
	}
}

int elevar(int niveles) {
	int result = 1;
	int base = 2;
	for (int i = 0; i < niveles; i++) {
		result *= base;
	}
	return result - 1;

}

void resuelveCaso() {
	vector<int> preorden;
	int niveles;
	int n, aux, minimo, maximo;
	cin >> niveles;
	n = elevar(niveles);
	for (int i = 0; i < n; i++) {
		cin >> aux;
		preorden.push_back(aux);
	}
	cout <<esABB(preorden,0, preorden.size()-1,minimo,maximo) << endl;
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
