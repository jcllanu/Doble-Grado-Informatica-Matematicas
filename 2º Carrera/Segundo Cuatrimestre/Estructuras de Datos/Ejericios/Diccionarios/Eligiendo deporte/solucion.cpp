
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>


using namespace std;


typedef struct tDato {
	int tamanno;
	string nombre;
	bool operator<(const tDato& dato2) {
		return this->tamanno > dato2.tamanno || (this->tamanno == dato2.tamanno && this->nombre < dato2.nombre);
	}
};

bool resuelveCaso() {
	unordered_map<string, unordered_set<string>> mapaDeportes;//El primer string corresponde al nombre del deporte y 
													//el campo de valor al conjunto de alumnos apuntados a ese deporte
	unordered_map<string, string> mapaAlumnos;//El primer string corresponde al nombre del alumno y el segundo el nombre 
												//del deporte en cuya lista aparece por primera vez
	string deporte;
	cin >> deporte;
	if (!cin) {
		return false;
	}
	if (deporte != "_FIN_") {
		mapaDeportes[deporte];
	}
	while (deporte != "_FIN_") {
		string usuario;
		cin >> usuario;
		if (usuario[0]<'a' || usuario[0] > 'z') {
			deporte = usuario;
			if (deporte != "_FIN_") {
				mapaDeportes[deporte];
			}
		}
		else {
			if (mapaAlumnos.count(usuario) == 0) {
				mapaAlumnos[usuario] = deporte;
				mapaDeportes[deporte].insert(usuario);
			}
			else {
				if (mapaAlumnos[usuario] == deporte) {//Misma hoja no hay que hacer nada

				}
				else {//Distinta hoja hay que eliminar de la hoja anterior el alumno
					mapaDeportes[mapaAlumnos[usuario]].erase(usuario);
				}
			}
		}
	}

	vector<tDato> auxiliar;
	for (auto elem : mapaDeportes) {
		tDato dato;
		dato.nombre = elem.first;
		dato.tamanno = elem.second.size();
		auxiliar.push_back(dato);
	}
	sort(auxiliar.begin(), auxiliar.end());
	for (auto elem : auxiliar) {
		cout << elem.nombre << ' ' << elem.tamanno << '\n';
	}
	cout << "---\n";
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