#include<iostream>
#include<fstream>
using namespace std;

bool resuelveCaso();


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

bool resuelveCaso() {
	int ini, fin, n;
	cin >> ini;
	cin >> fin;
	cin >> n;
	if (ini == 0 && fin == 0 && n == 0) {
		return false;
	}
	else {
		int k, aux;
		
		cin >> k;
		for (long long int i = 0; i < k; i++) {
			cin >> aux;
			if (!(aux < ini || aux > fin)) {
				if (aux <= n) {
					ini = aux;
				}
				else if (aux > n) {
					fin = aux-1;
				}
			}
		}
		if (ini==fin) {
			cout << "LO SABE" << endl;
		}
		else {
			cout << "NO LO SABE" << endl;
		}
		return true;
	}

}