
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <string>

using namespace std;



bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	map<string,int> mapa;
	
	string nombre, calificacion;
	for (int i = 0; i < n; i++) {
		cin.ignore(100, '\n');
		getline(cin, nombre);
		cin >> calificacion;
		if (calificacion == "CORRECTO") {
			++mapa[nombre];
		}
		else {
			--mapa[nombre];
		}
		if (mapa[nombre] == 0) {
			mapa.erase(nombre);
		}
	}
	for (auto elem: mapa) {
		cout << elem.first << ", " << elem.second << '\n';
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
	while(resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}