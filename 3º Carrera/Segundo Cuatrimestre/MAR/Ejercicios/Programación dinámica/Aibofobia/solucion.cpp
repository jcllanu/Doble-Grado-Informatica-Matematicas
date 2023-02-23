
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

bool resuelveCaso() {
	string palabra;
	cin >> palabra;
	if (!cin)
		return false;
	
	int N = palabra.size();

	vector<vector<int>> MinLetras(N + 1, vector<int>(N + 1));

	for (int i = N; i >= 0; i--) {
		for (int j = i; j <=N; j++) {
			if (j == i) {
				MinLetras[i][j] = 0;
			}
			else {
				if (palabra[i] == palabra[j - 1]) {
					MinLetras[i][j] = MinLetras[i + 1][j - 1];
				}
				else {
					MinLetras[i][j] = 1 + min(MinLetras[i + 1][j], MinLetras[i][j - 1]);
				}
			}
			
		}
	}
	cout << MinLetras[0][N] << ' ';
	
	int j = N;
	int i = 0;
	queue<char> ini;
	stack<char> fin;
	while (j > 0 && i < N && ini.size()+fin.size() < N + MinLetras[0][N]) {
		if (j == i + 1) {
			ini.push(palabra[i]);
			break;
		}

		if (MinLetras[i][j] == 1 + MinLetras[i][j - 1]) {
			ini.push(palabra[j - 1]);
			fin.push(palabra[j - 1]);
			j--;
		}
		else if (MinLetras[i][j]== 1 + MinLetras[i + 1][j]){
			ini.push(palabra[i]);
			fin.push(palabra[i]);
			i++;
		}
		else if (MinLetras[i][j] == MinLetras[i + 1][j - 1]) {
			ini.push(palabra[i]);
			fin.push(palabra[j - 1]);
			i++;
			j--;
		}
		
	}
	while (!ini.empty()) {
		cout << ini.front();
		ini.pop();
	}
	while (!fin.empty()) {
		cout << fin.top();
		fin.pop();
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