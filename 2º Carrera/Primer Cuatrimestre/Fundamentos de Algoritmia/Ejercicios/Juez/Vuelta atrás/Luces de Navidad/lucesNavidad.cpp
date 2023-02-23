/*Juan Carlos Llamas Núñez
	2º DG FAL*/

#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

bool resuelveCaso();
int numLuces(vector<int>& luces, const vector<int>& consumos, vector<int>& contLuces, const int& consumoMax, int k, int sumaConsumo);


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

bool resuelveCaso() {
	int N, coloresTotales, consumoMax;
	cin >> N;
	if (N == 0) {
		return false;
	}
	else {
		cin >> coloresTotales >> consumoMax;
		vector<int> consumos(coloresTotales);
		vector<int> contLuces(coloresTotales);
		for (int i = 0; i < consumos.size(); i++) {
			cin >> consumos[i];
			contLuces[i] = 0;
		}
		vector<int> luces(N);
		cout << numLuces(luces, consumos, contLuces, consumoMax, 0,0) << endl;
		return true;
	}
}

/*Llevamos un vector con las luces ya puestas(solucion), un vector constante de consumos de cada tipo de luz,
un vector con los contadores de luces (cuantas luces hay de cada tipo), el consumo máximo y el consumo de la solución actual, así como el nivel en el que nos encontramos*/
int numLuces(vector<int>& luces, const vector<int>& consumos, vector<int>& contLuces, const int& consumoMax, int k, int sumaConsumo) {
	int dev = 0;
	for (int i = 0; i < consumos.size(); i++) {
		luces[k] = i;
		contLuces[i]++;/*Marcamos*/
		sumaConsumo += consumos[i];
		if (k > 1) {
			if (!(luces[k - 1] == i && luces[k - 2] == i ) && 2 * contLuces[i] - k <= 2 && sumaConsumo <= consumoMax) {/*¿Es completable?*/
				if (k + 1 == luces.size()) {/*Último hijo y ya hemos comprobado que es solución*/
					dev++;
					/*for (int j = 0; j < luces.size(); j++) {
						cout << luces[j] << " ";
					}
					cout << endl;*/
				}
				else if(sumaConsumo < consumoMax) {/*La intentamos completar*/
					dev += numLuces(luces, consumos, contLuces, consumoMax, k + 1, sumaConsumo);
				}
				
			}
		}
		else {/*Caso especial ya la condición de que los dos anteriores sean distintos se cumple trivialmente y no podemos acceder a luces[k-1] ni a luces[k-2]*/
			if (2 * contLuces[i] - k <= 2 && sumaConsumo <= consumoMax) {
				if (k + 1 == luces.size()) {/*Último hijo y ya hemos comprobado que es solución*/
					dev++;
					/*for (int j = 0; j < luces.size(); j++) {
						cout << luces[j] << " ";
					}
					cout << endl;*/
				}
				else if (sumaConsumo < consumoMax) {/*La intentamos completar*/
					dev += numLuces(luces, consumos, contLuces, consumoMax, k + 1, sumaConsumo);
				}
			}
			
		}
		contLuces[i]--;/*Desmarcamos*/
		sumaConsumo -= consumos[i];
	}
	return dev;
}