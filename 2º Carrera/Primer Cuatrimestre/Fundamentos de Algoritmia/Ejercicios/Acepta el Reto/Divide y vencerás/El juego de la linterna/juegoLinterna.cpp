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
	long long int N;
	cin >> N;
	if (!cin) {
		return false;
	}
	else {
		long long int vimenos1, vi;
		cin >> vimenos1;
		long long int minimo = vimenos1, maximo;
		bool dev = true,estrcDecr=true;
		for (long long int i = 1; i < N; i++) {
			cin >> vi;
			if (dev) {
				if (estrcDecr) {
					if (vi < vimenos1) {
						minimo = vi;
					}
					else {
						estrcDecr = false;
						maximo = vi;
					}
				}
				else {
					if (vi< minimo) {
						minimo = vi;
						estrcDecr = true;
					}
					else if (vi < maximo) {
						dev = false;
					}
					else {
						maximo = vi;
					}
				}
			}
			vimenos1 = vi;
		}
		if (!dev) {
			cout << "ELEGIR OTRA" << endl;
		}
		else {
			cout << "SIEMPRE PREMIO" << endl;
		}
		return true;
	}

}
