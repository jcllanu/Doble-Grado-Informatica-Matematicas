#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

typedef int tCalculadora[3][3];

void iniciocalculadora(tCalculadora & calculadora) {
	calculadora[0][0] = 7;
	calculadora[0][1] = 8;
	calculadora[0][2] = 9;
	calculadora[1][0] = 4;
	calculadora[1][1] = 5;
	calculadora[1][2] = 6;
	calculadora[2][0] = 1;
	calculadora[2][1] = 2;
	calculadora[2][2] = 3;
}

void posicion(tCalculadora & calculadora, int numero, int& filn, int& coln) {
	int fila = 0;
	bool encontrado = false;
	while (fila < 3 && !encontrado) {
		int columna = 0;
		while (columna < 3 && !encontrado) {
			if (calculadora[fila][columna] == numero) {
				filn = fila;
				coln = columna;
				encontrado = true;
			}

			columna++;

		}
		fila++;
	}
}


bool jugar(tCalculadora & calculadora, int suma, int numero, int filn, int coln) {

	if (suma >= 31) {
		return false;
	}
	int fila = 0;

	while (fila < 3) {
		int columna = 0;
		while (columna < 3) {
			if (fila != filn && columna == coln) {
				if (jugar(calculadora, suma + calculadora[fila][columna], calculadora[fila][columna], fila, columna)) {
					return false;

				}
			}
			if (columna != coln && fila == filn) {
				if (jugar(calculadora, suma + calculadora[fila][columna], calculadora[fila][columna], fila, columna)) {
					return false;

				}

			}
			columna++;
		}
		fila++;
	}

	return true;

}

void resuelveCaso() {
	int puntRecibida, ultimoDigito;
	cin >> puntRecibida >> ultimoDigito;
	tCalculadora calcu;
	iniciocalculadora(calcu);
	int fila, columna;
	posicion(calcu, ultimoDigito, fila, columna);
	if (!jugar(calcu, puntRecibida, ultimoDigito, fila, columna)) {
		cout << "GANA" << endl;
	}
	else {
		cout << "PIERDE" << endl;
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