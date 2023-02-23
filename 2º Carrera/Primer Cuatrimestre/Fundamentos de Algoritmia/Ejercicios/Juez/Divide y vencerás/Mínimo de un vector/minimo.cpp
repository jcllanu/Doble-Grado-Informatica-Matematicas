/*Juan Carlos Llamas Núñez 2ºDG FAL*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int minimo(vector<int> v, int ini, int fin);

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) {
		return false;
	}
	vector<int> v(N);
	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}
	cout << minimo(v, 0,v.size()-1) << endl;
	return true;
}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while(resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}


int minimo(vector<int> v, int ini, int fin) {
	if (v[ini]>= v[fin]) {/*Caso base pues si el último elemnto del segmento es menor que el primero ,
						  sabiendo que es una rotación de un segmento estrictamente creciente, 
						  se tiene que el "salto" del minimo al maximo no está en el segmento. Por ello se tiene que el mínimo es v[fin] */
		return v[fin];
	}
	else {
		if (fin - ini == 1) {/*Caso base pues hemos llegado a que v[ini] es el mínimo y v[fin] es el máximo*/
			return v[ini];
		}
		int mitad = (ini + fin) / 2;
		if (v[mitad] > v[fin]){/*si v[min]>v[fin], el segmento [ini,fin] es estrictamente decreciente y 
									el "salto" no se encuentra ahí. Por tanto el salto está en [ini,mitad]*/
			return minimo(v, ini, mitad);
		}
		else {/*si v[min]<=v[fin], hemos encontrado el salto y miramos en el segmento [mitad,fin]*/
			return minimo(v, mitad, fin);
		}
	}
}
/*El orden de complejidad es log(2)(N)

*/