#include<iostream>
using namespace std;
//Problema de las reinas
const int N = 11;
typedef bool tTablero[N][N];
typedef int tArray[N];
bool colocar(tTablero &tablero, int reina, tArray& listaPos);
bool posible(tTablero tab, int fila, int col);
int abs(int a);

int main() {
	tTablero tablero;
	tArray listaPos;
	bool encontrado = false;
	int cont = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tablero[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		listaPos[i] = 0;
	}
	while (colocar(tablero, 0, listaPos)) {
		cout << cont + 1 << ".-" << endl << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tablero[i][j]) {
					cout << "1 ";
				}
				else {
					cout << "0 ";
				}
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < N; i++) {
			listaPos[i]--;
			tablero[i][listaPos[i]] = false;
		}
		listaPos[N - 1]++;
		cont++;
	}
	cout << "Hay " << cont << " posibles soluciones para N = " << N << endl << endl;
	
	system("pause");
	return 0;
}

bool colocar(tTablero &tablero, int reina, tArray& listaPos) {
	bool colocado = false;
	

	if (reina == N) {
		colocado = true;
	}
	else {
		while (listaPos[reina] < N && !colocado) {
			if (posible(tablero, reina, listaPos[reina])) {
				tablero[reina][listaPos[reina]] = true;
				colocado = colocar(tablero, reina + 1,listaPos);
				if (!colocado) {
					tablero[reina][listaPos[reina]] = false;
				}
			}
			listaPos[reina]++;
				
		}
		if (!colocado) {
			listaPos[reina] = 0;
		}
	}
	return colocado;
}



bool posible(tTablero tab, int fila, int col){
	bool posible = true;
	int i=0, j;

	while (posible && i < N) {
		j = 0;
		while (posible && j < N) {
			if (tab[i][j]) {
				if (i == fila) {
					posible = false;
				}
				else if (j == col) {
					posible = false;
				}
				else if (abs(fila - i) == abs(col - j)) {
					posible = false;
				}
			}
			j++;
		}
		i++;
	}
	return posible;
}


int abs(int a) {
	int b;
	if (a >= 0) {
		b = a;
	}
	else {
		b = -a;
	}
	return b;
}

/*
	if (colocar(tablero, 0, listaPos)) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tablero[i][j]) {
					cout << "1 ";
				}
				else {
					cout << "0 ";
				}
			}
			cout << endl;
		}
		cout << endl << endl << endl;
	}
	else{
		cout << "ERROR";

	}
	for (int i = 0; i < N; i++) {
		listaPos[i]--;
		tablero[i][listaPos[i]] = false;
	}
	listaPos[N - 1]++;
	if (colocar(tablero, 0, listaPos)) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tablero[i][j]) {
					cout << "1 ";
				}
				else {
					cout << "0 ";
				}
			}
			cout << endl;
		}
	}
	else {
		cout << "ERROR";

	}
	*/


	/*
	bool colocar(tTablero &tablero, int reina){
		bool colocado = false;
		int cont = 0;

		if (reina == N) {
			colocado = true;
		}
		else {
			while (cont < N && !colocado) {
				if(posible(tablero, reina, cont)){
					tablero[reina][cont] = true;
					colocado = colocar(tablero, reina + 1);
					if (!colocado) {
						tablero[reina][cont] = false;
					}
				}
				cont++;
			}
		}
		return colocado;
	}
	*/