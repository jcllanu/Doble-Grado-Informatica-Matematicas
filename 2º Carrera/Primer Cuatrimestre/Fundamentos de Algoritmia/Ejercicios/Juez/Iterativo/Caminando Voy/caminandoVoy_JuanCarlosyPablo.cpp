//Juan Carlos Llamas Núñez y Pablo Torre Piñana
// 2º DG FAL

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

/*
Segmentos [a,b)
A = precondicion = { D >= 0 y 1 <= N <= 200000 }
	func solucion(v:vect de ent, D: ent) dev b: bool
B = postcondicion = { b = (D >= max i,j :(0 <= i < j <= N && estrictCrec(i,j)) : V[j] - V[i]) }
estricCrec(a, b) = pt k : a <= k < b - 1 : V[k] < V[k + 1];

Invariante = ( d = max i, j : 0 <= i<j <= n y estricCrec(i, j) : V[j - 1] - V[i] &&
	1 <= n <= N &&
	p=min i: 0<=i<n && estricCrec(i, n): i &&
	s=v[p])

	Condicion del bucle:  ¬b = n = N
	Función de cota: C = N - n
*/
using namespace std;

bool solucion(vector<int> v, int D);

bool resuelveCaso() {
	int D, N;
	cin >> D;
	if (!std::cin) {
		return false;
	}
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	if (solucion(v, D)) {
		cout << "APTA" << endl;
	}
	else {
		cout << "NO APTA" << endl;
	}

		return true;

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

bool solucion(vector<int> v, int D) {
	int n = 1, d = 0, p=0, s=v[0];
	while (n != v.size()) {
		if (v[n - 1] >= v[n]) {
			p = n;
			s = v[n];
		}
		d = max(d, v[n] - s);
		n++;
	}
	return D >= d;
}