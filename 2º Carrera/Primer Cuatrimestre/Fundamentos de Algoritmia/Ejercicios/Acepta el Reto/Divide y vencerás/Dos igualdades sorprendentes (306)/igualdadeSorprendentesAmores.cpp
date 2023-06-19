#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
using namespace std;

bool resuelveCaso();
double const numAureo = (1 + sqrt(5)) / 2;
double absoluto(double x);
int const k = 46337;
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

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0) {
		return false;
	}
	else {
		double num;
		num = pow(numAureo, N) / sqrt(5);

		long long int sol = int(num);
		if (absoluto(sol - num) > 0.5) {
			if (absoluto(sol + 1- num) <= 0.5) {
				sol++;
			}
			if (absoluto(sol-1 -num ) <= 0.5) {
				sol--;
			}
		}
		cout << sol % k<< endl;
		return true;
	}

}
double absoluto(double x) {
	if (x >= 0) {
		return x;
	}
	else {
		return-x;
	}
}