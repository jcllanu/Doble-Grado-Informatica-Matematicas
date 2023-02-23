// Viva FAL
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Precondición:

Postcondición:

Invariante:

Función de cota:

*/

typedef struct {
	int numHijas;
	int numNietas;
	string cadena;
} Solucion;

bool hembra(int x);
bool macho(int x);
int cria(int hembra, int macho);

Solucion resolver(vector<int> jirafas, int n) {
	int sumaAlturas = 0, numHijas = 0, sumaHijas = 0, numNietas = 0;
	bool criaMacho = false, criaHembra = false;
	for (int i = 0; i != n; i++) {
		sumaAlturas += jirafas[i];
		// proceso de elegir que tienen una cria

		if (/* hay una cria*/) {
			int jirafita = cria(/*padre1, padre2*/);
			if (macho(jirafita)) {
				if (criaHembra) {
					criaHembra = false;
					numNietas++;
				}
				else
					criaMacho = true;
			}
			else {
				if (criaMacho) {
					criaMacho = false;
					numNietas++;
				}
			}
			sumaHijas += jirafita;
			numHijas++;
		}

	}
	Solucion sol = {numHijas, numNietas, ""};
	if ((sumaAlturas / n) < (sumaHijas / numHijas))
		sol.cadena = "INCREMENTO";
	else if ((sumaAlturas / n) > (sumaHijas / numHijas))
		sol.cadena = "DECREMENTO";
	else
		sol.cadena = "SIN CAMBIOS";
	return sol;
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!std::cin)
		return false;
	vector<int> jirafas(n);
	for (int i = 0; i < n; i++)
		cin >> jirafas[i];
	Solucion sol = resolver(jirafas, n);
	cout << sol.numCrias << " " << sol.numNietas << " " << sol.cadena << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}

bool hembra(int x) {
	return (x % 2 == 1);
}

bool macho(int x) {
	return !hembra(x);
}

int cria(int hembra, int macho) {
	if (hembra > macho)
		return (hembra + macho) / 2 + 1;
	else
		return (hembra + macho) / 2;
}