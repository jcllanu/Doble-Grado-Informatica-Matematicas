#include"ListaJuguetes.h"



bool cargar(tListaJuguetes& listaJuguetes) {
	ifstream archivo;
	bool ok;
	int contador, decada;
	long int unidades;
	double precio;
	string identificador;
	

	listaJuguetes.cont50 = 0;
	listaJuguetes.cont60 = 0;
	listaJuguetes.cont70 = 0;
	listaJuguetes.cont80 = 0;


	archivo.open("juguetes.txt");
	if (archivo.is_open()) {
		ok = true;
		archivo >> contador;
		listaJuguetes.lista = new tJuguete[0];
		for (int i = 0; i < contador; i++) {
			archivo >> identificador;
			archivo >> decada;
			archivo >> unidades;
			archivo >> precio;
			insertar(identificador, DevuelveDecada(decada), unidades, precio, listaJuguetes);
		}

	}
	else {
		ok = false;
	}

return ok;
}

bool buscar(string identificador, const tListaJuguetes& listaJuguetes, int& pos) {
	bool encontrado = false;
	pos = 0;

	while (!encontrado && pos < tamannoLista(listaJuguetes)) {
		if (identificador <= devuelveIdentificador(listaJuguetes.lista[pos])) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}

	if (encontrado && identificador < devuelveIdentificador(listaJuguetes.lista[pos])) {
		encontrado = false;

	}
	return encontrado;

}

void insertar(string id, tDecada decada, int unidades, double precioBase, tListaJuguetes& listaJuguetes) {
	int pos = 0;
	if (buscar(id, listaJuguetes, pos)) {
		annadir(listaJuguetes.lista[pos], unidades);
	}
	else {
		ampliarLista(listaJuguetes);
		if (decada == annos50) {
			listaJuguetes.cont50++;
		}
		else if (decada == annos60) {
			listaJuguetes.cont60++;
		}
		else if (decada == annos70) {
			listaJuguetes.cont70++;
		}
		else if (decada == annos80) {
			listaJuguetes.cont80++;
		}
		for (int i = tamannoLista(listaJuguetes) - 1; i > pos; i--) {
			listaJuguetes.lista[i] = listaJuguetes.lista[i - 1];
		}
		listaJuguetes.lista[pos] = devuelveJuguete(id, unidades, decada, precioBase);
	}
}

int tamannoLista(const tListaJuguetes& listaJuguetes) {
	return listaJuguetes.cont50 + listaJuguetes.cont60 + listaJuguetes.cont70 + listaJuguetes.cont80;
}

void ampliarLista(tListaJuguetes& listaJuguetes) {
	int tamanno = tamannoLista(listaJuguetes);
	tJuguetePtr puntaux;

	puntaux = new tJuguete[tamanno + 1];
	for (int i = 0; i < tamanno; i++) {
		puntaux[i] = listaJuguetes.lista[i];
	}
	liberar(listaJuguetes);
	listaJuguetes.lista = puntaux;
}

void liberar(tListaJuguetes& listaJuguetes) {
	delete[] listaJuguetes.lista;
}

bool eliminar(string id, tListaJuguetes& listaJuguetes) {
	int pos = 0;
	bool jugueteEliminado;

	if (buscar(id, listaJuguetes, pos)) {
		annadir(listaJuguetes.lista[pos], -1);
		if (devuelveUnidades(listaJuguetes.lista[pos]) <= 0) {
			for (int i = pos; i < tamannoLista(listaJuguetes) - 1; i++) {
				listaJuguetes.lista[i] = listaJuguetes.lista[i + 1];
			}
			reducirLista(listaJuguetes);
			if (DevuelveDecada(listaJuguetes.lista[pos]) == annos50) {
				listaJuguetes.cont50--;
			}
			else if (DevuelveDecada(listaJuguetes.lista[pos]) == annos60) {
				listaJuguetes.cont60--;
			}
			else if (DevuelveDecada(listaJuguetes.lista[pos]) == annos70) {
				listaJuguetes.cont70--;
			}
			else if (DevuelveDecada(listaJuguetes.lista[pos]) == annos80) {
				listaJuguetes.cont80--;
			}
			jugueteEliminado = true;
		}
		else {
			jugueteEliminado = false;
		}
	}
	else {
		cout << "No está en la lista";
	}

	return jugueteEliminado;
}

void reducirLista(tListaJuguetes& listaJuguetes) {
	int tamanno = tamannoLista(listaJuguetes);
	tJuguetePtr puntaux;

	puntaux = new tJuguete[tamanno - 1];
	for (int i = 0; i < tamanno-1; i++) {
		puntaux[i] = listaJuguetes.lista[i];
	}
	liberar(listaJuguetes);
	listaJuguetes.lista = puntaux;
}

void mostrar(const tListaJuguetes& listaJuguetes) {
	for (int i = 0; i < tamannoLista(listaJuguetes); i++) {
		mostrarJuguete(listaJuguetes.lista[i]);
		cout << endl << endl;
	}
}

tJuguete devuelveJuguete(const tListaJuguetes& listaJuguetes, int num) {
	return listaJuguetes.lista[num];
}