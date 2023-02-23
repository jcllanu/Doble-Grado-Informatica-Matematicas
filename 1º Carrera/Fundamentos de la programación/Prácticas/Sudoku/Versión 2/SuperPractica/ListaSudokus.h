#pragma once
#include"Juego.h"

const int MAX_SUDOKUS = 10;
const string LISTAS = "listaSudokus.txt";
const string LISTASb = "listaSudokusb.txt";
typedef tSudoku tArray[MAX_SUDOKUS];

typedef struct {
	tArray lista;
	int contador;
}tListaSudokus;

void creaListaVacia(tListaSudokus & lista);
bool cargar(tListaSudokus & lista);
void mostrar(const tListaSudokus & lista);

bool guardar(const tListaSudokus & lista);
bool registrarSudoku(tListaSudokus & lista);
bool buscarFichero(const tListaSudokus & lista, string nombreFich);
int buscarPos(const tListaSudokus & lista, const tSudoku & sudoku);
int puntosDeUnSudoku(const tListaSudokus & lista, string nombre);