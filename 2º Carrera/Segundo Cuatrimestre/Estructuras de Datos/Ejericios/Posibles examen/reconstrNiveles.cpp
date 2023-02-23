
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "hashmap.h"
#include <sstream>
using namespace std;


bintree<int> porNiveles(const vector<int>& niveles) {
	if (niveles.size() == 0) {
		return {};
	}
	else {
		int raiz = niveles[0];
		vector<int> nivelesIzq;
		vector<int> nivelesDer;
		for (int i = 1; i < niveles.size(); i++) {
			if (niveles[i] < raiz) {
				nivelesIzq.push_back(niveles[i]);
			}
			else {
				nivelesDer.push_back(niveles[i]);
			}
		}
		return{ porNiveles(nivelesIzq),raiz,porNiveles(nivelesDer) };
	}
}


void resuelveCaso() {
	vector<int> niveles;
	int n, aux;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> aux;
		niveles.push_back(aux);
	}
	bintree<int> arbol= porNiveles(niveles);
	for (int a : arbol.preorder())
		cout << a << ' ';
	cout << endl;

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