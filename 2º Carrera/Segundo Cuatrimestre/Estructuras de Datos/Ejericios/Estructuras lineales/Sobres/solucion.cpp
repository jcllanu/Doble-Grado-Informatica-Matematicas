
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "deque_eda.h"


using namespace std;

typedef struct{
	int valor, pos;
}tPar;


bool resuelveCaso() {
	deque<tPar> sobres;
	int N, M, aux;
	cin >> N >> M;
	if (N == 0 && M == 0) {
		return false;
	}
	

	for (int i = 0; i < N; i++) {
		cin >> aux;
		while (!sobres.empty() && sobres.back().valor < aux) {
			sobres.pop_back();
		}
		sobres.push_back({ aux,i });
		if (sobres.front().pos + M <= i) {
			sobres.pop_front();
		}
		if (i >= M-1) {
			cout << sobres.front().valor << ' ';
		}

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
