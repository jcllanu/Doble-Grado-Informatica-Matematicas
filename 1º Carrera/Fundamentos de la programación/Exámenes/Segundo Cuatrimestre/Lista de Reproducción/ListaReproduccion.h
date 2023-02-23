#pragma once
#include"ListaTemas.h"

typedef struct {
	tTemaPtr temaPtr; 
	int valoracion;
}tElemento;

typedef tElemento *tElementoPtr;

typedef struct {
	string nombre;
	tElementoPtr lista;
	int contador;
}tListaReproduccion;

typedef bool *tBoolPtr;

typedef struct {
	tBoolPtr lista;
	int tamanno;
}tArrayBool;


tListaReproduccion nueva(int dim, string nombre);
void insertar(tListaReproduccion& listaReproduccion, const tElemento& elemento);
bool buscar(const tListaReproduccion& listaReproduccion, string titulo, int& pos);
void mostrar(const tListaReproduccion& listaReproduccion);
void modificarOrden(tListaReproduccion& listaReproduccion, int origen, int destino);
void generarListaRep(tListaReproduccion& listaReproduccion, const tListaTemas& listaTemas, int numTemas);
void destruir(tListaReproduccion& listaReproduccion);