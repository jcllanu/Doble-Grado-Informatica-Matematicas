#pragma once
#include"ListaLonja.h"

typedef struct {
	long long int numComprador;
	double precioTotal;
}tComprador;

typedef tComprador *tCompradorPtr;

typedef struct {
	tCompradorPtr lista;
	int contador;
}tListaCompradores;

void inicializar(tListaCompradores& listaCompradores);
void insertar(tListaCompradores& listaCompradores, const tComprador& comprador);
bool buscar(const tListaCompradores& listaCompradores, long long int numComprador, int& pos);
void mostrar(const tListaCompradores& listaCompradores);
void liberar(tListaCompradores& listaCompradores);
tComprador devuleveComprador(long long int numCompr, double precioTotal);