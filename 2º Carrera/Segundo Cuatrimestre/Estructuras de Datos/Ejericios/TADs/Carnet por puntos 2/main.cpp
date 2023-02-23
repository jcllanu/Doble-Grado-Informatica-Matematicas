
//JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <fstream>
#include<string>
#include "carnet_puntos.h"

using namespace std;

bool resuelveCaso() {
	string orden;
	int num;
	cin >> orden;
	if (!cin)
		return false;

	carnet_puntos B;

	string dni;
	int puntos;
	while (orden != "FIN") {
		if (orden == "nuevo") {
			cin >> dni;
			try {
				B.nuevo(dni);
			}
			catch (std::domain_error e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (orden == "cuantos_con_puntos") {
			cin >> num;
			try {
				int M = B.cuantos_con_puntos(num);
				cout << "Con " << num << " puntos hay " << M << '\n';
			}
			catch (std::domain_error e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (orden == "consultar") {
			cin >> dni;
			try {
				int p = B.consultar(dni);
				cout << "Puntos de " << dni << ": " << p << '\n';
			}
			catch (std::domain_error e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (orden == "quitar") {
			cin >> dni >> puntos;
			try {
				B.quitar(dni, puntos);
			}
			catch (std::domain_error e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (orden == "recuperar") {
			cin >> dni >> puntos;
			try {
				B.recuperar(dni, puntos);
			}
			catch (std::domain_error e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (orden == "lista_por_puntos") {
			cin >> num;
			try {
				vector<string> dnis = B.lista_por_puntos(num);
				cout << "Tienen " << num << " puntos: ";
				for (string dni : dnis)
					cout << dni << ' ';
				cout << '\n';

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
