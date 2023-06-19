#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

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
	int N;
	cin >> N;
	
	if (N == 0) {
		return false;
	}
	else {
		int nuevoDato;
		cin >> nuevoDato; 
		int sumaMax = nuevoDato, s = nuevoDato;
		int sumaDesdeCero = nuevoDato, sumaMaxDesdeCero = nuevoDato, sumaMaxDesdeN;
		int b = 1, c = 0, a = 0;


		for (int i = 1; i < N; i++) {
			cin >> nuevoDato;
			sumaDesdeCero += nuevoDato;
			sumaMaxDesdeCero = max(sumaDesdeCero, sumaMaxDesdeCero);
		
			if (s >= 0) {
				s += nuevoDato;
			}
			else {
				s = nuevoDato;
				c = i;
			}
			if (sumaMax <= s) {
				b = i + 1;
				sumaMax = s;
				a = c;
			}
		
		}
		if (sumaMaxDesdeCero+s>sumaMax){
			sumaMax = sumaMaxDesdeCero + s;
		}
		cout << sumaMax << endl;
		return true;
	}

}
