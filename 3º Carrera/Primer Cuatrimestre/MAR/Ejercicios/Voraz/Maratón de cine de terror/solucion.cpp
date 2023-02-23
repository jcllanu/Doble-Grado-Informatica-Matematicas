
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

struct tPelicula {
	int horaInicio;
	int horaFin;

	bool operator<(tPelicula const& otra) {
		return this->horaFin < otra.horaFin;
	}
};
bool resuelveCaso() {
	long long int N;
	cin >> N;
	if (N==0)
		return false;
	
	char aux;
	
	vector<tPelicula> peliculas;
	for (long long int i = 0; i < N; i++) {
		int horaComienzo, horaFin, duracion;
		cin.get(aux);
		cin.get(aux);
		horaComienzo = 600 * int(aux - '0');
		cin.get(aux);
		horaComienzo += 60 * int(aux - '0');
		cin.get(aux);
		cin.get(aux);
		horaComienzo += 10 * int(aux - '0');
		cin.get(aux);
		horaComienzo += int(aux - '0');
		cin >> duracion;
		horaFin = horaComienzo + duracion + 10;
		peliculas.push_back({ horaComienzo ,horaFin });
	}
	sort(peliculas.begin(), peliculas.end());

	int numVistas = 0;
	int horaSalida = INT_MIN;
	for (auto p : peliculas) {
		if (p.horaInicio >= horaSalida) {
			horaSalida = p.horaFin;
			numVistas++;
		}
	}
	cout << numVistas << '\n';
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
