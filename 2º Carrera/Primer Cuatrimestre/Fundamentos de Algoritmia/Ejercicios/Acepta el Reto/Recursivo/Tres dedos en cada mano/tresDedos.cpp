#include<iostream>
#include<fstream>
using namespace std;

void base6(long long int N);


void resuelveCaso() {
	long long int N;
	cin >> N;
	base6(N);
	cout << endl;
}

void base6(long long int N) {
	if (N < 6) {
		cout << N;
	}
	else {
		base6(N / 6);
		cout << N % 6;
	}
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
