/*Juan Carlos Llamas Núñez
2º DG FAL*/

#include <iostream>
#include<fstream>

using namespace std;

long long int cifras(long long int n);
void polidivisibles(long long int N, long long int D, long long int cifr);
void escribePolidivisibles(long long int raiz, int maxDigitos);
bool resuelveCaso() {
	long long int N, D;
	cin >> N;
	if (!std::cin) {
		return false;
	}
	else {
		cin >> D;
		
		escribePolidivisibles(N, D);
		cout << "---" << endl;
		return true;
	}

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

long long int cifras(long long int n) {
	long long int cont = 1;
	long long int pot10 = 10;
	while (n / pot10 > 0) {
		cont++;
		pot10 *= 10;
	}
	return cont;
}
void polidivisibles(long long int N, long long int D, long long int cifr) {
	cout << N << endl;
	if (cifr < D) {
		for (long long int i = 0; i < 10; i++) {
			if ((N * 10 + i) % (cifr+1) == 0){
				polidivisibles(N * 10 + i, D, cifr + 1);
			}
		}
	}
}
void escribePolidivisibles(long long int raiz, int maxDigitos) {
	long long int cifr = cifras(raiz);
	polidivisibles(raiz, maxDigitos, cifr);
}
