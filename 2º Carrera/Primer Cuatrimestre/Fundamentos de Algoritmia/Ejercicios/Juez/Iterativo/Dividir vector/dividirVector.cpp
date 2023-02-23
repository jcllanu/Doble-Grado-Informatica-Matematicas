/*Grupo DG de FAL, Juan Carlos Llamas*/

/*La función solución recibe un array de MAX enteros y dos enteros n y p. Devuelve cierto sii
p divide al array en dos subarrays de tal forma que todo elemento del primero, incluendo hasta 
la posición p, es estrictamente menor que todo elemento del segundo*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int const MAX = 100000;
bool solucion(vector<int> v, int p);
void resuelveCaso();



void resuelveCaso() {
	int N, p;
	cin >> N;
	cin >> p;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	if (solucion(v, p)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos; 
	std::cin >> numCasos; 
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}


/*{A= (N>=1 && 0<=p<=N-1)}

	*/
bool solucion(vector<int> v, int p) {
	int n = 0, s = v[0];
	/*I=s=max i: 0<=i<=n: v[i] && 0<=n<=p
	 C=p-n*/
	while (n != p) {
		s = max(s ,v[n + 1]);
		n++;
	}
	/*{R= (s=max i: 0<=i<=p: v[i]) && (N>=1) && (0<=p<=N-1)}*/
	
	int m = p + 1;
	bool divide = true;
	/*I=(divide=para todo j: p < j <=m-1: s < V[j] &&
		p+1<=m<=N)
	  C=N-m;*/
	while (m != v.size()) {
		divide = divide && s < v[m];
		m++;
	}

	return divide;
}


/*
	func solucion(n: ent, p: ent, V[0...MAX) de ent) dev b: bool

	{b = para todo i,j : 0 <=  i <= p < j <=N-1 : v[i]<v[j]) o equivalentemente
	 b = para todo j: p < j <=N-1:(max i: 0<=i<=p:V[i]) < V[j]}*/