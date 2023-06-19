
#include <iostream>
#include <fstream>
using namespace std;


// Simulador 4 en línea
// Tablero formado por siete columnas y seis filas 
// Cada jugador coloca alternativamente una ficha en una columna comenzando a numerar en el cero, comenzando por las fichas amarillas.
// La entrada consta de una serie de casos de prueba. Cada caso comienza con una linea en la que se
// indica el numero total de fichas que se utilizan en la partida. En la linea siguiente se van indicando las
// columnas elegidas por cada jugador. 
// Para cada caso de prueba se escribe en una línea ''Gana A'' si ha ganado el jugador que comienza la
// partida, ''Gana B'' si ha ganado el jugador con las fichas rojas y ''Empate'' si no ha ganado ninguno.

const int MAX_FILAS = 6;
const int MAX_COLUMNAS = 7;

typedef enum{A,B,V}tFicha;

typedef struct {
	tFicha matriz[MAX_FILAS][MAX_COLUMNAS];
	int max[MAX_COLUMNAS];
} tTablero;

typedef struct {
	int x, y;
} tposicion;

bool resuelveCaso();

void mostrar(tTablero tablero);
bool propiedad(tTablero tablero, tposicion pos);
void inicializa(tTablero& tablero);


int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(in.rdbuf());
	system("PAUSE");
#endif

	return 0;
}




bool resuelveCaso() {
	bool encontrado = false;
	tTablero tablero;
	tposicion pos;
	tFicha ganador;
	int fichas, col, cont1, cont2;

	inicializa(tablero);
	cin >> fichas;
	if (fichas != 0) {

		for (int i = 0; i < fichas; i++) {

			cin >> col;

			if (i % 2 == 0) {
				tablero.matriz[tablero.max[col]][col] = A;
			}
			else {
				tablero.matriz[tablero.max[col]][col] = B;
			}
			tablero.max[col]--;



			cont1 = MAX_FILAS - 1;
			while (!encontrado && cont1 >= 0) {
				cont2 = 0;
				while (!encontrado && cont2 < MAX_COLUMNAS) {
					pos.x = cont1;
					pos.y = cont2;
					if (tablero.matriz[pos.x][pos.y] != V && propiedad(tablero, pos)) {
						encontrado = true;
						ganador = tablero.matriz[pos.x][pos.y];
					}
					cont2++;
				}
				cont1--;
			}
			if (encontrado) {
				for (int j=i+1; j < fichas; j++) {
					cin >> col;
				}
				i = fichas;
			}
		}

		
		if (!encontrado) {
			cout << "Empate";
		}
		else if (ganador == A) {
			cout << "Gana A";
		}
		else {
			cout << "Gana B";
		}
		cout << endl;

		return true;
	}
	else {
		return false;
	}

}

void mostrar(tTablero tablero) {
	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			if (tablero.matriz[i][j] == A) {
				cout << "A";
			}
			else if (tablero.matriz[i][j] == B) {
				cout << "B";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl << endl << endl;
}

bool propiedad(tTablero tablero, tposicion pos) {
	bool ok = true;

	int cont = 1;
	while (ok && cont < 4) {
		if (pos.y + cont >= MAX_COLUMNAS || tablero.matriz[pos.x][pos.y + cont] != tablero.matriz[pos.x][pos.y]) {
			ok = false;
		}
		cont++;
	}
	if (!ok) {
		cont = 1;
		ok = true;
		while (ok && cont < 4) {
			if (pos.x - cont < 0 || tablero.matriz[pos.x - cont][pos.y] != tablero.matriz[pos.x][pos.y]) {
				ok = false;
			}
			cont++;
		}
		if (!ok) {
			cont = 1;
			ok = true;
			while (ok && cont < 4) {
				if (pos.x - cont < 0 || pos.y + cont >= MAX_COLUMNAS || tablero.matriz[pos.x - cont][pos.y + cont] != tablero.matriz[pos.x][pos.y]) {
					ok = false;
				}
				cont++;
			}
			if (!ok) {
				cont = 1;
				ok = true;
				while (ok && cont < 4) {
					if (pos.x - cont < 0 || pos.y - cont < 0 || tablero.matriz[pos.x - cont][pos.y - cont] != tablero.matriz[pos.x][pos.y]) {
						ok = false;
					}
					cont++;
				}
			}
		}
	}

	return ok;

}

void inicializa(tTablero& tablero) {
	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			tablero.matriz[i][j] = V;
		}
	}
	for (int j = 0; j < MAX_COLUMNAS; j++) {
		tablero.max[j] = MAX_FILAS - 1;
	}

}