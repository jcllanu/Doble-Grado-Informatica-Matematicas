#include<iostream>
#include<fstream>
using namespace std;

long long int longitud(long long int N);

bool resuelveCaso() {
	long long int N;
	cin >> N;
	if (!cin) {
		return false;
	}
	else {
		cout << longitud(N) << endl;
		return true;
	}
}

long long int longitud(long long int N) {
	if (N == 1) {
		return 4;
	}
	else {
		return 4 * N + 4*longitud(N / 2);
	}
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
