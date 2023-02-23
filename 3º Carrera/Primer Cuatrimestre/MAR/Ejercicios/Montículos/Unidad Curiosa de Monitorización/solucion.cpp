
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

struct tPar {
	long long int identificador;
	long long int frecuencia;
	long long int tiempo;
};
struct Comparator{
	bool operator()(tPar const& a, tPar const& b) {
		return a.tiempo < b.tiempo || a.tiempo == b.tiempo && a.identificador < b.identificador;
	}
};
bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;

	PriorityQueue<tPar, Comparator> monticulo;
	long long int aux;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		tPar par;
		par.identificador = aux;
		cin >> aux;
		par.frecuencia = aux;
		par.tiempo = aux;
		monticulo.push(par);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		tPar par = monticulo.top();
		monticulo.pop();
		cout << par.identificador << '\n';
		par.tiempo += par.frecuencia;
		monticulo.push(par);
	}
	cout << "---\n";
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
