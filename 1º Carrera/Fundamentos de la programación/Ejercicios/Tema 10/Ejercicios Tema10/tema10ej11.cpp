#include<iostream>
using namespace std;

const int N = 8;
typedef bool tTablero[N][N];

bool colocar(tTablero &tablero, int reina);
//Problema de las reinas

int main() {
	tTabla tabla;
	tTableau tab;

	for (int i = 0; i < N; i++) {
		tabla[i] = i % 17;
	}

	tab.contador = N;
	for (int i = 0; i < N; i++) {
		tab.tabla[i] = tabla[i];
	}
	for (int i = 0; i < N; i++) {
		cout << tab.tabla[i] << " ";
	}

	cout << endl << max(tab);



	system("pause");
	return 0;
}

bool colocar(tTablero &tablero, int reina){
	bool colocado, posible;
	int cont = 0;

	if (reina = N) {
		colocado = true;
	}
	else {
		while (cont < N) {

			if(posible(tab, reina, cont)){
			}
		}
	}

}
bool posible(tTablero tab, int fila, int col){
	bool posible = true;
	for (int i = 0; i < N; i++) {
		if (tab[i][col]) {
			posible = false;
			i = N;
		}
	}
	if(menor(fila,col)==fila){
		fila = 0;
		col -= fila;
		for (int i = 0; col < N; i++, col++) {
			if (tab[i][col]) {
				posible = false;
				i = N;
			}
		}
	}
	else {
		col = 0;
		fila -= col;
		for (int i = 0; fila < N; i++, fila++) {
			if (tab[fila][i]) {
				posible = false;
				i = N;
			}
		}
	}
	



}

int menor(int a, int b) {
	if (a < b) {
		return a;

	}
	else { return b; }
}