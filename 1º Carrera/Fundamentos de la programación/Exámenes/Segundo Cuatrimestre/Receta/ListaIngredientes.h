#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;



const int MAX_INGREDIENTES = 50;
typedef struct {
	string nombre;
	double calorias;
}tIngrediente;

typedef tIngrediente *tIngredientePtr;

typedef struct {
	tIngredientePtr lista[MAX_INGREDIENTES];
	int contador;
}tListaIngredientes;

void inserta(tListaIngredientes& listaIngredientes, const tIngrediente& ingrediente);
bool carga(tListaIngredientes& listaIngredientes);
string selectIngred(const tListaIngredientes& listaIngredientes);
int busca(const tListaIngredientes& listaIngredientes, string nombre, int& ini, int& fin);
string devuelveNombre(const tIngrediente& ingrediente);
double calorias(const tIngrediente& ingrediente);
void liberar(tListaIngredientes& listaIngredientes);