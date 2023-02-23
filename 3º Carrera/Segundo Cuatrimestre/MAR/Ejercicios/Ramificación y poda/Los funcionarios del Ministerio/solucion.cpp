
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
#include <climits>

using namespace std;

typedef struct {
	int tab[20][20];
	int lado;
}tTrabajos;

bool resuelveCaso();
int estimacion(const vector<int>& minimos, int k);
void asignar(vector<int>& solucion, vector<bool>& trabUsados, int& tiempo, int& mejorTiempo, const tTrabajos& trabajos, int k, const vector<int>& minimos);



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
	int N;
	cin >> N;
	if (N == 0) {
		return false;
	}
	else {
		vector<int> solucion(N);
		vector<bool> trabUsados(N);
		tTrabajos trabajos;
		trabajos.lado = N;
		vector<int> minimos(N);

		for (int i = 0; i < trabajos.lado; i++) {
			for (int j = 0; j < trabajos.lado; j++) {
				cin >> trabajos.tab[i][j];
				if (i == 0) {
					minimos[j] = trabajos.tab[i][j];
				}
				else {
					minimos[j] = min(minimos[j], trabajos.tab[i][j]);
				}
			}
			trabUsados[i] = false;
		}
		int mejorTiempo = 50000, tiempo = 0;
		asignar(solucion, trabUsados, tiempo, mejorTiempo, trabajos, 0, minimos);
		cout << mejorTiempo << endl;
		return true;
	}

}

void asignar(vector<int>& solucion, vector<bool>& trabUsados, int& tiempo, int& mejorTiempo, const tTrabajos& trabajos, int k, const vector<int>& minimos) {

	for (int i = 0; i < trabajos.lado; i++) {
		solucion[k] = trabajos.tab[i][k];
		tiempo += trabajos.tab[i][k];/*Actualizar*/

		if (!(trabUsados[i] || tiempo > mejorTiempo || tiempo + estimacion(minimos, k + 1) > mejorTiempo)) {/*Vemos si la solución es completable y si es prometedora*/
			trabUsados[i] = true;/*Marcar*/
			if (k + 1 == trabajos.lado) {/*Si es el hijo del último nivel tenemos una nueva mejor solución*/
				mejorTiempo = tiempo;
			}
			else {/*Avanzamos un nivel más en busca de completar la solución*/
				asignar(solucion, trabUsados, tiempo, mejorTiempo, trabajos, k + 1, minimos);
			}
			trabUsados[i] = false;/*Desmarcar*/
		}
		tiempo -= trabajos.tab[i][k];/*Desactualizar*/
	}
}


int estimacion(const vector<int>& minimos, int k) {/*Para una solución en la que se han elegido ya k+1 trabajos se va a sumar, al menos,
													el tiempo de cada trabajo restante (N-k-1) realizado por el trabajador más rápido en dicha tarea*/
	int suma = 0;
	for (int i = k; i < minimos.size(); i++) {
		suma += minimos[i];
	}
	return suma;
}