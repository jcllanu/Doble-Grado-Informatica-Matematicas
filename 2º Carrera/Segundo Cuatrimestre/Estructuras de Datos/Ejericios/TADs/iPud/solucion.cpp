
//JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <fstream>
#include<string>
#include "ipud.h"

using namespace std;

bool resuelveCaso() {
	string orden;
	cin >> orden;
	if (!cin)
		return false;

	ipud apel;
	string cancion, artista;
	int duracion, n;
	while(orden != "FIN") {
		if (orden == "addSong") {
			cin >> cancion >> artista >> duracion;
			try {
				apel.addSong(cancion, artista, duracion);
			}
			catch (domain_error e) {
				cout << "ERROR addSong\n";
			}
		}
		else if (orden == "addToPlaylist") {
			cin >> cancion ;
			try {
				apel.addToPlaylist(cancion);
			}
			catch (domain_error e) {
				cout << "ERROR addToPlaylist\n";
			}
		}
		else if (orden == "play") {
			try {
				string c = apel.current();
				apel.play();
				cout << "Sonando "<<c << '\n';
			}
			catch (domain_error e) {
				cout << "No hay canciones en la lista\n";
			}
		}
		else if (orden == "totalTime") {
			cout << "Tiempo total " << apel.totalTime() << '\n';
		}
		else if (orden == "deleteSong") {
			cin >> cancion;
			try {
				apel.deleteSong(cancion);
			}
			catch (domain_error e) {
				cout << "ERROR deleteSong\n";
			}
		}
		else if (orden == "recent") {
			cin >> n;
			vector<string> dev = apel.recent(n);
			if (dev.size() == 0) {
				cout << "No hay canciones recientes\n";
			}
			else {
				cout << "Las " << dev.size() << " mas recientes\n";
				for (string cancion : dev) {
					cout << "    " << cancion << '\n';
				}
			}
			

		}
		else if (orden == "current") {
			try {
				apel.current();
			}
			catch (domain_error e) {
				cout << "ERROR current\n";
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
