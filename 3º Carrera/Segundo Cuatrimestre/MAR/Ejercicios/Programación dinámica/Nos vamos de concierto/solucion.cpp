
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;
struct festival {
	int precio, grupos;
};
bool resuelveCaso() {
	int N, P;
	cin >> P >> N;
	if (!cin)
		return false;

	vector<festival> festivales(N);
	for (int i = 0; i < N; i++) {
		cin >> festivales[i].grupos >> festivales[i].precio;
	}
	vector<int> MaxGrupos(P+1);
	for (int j = 0; j <= P; j++) {
		MaxGrupos[j] = 0;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = P; j >0; j--) {
			if (festivales[i - 1].precio > j) {
				MaxGrupos[j] = MaxGrupos[j];
			}
			else {
				MaxGrupos[j] = max(MaxGrupos[j], festivales[i - 1].grupos + MaxGrupos[j - festivales[i - 1].precio]);
			}
		}
	}
	cout << MaxGrupos[P] << '\n';
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
