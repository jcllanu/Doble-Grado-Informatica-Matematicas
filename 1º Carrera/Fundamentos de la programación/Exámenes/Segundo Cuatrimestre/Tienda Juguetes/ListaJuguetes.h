#pragma once
#include"Juguete.h"


typedef tJuguete *tJuguetePtr;

typedef struct {
	tJuguetePtr lista;
	int cont50, cont60, cont70, cont80;
}tListaJuguetes;


bool cargar(tListaJuguetes& listaJuguetes);
bool buscar(string identificador, const tListaJuguetes& listaJuguetes, int& pos);
void insertar(string id, tDecada decada, int unidades, double precioBase, tListaJuguetes& listaJuguetes);
bool eliminar(string id, tListaJuguetes& listaJuguetes);
void mostrar(const tListaJuguetes& listaJuguetes);
void liberar(tListaJuguetes& listaJuguetes);

void ampliarLista(tListaJuguetes& listaJuguetes);
void reducirLista(tListaJuguetes& listaJuguetes);
int tamannoLista(const tListaJuguetes& listaJuguetes);
tJuguete devuelveJuguete(const tListaJuguetes& listaJuguetes, int num);

