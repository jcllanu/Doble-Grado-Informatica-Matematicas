#pragma once
#include"ListaClientes.h"


const int CAPACIDAD_INICIAL = 2;

typedef struct {
	tClientePtr cliente1, cliente2;
	string lugar;
	int valoracion;
}tCita;

typedef tCita *tCitaPtr;

typedef struct {
	tCitaPtr lista;
	int contador, max;
}tListaCitas;

bool nuevaLista(tListaCitas& listaCita);
bool inserta(tListaCitas& listaCita, const tCita& cita);
bool ampliar(tListaCitas& listaCita);
void muestra(const tListaCitas& listaCita);
void liberar(tListaCitas& listaCita);
int devuelveNumero(const tListaClientes& listaClientes);
tCita devuelveCita(const tListaClientes& listaClientes);
