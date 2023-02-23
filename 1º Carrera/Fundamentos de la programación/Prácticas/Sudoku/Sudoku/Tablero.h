#pragma once
#include"Casilla.h"

typedef tCasilla tTablero[N][N];

typedef struct {
	int x, y;
}tCoor;

void iniciaTablero(tTablero tablero);/*Inicia el tablero para que todas sus casillas sean casillas vac�as con todos los valores como posibles*/
bool cargarTablero(string nombreFichero, tTablero tablero);/*Reecibe el tablero inicializado y lo devuelve con la informaci�n del archivo nobreFichero. Se asegura de que los valores posibles queden actualizados*/
void dibujarTablero(const tTablero tablero);/*Dibuja el tablero en pantalla*/
bool ponerNum(tTablero tablero, int fila, int col, int c);/*Devuelve true si la casilla que se encuentra en la fila y columnas dadas de tablero es vac�a y c est� entre los valores posibles. 
														  En ese caso asigna el campo valor de esa casilla al valor c. En cualquier otro caso devuelve false y no se produceninguna modificaci�n.
														  Se asegura de que los valores posibles afectados queden actualizados*/
bool borrarNum(tTablero tablero, int fila, int col);/*Devuelve true si el estado de la casilla (fila, col) de tablero es rellenada y se realiza la operaci�n de borrado. En este supuesto se asegura de que los valores 
													posibles afectados queden actualizados. En caso contrario se devuelve false.*/
bool tableroLleno(const tTablero tablero);/*Devuelve true si el tablero est� rellenado por completo*/
void mostrarPosibles(const tTablero tablero, int fila, int col);/*Muetra por pantalla los valores posible de la casilla (fila, col) de tablero.*/
void rellenarSimples(tTablero tablero);/*En aquellas casillas de tablero que haya un �nico valor posible, se pone dicho valor y se actualiza convenientemente los valores posibles afectados*/