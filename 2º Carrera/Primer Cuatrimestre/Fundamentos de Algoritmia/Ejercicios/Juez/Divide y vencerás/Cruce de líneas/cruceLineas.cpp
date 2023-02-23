// Alberto Almagro Sánchez y Juan Carlos Llamas Núñez
#include <iostream>
#include <vector>
using namespace std;

/*
Precondición = { ordenado(v[0,N)) ^ (N > 0) }
ordenado(v[0,N)) = p.t. i: 0 <= i < N-1: v[i] <= v[i+1];
proc resolver(v[0,N) sec de ent, c ent, f ent) dev cruce: bool, pos1: ent, pos2: ent
Postcondición = { (cruce --> ((ex. i: 0 <= i < N: v[i] == 0)) ^ 
	^ (pos1 = max i: (0 <= i < N) ^ (v[i] == 0): i) ^ (pos2 = min i: (0 <= i < N) ^ (v[i] == 0): i))
	^ !cruce --> (!(ex. i: 0 <= i < N: v[i] == 0)) ^ 
	^ (pos1 = {(-1) si v[0] > 0
			  {max i: (0 <= i < N) ^ (v[i] < 0): i) en c.c.
	^ (pos2 = {n si v[n - 1] < 0
			  {min i: (0 <= i < N) ^ (v[i] > 0): i) en c.c.    }

Orden de complejidad: log(n)
Construímos un vector de diferencias (que es estrictamente creciente) y buscamos el 0 mediante búsqueda binaria.
Está inspirado en la resolución de intersección de curvas en matemáticas mediante el Teorema de Bolzano.
*/

typedef struct {
	int pos1;
	int pos2;
	bool cruce;
}tSolucion;

tSolucion resolver(vector<int> v, int c, int f) {
	tSolucion sol;
	if (c > f) {
		sol.cruce = false;
		sol.pos1 = c - 1;
		sol.pos2 = c;
		return sol;
	}
	int mitad = (c + f) / 2;
	if (v[mitad] == 0) {
		sol.cruce = true;
		sol.pos1 = mitad;
		sol.pos2 = mitad;
		return sol;
	}
	if (v[mitad] < 0) {
		return resolver(v, c, mitad - 1);
	}
	return resolver(v, mitad + 1, f);
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0)
		return false;
	vector<int> creciente(N);
	vector<int> decreciente(N);
	vector<int> diferencias(N);
	for (int i = 0; i < N; i++) {
		cin >> creciente[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> decreciente[i];
		diferencias[i] = decreciente[i] - creciente[i];
	}
	tSolucion sol = resolver(diferencias, 0, N - 1);
	if (sol.cruce) {
		cout << "SI " << sol.pos1 << endl;
	}
	else {
		cout << "NO " << sol.pos1 << " " << sol.pos2 << endl;
	}
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}