#pragma once

#include"Conjunto.h"

typedef enum { VACIA, FIJA, RELLENADA }tEstado;

typedef struct {
	tEstado estado;
	int numero;
	tConjunto valoresPosibles;
}tCasilla;

void iniciaCasilla(tCasilla & casilla);
void rellenaCasilla(tCasilla & casilla, char c, bool fija=false);
void dibujaCasilla(const tCasilla & casilla);
bool esSimple(const tCasilla & casilla, int & numero);

void colorFondo(int color);
tEstado devuelveEstado(const tCasilla & casilla);
void borraElemento(tCasilla & casilla, int num);
int devuelveNumero(const tCasilla & casilla);
bool pertenece(const tCasilla& casilla, int num);
void annadeElemento(tCasilla& casilla, int num);
void mostrar(const tCasilla & casilla);