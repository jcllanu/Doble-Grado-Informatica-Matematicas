#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;

int const MAX = 100;
int const RANGO = 50;
typedef int tArray[MAX];
typedef int tFrecuencias[RANGO];

int aleatorio();
void inicializacion(tArray lista, tFrecuencias frecuencias);
void actualizaFrecuencias(tFrecuencias frecuencias, tArray lista);
void mostrarFrecuencias(tFrecuencias frecuencias);
void mostrarLista(tArray lista);
void ordenarLista(tArray lista, tFrecuencias frecuencias);
int minimoLista(tFrecuencias frecuencias);
int maximoLista(tFrecuencias frecuencias);

int main() {
	srand(time(NULL));
	tArray lista;
	tFrecuencias frecuencias;
	

	inicializacion(lista, frecuencias);
	actualizaFrecuencias(frecuencias, lista);
	mostrarLista(lista);
	mostrarFrecuencias(frecuencias);
	ordenarLista(lista, frecuencias);
	mostrarLista(lista);

	system("pause");
	return 0;
}


int aleatorio() {
	return rand() % RANGO;
}
void inicializacion(tArray lista, tFrecuencias frecuencias) {
	for (int i = 0; i < MAX; i++) {//Inicializa aleatoriamente la lista a oredenar
		lista[i] = aleatorio();
	}
	for (int i = 0; i < RANGO; i++) {//Inicializa la lista de frecuencias a 0
		frecuencias[i] = 0;
	}
}
void actualizaFrecuencias(tFrecuencias frecuencias, tArray lista) {
	for (int i = 0; i < MAX; i++) {//Actualiza la lista de frecuencias
		frecuencias[lista[i]]++;
	}
}
void mostrarFrecuencias(tFrecuencias frecuencias) {
	for (int i = minimoLista(frecuencias); i <= maximoLista(frecuencias); i++) {
		cout << setw(3) << i << " ";
	}
	cout << endl;
	for (int i = minimoLista(frecuencias); i <= maximoLista(frecuencias); i++) {
		cout << setw(3) << frecuencias[i] << " ";
	}
	cout << endl << endl;
}
void mostrarLista(tArray lista) {
	for (int i = 0; i < MAX; i++) {
		cout << lista[i] << " ";
	}
	cout << endl << endl;

}
void ordenarLista(tArray lista, tFrecuencias frecuencias) {
	int pos = 0;

	for (int i = minimoLista(frecuencias); i <= maximoLista(frecuencias); i++) {//Ordena la lista
		for (int j = 0; j < frecuencias[i]; j++) {
			lista[pos] = i;
			pos++;
		}
	}

}
int minimoLista(tFrecuencias frecuencias) {
	bool encontrado = false;
	int pos = 0;

	while (!encontrado && pos<RANGO) {
		if (frecuencias[pos] > 0) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}
	return pos;
}
int maximoLista(tFrecuencias frecuencias) {
	bool encontrado = false;
	int pos = RANGO - 1;

	while (!encontrado && pos >=0) {
		if (frecuencias[pos] > 0) {
			encontrado = true;
		}
		else {
			pos--;
		}
	}
	return pos;
}