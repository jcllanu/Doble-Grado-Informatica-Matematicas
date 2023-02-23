#pragma once
#include"Casilla.h"

typedef tCasilla tTablero[N][N];

typedef struct {
	int x, y;
}tCoor;

void iniciaTablero(tTablero tablero);
bool cargarTablero(string nombreFichero, tTablero tablero);
void dibujarTablero(const tTablero tablero);
bool ponerNum(tTablero tablero, int fila, int col, int c);
bool borrarNum(tTablero tablero, int fila, int col);
bool tableroLleno(const tTablero tablero);
void mostrarPosibles(const tTablero tablero, int fila, int col);
void rellenarSimples(tTablero tablero);