#include"Plantacion.h"


bool cargar(tPlantacion & plantacion, string fichero) {
	ifstream archivo;
	bool ok ;

	archivo.open(fichero);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		archivo >> plantacion.identificador;/*Igual faltan poner archivo.get*/
		archivo >> plantacion.numF;
		archivo >> plantacion.numC;
		for (int i = 0; i < plantacion.numF; i++) {
			for (int j = 0; j < plantacion.numC; j++) {
				archivo >> plantacion.matriz[i][j];
			}
		}
		archivo.close();
		ok = true;
	}
	return ok;
}

int calcularPlatanosParcela(const tPlantacion & plantacion, int fila, int col, int len) {
	int suma = 0;

	for (int i = fila; i < fila + len && i < plantacion.numF; i++) {
		for (int j = col; j < col + len && j < plantacion.numC; j++) {
			suma += plantacion.matriz[i][j];
		}
	}

	return suma;
}

int devuelveFilas(const tPlantacion & plantacion) {
	return plantacion.numF;
}
int devuelveColumnas(const tPlantacion & plantacion) {
	return plantacion.numC;
}
string devuelveIdentificador(const tPlantacion & plantacion) {
	return plantacion.identificador;
}