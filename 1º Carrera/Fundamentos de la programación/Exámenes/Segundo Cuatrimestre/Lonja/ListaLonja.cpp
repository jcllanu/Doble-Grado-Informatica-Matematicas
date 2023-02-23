#include"ListaLonja.h"

void inicializa(tListaLonja& lista) {
	lista.contador = 0;
}
int numLotes(const tListaLonja& lista) {
	return lista.contador;
}

void insertar(tListaLonja& lista, const tLote& lote) {
	int pos, ini = 0, fin = lista.contador - 1;
	if (!buscar(lista, devuelveIdLote(lote), devuelvePescadoLote(lote), pos, ini, fin)) {
		lista.contador++;
		for (int i = lista.contador - 1; i > pos; i--) {
			lista.lista[i] = lista.lista[i - 1];
		}
		lista.lista[pos] = new tLote(lote);
	}
}

bool cargar(tListaLonja& lista) {
	ifstream archivo;
	bool ok;
	tLote loteAux;

	archivo.open(ENTRADA);
	if (archivo.is_open()) {
		ok = true;
		inicializa(lista);
		archivo >> loteAux.idLote >> loteAux.pescado >> loteAux.peso >> loteAux.precio;
		lista.lista[0] = new tLote(loteAux);
		lista.contador++;
		while (!archivo.eof() && lista.contador < MAX_LOTES) {
			archivo >> loteAux.idLote >> loteAux.pescado >> loteAux.peso >> loteAux.precio;
			insertar(lista, loteAux);
		}


	}
	else {
		ok = false;
	}

	return ok;
}

bool buscar(const tListaLonja& lista, string idLote, string pescado, int& pos, int& ini, int& fin) {
	int mitad = (ini + fin) / 2;
	bool encontrado;
	tLote lote;
	lote.idLote = idLote;
	lote.pescado = pescado;

	if (ini < fin) {
		if (*lista.lista[mitad] == lote) {
			encontrado = true;
			pos = mitad;
		}
		else if (*lista.lista[mitad] < lote) {
			ini = mitad + 1;
			encontrado = buscar(lista, idLote, pescado, pos, ini, fin);
		}
		else {
			fin = mitad - 1;
			encontrado = buscar(lista, idLote, pescado, pos, ini, fin);
		}
	}
	else {
		if (*lista.lista[mitad] == lote) {
			encontrado = true;
			pos = mitad;
		}
		else if (*lista.lista[mitad] < lote) {
			encontrado = false;
			pos = mitad + 1;
		}
		else {
			encontrado = false;
			pos = mitad;
		}
	}

	return encontrado;
}


tLote& obtenerLote(tListaLonja& lista, int pos) {
	return *lista.lista[pos];
}
void mostrar(const tListaLonja& lista) {
	for (int i = 0; i < lista.contador; i++) {
		mostrarPrecio(*lista.lista[i]);
		cout << endl;
	}
}

void liberar(tListaLonja& lista) {
	for (int i = 0; i < lista.contador; i++) {
		delete lista.lista[i];
	}
}