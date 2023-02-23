//Juan Carlos Llamas y Pablo Torre Piñana

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool solucion(const vector<int>& v, int D);
/*

A = precondicion = {D>= 0 y 1 <= N <= 200000}
	func
B = postcondicion = {r = D<= max i,j : 0 <= i < j <= N y estrictCrec(i,j): V[j] - V[i]}
estricCreci(a,b) = pt k: i <= k < j - 1: V[k] < V[k+1];

Invariante => d = max i,j: 0<= i<j<=n y estricCrec(i,j): V[j-1] - V[i] y 1 <= n <=N
Condicion del bucle=> ¬b= n = N
Función de cota = N - n




*/

bool resuelveCaso() {
	int D, N;
	int aux;
	vector<int>v;
	if (!std::cin) { // fin de la entrada
		return false;
	}
	cin >> D;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> aux;
		v.push_back(aux);
	}
	bool b = solucion(v, D);
	if(b){
		cout << "APTA" << endl;
	}else {
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
}bool solucion(const vector<int>& v, int D){
	long long int n = 1, d = 0, p = 0, s = v[0];	while (n != v.size()) {				if (v[n] <= v[n - 1]) { 			p = n;			s = v[p];		}		d = max(d, v[n] - s);		n++;	}	return (D <= d);}