#include"ListaCompradores.h"

void inicializar(tListaCompradores& listaCompradores) {
	listaCompradores.contador = 0;
	listaCompradores.lista = new tComprador[0];
}

void insertar(tListaCompradores& listaCompradores, const tComprador& comprador) {
	int pos;
	tCompradorPtr listaAux;

	if (buscar(listaCompradores, comprador.numComprador, pos)) {
		listaCompradores.lista[pos].precioTotal += comprador.precioTotal;
	}
	else {
		listaCompradores.contador++;
		listaAux = new tComprador[listaCompradores.contador];
		for (int i = 0; i < listaCompradores.contador - 1; i++) {
			listaAux[i] = listaCompradores.lista[i];
		}
		listaAux[listaCompradores.contador - 1] = comprador;
		liberar(listaCompradores);
		listaCompradores.lista = listaAux;
	}

}

bool buscar(const tListaCompradores& listaCompradores, long long int numComprador, int& pos) {
	bool encontrado = false;
	pos = 0;
	while (!encontrado && pos < listaCompradores.contador) {
		if (listaCompradores.lista[pos].numComprador == numComprador) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}
	return encontrado;
}

void mostrar(const tListaCompradores& listaCompradores) {
	cout << endl << endl;
	for (int i = 0; i < listaCompradores.contador; i++) {
		cout << "Comprador:" << setw(10) << right << listaCompradores.lista[i].numComprador << setw(17) << "Total: " << listaCompradores.lista[i].precioTotal << endl;
	}
	cout << endl;
}
void liberar(tListaCompradores& listaCompradores) {
	delete[] listaCompradores.lista;
}
tComprador devuleveComprador(long long int numCompr, double precioTotal) {
	tComprador comprador;

	comprador.numComprador = numCompr;
	comprador.precioTotal = precioTotal;

	return comprador;
}