#include"Jugador.h"



string toString(tJugador jugador) {
	return jugador.identificador + " " + to_string(jugador.puntos);
}

void modificarJugador(tJugador & jugador, int puntos) {
	jugador.puntos += puntos;
}
bool operator<(const tJugador & opIzq, const tJugador & opDer) {
	bool menor;
	if (opIzq.identificador < opDer.identificador) {
		menor = true;
	}
	else {
		menor = false;
	}
	return menor;
}
string devuelveIdentificador(const tJugador & jugador) {
	return jugador.identificador;
}
bool menor(const tJugador & j1, const tJugador & j2) {
	bool menor;
	if (j1.puntos < j2.puntos) {
		menor = true;
	}
	else if (j1.puntos == j2.puntos && j2 < j1){
		menor = true;
	}
	else {
		menor = false;
	}
	return menor;
}

void datosJugador(tJugador & jugador, string id, int puntos) {
	jugador.identificador = id;
	jugador.puntos = puntos;
}