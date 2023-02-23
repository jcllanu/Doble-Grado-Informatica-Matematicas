
//JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <fstream>
#include<string>
#include "autoescuela.h"

using namespace std;

bool resuelveCaso() {
	string orden;
	cin >> orden;
	if (!cin)
		return false;

	autoescuela c;
	string alumno, profesor;
	int n;
	while(orden != "FIN") {
		if (orden == "alta") {
			cin >> alumno >> profesor;
			c.alta(alumno, profesor);
		}
		else if (orden == "es_alumno") {
			cin >> alumno >> profesor;
			cout << alumno;
			if(!c.es_alumno(alumno,profesor)){
				cout << " no";
			}
			cout << " es alumno de " << profesor << '\n';
		}
		else if (orden == "examen") {
			cin >> profesor >> n;
			vector<string> alumnos = c.examen(profesor, n);
			cout << "Alumnos de " << profesor << " a examen:\n";
			for (string a : alumnos)
				cout << a << '\n';

		}
		else if (orden == "actualizar") {
			cin >> alumno >> n;
			try {
				 c.actualizar(alumno,n);
			}
			catch (std::domain_error e) {
				cout << "ERROR\n";
			}
		}
		else if (orden == "puntuacion") {
			cin >> alumno;
			try {
				int p=c.puntuacion(alumno);
				cout << "Puntuacion de " << alumno << ": " << p << '\n';
			}
			catch (std::domain_error e) {
				cout << "ERROR\n";
			}
		}
		else if (orden == "aprobar") {
			cin >> alumno;
			try {
				c.aprobar(alumno);
			}
			catch (std::domain_error e) {
				cout << "ERROR\n";
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
