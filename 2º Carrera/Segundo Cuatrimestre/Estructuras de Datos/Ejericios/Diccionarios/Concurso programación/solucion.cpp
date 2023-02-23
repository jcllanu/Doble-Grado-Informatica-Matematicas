
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

struct tEquipo {
	string nombre;
	int tiempo;
	int problemasResueltos;

	bool operator<(const tEquipo& eq2) {
		return this->problemasResueltos > eq2.problemasResueltos ||
			(this->problemasResueltos == eq2.problemasResueltos && this->tiempo < eq2.tiempo) ||
			(this->problemasResueltos == eq2.problemasResueltos && this->tiempo == eq2.tiempo && this->nombre < eq2.nombre);
	}
};

struct tProblema {
	int intentosFallidos;
	bool resuelto;
	int tiempo;
};
void resuelveCaso() {
	unordered_map<string, unordered_map<string,tProblema>> mapaEquipos;
	string equipo, problema, veredicto;
	int tiempo;
	cin >> equipo;
	while (equipo != "FIN") {
		cin >> problema >> tiempo >> veredicto;
		if (!mapaEquipos[equipo][problema].resuelto) {
			if (veredicto == "AC") {
				mapaEquipos[equipo][problema].resuelto = true;
				mapaEquipos[equipo][problema].tiempo = tiempo;
			}
			else {
				mapaEquipos[equipo][problema].intentosFallidos++;
			}
		}
		cin >> equipo;
	}
	
	vector<tEquipo> auxiliar;
	for (auto equipo : mapaEquipos) {
		tEquipo eq;
		eq.nombre = equipo.first;
		eq.problemasResueltos = 0;
		eq.tiempo = 0;
		for (auto problema : equipo.second) {
			if (problema.second.resuelto) {
				eq.problemasResueltos++;
				eq.tiempo += 20 * problema.second.intentosFallidos + problema.second.tiempo;
			}
		}
		auxiliar.push_back(eq);
	}
	sort(auxiliar.begin(), auxiliar.end());
	for (auto equipo : auxiliar) {
		cout << equipo.nombre << ' ' << equipo.problemasResueltos << ' ' << equipo.tiempo << '\n';
	}
	cout << "---\n";
}




int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i<numCasos; i++) {
		resuelveCaso();
	}
	
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}