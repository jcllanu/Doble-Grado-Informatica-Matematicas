#include<iostream>
#include<fstream>
using namespace std;

bool polidivisible(long long int N, long long int magnitud);
long long int magnitud(long long int N);


bool resuelveCaso() {
	long long int N;
	cin >> N;
	if (!cin) {
		return false;
	}
	else {
		if (polidivisible(N, magnitud(N))) {
			cout << "POLIDIVISIBLE" << endl;
		}
		else {
			cout << "NO POLIDIVISIBLE" << endl;
		}
		return true;
	}
}

bool polidivisible(long long int N, long long int magnitud) {
	if (magnitud == 1) {
		return true;
	}
	else {
		return N % magnitud == 0 && polidivisible(N / 10, magnitud - 1);
	}
}

long long int magnitud(long long int N) {
	long long int cont = 1;
	while (N / 10 > 0) {
		N /= 10;
		cont++;
	}
	return cont;
}
int main() {
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/

	while (resuelveCaso());

	/*#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}
