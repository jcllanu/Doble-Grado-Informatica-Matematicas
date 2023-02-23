#pragma once
#include"ListaSudokus.h"

typedef struct {
	string identificador;
	int puntos;
} tJugador;



string toString(tJugador jugador);
void modificarJugador(tJugador & jugador, int puntos);
bool operator<(const tJugador & opIzq, const tJugador & opDer);
bool menor(const tJugador & j1, const tJugador & j2);
void datosJugador(tJugador & jugador, string id, int puntos);
string devuelveIdentificador(const tJugador & jugador);