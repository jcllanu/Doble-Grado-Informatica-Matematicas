#pragma once
#include"ListaIngredientes.h"


typedef struct {
	tIngredientePtr ingredientePtr;
	double gramos;
}tComponente;


tComponente leeComponente(tListaIngredientes& listaIngredientes);
void muestra(const tComponente& componente);
double calorias(const tComponente& componente);
