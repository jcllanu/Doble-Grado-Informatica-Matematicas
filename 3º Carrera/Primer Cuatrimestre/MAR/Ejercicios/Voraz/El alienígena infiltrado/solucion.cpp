
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

struct intervalo {
	long long int ini;
	long long int fin;
	bool operator<(intervalo const& otro) {
		return this->ini < otro.ini;
	}
};

bool resuelveCaso() {
	long long int N, C, F, c, f;
	cin >> C >> F >> N;
	if (N == 0 && C==0 && F == 0)
		return false;

	vector<intervalo> intervalos;

	for (long long int i = 0; i < N; i++) {
		cin >> c >> f;
		intervalos.push_back({ c,f });
	}
	sort(intervalos.begin(), intervalos.end());

	long long int minIntervalos = 0;
	long long int final = C;
	long long int i = 0;
	bool posible = true;
	bool salir = false;
	stack<intervalo> pila;
	for (int i = 0; i < N && posible && !salir; i++) {
		if (intervalos[i].ini > final && !pila.empty()) {
			if (pila.top().ini <= final) {
				final = pila.top().fin;
				pila.pop();
				minIntervalos++;
			}
			else {
				posible = false;
			}
		}
		if (final >= F) {
			salir = true;
		}
		if (intervalos[i].ini <= final && !salir) {
			if (pila.empty() || intervalos[i].fin >= pila.top().fin) {
				pila.push(intervalos[i]);
			}
		}
	}
	
	if (!pila.empty() && !salir) {
		if (pila.top().ini <= final) {
			minIntervalos++;
			final = pila.top().fin;
			pila.pop();
		}
		else {
			posible = false;
		}
	}
	if (final < F) {
		posible = false;
	}
	if (!posible) {
		cout << "Imposible\n";
	}
	else {
		cout << minIntervalos <<'\n';
	}

	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	/*int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}*/
	while (resuelveCaso());


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}