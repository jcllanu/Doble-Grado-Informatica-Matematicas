#pragma once
#include"ListaProgramas.h"

const int CAP_INI = 20;

typedef struct {
	tProgramaPtr programaPtr;
	bool grabado;
}tGrabacion;

typedef tGrabacion *tGrabacionPtr;

typedef struct {
	tGrabacionPtr lista;
	int contador, maximo;
}tListaGrabaciones;

void crear(tListaGrabaciones& listaGrabaciones);
bool solapan(const tGrabacion& grabacion1, const tGrabacion& grabacion2);
bool insertar(tListaGrabaciones& listaGrabaciones, const tGrabacion& grabacion);
void mostrar(const tListaGrabaciones& listaGrabaciones);
void destruir(tListaGrabaciones& listaGrabaciones);
tGrabacion grabar(const tProgramaPtr& programaPtr);