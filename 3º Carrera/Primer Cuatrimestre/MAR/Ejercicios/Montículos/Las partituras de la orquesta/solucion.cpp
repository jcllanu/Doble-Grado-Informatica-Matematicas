
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "PriorityQueue.h"
#include <string>
using namespace std;
struct instrumento {
	int musicos;
	int atriles;
};
struct ComparatorMayor {
	bool operator()(instrumento const& a, instrumento const& b) {
		return double(a.musicos) / a.atriles > double(b.musicos) / b.atriles;
	}
};
bool resuelveCaso() {
	long long int p, n;
	cin >> p >> n;
	if (!cin)
		return false;

	PriorityQueue<instrumento, ComparatorMayor> monticulo;

	instrumento aux;
	for (long long int i = 0; i < n; i++) {
		cin >> aux.musicos;
		aux.atriles = 1;
		monticulo.push(aux);
		p--;
	}
	while (p > 0) {
		instrumento mostCrowded = monticulo.top();
		monticulo.pop();
		mostCrowded.atriles++;
		monticulo.push(mostCrowded);
		p--;	
	}
	instrumento masLleno = monticulo.top();
	if (masLleno.musicos % masLleno.atriles == 0) {
		cout << masLleno.musicos / masLleno.atriles << endl;
	}
	else {
		cout << 1 + (masLleno.musicos / masLleno.atriles) << endl;
	}
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
