#include <iostream>
#include <fstream>

#include <iostream>
#include<string>
#include "Conjunto.h"

using namespace std;
//#include <...>
//#include "..." // propios o los de las estructuras de datos de clase

typedef int tSudoku[N][N];
typedef bool tArray[N];
typedef struct {
	int x;
	int y;
}tCoor;



//#include <...>
//#include "..." // propios o los de las estructuras de datos de clase
// Resuelve un caso de prueba
void resuelveCaso();
bool comprobar(const tSudoku& sudoku, tCoor posini, tCoor posfin);
// función que resuelve el problema

// 
bool resolver() {
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
		posfin.x = N - 1;
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
			cont2 += 3;
		}
		cont += 3;
		cont2 = 0;
	}
	return correct;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bool sol = resolver();
	if (sol) std::cout << "SI" << endl;
	else std::cout << "NO" << endl;
}
int main() {
	#ifndef DOMJUDGE
	std::ifstream in("Text.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	#ifndef DOMJUDGE
	std::cin.rdbuf(in.rdbuf());
	system("PAUSE");
	#endif	
	return 0;
}

// Carga de la matriz
bool cargaMatriz(tSudoku & m) {
	bool cargada;
	if (!cin) {
		cargada = false;
	}
	else {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> m[i][j];
			}
		}
		cargada = true;
	}
	return cargada;
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