
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

typedef struct {
	int tab[50][50];
	int fila, columna;
}tCalidades;

void resuelveCaso();
int estimacion(const vector<int>& maximos, int k);
void asignar(vector<int>& solucion, vector<bool>& quitanieves, int& calidad, int& mejorCalidad, const tCalidades& calidades, int k, const vector<int>& maximos, const vector<int>& anchoQuitanieves, const vector<int>& anchoCarreteras);



int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}

void resuelveCaso() {
	int numCarreteras, numQuitanieves;
	cin >> numQuitanieves >> numCarreteras;

	vector<int> solucion(numCarreteras);
	vector<bool> quitanieves(numQuitanieves + 1);
	vector<int> anchoQuitanieves(numQuitanieves + 1);
	vector<int> anchoCarreteras(numCarreteras);

	for (int i = 0; i < anchoQuitanieves.size() - 1; i++) {
		cin >> anchoQuitanieves[i];
	}
	anchoQuitanieves[anchoQuitanieves.size() - 1] = 0;/*Quitanieves de anchura 0*/
	for (int i = 0; i < anchoCarreteras.size(); i++) {
		cin >> anchoCarreteras[i];
	}
	tCalidades calidades;
	calidades.fila = numQuitanieves + 1;
	calidades.columna = numCarreteras;
	vector<int> maximos(numCarreteras);

	for (int i = 0; i < calidades.fila - 1; i++) {
		for (int j = 0; j < calidades.columna; j++) {
			cin >> calidades.tab[i][j];
			if (i == 0) {
				maximos[j] = calidades.tab[i][j];
			}
			else {
				maximos[j] = max(maximos[j], calidades.tab[i][j]);
			}
		}

		quitanieves[i] = false;
	}
	quitanieves[calidades.fila - 1] = false;
	for (int i = 0; i < calidades.columna; i++) {
		calidades.tab[calidades.fila - 1][i] = 0;
	}
	int mejorCalidad = -1, calidad = 0;
	asignar(solucion, quitanieves, calidad, mejorCalidad, calidades, 0, maximos, anchoQuitanieves, anchoCarreteras);
	cout << mejorCalidad << endl;

}

void asignar(vector<int>& solucion, vector<bool>& quitanieves, int& calidad, int& mejorCalidad, const tCalidades& calidades, int k, const vector<int>& maximos, const vector<int>& anchoQuitanieves, const vector<int>& anchoCarreteras) {

	for (int i = 0; i < quitanieves.size(); i++) {
		solucion[k] = calidades.tab[i][k];
		calidad += calidades.tab[i][k];/*Actualizar*/

		if (!(quitanieves[i] || anchoQuitanieves[i] > anchoCarreteras[k] || calidad + estimacion(maximos, k + 1) < mejorCalidad)) {/*Vemos si la solución es completable y si es prometedora*/
			if (i != quitanieves.size() - 1) {
				quitanieves[i] = true;/*Marcar*/
			}
			if (k + 1 == solucion.size()) {/*Si es el hijo del último nivel tenemos una nueva mejor solución*/
				mejorCalidad = calidad;
			}
			else {/*Avanzamos un nivel más en busca de completar la solución*/
				asignar(solucion, quitanieves, calidad, mejorCalidad, calidades, k + 1, maximos, anchoQuitanieves, anchoCarreteras);
			}
			quitanieves[i] = false;/*Desmarcar*/
		}
		calidad -= calidades.tab[i][k];/*Desactualizar*/
	}
}


int estimacion(const vector<int>& maximos, int k) {/*Para una solución en la que se han elegido ya k+1 quitanieves se va a sumar, como mucho,
													la calidad de cada quitanieves restante (N-k-1) realizando el trabajado en la carretera donde su calidad sea máxima*/
	int suma = 0;
	for (int i = k; i < maximos.size(); i++) {
		suma += maximos[i];
	}
	return suma;
}