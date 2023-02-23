#pragma once
#include"ListaLugares.h"


const int TAM_INCIAL = 3;

typedef struct {
	tLugarPtr OpcPlaya, OpcSierra;
	int precioTotal;
}tOpc;

typedef tOpc *tOpcPtr;

typedef struct {
	tOpcPtr lista;
	int contador, maximo;
}tListaOpc;

ostream& operator<< (ostream & out, tListaOpc const& lista);
void liberar(tListaOpc& lista);
void nuevoViaje(tListaOpc& listaOpc, const tListaLugares& playa, const tListaLugares& sierra);
void crearListaOpc(tListaOpc& lista);