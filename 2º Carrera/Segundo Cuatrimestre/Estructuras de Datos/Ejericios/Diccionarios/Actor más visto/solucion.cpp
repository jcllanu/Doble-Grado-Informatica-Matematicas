
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

struct Pelicula {
	string nombre;
	int ultimaEmision, repeticiones;
	bool operator<(const Pelicula& p2) {
		return this->repeticiones > p2.repeticiones || (this->repeticiones == p2.repeticiones && this->ultimaEmision > p2.ultimaEmision);
	}
};

bool resuelveCaso() {
	int P, A, tiempo, E;
	string pelicula, actor;
	unordered_map<string, unordered_map<string, int>> mapaPeliculas;//Cada película guarda la información de los actores que aparecen y su minutaje
	unordered_map<string, int> mapaEmisiones; //Cada pelicula guarda el numero de emisiones
	unordered_map<string, int> mapaActores;//Cada actor guarda su minutaje total
	cin >> P;
	if (P==0) {
		return false;
	}

	//Construimos el mapaPeliculas
	for (int i = 0; i < P; i++) {
		cin >> pelicula >> A;
		for (int j = 0; j < A; j++) {
			cin >> actor >> tiempo;
			mapaPeliculas[pelicula][actor] = tiempo;
		}
	}

	//Procesamos las emisiones
	cin >> E;
	Pelicula pelicMax = { "", 0, 0 };
	Pelicula pelicAux;
	for (int i = 0; i < E; i++) {
		cin >> pelicAux.nombre;
		pelicAux.repeticiones = ++mapaEmisiones[pelicAux.nombre];//Aumentamos en 1 el numero de emisiones de dicha pelicula
		pelicAux.ultimaEmision = i;//Actualizamos la última vez que fue emitida

		if (pelicAux < pelicMax) {//Actualizamos la película que más veces se ha emitido con el criterio especificado
			pelicMax = pelicAux;
		}

		for (auto actor : mapaPeliculas[pelicAux.nombre]) {//Para cada pelicula emitida recorremos sus actores y los añadimos al mapa de actores
														   //aumentando su minutaje.
			mapaActores[actor.first] += actor.second;//actor.first es el nombre del actor y actor.second es el minutaje de dicho actor en la pelicula emitida
		}
	}

	//Recorremos los actores para quedarnos con aquellos con minutaje máximo
	vector<string> actoresMax;
	int tiempoMax = INT_MIN;
	for (auto actor : mapaActores) {
		if (actor.second > tiempoMax) {
			actoresMax.clear();
			actoresMax.push_back(actor.first);
			tiempoMax = actor.second;
		}
		else if (actor.second == tiempoMax) {
			actoresMax.push_back(actor.first);
		}
	}
	//Ordenamos por orden alfabético a los actores
	sort(actoresMax.begin(), actoresMax.end());

	//Mostramos la información
	cout << pelicMax.repeticiones << ' ' << pelicMax.nombre<<'\n';
	cout << tiempoMax << ' ';
	for (string actor : actoresMax) {
		cout << actor << ' ';
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
	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}