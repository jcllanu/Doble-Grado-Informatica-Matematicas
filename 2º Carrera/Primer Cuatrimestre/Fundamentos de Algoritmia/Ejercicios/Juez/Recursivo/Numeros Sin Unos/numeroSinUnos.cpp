/*Juan Carlos Llamas Núñez
2º DG FAL*/

#include <iostream>
#include<fstream>

using namespace std;


long long int numeros(long long int n, long long int pot10, long long int pot9);
bool resuelveCaso();
long long int valcifra(long long int n);
void magnitud(long long int n, long long int& pot10, long long int& pot9);

bool resuelveCaso() {
	long long int n;
	cin >> n;
	if (!std::cin) {
		return false;
	}
	else {
		long long int pot10, pot9;
		magnitud(n, pot10, pot9);
		cout << numeros(n, pot10, pot9) << endl;

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


/*n>=0*/
long long int numeros(long long int n, long long int pot10, long long int pot9) {
	long long int dev;
	if (n == 0) {
		dev = 1;
	}
	else {
		if (n / pot10 == 0 && n != 0) {
			while (pot10 > 1 && n / pot10 == 0) {
				pot10 /= 10;
				pot9 /= 9;
			}
		}
		if (pot10 == 1) {
			if (n <= 1) {
				dev = 1;
			}
			else {
				dev = n;
			}
		}
		else if (n / pot10 == 1) {
			dev = pot9;
		}
		else {
			dev = valcifra(n / pot10)*pot9 + numeros(n - (n / pot10)*pot10, pot10 / 10, pot9 / 9);
		}
	}
	return dev;
}
/*dev=#i: 0<=i<=n: noUnos(i)

	noUnos(i)= p.t j: 0 <= j < magnitud(i): (i div 10^j) mod 10 != 1

	magnitud(i) = min k: 0<=k<=i: (i div 10^(k+1) = 0)
*/

void magnitud(long long int n, long long int& pot10, long long int& pot9) {
	pot10 = 1;
	pot9 = 1;

	while (n >= 10) {
		n = n / 10;
		pot10 *= 10;
		pot9 *= 9;
	}
}

long long int valcifra(long long int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n - 1;
	}
}