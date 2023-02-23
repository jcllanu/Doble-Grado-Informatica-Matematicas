
// JUAN CARLOS LLAMAS NUÑEZ 

#include <iostream>               
#include <fstream>               
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


bool resuelveCaso() {
	int N, M, k;
	cin >> N;
	if (!cin)
		return false;
	string nuevoAviso, hora;
	unordered_map<string, vector<string>> avisos; //La clave representa el nombre del juego, y el valor es un vector donde el índice es la vez menos uno y el contenido es la fecha
	cin >> M;
	for (int i = 0; i < N; i++) {
		cin >> nuevoAviso >> hora;
		avisos[nuevoAviso].push_back(hora);
	}
	for (int i = 0; i < M; i++) {
		cin >> nuevoAviso >> k;
		if (avisos.count(nuevoAviso) == 0 || avisos[nuevoAviso].size()<k) {
			cout << "-- ";
		}
		else {
			cout << avisos[nuevoAviso][k-1] << ' ';
		}
	}
	cout << '\n';
	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
