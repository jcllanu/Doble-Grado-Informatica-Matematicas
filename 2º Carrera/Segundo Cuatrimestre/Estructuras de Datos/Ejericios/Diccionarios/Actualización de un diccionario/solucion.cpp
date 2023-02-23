
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <map>
#include<set>
using namespace std;


void resuelveCaso() {
	unordered_map<string,unsigned int> diccAntiguo;
	unordered_map<string, unsigned int> diccNuevo;
	string line;
	
	getline(cin, line);
	stringstream ss(line);
	unsigned int valorInt;
	string valorString;
	while (ss >> valorString) {
		ss >> valorInt;
		diccAntiguo[valorString] = valorInt;
	}
	getline(cin, line);
	stringstream ss2(line);
	while (ss2 >> valorString) {
		ss2 >> valorInt;
		diccNuevo[valorString] = valorInt;
	}

	set<string> annadidos;
	set<string> eliminados;
	set<string> cambiados;
	
	for (auto elem : diccNuevo) {
		if (diccAntiguo.count(elem.first) == 1) {
			if (elem.second != diccAntiguo[elem.first]) {
				cambiados.insert(elem.first);
			}
		}
		else {
			annadidos.insert(elem.first);
		}
	}
	for (auto elem : diccAntiguo) {
		if (diccNuevo.count(elem.first) == 0) {
			eliminados.insert(elem.first);
		}
	}

	if (annadidos.size() == 0 && eliminados.size() == 0 && cambiados.size() == 0) {
		cout << "Sin cambios\n";
	}
	else {
		if (annadidos.size() > 0) {
			cout << "+ ";
			for (auto elem : annadidos) {
				cout << elem << ' ';
			}
			cout << '\n';
		}
		if (eliminados.size() > 0) {
			cout << "- ";
			for (auto elem : eliminados) {
				cout << elem << ' ';
			}
			cout << '\n';
		}
		if (cambiados.size() > 0) {
			cout << "* ";
			for (auto elem : cambiados) {
				cout << elem << ' ';
			}
			cout << '\n';
		}
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
	cin.ignore(100, '\n');
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