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

void iniciaJuego(tJuego & juego, const tSudoku & sudoku); //Inicia el juego a 'no resuelto' e inicia el tablero correspondiente al tSudoku pasado como par�metro.
void mostrarJuego(const tJuego & juego); //Muestra en consola la informaci�n del sudoku correspondiente al tJuego y dibuja el tablero.
bool cargaJuego(tJuego & juego, const tSudoku & sudoku); //Devuelve un booleano en funci�n de si se ha podido cargar el juego en funci�n de un tSudoku pasado como par�metro. En caso afirmativo realiza la operaci�n de carga.
int jugarUnSudoku(const tSudoku & sudoku); //Permite resolver un sudoku y devuelve los puntos obtenidos.

//Funciones a�adidas
void mostrarSudoku(const tSudoku & sudoku); //Muestra en consola la informaci�n (nombre y puntos obtenidos por resoluci�n) de un tSudoku.
void datosSudoku(tSudoku & sudoku, string nombre, int puntos); //Actualiza el nombre y los puntos obtenidos por resoluci�n de un sudoku en funci�n de los par�metros 'nombre' y 'puntos'.
string devuelveSudoku(const tSudoku &sudoku); //Devuelve la informaci�n de un tSudoku (nombre y puntos obtenidos por resoluci�n) en formato string.
string devuelveNombre(const tSudoku &sudoku); //Devuelve el nombre de un sudoku en formato string.
int devuelvePuntos(const tSudoku &sudoku); //Devuelve los puntos de un sudoku 
bool operator<(const tSudoku & sudoku1, const tSudoku & sudoku2); //Modifica el operador '<' para comparar dos estructuras de tipo tSudoku seg�n la puntuaci�n obtenida por resoluci�n (y por �rden alfab�tico en caso de que la puntuaci�n sea igual).