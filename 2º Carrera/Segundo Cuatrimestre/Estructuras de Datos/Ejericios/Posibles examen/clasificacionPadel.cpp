
//JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

bool resuelveCaso() {
	string categoria, pareja1, pareja2;
	int puntos1, puntos2;
	cin >> categoria;
	if (categoria == "FIN") 
		return false;
	unordered_map<string, int> clasificacion;
	int partidosJugados = 0;
	cin >> pareja1;
	while (pareja1 != "FIN") {
		cin >> puntos1 >> pareja2 >> puntos2;
		if (puntos1 > puntos2) {
			clasificacion[pareja1] += 2;
			clasificacion[pareja2] += 1;
		}
		else {
			clasificacion[pareja1] += 1;
			clasificacion[pareja2] += 2;
		}
		partidosJugados++;
		cin >> pareja1;
	}
	int puntMax = -1;
	bool empate = false;
	string parejaGanadora;
	for (auto parPareja : clasificacion) {
		if (parPareja.second > puntMax) {
			empate = false;
			parejaGanadora = parPareja.first;
			puntMax = parPareja.second;
		}
		else if (parPareja.second == puntMax) {
			empate = true;
		}
		else {
			empate = false;
		}
	}
	cout << (empate? "EMPATE" : parejaGanadora )<<' '<< clasificacion.size()*(clasificacion.size()-1) - partidosJugados<<'\n';
	
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
