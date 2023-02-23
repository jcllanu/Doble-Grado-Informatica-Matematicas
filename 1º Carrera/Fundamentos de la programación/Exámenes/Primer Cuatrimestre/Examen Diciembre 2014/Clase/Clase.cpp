#include <iostream>
#include<fstream>;
using namespace std;

const int Tam = 100;
typedef int tLista[Tam];
void generarArray(tLista lista, int tam, int r);
int nuevoNum(const tLista lista, int i, int s);
int pasar(const tLista lista, int tam, int pas);
void escritura(const tLista lista, int tam, ofstream& archivo);

int main() {
	system("chcp 1252");
	int n, x, pasarse;
	tLista lista;
	ofstream archivo;
	cout << "¿Cuántos números quieres en la secuencia? " << endl;
	cin >> n;
	if (n > 100) {
		n = 100;
	}
	cout << "¿Cuántos números anteriores quieres sumar para calcular cada nuevo número? " << endl;
	cin >> x;

	generarArray( lista, n , x);

	cout << "Hallemos el primer número de la secuencia que se pasa de uno dado." << endl << "¿De cuál debe pasarse?" << endl;
	cin >> pasarse;

	cout<<"El primer número que se pasa de "<<pasarse<<" es "<< pasar(lista, n, pasarse)<< endl;

	cout << "Ahora guardaremos la secuencia completa en el fichero." << endl;
	escritura(lista, n, archivo);
	cout << "Archivo guardado." << endl;

	system("pause");
	return 0;
}

void generarArray(tLista lista, int tam, int r) {
	int a, s;
	lista[0] = 1;
	for (int j = 1; j < tam; j++) {
		s = j - 1;
		a = j - r;
		lista[j] = nuevoNum(lista, a, s);
	}
}

int nuevoNum(const tLista lista, int a, int s) {
	int num = 0;
	if (a < 0) {
		a = 0;
	}
	for (int i = s; i >= a; i--) {
		num = num + lista[i];
	}

	return num;
}
int pasar(const tLista lista, int tam, int pas) {
	int final;
	bool encontrado = false;
	int i = 0;
	while (i < tam && !encontrado) {
		if (pas < lista[i]) {
			final = lista[i];
			encontrado = true;
		}
		i++;
	}
	
	if (!encontrado) {
		final = lista[tam - 1];
	}
	return final;

}

void escritura(const tLista lista, int tam, ofstream& archivo) {
	archivo.open("salida.txt");
	for (int i=0; i < tam; i++) {
		archivo << lista[i] << endl;
	}
	archivo.close();
}