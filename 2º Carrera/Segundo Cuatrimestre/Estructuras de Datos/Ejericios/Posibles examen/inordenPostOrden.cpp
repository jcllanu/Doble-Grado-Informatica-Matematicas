
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "hashmap.h"
#include <sstream>
using namespace std;

//NO ES TODO LO EFICIENTE QUE PODRIA SER VER VIDEO

template<class T>
bintree<T> construir(const vector<T>& inorden, const vector<T>& postorden, int a, int b, int c, int d) {
	if (a > b) {
		return { };
	}
	else {
		T raiz = postorden[d];
		int i = a;
		while (inorden[i] != raiz) {
			i++;
		}
		return { construir(inorden, postorden,a, i - 1,c, c + i - a-1),
			raiz,
			construir(inorden, postorden,i + 1, b,c + i - a + 1, d - 1)
		};
	}
}


bool resuelveCaso() {
	vector<int> postorden, inorden;
	int n,aux;
	cin >> n;
	if (n == 0)
		return false;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		inorden.push_back(aux);
	}
	for (int i = 0; i < n; i++) {
		cin >> aux;
		postorden.push_back(aux);
	}
	bintree<int> arbol = construir(inorden,postorden, 0,inorden.size()-1, 0, postorden.size() - 1);
	vector<int> pretorden = arbol.preorder();
	for (int i = 0; i < pretorden.size(); i++) {
		cout << pretorden[i] << ' ';
	}
	cout << '\n';
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