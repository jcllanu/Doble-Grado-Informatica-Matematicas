
//JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ventaLibros.h"

using namespace std;


string tratarString(string libro) {
	int pos = 0;
	while (libro[pos] == ' ') {
		pos++;
	}
	return libro.substr(pos, libro.size() - 1);
}

bool resuelveCaso() {
	int numOrdenes;
	
	cin >> numOrdenes;
	if (!cin)
		return false;
	string orden;
	string titulo;
	int numEjemplares;

	ventaLibros v;
	for (int i=0; i<numOrdenes; i++) {
		cin >> orden;
		if (orden == "nuevoLibro") {
			cin >> numEjemplares;
			getline(cin, titulo);
			titulo = tratarString(titulo);
			v.nuevoLibro(numEjemplares, titulo);
		}
		else if (orden == "comprar") {
			getline(cin, titulo);
			titulo = tratarString(titulo);
			try {
				v.comprar(titulo);
			}
			catch (invalid_argument e) {
				cout << e.what() << '\n';
			}
			catch (out_of_range e) {
				cout << e.what() << '\n';
			}
		}
		else if (orden == "numEjemplares") {
			getline(cin, titulo);
			titulo = tratarString(titulo);
			try {
				int num = v.numEjemplares(titulo);
				cout << "Existen " << num << " ejemplares del libro " << titulo << '\n';
			}
			catch (invalid_argument e) {
				cout << "No existe el libro " << titulo << " en el sistema\n";
			}
		}
		else if (orden == "top10") {
			cout << "TOP10\n";
			vector<string> dev = v.top10();
			for (string libro : dev)
				cout << "    " << libro << '\n';
		}
		else if (orden == "estaLibro") {
			getline(cin, titulo);
			titulo = tratarString(titulo);
			if (v.estaLibro(titulo)) {
				cout << "El libro " << titulo << " esta en el sistema\n";
			}
			else {
				cout << " No existe el libro " << titulo << " en el sistema\n";
			}
		}
		else if (orden == "elimLibro") {
			getline(cin, titulo);
			titulo = tratarString(titulo);
			v.elimLibro(titulo);
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
