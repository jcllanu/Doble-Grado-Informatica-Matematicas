#pragma once
#include"Lotes.h"

const int MAX_LOTES = 300;
const string ENTRADA = "lonja.txt";
typedef tLote *tLotePtr;

typedef struct {
	tLotePtr lista[MAX_LOTES];
	int contador;
}tListaLonja;

void inicializa(tListaLonja& lista);
int numLotes(const tListaLonja& lista);
void insertar(tListaLonja& lista, const tLote& lote);
bool cargar(tListaLonja& lista);
bool buscar(const tListaLonja& lista, string idLote, string pescado, int& pos, int& ini, int& fin);
tLote& obtenerLote(tListaLonja& lista, int pos);
void mostrar(const tListaLonja& lista);
void liberar(tListaLonja& lista);

