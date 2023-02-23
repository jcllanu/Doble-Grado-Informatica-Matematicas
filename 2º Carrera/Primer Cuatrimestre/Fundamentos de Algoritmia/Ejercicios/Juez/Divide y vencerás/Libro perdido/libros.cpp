/*Juan Carlos Llamas Núñez 2ºDG FAL*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int indice(vector<int> v, int ini, int fin);

void resuelveCaso() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}
	cout << indice(v, 0, v.size() - 1) << endl;
}


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

int indice(vector<int> v, int ini, int fin) {
	int mitad = (ini + fin) / 2;
	if (mitad<2 || mitad>v.size() - 3) {/*Se puede calcular de manera sencilla con un método directo. 
										Con esta distinción nos aseguramos que las posiciones desde a mitad-2 a mitad+2 son posiciones válidas*/
		for (int i = ini; i + 1 <= fin; i+=2) {
			if (v[i] != v[i + 1]) {
				return i;
			}
		}
		return fin;
	}
	else {/*Hacemos una distición de casos según la posicioón de mitad sea par o impar*/
		if (mitad % 2 == 0) {/*Si la posición de mitad es par (recordemos que la primera posición es el cero que es par)*/

			if (v[mitad] == v[mitad + 1]) {/*Si en la posición siguiente a mitad está el mismo elemento que en mitad se 
										   tiene que todas las parejas de posiciones (2n,2n+1) con n pert{0,...mitad/2} 
										   tienen los mismos elementos. Nótese que la última de estas parejas es la que 
										   miramos(mitad, mitad+1). El libro que está solo una vez estará en el segmento
										   [mitad+2,fin]*/
				return indice(v, mitad + 2, fin);
			}
			else if (v[mitad] == v[mitad - 1]) {/*Si en la posición anterior a mitad está el mismo elemento que en mitad hay un decuadre, es decir,
												hay algún elemento en [ini,mitad-2] cuya imagen solo aparece una vez*/
				return indice(v, ini, mitad - 2);
			}
			else {
				return mitad;/*Caso base*/
			}
		}
		else {
			if (v[mitad] == v[mitad + 1]) {/*Si en la posición siguiente a mitad está el mismo elemento que en mitad hay un decuadre, es decir,
										hay algún elemento en [ini,mitad-1] cuya imagen solo aparece una vez*/
				return indice(v, ini, mitad - 1);
			}
			else if (v[mitad] == v[mitad - 1]) {/*Si en la posición anterior a mitad está el mismo elemento que en mitad se 
										   tiene que todas las parejas de posiciones (2n,2n+1) con n pert{0,...(mitad-1)/2} 
										   tienen los mismos elementos.Nótese que la última de estas parejas es la que 
										   miramos(mitad-1, mitad). El libro que está solo una vez estará en el segmento
										   [mitad+1,fin] */
				return indice(v, mitad + 1, fin);
			}
			else {/*Caso base*/
				return mitad;
			}
		}
	}
}
/*Orden de complejidad log(2)(N)*/