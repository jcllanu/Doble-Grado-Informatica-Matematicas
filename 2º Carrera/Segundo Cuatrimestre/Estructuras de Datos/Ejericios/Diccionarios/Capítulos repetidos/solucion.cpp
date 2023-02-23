
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <string>

using namespace std;



void resuelveCaso() {
	map<int,int> mapa;//El primer valor indica el nombre de la serie y el segundo la ultima vez que se emitio empezando a contar los días desde el 0
	int maxDias=0, maxActual=0;
	int nombreSerie, numDias;
	cin >> numDias;
	for (int i = 0; i < numDias; i++) {
		cin >> nombreSerie;
		if (mapa.count(nombreSerie) == 1) {
			if (i - mapa.at(nombreSerie) > maxActual) {
				maxActual++;
			}
			else {
				maxActual= i - mapa.at(nombreSerie);
			}
			mapa[nombreSerie] = i;
		}
		else {
			mapa[nombreSerie] = i;
			maxActual++;
			
		}
		maxDias = max(maxActual, maxDias);
	}
	
	cout << maxDias<<'\n';


}




int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}
	

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}