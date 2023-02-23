
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>


using namespace std;
struct evento {
	long long int tiempo;
	char tipo;
	bool operator<(evento const& otro) {
		return this->tiempo < otro.tiempo || (this->tiempo == otro.tiempo && this->tipo > otro.tipo);//termina (t) se porcesa antes que comienza (c)
	}
};
bool resuelveCaso() {
	long long int N, comienzo, fin;
	cin >> N;
	if (N == 0)
		return false;
	vector<evento> eventos;
	
	for (long long int i = 0; i < N; i++) {
		cin >> comienzo >> fin;
		eventos.push_back({ comienzo,'c' });
		eventos.push_back({ fin, 't' });
	}
	sort(eventos.begin(), eventos.end());

	long long int maxAlaVez = 0;
	long long int ahora = 0;
	
	for (auto e : eventos) {
		if (e.tipo == 'c') {
			ahora++;
			maxAlaVez = max(ahora, maxAlaVez);
		}
		else {
			ahora--;
		}
	}
	if (maxAlaVez > 0) {
		maxAlaVez--;
	}
	cout << maxAlaVez << '\n';
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