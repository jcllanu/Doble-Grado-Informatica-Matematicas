
//JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

bool resuelveCaso() {
	string nombre;
	int numReyes, numSucesores;
	cin >> numReyes;
	if (numReyes == 0)
		return false;

	unordered_map<string, int> reyes;//EL string representa un nombre de rey y el entero los antecesores que se llamas así
	for (int i = 0; i < numReyes; i++) {
		cin >> nombre;
		reyes[nombre]++;
	}
	cin >> numSucesores;
	for (int i = 0; i < numSucesores; i++) {
		cin >> nombre;
		int palotes=++reyes[nombre];
		cout << palotes << '\n';
	}
	cout << '\n';
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
