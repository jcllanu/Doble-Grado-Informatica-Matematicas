#include"Reparto.h"

void cargar(tReparto& reparto, istream& archivo) {
	char aux;

	archivo >> reparto.contador;
	archivo.get(aux);
	for (int i = 0; i < reparto.contador; i++) {
		getline(archivo, reparto.actores[i]);
	}
}

bool aparece(const tReparto& reparto, string nombre, int& pos) {
	bool encontrado;

	if (pos < reparto.contador) {
		if (reparto.actores[pos] == nombre) {
			encontrado = true;
		}
		else {
			pos++;
			encontrado = aparece(reparto, nombre, pos);
		}
	}
	else {
		encontrado = false;
	}

	return encontrado;
}