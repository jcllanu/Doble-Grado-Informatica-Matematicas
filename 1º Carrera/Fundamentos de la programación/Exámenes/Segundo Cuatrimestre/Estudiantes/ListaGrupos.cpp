#include"ListaGrupos.h"

bool cargar(tListaGrupos& listaGrupos) {
	bool ok;
	ifstream archivo;
	tGrupo grupo;

	listaGrupos.contador = 0;
	archivo.open(LECTURA);
	if (archivo.is_open()) {
		ok = true;
		archivo >> grupo.identificador;
		while (grupo.identificador != "XXX" && listaGrupos.contador < MAX_GRUPOS) {
			cargar(grupo.estudiantes, archivo);
			listaGrupos.lista[listaGrupos.contador] = new tGrupo(grupo);
			listaGrupos.contador++;
			archivo >> grupo.identificador;
		}
		archivo.close();

	}
	else {
		ok = false;
	}
	return ok;
}

void mostrar(const tListaGrupos& listaGrupos) {

	for (int i = 0; i < listaGrupos.contador; i++) {
		cout << "-------------------------------" << endl;
		cout << "Grupo: " << listaGrupos.lista[i]->identificador << endl;
		mostrar(listaGrupos.lista[i]->estudiantes);
	}

}

bool buscar(const tListaGrupos& listaGrupos, string NIF, int &pos) {
	bool encontrado;
	int num;
	if (pos >= listaGrupos.contador) {
		encontrado = false;
	}
	else {
		if (buscar(listaGrupos.lista[pos]->estudiantes, NIF, num)) {
			encontrado = true;
		}
		else {
			pos++;
			encontrado = buscar(listaGrupos, NIF, pos);
		}
	}
	return encontrado;
}

void destruir(tListaGrupos& listaGrupos) {
	for (int i = 0; i < listaGrupos.contador; i++) {
		destruir(listaGrupos.lista[i]->estudiantes);
		delete listaGrupos.lista[i];
	}
}

string devuelveIdentificador(const tListaGrupos& listaGrupos, int pos) {

	return listaGrupos.lista[pos]->identificador;
}