/*Juan Carlos Llamas N��ez 2�DG FAL*/

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
/*Encontrar la soluci�n se puede reducir a un problema de b�squeda binariabusqueda binaria.
Al leer los datos, guardamos en cada posici�n del vector, el valor que corresponda menos la posici�n que ocupa. tomando el mismo ejemplo del enunciado si se nos proporciona el vector:
 2 4 7 9 12 15 22 nosotros vamos a guardar el vector 2 3 5 6 8 10 16. As�, cuando se cante el n�mero 6, solo tenemos que limitarnos a mirar nuestro nuevo vector y fijarnos si hay un 6 en �l.
 Si lo hay, significar� que en el antiguo tenemos una posici�n tal que si se le suma 6 se obtiene el valor de dicha posici�n (en este caso 3+6=9 que est� en la posici�n 3 */
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

/*La busqueda se ha implementado como una b�squeda binaria recursiva de un vetor ordenado*/
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
/*El coste de la soluci�n es log(2)(N)*/