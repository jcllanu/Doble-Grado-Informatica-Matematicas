#pragma once
#include"Juego.h"

const int MAX_SUDOKUS = 20;
const string LISTA = "listaSudokus.txt";
typedef tSudoku tArray[MAX_SUDOKUS];

typedef struct {
	tArray lista;
	int contador;
}tListaSudokus;

void creaListaVacia(tListaSudokus & lista);
bool cargar(tListaSudokus & lista);
void mostrar(const tListaSudokus & lista);