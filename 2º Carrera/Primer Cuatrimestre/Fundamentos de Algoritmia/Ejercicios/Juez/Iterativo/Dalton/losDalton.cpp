/*Grupo DG de FAL, Juan Carlos Llamas y Adrián Sanjuán*/

/*La función solucion recibe un array de un máximo de 100000 elementos y un n con 2<=n<=100000 
y devuelve cierto si el array esta ordenado esctrictamente creciente hasta la posición n-1 y
falso en caso contrario*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool solucion(vector <int> v);

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0) {
		return false;
	}
	else {
		vector <int> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		if (solucion(v)) {
			cout << "DALTON" << endl;
		}
		else {
			cout << "DESCONOCIDOS" << endl;
		}
		return true;
	}
		

}


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


/*{ N entero
	V[0...100.000) de enteros
	(2<=n<100.000) ^ (para todo i: 0<=i<=n-1: 1<=V[i] ^ V[i]<=1.000.000)}
	
	*/
bool solucion(vector <int> v) {
	bool estrcCrec = true, estrcDecr = true;
	int n = 1;
	/*I=(estrcCrec=(para todo i: 0 <= i < n-1: v[i] < v[i+1]) &&
		estrcDecr=(para todo i: 0 <= i < n-1: v[i] > v[i+1]) &&
		1 <= n <= N-1 )
	
	  C= N-1-n
	  */
	while (n != v.size()) {
		estrcCrec = estrcCrec && v[n - 1] < v[n];
		estrcDecr = estrcDecr && v[n - 1] > v[n];
		n++;
	}

	return estrcCrec || estrcDecr;
}
/* func solucion(n: ent, V[0...100.000) de ent) dev b: bool

	{b = (para todo i: 0 <= i < N-1: v[i] < v[i+1]) o (para todo i: 0 <= i <= N-1: v[i] > v[i+1])}*/