#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;

void combinaciones(int C, int V, string helado);
long long int factorial(int n);

long long int comb;

void resuelveCaso() {
	int C, V;
	cin >> C;
	cin >> V;
	comb = factorial(C + V) / (factorial(C)*factorial(V));
	string helado = "";
	combinaciones(C, V, helado);
	cout << endl;

}


int main() {
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

/*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}

void combinaciones(int C, int V, string helado) {
	if (C == 0) {
		for (int i = 0; i < V; i++) {
			helado+="V";
		}
		comb--;
		cout << helado;
		if (comb != 0) {
			cout <<" ";
		}
	}
	else if (V == 0) {
		for (int i = 0; i < C; i++) {
			helado += "C";
		}
		comb--;
		cout << helado;
		if (comb != 0) {
			cout << " ";
		}
	}
	else {	
		combinaciones(C - 1, V, helado + "C");
		combinaciones(C, V-1, helado + "V");
	}
}

long long int factorial(int n) {
	long long int fact = 1;
	for (int i = 1; i <= n; i++) {
		fact = fact * i;
	}
	return fact;
}