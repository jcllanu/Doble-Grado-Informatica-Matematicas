#pragma once
#include"Pelicula.h"

const int MAX_PELICULAS = 50;
const string LECTURA = "peliculas.txt";

typedef tPelicula *tPeliculaPtr;

typedef struct {
	tPeliculaPtr lista[MAX_PELICULAS];
	int contador;
}tListaPeliculas;

bool cargar(tListaPeliculas& listaPeliculas);
tListaPeliculas filtrarPorActor(const tListaPeliculas& listaPeliculas, string nombre);
void mostrar(const tListaPeliculas& listaPeliculas);
void ordenaPorGenero(tListaPeliculas& listaPeliculas);
void ordenaPorValoracion(tListaPeliculas& listaPeliculas);
void destruir(tListaPeliculas& listaPeliculas);
void ordenaListaOrdenada(tListaPeliculas& listaPeliculas);