
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree.h"
#include <queue>
using namespace std;

template <class T>
vector<T> perfilIzquierdo2(const bintree<T>& arbol) {
	vector<T> perfil;
	int nivelActual = 1;
	if (!arbol.empty()) {
		std::queue<pair<bintree<T>,int>> pendientes;//Guardamos en la cola tanto el arbol como el nivel al que se encuentra 
													//y agrandamos el vector cuando alcanzamos el primer elemento de un nivel
		pendientes.push(make_pair(arbol,1));
		while (!pendientes.empty()) {
			auto sig = pendientes.front();
			pendientes.pop();
			if (nivelActual == sig.second) {
				perfil.push_back(sig.first.root());
				nivelActual++;
			}
			if (!sig.first.left().empty())
				pendientes.push(make_pair(sig.first.left(), sig.second+1));
			
			if (!sig.first.right().empty())
				pendientes.push(make_pair(sig.first.right(), sig.second+1));
			
		}
	}
	return perfil;
}


template <class T>
vector<T> perfilIzquierdo(const bintree<T>& arbol) {
	vector<T> solucion;
	if (!arbol.empty()) {
		vector<T> solIzq = perfilIzquierdo(arbol.left());
		vector<T> solDer = perfilIzquierdo(arbol.right());

		solucion.push_back(arbol.root());
		solucion.insert(solucion.end(), solIzq.begin(), solIzq.end());
		for (int i = solIzq.size(); i < solDer.size(); i++) {
			solucion.push_back(solDer[i]);
		}
	}

	return solucion;
}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	vector<int> solucion = perfilIzquierdo2(arbol);
	for (int elem : solucion) {
		cout << elem << ' ';
	}
	cout << '\n';
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
