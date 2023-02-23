#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

void combinacionseUvas(const vector<long long int>& uvas, vector<bool>& solucion, const long long int& minimo, const long long int&  maxPeso, long long int&pesoActual, long long int&numComb, int k, int& uvasPuestas);/*QUITAR SOLUCION*/

bool resuelveCaso() {
	int numUvas;
	long long int maxPeso;
	cin >> maxPeso >> numUvas;
	if (maxPeso == 0 && numUvas == 0) {
		return false;
	}
	else {
		vector<long long int> uvas(numUvas);
		vector <bool> solucion(numUvas);
		
		cin >> uvas[0];
		long long int minimo = uvas[0];
		for (int i = 1; i < uvas.size(); i++) {
			cin >>uvas[i];
			minimo = min(minimo, uvas[i]);
		}
		long long int numComb = 0, pesoActual = 0;
		int uvasPuestas = 0;
		combinacionseUvas(uvas,  solucion, minimo, maxPeso, pesoActual, numComb,0, uvasPuestas);
		cout << numComb << endl;
		return true;
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
void combinacionseUvas(const vector<long long int>& uvas, vector<bool>& solucion, const long long int& minimo, const long long int&  maxPeso, long long int&pesoActual, long long int&numComb, int k, int& uvasPuestas) {/*QUITAR SOLUCION*/
	
		solucion[k] = true;
		uvasPuestas++;
		pesoActual += uvas[k];
		if (pesoActual + minimo * (12 - uvasPuestas) <= maxPeso) {
			if (uvasPuestas == 12) {
				numComb++;
			}
			else {
				if (k + 1 < uvas.size()) {
					combinacionseUvas(uvas, solucion, minimo, maxPeso, pesoActual, numComb, k + 1,uvasPuestas);
				}
			}
		}
		pesoActual -= uvas[k];
		uvasPuestas--;

		solucion[k] = false;
		if (k + 1 < uvas.size()) {
			combinacionseUvas(uvas, solucion, minimo, maxPeso, pesoActual, numComb, k + 1, uvasPuestas);
		}
	
}