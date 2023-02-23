
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "ConjuntosDisjuntos.h"

using namespace std;

bool check(int f, int c, int F, int C) {//Comprueba si los accesos a la tabla son correctos
	return f >= 0 && c >= 0 && f < F && c < C;
}

int valor(int f, int c, int C) {//Devuelve el numero asociado a cada fila numneradas de izquierad a derecha y de arriba hacia abajo
	return C * f + c;
}

bool resuelveCaso() {
	int F, C;
	cin >> F >> C;
	if (!cin)
		return false;

	char aux;
	ConjuntosDisjuntos componentes(F*C);
	vector<vector<bool>> petroleo(F, vector<bool>(C));//Va a llevar el mapa de las manchas de petroleo

	for (int i = 0; i < F; i++) {//Lectura del mapa de petroleo
		cin.get(aux);
		for (int j = 0; j < C; j++) {
			cin.get(aux);
			if (aux == '#') {
				petroleo[i][j] = true;
			}
			else {
				petroleo[i][j] = false;
			}
		}
	}

	int elems_max_componente = 0;
	for (int i = 0; i < F; i++) {//Actualización de las componentes conexas realizando uniones y actualizacion del tamano maximo
		for (int j = 0; j < C; j++) {
			if (petroleo[i][j]) {
				elems_max_componente = max(elems_max_componente, 1);
				if (check(i - 1, j - 1, F, C) && petroleo[i - 1][j - 1]) {//Arriba izquierda
					componentes.unir(valor(i, j, C), valor(i - 1, j - 1, C));
					elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
				}
				if (check(i - 1, j, F, C) && petroleo[i - 1][j]) {//Arriba
					componentes.unir(valor(i, j, C), valor(i - 1, j, C));
					elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
				}
				if (check(i - 1, j + 1, F, C) && petroleo[i - 1][j + 1]) {//Arriba derecha
					componentes.unir(valor(i, j, C), valor(i - 1, j + 1, C));
					elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
				}
				if (check(i, j - 1, F, C) && petroleo[i][j - 1]) {//Izquierda
					componentes.unir(valor(i, j, C), valor(i, j - 1, C));
					elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
				}
				if (check(i, j + 1, F, C) && petroleo[i][j + 1]) {//Derecha
					componentes.unir(valor(i, j, C), valor(i, j + 1, C));
					elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
				}
				if (check(i + 1, j - 1, F, C) && petroleo[i + 1][j - 1]) {//Abajo izquierda
					componentes.unir(valor(i, j, C), valor(i + 1, j - 1, C));
					elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
				}
				if (check(i + 1, j, F, C) && petroleo[i + 1][j]) {//Abajo
					componentes.unir(valor(i, j, C), valor(i + 1, j, C));
					elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
				}
				if (check(i + 1, j + 1, F, C) && petroleo[i + 1][j + 1]) {//Abajo derecha
					componentes.unir(valor(i, j, C), valor(i + 1, j + 1, C));
					elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
				}
			}
		}
	}
	cout << elems_max_componente << ' ';
	
	long long int N, i, j;
	cin >> N;
	for (long long int k = 0; k < N; k++) {//Lectura de las nuevas manchas y unión de las componentes conexas
		cin >> i >> j;
		i--;
		j--;
		elems_max_componente = max(elems_max_componente, 1);
		if (!petroleo[i][j]) {
			petroleo[i][j] = true;
			
			if (check(i - 1, j - 1, F, C) && petroleo[i - 1][j - 1]) {//Arriba izquierda
				componentes.unir(valor(i, j, C), valor(i - 1, j - 1, C));
				elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
			}
			if (check(i - 1, j, F, C) && petroleo[i - 1][j]) {//Arriba
				componentes.unir(valor(i, j, C), valor(i - 1, j, C));
				elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
			}
			if (check(i - 1, j + 1, F, C) && petroleo[i - 1][j + 1]) {//Arriba derecha
				componentes.unir(valor(i, j, C), valor(i - 1, j + 1, C));
				elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
			}
			if (check(i, j - 1, F, C) && petroleo[i][j - 1]) {//Izquierda
				componentes.unir(valor(i, j, C), valor(i, j - 1, C));
				elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
			}
			if (check(i, j + 1, F, C) && petroleo[i][j + 1]) {//Derecha
				componentes.unir(valor(i, j, C), valor(i, j + 1, C));
				elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
			}
			if (check(i + 1, j - 1, F, C) && petroleo[i + 1][j - 1]) {//Abajo izquierda
				componentes.unir(valor(i, j, C), valor(i + 1, j - 1, C));
				elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
			}
			if (check(i + 1, j, F, C) && petroleo[i + 1][j]) {//Abajo
				componentes.unir(valor(i, j, C), valor(i + 1, j, C));
				elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
			}
			if (check(i + 1, j + 1, F, C) && petroleo[i + 1][j + 1]) {//Abajo derecha
				componentes.unir(valor(i, j, C), valor(i + 1, j + 1, C));
				elems_max_componente = max(elems_max_componente, componentes.cardinal(valor(i, j, C)));
			}
		}
		cout << elems_max_componente << ' ';
	}
	cout << '\n';
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	/*int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}*/
	while (resuelveCaso());


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
