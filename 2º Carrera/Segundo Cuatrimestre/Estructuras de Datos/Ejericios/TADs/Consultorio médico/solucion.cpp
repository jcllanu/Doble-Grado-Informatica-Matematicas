
//JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <fstream>
#include<string>
#include "consultorio.h"

using namespace std;

bool resuelveCaso() {
	int num;
	cin >> num;
	if (!cin)
		return false;

	consultorio c;
	string orden;
	string medico, paciente;
	int day;
	hora hour;
	for(int i=0; i<num; i++){
		cin >> orden;
		if (orden == "nuevoMedico") {
			cin >> medico;
			c.nuevoMedico(medico);
		}
		else if (orden == "pideConsulta") {
			cin >> paciente >> medico >> day >> hour;
			try {

				c.pideConsulta(paciente, medico, { hour,day });
			}
			catch (std::domain_error e) {
				cout << e.what() << '\n';
			}
		}
		else if (orden == "listaPacientes") {
			cin >> medico >> day;
			try {
				vector <pair<string,string>> lista= c.listaPacientes(medico, day);
				cout << "Doctor " << medico << " dia " << day << '\n';
				for (auto par : lista) {
					cout << par.second << ' ' << par.first << '\n';
				}
			}
			catch (std::domain_error e) {
				cout << e.what() << '\n';
			}
		}
		else if (orden == "siguientePaciente") {
			cin >> medico;
			try {
				string sig = c.siguientePaciente(medico);
				cout << "Siguiente paciente doctor " << medico << '\n';
				cout << sig << '\n';
			}
			catch (std::domain_error e) {
				cout << e.what() << '\n';
			}
		}
		else if (orden == "atiendeConsulta") {
			cin >> medico;
			try {
				c.atiendeConsulta(medico);
			}
			catch (std::domain_error e) {
				cout << e.what() << '\n';
			}
		}
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
