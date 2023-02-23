#pragma once
#include"Juego.h"

const int MAX_SUDOKUS = 20;
const string LISTAS = "listaSudokus.txt";

typedef tSudoku tArray[MAX_SUDOKUS];

typedef struct {
	tArray lista;
	int contador;
}tListaSudokus;

void creaListaVacia(tListaSudokus & lista);/*Inicializa lista a una lista vacía*/
bool cargar(tListaSudokus & lista);/*Carga en lista la información de listaSudokus.txt y devuelve true si la operación se ha realizado con éxito y false en caso contrario.*/
void mostrar(const tListaSudokus & lista);/*Muestra por pantalla la lista de sudokus almacenada en lista.*/
bool guardar(const tListaSudokus & lista);/*Escribe en el archivo listaSudokus.txt el contenido de lista respetando el mismo formato que en su lectura y devuleve true si la operación ha podide ser realizada con esto */
bool registrarSudoku(tListaSudokus & lista);/*Pide los datos de un sudoku y lo añade a la lista si hay espacio y si el nombre del nuevo sudoku no aparece ya en la lista. En este caso se devolverá true*/
bool buscarFichero(const tListaSudokus & lista, string nombreFich);/*Dada una lista de sodokus y un nombre de fichero devuleve true si alguno de los sudokus tiene como nombre mobreFich*/
int buscarPos(const tListaSudokus & lista, const tSudoku & sudoku);/*Devuelve la posición donde debería ir sudoku en lista respetando el orden ascendentemente por el nº de puntos y, a igualdad en el nº
																	de puntos, ascendentemente por el nombre del archivo. Se ha implementado como búsqueda binaria*/

//Funciones añadidas

int devuelveContador(const tListaSudokus& lista); //Devuelve el contador de una lista de sudokus.
tSudoku devuelveSudoku(const tListaSudokus& lista, int num); //Devuelve el sudoku en la posición 'num' de una lista de sudokus.
