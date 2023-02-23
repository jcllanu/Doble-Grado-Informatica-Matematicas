/*Juan Carlos Llamas Núñez
	2º DG FAL*/

#include<vector>
#include<iostream>
#include<fstream>

using namespace std;
const int N = 9;
typedef enum { DAMA, TORRE }tPieza;


typedef struct {
	bool v[N][N];
	int cont;
}tInvalida;

typedef struct {
	int columna;
	tPieza pieza;
}tColumnaPieza;

bool resuelveCaso();
int numTableros(vector<tColumnaPieza>& solucion, vector<bool>& columnas, vector<bool>& diagonalesTODAS, vector<bool>& diagonalesDAMAS, const tInvalida& invalidas, int k, int& T, int& R);
void print(const vector<tColumnaPieza>& solucion);

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

bool resuelveCaso() {
	int T, R, invalid;
	cin >> T;
	if (!cin) {
		return false;
	}
	else {
		cin >> R;
		cin >> invalid;

		vector<tColumnaPieza> solucion(T + R);
		vector<bool> columnas(T + R);
		vector<bool> diagonalesTODAS(4 * (T + R) - 2);
		vector<bool> diagonalesDAMAS(4 * (T + R) - 2);
		tInvalida tab;
		tab.cont = T + R;

		for (int i = 0; i < tab.cont;i++) {
			for (int j = 0; j < tab.cont; j++) {
				tab.v[i][j] = false;
				if (i < 3 || (i == 3 && j < tab.cont - 2)) {
					diagonalesDAMAS[i*tab.cont + j] = false;
					diagonalesTODAS[i*tab.cont + j] = false;
				}
			}
			columnas[i] = false;
		}
		int fila, columna;
		for (int i = 0; i < invalid; i++) {
			cin >> fila >> columna;
			fila--;
			columna--;
			tab.v[fila][columna] = true;
		}
			
		cout << numTableros(solucion, columnas, diagonalesTODAS, diagonalesDAMAS, tab, 0, T, R) << endl;
		return true;
	}
}


/*Mismo sistema de marcado y desmarcado que para el de las N reinas, salvo que en este caso hay que tener más precaución con el número de reinas y torres que nos quedan por poner, 
las casillas invalidas y que los marcados de las reinas y las torres son distintos*/

int numTableros(vector<tColumnaPieza>& solucion, vector<bool>& columnas, vector<bool>& diagonalesTODAS, vector<bool>& diagonalesDAMAS, const tInvalida& invalidas, int k, int& T, int& R) {
	int dev = 0;
	bool hayPieza = T > 0;
	bool yaMarcada1;
	bool yaMarcada2;
	for (int pieza = 1; pieza <= 2; pieza++) {/*Primero colocamos las torres y después las reinas*/
		if (hayPieza) {/*Si hay al menos una torre (o reina en su caso) que colocar...*/

			for (int i = 0; i < solucion.size(); i++) {
				solucion[k].columna = i;
				
				if (pieza == 1) {
					solucion[k].pieza = TORRE;
				}
				else {
					solucion[k].pieza = DAMA;
				}
				if (!(columnas[solucion[k].columna] || diagonalesDAMAS[k + solucion[k].columna] ||
					diagonalesDAMAS[3 * columnas.size() + solucion[k].columna - k - 2] ||  (diagonalesTODAS[k + solucion[k].columna] && solucion[k].pieza == DAMA )
					||(diagonalesTODAS[3 * columnas.size() + solucion[k].columna - k - 2] && solucion[k].pieza == DAMA) || invalidas.v[k][solucion[k].columna])) {
					columnas[i] = true;/*Marcado común de reina y torre*/
					yaMarcada1 = false;
					yaMarcada2 = false;
					if (diagonalesTODAS[k + solucion[k].columna]) {
						yaMarcada1 = true;
					}
					if (diagonalesTODAS[3 * columnas.size() + solucion[k].columna - k - 2]) {
						yaMarcada2 = true;
					}
					diagonalesTODAS[k + solucion[k].columna] = true;
					diagonalesTODAS[3 * columnas.size() + solucion[k].columna - k - 2] = true;
					if (pieza==2) {/*Marcado de reina*/
						diagonalesDAMAS[k + solucion[k].columna] = true;
						diagonalesDAMAS[3 * columnas.size() + solucion[k].columna - k - 2] = true;
						R--;
					}
					else {/*Marcado de torre*/
						T--;
					}

					if (k + 1 == solucion.size()) {/*Último nivel: solución encontrada*/

						/*print(solucion);*/
						dev++;
					}
					else {/*Buscamos una solución profundizando un nivel más*/
						dev += numTableros(solucion, columnas, diagonalesTODAS, diagonalesDAMAS, invalidas, k + 1, T, R);
					}
					columnas[i] = false;/*Dasmarcado común*/
					if (!yaMarcada1) {
						diagonalesTODAS[k + solucion[k].columna] = false;
					}
					if (!yaMarcada2) {
						diagonalesTODAS[3 * columnas.size() + solucion[k].columna - k - 2] = false;
					}
					if (pieza == 2) {/*Desmarcado dama*/
						diagonalesDAMAS[k + solucion[k].columna] = false;
						diagonalesDAMAS[3 * columnas.size() + solucion[k].columna - k - 2] = false;
						R++;
					}
					else {/*Desmarcado torre*/
						T++;
					}

				}
			}
		}
		hayPieza = R > 0;/*Para la siguiente vuelta del for más externo comprobamos si se pude poner aguna reina*/
	}

	return dev;
}

void print(const vector<tColumnaPieza>& solucion) {
	for (int j = 0; j < solucion.size(); j++) {
		for (int l = 0; l < solucion.size(); l++) {
			if (solucion[j].columna == l) {
				if (solucion[j].pieza == DAMA) {
					cout << "|D";
				}
				else {
					cout << "|T";
				}
			}
			else {
				cout << "| ";
			}
		}
		cout << "|" << endl;
	}
	cout << endl;

}