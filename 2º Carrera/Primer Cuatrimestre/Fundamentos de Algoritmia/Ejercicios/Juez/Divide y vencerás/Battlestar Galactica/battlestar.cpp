/*Juan Carlos Llamas Núñez 2ºDG FAL*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

long long int inversiones(const vector< int>& v, vector< int>& aux, int ini, int fin);
long long int merge(const vector< int>& aux1, const vector< int>& aux2, vector< int>& aux);

/*El problema se reduce a calcular el número de intercambios o inversiones contiguos (transposiciones) que realizamos para oredenar un vector*/
/*Para resolverlo imlpementeamos una ordenación por mezcla para la cual necesitaremos un vector auxiliar aux donde iremos guardando cada subarray ya ordenado.*/
bool resuelveCaso() {
	long long int N;
	cin >> N;
	if (!cin) {
		return false;
	}
	vector<int> v(N);
	vector<int> aux(N);
	for (long long int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}
	cout << inversiones(v, aux, 0, v.size()) << endl;
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

long long int inversiones(const vector< int>& v, vector< int>& aux, int ini, int fin) {
	if (fin - ini <= 1) {/*Caso base: el vector aux tiene un tamaño de 1. El número de transposiciones para ordenar este vector es 0*/
		aux[0] = v[ini];
		return 0;
	}
	else {
		long long int intercambios;
		int mitad = (ini + fin) / 2;
		vector <int> aux1(mitad - ini);
		vector <int> aux2(fin - mitad);
		intercambios = inversiones(v, aux1, ini, mitad) + inversiones(v, aux2, mitad, fin);/*Calculamos las transposiciones de los segmentos [ini,mitad) y [mitad,fin) y 
																						   los guardamos ya ordenados en aux1 y aux2 respectivamente*/
		intercambios += merge(aux1, aux2, aux);/*Hacemos la mezcla y contamos todas las trasposiciones que se producen al mezclar los dos segmentos ordenados. El vector aux 
											   guarda el segmento [ini,fin) totalmente ordenado*/
		return intercambios;
	}
}
/*El coste de complejidad es N*log(2)(N) ya que estamos ejecutando el algoritmo de ordenación por mezcla*/


long long int merge(const vector< int>& aux1, const vector< int>& aux2, vector< int>& aux) {/*Algoritmo de mezcla*/
	long long int intercambios = 0;
	int contadorAux1 = 0, contadorAux2 = 0, contadorAux = 0;

	while (contadorAux1 < aux1.size() && contadorAux2 < aux2.size()) {
		if (aux1[contadorAux1] > aux2[contadorAux2]) {/*Las trasposiciones solo se producen en este caso y si se cumple esta condición el
													  número de transposiciones que se produce es igual a los elementos del vector aux1 
													  que todavía quedan por colocar, es decir, aux1.size()-contadorAux1*/
			aux[contadorAux] = aux2[contadorAux2];
			intercambios += (aux1.size() - contadorAux1);
			contadorAux2++;
		}
		else {
			aux[contadorAux] = aux1[contadorAux1];
			contadorAux1++;
		}
		contadorAux++;
	}
	if (contadorAux1 == aux1.size()) {
		while (contadorAux2 < aux2.size()) {
			aux[contadorAux] = aux2[contadorAux2];
			contadorAux++;
			contadorAux2++;
		}
	}
	else {
		while (contadorAux1 < aux1.size()) {
			aux[contadorAux] = aux1[contadorAux1];
			contadorAux++;
			contadorAux1++;
		}
	}
	return intercambios;
}