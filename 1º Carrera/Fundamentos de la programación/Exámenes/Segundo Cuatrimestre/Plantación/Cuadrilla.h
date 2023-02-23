#pragma once
#include"Parcela.h"

const string LECTURA_CUADRILLAS = "Cuadrillas.txt";


typedef struct {
	string identificador;
	int maxPlatanos;
	tParcelaPtr punteroaParcela;
}tCuadrilla;

typedef tCuadrilla *tCuadrillaPtr;

typedef struct {
	tCuadrillaPtr lista;
	int contador;
}tListaCuadrillas;

void leerCuadrilla(tCuadrilla& cuadrilla, ifstream& archivo);
void escribirCuadrilla(const tCuadrilla& cuadrilla);
bool operator<(const tCuadrilla& cuadrilla1, const tCuadrilla& cuadrilla2);
void inicializarListaCuadrillas(tListaCuadrillas& listaCuadrillas, int num);
tListaCuadrillas crearListaCuadrilla();
void asignarParcela(tListaCuadrillas& listaCuadrillas, const tListaParcelas& listaParcelas);
void mostrarAsignaciones(const tListaCuadrillas& listaCuadrilla);
void liberar(tListaCuadrillas& listaCuadrillas);
bool guardar(const tListaCuadrillas& listaCuadrilla);
