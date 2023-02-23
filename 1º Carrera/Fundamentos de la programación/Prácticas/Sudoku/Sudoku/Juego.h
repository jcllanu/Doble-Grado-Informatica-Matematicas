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

void iniciaJuego(tJuego & juego, const tSudoku & sudoku); //Inicia el juego a 'no resuelto' e inicia el tablero correspondiente al tSudoku pasado como parámetro.
void mostrarJuego(const tJuego & juego); //Muestra en consola la información del sudoku correspondiente al tJuego y dibuja el tablero.
bool cargaJuego(tJuego & juego, const tSudoku & sudoku); //Devuelve un booleano en función de si se ha podido cargar el juego en función de un tSudoku pasado como parámetro. En caso afirmativo realiza la operación de carga.
int jugarUnSudoku(const tSudoku & sudoku); //Permite resolver un sudoku y devuelve los puntos obtenidos.

//Funciones añadidas
void mostrarSudoku(const tSudoku & sudoku); //Muestra en consola la información (nombre y puntos obtenidos por resolución) de un tSudoku.
void datosSudoku(tSudoku & sudoku, string nombre, int puntos); //Actualiza el nombre y los puntos obtenidos por resolución de un sudoku en función de los parámetros 'nombre' y 'puntos'.
string devuelveSudoku(const tSudoku &sudoku); //Devuelve la información de un tSudoku (nombre y puntos obtenidos por resolución) en formato string.
string devuelveNombre(const tSudoku &sudoku); //Devuelve el nombre de un sudoku en formato string.
int devuelvePuntos(const tSudoku &sudoku); //Devuelve los puntos de un sudoku 
bool operator<(const tSudoku & sudoku1, const tSudoku & sudoku2); //Modifica el operador '<' para comparar dos estructuras de tipo tSudoku según la puntuación obtenida por resolución (y por órden alfabético en caso de que la puntuación sea igual).