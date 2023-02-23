
//JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <fstream>
#include<string>
#include "carnet_puntos.h"

using namespace std;

bool resuelveCaso() {
	string orden;

	cin >> orden;
	if (!cin)
		return false;

	GestorSurtidores B;

	string surtidor, combustible, coche;
	int litros;

	while (orden != "FIN") {
		if (orden == "an_surtidor") {
			cin >> surtidor;
			try {
				B.an_surtidor(surtidor);
			}
			catch (std::domain_error e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (orden == "carga") {
			cin >> surtidor >> combustible >> litros;

			try {
				B.carga(surtidor, combustible,litros);
			}
			catch (std::domain_error e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (orden == "pon_en_espera") {
			cin >> coche >> surtidor;
			try {
				B.pon_en_espera(coche, surtidor);
			}
			catch (std::domain_error e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (orden == "vende") {
			cin >> surtidor >> combustible >> litros;
			try {
				result dev=B.vende(surtidor, combustible, litros);
				cout << dev.c << " " << dev.num_litros << " " << '\n';
			}
			catch (std::domain_error e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (orden == "abandona") {
			cin >> coche;
			try {
				B.abandona(coche);
			}
			catch (std::domain_error e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		
		cin >> orden;
	}
	cout << "---\n";
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
