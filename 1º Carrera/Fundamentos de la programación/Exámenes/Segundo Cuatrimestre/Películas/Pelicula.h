#pragma once
#include"Reparto.h"


typedef struct {
	tReparto reparto;
	double valoracion;
	string titulo, director, genero;
}tPelicula;

void cargar(tPelicula& pelicula, istream& archivo);
bool interviene(const tPelicula& pelicula, string actor);
void mostrar(const tPelicula& pelicula);
bool menorGen(const tPelicula& pelicula1, const tPelicula& pelicula2);
bool mayorVal(const tPelicula& pelicula1, const tPelicula& pelicula2);
string devuelveGenero(const tPelicula& pelicula1);