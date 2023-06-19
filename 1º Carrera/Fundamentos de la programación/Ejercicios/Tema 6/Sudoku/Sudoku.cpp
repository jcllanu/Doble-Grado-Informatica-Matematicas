//Para el primer tipo de entrada, el esquema debe ser el siguiente :

// Nombre: Juan Carlos Llamas Núñez, Adrián Sanjuán Espejo

//Comprobar y resolver sudokus

#include <iostream>
#include<string>
#include "Conjunto.h"

using namespace std;
//#include <...>
//#include "..." // propios o los de las estructuras de datos de clase

const int N = 9;
typedef int tSudoku[N][N];
typedef bool tArray[N];
typedef struct {
	int x;
	int y;
}tCoor;
// función que resuelve el problema

// 


string resolver() {
	tSudoku sudoku;
	int cont = 0, cont2 = 0;
	tCoor posin, posfin;
	bool correct = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sudoku[i][j];
		}
	}
	while (cont < N && correct) {
		posin.x = cont;
		posin.y = 0;
		posfin.x = cont;
		posfin.y = N - 1;
		if (!comprobar(sudoku, posin, posfin)) {
			correct = false;
		}
		cont++;
	}
	cont = 0;
	while (cont < N && correct) {
		posin.x = 0;
		posin.y = cont;
		posfin.x = N-1;
		posfin.y = cont;
		if (!comprobar(sudoku, posin, posfin)) {
			correct = false;
		}
		cont++;
	}
	cont = 0;
	while (cont < N && correct) {
		while (cont2 < N && correct) {
			posin.x = cont;
			posin.y = cont2;
			posfin.x = posin.x + 2;
			posfin.y = posin.y + 2;
			if (!comprobar(sudoku, posin, posfin)) {
				correct = false;
			}
			cont2+=3;
		}
		cont += 3;
		cont2 = 0;
	}
	return ok;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	string sol = resolver();
	std::cout << sol << endl;
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
bool comprobar(const tSudoku& sudoku, tCoor posini, tCoor posfin) {
	tConjunto conjunto;
	cjto_vacio(conjunto);
	for (int i = posini.x; i <= posfin.x; i++) {
		for (int j = posini.y; j <= posfin.y; j++) {
			addElemento(conjunto, sudoku[i][j]);
		}
	}
	return numElems(conjunto) == 9;
}
	