#pragma once
#include"Tema.h"

const int MAX_TEMAS = 50;
const string LECTURA = "temas.txt";
typedef tTema *tTemaPtr;

typedef struct {
	tTemaPtr lista[MAX_TEMAS];
	int contador;
}tListaTemas;

bool cargar(tListaTemas& listaTemas);
void destruir(tListaTemas& listaTemas);
tTemaPtr devuelveTemaPtr(const tListaTemas& listaTemas, int num);
int devuelveTam(const tListaTemas& listaTemas);