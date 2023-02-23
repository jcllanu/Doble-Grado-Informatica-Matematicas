/*Juan Carlos Llamas Núñez 2ºDG FAL*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;


typedef struct {
	int pos;
	bool encontrado;
}tSolucion;

tSolucion buscar(vector<int> v, int ini, int fin, int buscado);
/*Encontrar la solución se puede reducir a un problema de búsqueda binariabusqueda binaria.
Al leer los datos, guardamos en cada posición del vector, el valor que corresponda menos la posición que ocupa. tomando el mismo ejemplo del enunciado si se nos proporciona el vector:
 2 4 7 9 12 15 22 nosotros vamos a guardar el vector 2 3 5 6 8 10 16. Así, cuando se cante el número 6, solo tenemos que limitarnos a mirar nuestro nuevo vector y fijarnos si hay un 6 en él.
 Si lo hay, significará que en el antiguo tenemos una posición tal que si se le suma 6 se obtiene el valor de dicha posición (en este caso 3+6=9 que está en la posición 3 */
bool resuelveCaso() {
	int N,cantado, aux;
	tSolucion solucion;
	cin >> N;
	cin >> cantado;
	vector<int> v(N);
	for (int i = 0; i < v.size(); i++) {
		cin >> aux;
		v[i] = aux - i;
	}
	solucion = buscar(v, 0, v.size() - 1, cantado);
	if (solucion.encontrado) {
		cout << solucion.pos + v[solucion.pos] << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return true;
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

/*La busqueda se ha implementado como una búsqueda binaria recursiva de un vetor ordenado*/
tSolucion buscar(vector<int> v, int ini, int fin, int buscado) {
	tSolucion sol;
	if (ini > fin) {
		sol.encontrado = false;
		sol.pos = ini;
	}
	else {
		int mitad = (ini + fin) / 2;
		if (buscado < v[mitad]) {
			sol = buscar(v, ini, mitad - 1, buscado);
		}
		else if (buscado == v[mitad]) {
			sol.encontrado = true;
			sol.pos = mitad;
		}
		else {
			sol = buscar(v, mitad + 1, fin, buscado);
		}
	}
	return sol;
}
/*El coste de la solución es log(2)(N)*/