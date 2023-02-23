#pragma once

#include"Conjunto.h"

typedef enum { VACIA, FIJA, RELLENADA }tEstado;

typedef struct {
	tEstado estado;
	int numero;
	tConjunto valoresPosibles;
}tCasilla;

void iniciaCasilla(tCasilla & casilla); //Inicia una casilla a vac�a e inicializa el conjunto de valores posibles de la casilla a todos los n�meros del 1-9.
void rellenaCasilla(tCasilla & casilla, char c, bool fija = false); //Rellena una casilla y actualiza su estado en funci�n del par�metro 'c' (en caso de contener un valor cambia el estado a 'fija' o 'rellenada' en funci�n del par�metro 'fija'.
void dibujaCasilla(const tCasilla & casilla); //Muestra por consola una casilla cambiando el color de fondo en funci�n del estado de esta.
bool esSimple(const tCasilla & casilla, int & numero); //Devuelve un booleano en funci�n de los valores posibles de la casilla (si su estado es 'VACIA' y tiene un solo valor posible devuelve TRUE)
void colorFondo(int color); //Cambia el color de fondo en consola de un caracter en funci�n del par�metro 'color'. 

//Funciones a�adidas
tEstado devuelveEstado(const tCasilla & casilla); //Devuelve el estado de una casilla
void borraElemento(tCasilla & casilla, int num); //Borra el elemento 'num' (par�metro) de los valores posibles de una casilla.
int devuelveNumero(const tCasilla & casilla); //Devuelve el valor/n�mero de la casilla (espacio en blanco en caso de estar vac�a).
bool pertenece(const tCasilla& casilla, int num); //Devuelve un booleano en funci�n de si 'num' (par�metro) se encuentra entre los valores posibles (true) o no (false) de una casilla. 
void annadeElemento(tCasilla& casilla, int num); //A�ade un elemento ('num') a los valores posibles de una casilla.
void mostrar(const tCasilla & casilla); //Mustra por consola los valores posibles de una casilla.