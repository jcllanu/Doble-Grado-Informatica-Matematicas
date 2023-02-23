#include"Tema.h"

void cargar(tTema& tema, istream& archivo) {
	char aux;

	archivo.get(aux);/*Igual va en otro lado*/
	getline(archivo, tema.titulo);
	getline(archivo, tema.interprete);
	archivo >> tema.segundos;
}
	
	
void mostrar(const tTema& tema) {
	cout << setw(10) << tema.titulo << setw(15) << tema.interprete << setw(5) << right << tema.segundos << " seg.";
}
string devuelveTitulo(const tTema& tema) {
	return tema.titulo;
}
int devuelveSegundos(const tTema& tema) {
	return tema.segundos;
}