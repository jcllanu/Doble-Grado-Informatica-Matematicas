/*Juan Carlos Llamas N��ez 2�DG FAL*/

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int falta(vector<int> v, int ini, int fin);

void resuelveCaso() {
	char inic, finc, aux;
	cin >> inic; 
	cin >> finc;
	int ini = int(inic - 'a');
	int fin= int(finc- 'a');
	if (ini < 0 || fin < 0 || fin-ini<0) {
		cout << "No es una letra del alfabeto";
		return;
	}
	vector<int> v (fin - ini);
	for (int i = 0; i < v.size(); i++) {
		cin >> aux;
		v[i] = int(aux - 'a')-ini;
	}
	cout << char(char(ini+falta(v, 0, v.size()-1))+'a') << endl;
}
/*Simplificamos la resoluci�n para un N+1 n�meros entre el 0 y el N ambos incluidos
Construimos un vector de N n�meros y preguntamos si en la posici�n de la mitad, el 
valor coincide con mitad. En ese caso el fugado est� entre mitad y final. En caso contrario est� inicio y mitad*/

int main() {
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}



int falta(vector<int> v, int ini, int fin) {
	if (fin - ini == 1) {
		if (v[ini] == ini) {
			if (v[fin] == fin) {
				return fin + 1;
			}
			else {
				return fin;
			}
		}
		else {
			return ini;
		}
		return fin;
	}
	else if (fin - ini == 0) {
		if (v[ini] == ini) {
			return ini + 1;
		}
		else {
			return ini;
		}
	}
	else{
		int mitad = (fin + ini) / 2;
		if (mitad == v[mitad]) {
			return falta(v, mitad+1, fin);
		}
		else {
			return falta(v, ini, mitad);
		}
	}
}
/*Orden de complejidad log(2)(fin-ini)
Siendo esta diferencia la diferencia entre los caracteres entre los que hay que buscar, es decir,
el tama�o del vector de caracteres que se nos da como entrada*/