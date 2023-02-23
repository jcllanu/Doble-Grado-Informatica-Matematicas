#pragma once
#include"Programa.h"

const int MAX_TAM = 20;
const string LECTURA = "programas.txt";
typedef tPrograma *tProgramaPtr;

typedef struct {
	tProgramaPtr lista[MAX_TAM];
	int contador;
}tListaProgramas;

bool insertar(tListaProgramas& listaProgramas, const tPrograma& programa);
bool cargar(tListaProgramas& listaProgramas);
tProgramaPtr selecPrograma(const tListaProgramas& listaProgramas);
void destruir(tListaProgramas& listaProgramas);