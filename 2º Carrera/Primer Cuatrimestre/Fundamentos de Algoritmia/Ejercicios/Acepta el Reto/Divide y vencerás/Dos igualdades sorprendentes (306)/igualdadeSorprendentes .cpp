#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
using namespace std;

bool resuelveCaso();
int const k = 46337;

typedef struct {
	 int a1, a2, a3, a4;
}tMatriz2x2;



tMatriz2x2 potencia(tMatriz2x2 mat, int N);
tMatriz2x2 operator*(const tMatriz2x2& A, const tMatriz2x2& B);

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
	if (N == 0) {
		return false;
	}
	else {
		tMatriz2x2 mat;
		mat.a1 = 0;
		mat.a2 = 1;
		mat.a3 = 1;
		mat.a4 = 1;
		cout << potencia(mat, N).a2 << endl;
		return true;
	}

}

tMatriz2x2 potencia(tMatriz2x2 mat, int N) {
	tMatriz2x2 dev;
	
	if (N == 1) {
		dev=mat;
	}
	else {
		if (N % 2 == 0) {
			tMatriz2x2 aux= potencia(mat, N / 2);
			dev= aux * aux;
		}
		else {
			tMatriz2x2 aux = potencia(mat, (N-1)/ 2);
			dev= mat * (aux * aux);
		}
	}
	return dev;
}
tMatriz2x2 operator*(const tMatriz2x2& A, const tMatriz2x2& B) {
	tMatriz2x2 C;
	C.a1 = ((A.a1*B.a1)%k + (A.a2*B.a3) % k) % k;
	C.a2 = ((A.a1*B.a2) % k + (A.a2*B.a4) % k) % k;
	C.a3 = ((A.a3*B.a1) % k + (A.a4*B.a3) % k) % k;
	C.a4 = ((A.a3*B.a2) % k + (A.a4*B.a4) % k) % k;

	return C;
}