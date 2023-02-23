
/*Juan Carlos Llamas Núñez 
2º DG FAL*/


#include<iostream>
#include<fstream>

using namespace std;


bool resuelveCasos();
long long int numLetras(long long int n);
char letraEnPos(long long int k, long long int n);






/*n>=0*/
long long int numLetras(long long int n) {
	long long int letr;
	if (n == 0) {
		letr = 0;
	}
	else {
		letr = 2 * numLetras(n - 1) + n + 2;
	}
	return letr;
}




/*n>=1 && 0<=k<numLetras && v[0...numLetras) de char*/
char letraEnPos(long long int k, long long int n) {
	char dev;
	long long numLetrAnt = numLetras(n-1);
	if (k <= numLetrAnt) {
		dev = letraEnPos(k, n - 1);
	}
	else if(k <= numLetrAnt + 2 + n){
		if (k == numLetrAnt + 2 + n) {
			dev = 'H';
		}
		else if (k == numLetrAnt+1) {
			dev = 'B';
		}
		else {
			dev = 'U';
		}
	}
	else {
		dev = letraEnPos(k-numLetrAnt-n-2, n - 1);
	}
	return dev;
}
/*dev=v[k]*/

bool resuelveCasos() {
	long long int n, k;
	bool ok;
	cin >> n;
	if (!cin) {
		ok = false;
	}
	else {
		cin >> k;
		ok = true;
		cout << letraEnPos(k, n) << endl;
	}


	return ok;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCasos());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}