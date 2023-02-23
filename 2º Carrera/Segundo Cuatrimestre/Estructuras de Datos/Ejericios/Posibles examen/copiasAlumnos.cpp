
//JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

bool resuelveCaso() {
	unordered_map<int, int> totalRespuestas; //Primer entero la respuesta y segundo el numero de respuestas
	unordered_map<int, int> ultimasKRespuestas; //Primer entero la respuesta y segundo el numero de respuestas
	queue<int> colaRespuestas; //Guardamos las K ultimas respuestas en orden
	int numeroTotalCopias = 0, numeroPilladoCopias = 0;

	int N, K, respuesta;
	cin >> N >> K;
	if (!cin)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> respuesta;
		if (++totalRespuestas[respuesta] > 1)
			numeroTotalCopias++;
		if (colaRespuestas.size() > K) {
			if (--ultimasKRespuestas[colaRespuestas.front()] == 0)
				ultimasKRespuestas.erase(colaRespuestas.front());
			colaRespuestas.pop();
		}
		colaRespuestas.push(respuesta);
		if (++ultimasKRespuestas[respuesta] > 1)
			numeroPilladoCopias++;

	}
	cout << numeroTotalCopias << ' ' << numeroPilladoCopias << '\n';
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
