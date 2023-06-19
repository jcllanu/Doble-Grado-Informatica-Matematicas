#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void resuelveCaso();
int resolver(string cadena, int maximo);
int main() {

	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	/*#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/
	return 0;
}

void resuelveCaso() {
	int N;
	string cadena;
	cin >> N;
	cin >> cadena;
	for (int i = 0; i < cadena.length(); i++) {
		cadena[i] -= '0';
	}
	cout << resolver(cadena, N) << endl;
}
int resolver(string cadena, int maximo) {
	int resultado = 0, suma = 0, inicio = 0, fin = 0;
	while (fin != cadena.length()) {
		if (suma < maximo) {
			suma += cadena[fin];
			fin++;
		}
		else if (suma == maximo) {
			resultado++;
			suma += cadena[fin];
			suma -= cadena[inicio];
			fin++;
			inicio++;
		}
		else {
			suma -= cadena[inicio];
			inicio++;
		}
	}
	while (suma > maximo) {
		suma-= cadena[inicio];
		inicio++;
	}
	if (suma == maximo) {
		resultado++;
	}
	return resultado;
}
