#pragma once
#include"ListaSudokus.h"

typedef struct {
	string identificador;
	int puntos;
} tJugador;

typedef tJugador* tJugadorPtr;

string toString(tJugador jugador); //Muestra por consola el nombre y los puntos de un tJugador.
void modificarJugador(tJugador & jugador, int puntos); //Actualiza la puntación de un tJugador (suma los puntos pasados como parámetro).
bool operator<(const tJugador & opIzq, const tJugador & opDer); //Modifica el operador '<' para comparar dos estructuras de tipo tJugador según su identificador (en órden alfabético).
bool menor(const tJugador & j1, const tJugador & j2); //Compara dos estructuras tJugador (j1 y j2) y devuelve true en caso de que 'j1' tenga menos puntos que 'j2' (en caso de empate devulve true si el identificador de 'j1' se encuentra antes alfabéticamente que 'j2').  

//Funciones añadidas
void datosJugador(tJugador & jugador, string id, int puntos); //Actualiza el identificador y los puntos de un tJugador según los parámetros 'id' y 'puntos'.
string devuelveIdentificador(const tJugador & jugador); //Devuelve el identificador de un tJugador.