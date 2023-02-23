//Juan Carlos Llmas y Adrián Sanjuán 2º DG FAL
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

typedef struct{
	int tab[20][20];
	int filas, columnas;
}tSatisfaccion;


bool resuelveCaso();
void resolver(vector<int>& solucion, vector<int>& mejorSolucion, const vector<int>& edadesJuguetes, const vector<int>& edadesNinnos, vector<int>& juguetesPorNinno, const tSatisfaccion& satisfaccion, int k, int&satisf, int&mejorSatisf, const int& minJuguetes);
bool todosTienenElMinimo(const vector<int>& juguetesPorNinno, const int &minJuguetes);
bool esPrometedor(const vector<int>& juguetesPorNinno, int k, int minJuguetes, int numJuguetes);

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
	int numJuguetes, numNinnos, minJuguetes;
	cin >> numJuguetes >> numNinnos >> minJuguetes;
	if (numJuguetes == 0 && numNinnos == 0 && minJuguetes == 0) {
		return false;
	}
	else {
		vector<int> solucion(numJuguetes);
		vector<int> mejorSolucion(numJuguetes);
		vector<int> edadesJuguetes(numJuguetes);
		vector<int> edadesNinnos(numNinnos+1);
		vector<int> juguetesPorNinno(numNinnos+1);
		tSatisfaccion satisfaccion;
		satisfaccion.filas = numNinnos+1;
		satisfaccion.columnas = numJuguetes;

		for (int i = 0; i < edadesJuguetes.size(); i++) {
			cin >> edadesJuguetes[i];
		}
		for (int i = 0; i < edadesNinnos.size()-1; i++) {
			cin >> edadesNinnos[i];
		}
		edadesNinnos[edadesNinnos.size() - 1] = 20;
		for (int i = 0; i < satisfaccion.filas; i++) {
			for (int j = 0; j < satisfaccion.columnas; j++) {
				if (i == satisfaccion.filas - 1) {
					satisfaccion.tab[i][j] = 0;
				}
				else {
					cin >> satisfaccion.tab[i][j];
				}
			}
			juguetesPorNinno[i] = 0;
		}
		int satisf = 0, mejorSatisf = 0;
		resolver(solucion, mejorSolucion, edadesJuguetes, edadesNinnos, juguetesPorNinno, satisfaccion, 0, satisf, mejorSatisf, minJuguetes);
		cout << mejorSatisf << endl;
		return true;
	}
}

void resolver(vector<int>& solucion, vector<int>& mejorSolucion, const vector<int>& edadesJuguetes, const vector<int>& edadesNinnos, vector<int>& juguetesPorNinno, const tSatisfaccion& satisfaccion, int k, int&satisf, int&mejorSatisf, const int& minJuguetes) {
	for (int i = 0; i < edadesNinnos.size(); i++) {
		solucion[k] = satisfaccion.tab[i][k];
		satisf+= satisfaccion.tab[i][k];
		juguetesPorNinno[i]++;

		if (k + 1 == edadesJuguetes.size()) {
			if (todosTienenElMinimo(juguetesPorNinno, minJuguetes) && edadesNinnos[i]>=edadesJuguetes[k]) {
				if (satisf > mejorSatisf) {
					mejorSolucion = solucion;
					mejorSatisf = satisf;
				}
			}
		}
		else {
			if (esPrometedor(juguetesPorNinno,  k, minJuguetes, edadesJuguetes.size())) {
				if (edadesNinnos[i] >= edadesJuguetes[k]) {
					resolver(solucion, mejorSolucion, edadesJuguetes, edadesNinnos, juguetesPorNinno, satisfaccion, k + 1, satisf, mejorSatisf, minJuguetes);
				}
			}
		}
		
		satisf -= satisfaccion.tab[i][k];
		juguetesPorNinno[i]--;

	}
}



bool todosTienenElMinimo(const vector<int>& juguetesPorNinno, const int &minJuguetes) {
	int contador = 0;
	while (contador < juguetesPorNinno.size()-1) {
		if (juguetesPorNinno[contador] < minJuguetes) {
			return false;
		}
		contador++;
	}
	return true;
}

bool esPrometedor(const vector<int>& juguetesPorNinno, int k, int minJuguetes, int numJuguetes) {
	int faltanParaMinimo = 0;
	for (int i = 0; i < juguetesPorNinno.size()-1; i++) {
		if (juguetesPorNinno[i] < minJuguetes) {
			faltanParaMinimo += (minJuguetes - juguetesPorNinno[i]);
		}
		if (faltanParaMinimo > numJuguetes - k-1) {
			return false;
		}
	}
	return true;
}