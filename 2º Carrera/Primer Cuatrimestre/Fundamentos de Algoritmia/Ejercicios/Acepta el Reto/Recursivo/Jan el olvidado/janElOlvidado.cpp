#include<iostream>
#include<fstream>
using namespace std;

long long int resuelve();


void resuelveCaso() {
	
	cout << resuelve() << endl;

}

long long int resuelve() {
	char aux;
	cin >> aux;
	if (aux == '+') {
		return resuelve() + resuelve();
	}
	else if (aux == '-') {
		return resuelve() - resuelve();
	}
	else if (aux == '*') {
		return resuelve() * resuelve();
	}
	else if (aux == '/') {
		return resuelve() / resuelve();
	}
	else {
		aux = aux - '0';
		long long int dev = int(aux);
		return dev;
	}
}

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
