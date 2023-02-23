#include<iostream>
#include<fstream>
using namespace std;

const int Tam=100;
typedef int tLista[Tam];

int nuevoNumero(const tLista lista, int ind1, int ind2);
void generaArray(tLista lista, int n, int x);
int pasar(const tLista lista, int n, int pasarse);
void guardar(const tLista lista, int n);
int main() {
	system("chcp 1252");

	int n, x, pasarse;
	tLista lista;

	cout << "¿Cuántos números quiere en la secuencia?" << endl;
	cin >> n;
	if (n > Tam) {
		n = Tam;
	}
	cout << "¿Cuántos números anteriores quiere sumar para calcular cada nuevo número? " << endl;
	cin >> x;

	generaArray(lista, n, x);

	cout << "Hallemos el primer numero de la secuencia que se pasa de un dado" << endl;
	cout << "¿De cuál debe pasarse?" << endl;
	cin >> pasarse;
	cout << "El primero que se pasa de " << pasarse << " es " << pasar(lista, n, pasarse) << " ." << endl;
	cout << "Ahora guardaremos la secuencia completa un fichero." << endl;
	guardar(lista, n);
	cout << "Archivo guardado." << endl;
	system("pause");
	return 0;
}
int nuevoNumero(const tLista lista, int ind1, int ind2) {
	int final = 0;

	if (ind1 < 0) {
		ind1 = 0;
	}
	for (int i = ind1; i <= ind2; i++) {
		final = final + lista[i];
	}
	return final;
}
void generaArray(tLista lista, int n, int x) {
	int arriba, abajo;

	lista[0] = 1;

	for (int i = 1; i < n; i++) {
		arriba = i - 1;
		abajo = i - x;
		lista[i] = nuevoNumero(lista, abajo, arriba);
	}
}
int pasar(const tLista lista, int n, int pasarse) {
	int i = 0;
	bool encontrado = false;

	while (i < n && !encontrado) {
		if (pasarse < lista[i]) {
			encontrado = true;
		}
		i++;
	}
	
	return lista[i-1];
}
void guardar(const tLista lista, int n) {
	ofstream archivo;
	archivo.open("salida.txt");
	for (int i = 0; i < n; i++) {
		archivo << lista[i] << endl;
	}
	archivo.close();
}