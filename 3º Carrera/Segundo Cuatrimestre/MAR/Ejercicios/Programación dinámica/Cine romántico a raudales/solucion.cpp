
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

struct tPelicula {
	long long int horaInicio;
	long long int horaFin;
	long long int duracion;

	bool operator<(tPelicula const& otra) {
		return this->horaInicio < otra.horaInicio;
	}
};

bool resuelveCaso() {
	long long int N;
	cin >> N;
	if (N == 0)
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
		peliculas.push_back({ horaComienzo ,horaFin, duracion });
	}
	sort(peliculas.begin(), peliculas.end());
	long long int T = 24 * 60 + 10;
	vector<long long int> MaxTiempo(T + 1, 0);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			if (peliculas[i-1].horaFin > j) {
				MaxTiempo[j] = MaxTiempo[j];
			}
			else {
				MaxTiempo[j] = max(MaxTiempo[j], MaxTiempo[peliculas[i-1].horaInicio] + peliculas[i-1].duracion);
				
			}
		}
	}
	cout << MaxTiempo[T] << '\n';
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

