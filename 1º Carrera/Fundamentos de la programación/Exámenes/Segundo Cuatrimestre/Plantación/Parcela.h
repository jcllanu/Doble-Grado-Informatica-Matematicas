#pragma once
#include"Plantacion.h"

const int TAM_MAX = 1000;

typedef struct {
	string identificador;
	int fila, columna, platanos;

}tParcela;

typedef tParcela *tParcelaPtr;

typedef struct {
	tParcelaPtr lista[TAM_MAX];
	int contador;
}tListaParcelas;


void escribirParcela(const tParcela& parcela);
bool operator<(const tParcela& parcela1, const tParcela& parcela2);
void crearParcelas(const tPlantacion& plantacion, int len, tListaParcelas& listaParcelas);
void mezclar(const tListaParcelas& listaParcelas1, const tListaParcelas& listaParcelas2, tListaParcelas& mezcla);
void mostrarListaParcelas(const tListaParcelas& listaParcelas, int& num);
void liberar(tListaParcelas& listaParcelas);

int devuelvePlatanos(const tListaParcelas& listaParcelas, int pos);
tParcelaPtr devuelveParcelaPtr(const tListaParcelas& listaParcelas, int pos);
void guardarParcela(const tParcela& parcela, ofstream& archivo);