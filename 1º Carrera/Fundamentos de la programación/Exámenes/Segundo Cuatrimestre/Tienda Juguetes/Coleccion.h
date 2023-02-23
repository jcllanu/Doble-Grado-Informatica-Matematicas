#pragma once
#include"ListaJuguetes.h"

const int MAX_JUGUETES = 50;

typedef struct {
	tJuguetePtr lista[MAX_JUGUETES];
	int contador;
}tColeccion;

tColeccion crearColeccion(tListaJuguetes& listaJuguetes, double precioMax, tDecada decada);
void mostrar(const tColeccion& coleccion, int& num);
void liberar(tColeccion& coleccion);