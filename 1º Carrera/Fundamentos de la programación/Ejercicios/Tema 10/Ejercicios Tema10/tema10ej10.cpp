#include<iostream>
#include<ctime>
using namespace std;
//Operaciones sobre un array

int const N = 25;
typedef int tTabla[N];
typedef struct {
	tTabla tabla;
	int contador;
}tTableau;

int max(tTableau tab);
int aleatorio(int limitinf, int intervalo);
double media(tTableau tab);
bool sonIguales(tTableau tab);
bool estanOrdenadosMm(tTableau tab);
bool estanOrdenadosmM(tTableau tab);
int apariciones(tTableau tab, int num);
int main() {
	tTabla tabla;
	tTableau tab;
	int num;
	system("chcp 1252");
	srand(time(NULL));
	
	for (int i = 0; i < N; i++) {
		tabla[i] = aleatorio(0,30);
		
	}
	tab.contador = N;
	for (int i = 0; i < N; i++) {
		tab.tabla[i] = tabla[i];
	}
	for (int i = 0; i < N; i++) {
		cout <<tab.tabla[i]<<" ";
	}
	
	cout << endl << endl << "El máximo del array es: " << max(tab);
	cout << endl << endl << "La media del array es: " << media(tab);
	cout << endl << endl << "¿Todos los elementos son iguales? ";
	if (sonIguales(tab)) {
		cout << "Sí";
	}
	else {
		cout << "No";
	}
	cout << endl << endl << "¿Están ordenados? ";
	if (estanOrdenadosMm(tab) || estanOrdenadosmM(tab)) {
		cout << "Sí";
	}
	else {
		cout << "No";
	}
	cout << endl << endl << "Introduzca un valor para ver su número de apariciones en el arrray: ";
	cin >> num;
	cout << endl << endl << "Las apariciones del valor " << num << " en el array son " << apariciones(tab, num);
	cout << endl << endl;
	
	system("pause");
	return 0;
}

int max(tTableau tab) {
	int maximo, aux;
	if (tab.contador == 1) {
		maximo = tab.tabla[0];

	}
	else {
		tab.contador--;
		aux = max(tab);
		if (aux > tab.tabla[tab.contador]) {
			maximo = aux;
		}
		else {
			maximo = tab.tabla[tab.contador];
		}
	}
	return maximo;
}

int aleatorio(int limitinf, int intervalo) {
	int final = limitinf + rand() % intervalo;

	return final;
}

double media(tTableau tab) {
	double aver, aux;
	if (tab.contador == 1) {
		aver = tab.tabla[0];

	}
	else {
		tab.contador--;
		aux = media(tab);
		aver = ((tab.tabla[tab.contador]) / double(tab.contador + 1)) + (tab.contador*aux / double(tab.contador + 1));
	}
	return aver;
}

bool sonIguales(tTableau tab) {
	bool iguales, aux;

	if (tab.contador == 2) {
		if (tab.tabla[0] == tab.tabla[1]) {
			iguales = true;
		}
		else {
			iguales = false;
		}
	}
	else {
		tab.contador--;
		aux = sonIguales(tab);
		if (tab.tabla[tab.contador-1] == tab.tabla[tab.contador] && aux) {
			iguales = true;
		}
		else {
			iguales = false;
		}
	}
	
	return iguales;
}

bool estanOrdenadosMm(tTableau tab) {
	bool ordenados, aux;

	if (tab.contador == 2) {
		if (tab.tabla[0] >= tab.tabla[1]) {
			ordenados = true;
		}
		else {
			ordenados = false;
		}
	}
	else {
		tab.contador--;
		aux = estanOrdenadosMm(tab);
		if (tab.tabla[tab.contador-1] >= tab.tabla[tab.contador] && aux) {
			ordenados = true;
		}
		else {
			ordenados = false;
		}
	}
	return ordenados;
}
bool estanOrdenadosmM(tTableau tab) {
	bool ordenados, aux;

	if (tab.contador == 2) {
		if (tab.tabla[0] <= tab.tabla[1]) {
			ordenados = true;
		}
		else {
			ordenados = false;
		}
	}
	else {
		tab.contador--;
		aux = estanOrdenadosmM(tab);
		 if (tab.tabla[tab.contador-1] <= tab.tabla[tab.contador] && aux) {
			ordenados = true;
		}
		else {
			ordenados = false;
		}
	}
	return ordenados;
}
int apariciones(tTableau tab, int num) {
	int ap;
	if (tab.contador == 1) {
		if (tab.tabla[0] == num) {
			ap = 1;
		}
		else {
			ap = 0;
		}
	}
	else {
		tab.contador--;
		if (tab.tabla[tab.contador] == num) {
			ap = 1 + apariciones(tab,num);
		}
		else {
			ap = apariciones(tab, num);
		}
	}
	return ap;
}
