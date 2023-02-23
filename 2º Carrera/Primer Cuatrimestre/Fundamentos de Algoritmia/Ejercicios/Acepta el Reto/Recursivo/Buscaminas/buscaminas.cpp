#include<iostream>
#include<fstream>
using namespace std;


int const MAX_TAM = 50;

typedef struct {
	int fil, col;
}tPos;

const tPos v[8] = { {-1,-1},{-1,0}, {-1,1},{0,-1}, {0,1},{1,-1}, {1,0},{1,1} };

typedef struct {
	char a;
	bool mirada;
}tCelda;

typedef struct {
	tCelda tablero[MAX_TAM][MAX_TAM];
	int filas, columnas;
}tTablero;

bool descubrir(tTablero &tab, int fil, int col);
bool bomba(tTablero &tab, int fil, int col);
bool enTablero(const tTablero &tab, tPos pos);

bool resuelveCaso() {
	int filas, columnas;
	cin >> filas;
	if (!cin) {
		return false;
	}
	else {
		cin >> columnas;
		tTablero tab;
		tab.filas = filas;
		tab.columnas = columnas;
		for (int i=0; i < filas; i++) {
			for (int j = 0; j < columnas; j++) {
				cin >>tab.tablero[i][j].a;
				tab.tablero[i][j].mirada = false;
			}
		}

		int k, fil, col;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> fil;
			cin >> col;
			fil--;
			col--;
			if (descubrir(tab, fil, col)) {
				if (i == k - 1) {
					for (int i = 0; i < filas; i++) {
						for (int j = 0; j < columnas; j++) {
							if (!tab.tablero[i][j].mirada) {
								cout << "X";
							}
							else {
								cout << tab.tablero[i][j].a;
							}


						}
						cout << endl;
					}
					cout << endl;
				}
			}
			else {
				cout << "GAME OVER" << endl;
				break;
			}
		}



		return true;
	}

}

bool descubrir(tTablero &tab, int fil, int col) {
	tab.tablero[fil][col].mirada = true;
	if (tab.tablero[fil][col].a == '*') {
		return false;
	}
	else if (tab.tablero[fil][col].a == '-') {
		int cont = 0;
		for (int i = 0; i < 8; i++) {
			tPos nuevaPos = { fil + v[i].fil, col + v[i].col };
			if (enTablero(tab, nuevaPos) && bomba(tab, nuevaPos.fil, nuevaPos.col)) {
				cont++;
			}
			
		}
		if (cont > 0) {
			tab.tablero[fil][col].a = char(cont) + '0';
		}
		else {
			for (int i = 0; i < 8; i++) {
				tPos nuevaPos = { fil + v[i].fil, col + v[i].col };
				if (enTablero(tab, nuevaPos) && !tab.tablero[nuevaPos.fil][nuevaPos.col].mirada) {
					descubrir(tab, nuevaPos.fil, nuevaPos.col);
				}
			}
		}
		return true;
	}
	else {
		return true;
	}
}

int main() {
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/
	while (resuelveCaso());

	/*#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}

bool bomba(tTablero &tab, int fil, int col) {
	return tab.tablero[fil][col].a == '*';
}
bool enTablero(const tTablero &tab, tPos pos) {
	return pos.fil < tab.filas &&pos.col < tab.columnas&&pos.fil >= 0 && pos.col >= 0;
}