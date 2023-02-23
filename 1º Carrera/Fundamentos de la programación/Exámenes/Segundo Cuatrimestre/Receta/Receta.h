#pragma once
#include"Componente.h"

typedef tComponente *tComponentePtr;

typedef struct {
	tComponentePtr lista;
	int contador;
	string nombre;
}tReceta;

tReceta crea();
void inserta(tReceta& receta, const tComponente& componente);
void muestra(const tReceta& receta);
void liberar(tReceta& receta);