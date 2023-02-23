#include"Pelicula.h"

void cargar(tPelicula& pelicula, istream& archivo) {
	getline(archivo, pelicula.titulo);
	getline(archivo, pelicula.director);
	getline(archivo, pelicula.genero);
	archivo >> pelicula.valoracion;
	cargar(pelicula.reparto, archivo);
}
bool interviene(const tPelicula& pelicula, string actor) {
	int pos = 0;
	return aparece(pelicula.reparto, actor, pos);
}

void mostrar(const tPelicula& pelicula) {
	cout << setw(15) << left << "Título:" << pelicula.titulo << endl;
	cout << setw(15) << "Director:" << pelicula.director << endl;
	cout << setw(15) << "Género:" << pelicula.genero << endl;
	cout << setw(15) << "Valoración:" << pelicula.valoracion << endl;
}

bool menorGen(const tPelicula& pelicula1, const tPelicula& pelicula2) {
	return pelicula1.genero < pelicula2.genero;
}
bool mayorVal(const tPelicula& pelicula1, const tPelicula& pelicula2) {
	return pelicula1.valoracion > pelicula2.valoracion;
}

string devuelveGenero(const tPelicula& pelicula1) {
	return pelicula1.genero;
}