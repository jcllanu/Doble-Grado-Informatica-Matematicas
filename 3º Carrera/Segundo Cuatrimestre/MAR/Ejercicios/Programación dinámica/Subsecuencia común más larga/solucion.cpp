
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include <string>
#include <stack>
#include <queue>
using namespace std;



string escribir(vector<vector<int>> const& MasLargas, string const& palabra1, string const& palabra2, int i, int j) {
	if (i == 0 || j == 0) {
		return "";
	}
	else if (palabra1[i-1] == palabra2[j-1]) {
		return escribir(MasLargas, palabra1, palabra2, i - 1, j - 1) + palabra1[i-1];
	}
	else {
		if (MasLargas[i][j - 1] > MasLargas[i - 1][j]) {
			return escribir(MasLargas, palabra1, palabra2, i, j - 1);
		}
		else {
			return escribir(MasLargas, palabra1, palabra2, i - 1, j);
		}
	}
}


bool resuelveCaso() {
	string palabra1, palabra2;
	cin >> palabra1 >> palabra2;
	if (!cin)
		return false;
	
	int N1 = palabra1.size();
	int N2 = palabra2.size();

	vector<vector<int>> MasLargas(N1 + 1, vector<int>(N2 + 1));
	for (int i = 0; i <= N1; i++) {
		MasLargas[i][0] = 0;
	}
	for (int j = 0; j <= N2; j++) {
		MasLargas[0][j] = 0;
	}
	for (int i = 1; i <= N1; i++) {
		for (int j = 1; j <= N2; j++) {
			if (palabra1[i-1] == palabra2[j-1]) {
				MasLargas[i][j] = MasLargas[i-1][j-1] + 1;
			}
			else {
				MasLargas[i][j] = max(MasLargas[i][j - 1], MasLargas[i - 1][j]);
			}
		}
	}
	
	int i = N1;
	int j = N2;
	stack<char> pila;
	while (i > 0 && j > 0) {
		if (MasLargas[i][j] == MasLargas[i][j - 1]) {
			j--;
		}
		else if (MasLargas[i][j] == MasLargas[i - 1][j]) {
			i--;
		}
		else if (MasLargas[i][j] == MasLargas[i - 1][j - 1] + 1) {
			pila.push(palabra1[i-1]);
			i--;
			j--;
		}
	}
	while (!pila.empty()) {
		cout << pila.top();
		pila.pop();
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