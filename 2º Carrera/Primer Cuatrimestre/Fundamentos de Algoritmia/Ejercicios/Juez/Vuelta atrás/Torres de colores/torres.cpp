/*Juan Carlos Llamas Núñez 
	2º DG FAL*/

#include<vector>
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

bool resuelveCaso();
bool esValido(vector<int>& colores, vector<int>& solucion, vector<int>& numColores, int k);
string toString(int i);

int main() {
	#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf=std::cin.rdbuf(in.rdbuf());
	#endif
	while (resuelveCaso());
	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif


	return 0;
}

bool resuelveCaso() {
	vector<int> colores(3);
	int N;
	cin >> N >> colores[0] >> colores[1] >> colores[2];
	if (colores[0] == 0 && colores[1] == 0 && colores[2] == 0) {
		return false;
	}
	else {
		vector<int> solucion (N), numColores(3);
		numColores[0] = 0;
		numColores[1] = 0;
		numColores[2] = 0;

		if (colores[1] > 0) {
			solucion[0] = 2;
			colores[1]--;
			numColores[1]++;
			if (!esValido(colores, solucion, numColores, 1)) {
				cout << "SIN SOLUCION" << endl;
			}
		}
		else {
			cout << "SIN SOLUCION" << endl;
		}
		
		cout << endl;



		return true;
	}
}

bool esValido(vector<int>& colores, vector<int>& solucion, vector<int>& numColores, int k) {
	bool dev = false;
	for (int i = 0; i < 3; i++) {
		if (i==2){
			if (solucion[k - 1] != 3) {
				if (numColores[2] + 1 <= numColores[0]) {
					if (colores[i] > 0) {
						solucion[k] = i + 1;
						colores[i]--;
						numColores[i]++;
						if (k == solucion.size() - 1) {
							if (numColores[1] > numColores[0] + numColores[2]) {
								for (int i = 0; i < solucion.size(); i++) {
									cout << toString(solucion[i]) << " ";
								}
								cout << endl;
								dev = true;
							}
						}
						else {
							if (esValido(colores, solucion, numColores, k + 1)) {
								dev = true;
							}

						}
						colores[i]++;
						numColores[i]--;
					}
				}
			}
		}
		else {
			if (colores[i] > 0) {
				solucion[k] = i+1;
				colores[i]--;
				numColores[i]++;
				if (k == solucion.size() - 1) {
					if (numColores[1] > numColores[0] + numColores[2]) {
						for (int i = 0; i < solucion.size(); i++) {
							cout << toString(solucion[i]) << " ";
						}
						cout << endl;
						dev = true;
					}
				}
				else {
					if (esValido(colores, solucion, numColores, k + 1)) {
						dev = true;
					}

				}
				colores[i]++;
				numColores[i]--;
			}
		}
	}
	
	return dev;
	
	
}
string toString(int i) {
	if (i == 1) {
		return "azul";
	}
	else if (i == 2) {
		return "rojo";
	}
	else if (i == 3) {
		return "verde";
	}
	else {
		return "";
	}
}