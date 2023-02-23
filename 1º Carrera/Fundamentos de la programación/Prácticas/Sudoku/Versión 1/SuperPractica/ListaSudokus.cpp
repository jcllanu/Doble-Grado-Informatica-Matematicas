#include"ListaSudokus.h"
#include<fstream>
void creaListaVacia(tListaSudokus & lista) {
	lista.contador = 0;
}
bool cargar(tListaSudokus & lista) {
	bool ok = false;
	string nombre;
	int puntos;
	char aux;
	tSudoku sudokuaux;
	ifstream archivo;
	archivo.open(LISTA);
	if (archivo.is_open()) {
		creaListaVacia(lista);
		while ( !archivo.eof() && lista.contador < MAX_SUDOKUS) {
			archivo >> nombre;
			archivo >> puntos;
			datosSudoku(sudokuaux, nombre, puntos);
			archivo.get(aux);
			lista.lista[lista.contador] = sudokuaux;
			if (!archivo.eof()) {
				lista.contador++;
			}
		}
		ok = true;
	}
	return ok;
}
void mostrar(const tListaSudokus & lista) {
	for (int i = 0; i < lista.contador; i++) {
		mostrarSudoku(lista.lista[i]);
	}
}
