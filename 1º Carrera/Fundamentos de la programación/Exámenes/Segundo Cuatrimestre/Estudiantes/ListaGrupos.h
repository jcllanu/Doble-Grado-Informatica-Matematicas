#pragma once
#include"ListaEstudiante.h"

const int MAX_GRUPOS = 10;
const string LECTURA = "notas.txt";


typedef struct {
	string identificador;
	tListaEstudiantes estudiantes;
}tGrupo;

typedef tGrupo *tGrupoPtr;

typedef struct {
	tGrupoPtr lista[MAX_GRUPOS];
	int contador;
}tListaGrupos;

bool cargar(tListaGrupos& listaGrupos);
void mostrar(const tListaGrupos& listaGrupos);
bool buscar(const tListaGrupos& listaGrupos, string NIF, int &pos);
void destruir(tListaGrupos& listaGrupos);
string devuelveIdentificador(const tListaGrupos& listaGrupos, int pos);
