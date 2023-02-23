#pragma once
#include"Tablero.h"

typedef struct {
	int puntos;
	string nombre;
}tSudoku;

typedef struct {
	tSudoku sudoku;
	tTablero tablero;
	bool resuelto;
}tJuego;

void iniciaJuego(tJuego & juego, const tSudoku & sudoku);
void mostrarJuego(const tJuego & juego);
void mostrarSudoku(const tSudoku & sudoku);
bool cargaJuego(tJuego & juego, const tSudoku & sudoku);
int jugarUnSudoku(const tSudoku & sudoku);
void datosSudoku(tSudoku & sudoku, string nombre, int puntos);