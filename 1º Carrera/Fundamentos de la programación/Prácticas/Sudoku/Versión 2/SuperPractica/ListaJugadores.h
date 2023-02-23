#pragma once
#include"Jugador.h"

const int MAX_JUGADORES = 10;
const string LISTAJ = "listaJugadores.txt";
const string LISTAJb = "listaJugadoresb.txt";
typedef struct {
	tJugador lista[MAX_JUGADORES];
	int contador;
}tListaJugadores;

void creaListaVacia(tListaJugadores & lista);
bool cargar(tListaJugadores & lista);
void mostrar(const tListaJugadores & lista);
bool guardar(const tListaJugadores & lista);
void puntuarJugador(tListaJugadores & lista, int puntos);
bool buscar(const tListaJugadores & lista, string id, int & pos);
tListaJugadores ordenarPorRanking(const tListaJugadores & lista);