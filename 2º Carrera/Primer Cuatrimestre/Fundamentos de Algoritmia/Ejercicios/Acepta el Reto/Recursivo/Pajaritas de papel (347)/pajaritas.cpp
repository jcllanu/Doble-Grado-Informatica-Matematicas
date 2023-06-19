#include<iostream>
#include<fstream>
using namespace std;

long long int pajaritas(long long int alto, long long int ancho);


bool resuelveCaso() {
	long long int alto, ancho;
	cin >> alto;
	cin >> ancho;
	if (ancho == 0 && alto == 0) {
		return false;
	}
	else {
		cout << pajaritas(alto, ancho) << endl;

		return true;
	}

}

long long int pajaritas(long long int alto, long long int ancho) {
	if (alto < 10 || ancho < 10) {
		return 0;
	}
	else {
		if (ancho > alto) {
			return ancho / alto + pajaritas(alto,ancho%alto);
		}
		else {
			return alto / ancho + pajaritas(alto%ancho, ancho);
		}
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
