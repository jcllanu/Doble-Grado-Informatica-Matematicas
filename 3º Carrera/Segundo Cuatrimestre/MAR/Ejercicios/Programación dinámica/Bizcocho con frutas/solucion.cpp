
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;


bool iguales(int a, int b) {
	return (a == 1 && b == 1) || (a == 2 && b == 2);
}
bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)
		return false;

	vector<int> pastel(N);
	for (int i = 0; i < N; i++) {
		cin >> pastel[i];
	}
	vector<vector<int>> MaxDias(N+1,vector<int> (N+1,0));
	
	for (int d = 2; d <= N; d+=2) {
		for (int i = 0; i <=N-d; i++) {
			int j = i + d;
			int derIzq, derDer, izqIzq;
			//Izquierda izquierda
			izqIzq = MaxDias[i + 2][j];
			if (iguales(pastel[i], pastel[i + 1])) {
				izqIzq++;
			}

			//Derecha derecha
			derDer = MaxDias[i][j - 2];
			if (iguales(pastel[j - 1],pastel[j - 2])) {
				derDer++;
			}

			//Derecha izquierda = Izquierda Derecha
			derIzq = MaxDias[i + 1][j - 1];
			if (iguales(pastel[j - 1],pastel[i])) {
				derIzq++;
			}
			MaxDias[i][j] = max(max(derIzq, derDer), izqIzq);
		}
	}
	cout << MaxDias[0][N] << '\n';
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
