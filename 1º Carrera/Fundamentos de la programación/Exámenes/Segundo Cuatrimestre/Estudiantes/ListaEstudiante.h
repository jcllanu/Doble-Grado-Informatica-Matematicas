#pragma once
#include"Estudiante.h"


const int TAM_INI = 5;

typedef tEstudiante *tEstudiantePtr;

typedef struct {
	tEstudiantePtr lista;
	int contador, maximo;
}tListaEstudiantes;

void cargar(tListaEstudiantes& listaEstudiantes, istream& archivo);
bool buscar(const tListaEstudiantes& listaEstudiantes, string NIF, int &pos);
void inserta(tListaEstudiantes& listaEstudiantes, const tEstudiante& estudiante);
void mostrar(const tListaEstudiantes& listaEstudiantes);
void destruir(tListaEstudiantes& listaEstudiantes);
