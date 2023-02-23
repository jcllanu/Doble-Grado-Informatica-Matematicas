#include"Coleccion.h"

tColeccion crearColeccion(tListaJuguetes& listaJuguetes, double precioMax, tDecada decada) {
	tColeccion coleccion;
	int contador = 0, contadorDecada;
	tJuguete jugueteaux;
	coleccion.contador = 0;

	if (decada == annos50) {
		contadorDecada = listaJuguetes.cont50;
	}
	else if (decada == annos60) {
		contadorDecada = listaJuguetes.cont60;
	}
	else if (decada == annos70) {
		contadorDecada = listaJuguetes.cont70;
	}
	else if (decada == annos80) {
		contadorDecada = listaJuguetes.cont80;
	}


	while (contador < tamannoLista(listaJuguetes) && precioMax>0 && coleccion.contador < MAX_JUGUETES && coleccion.contador<contadorDecada) {
		jugueteaux = devuelveJuguete(listaJuguetes, contador);
		if (DevuelveDecada(jugueteaux) == decada) {
			coleccion.lista[coleccion.contador] = new tJuguete(jugueteaux);
			annadir(*coleccion.lista[coleccion.contador], 1 - devuelveUnidades(*coleccion.lista[coleccion.contador]));
			coleccion.contador++;
			precioMax -= DevuelvePrecio(jugueteaux);
			if (!eliminar(devuelveIdentificador(jugueteaux),listaJuguetes)) {
				contador++;
			}
		}
		else {
			contador++;
		}
	}

	return coleccion;
}
void mostrar(const tColeccion& coleccion, int& num) {
	if (num < coleccion.contador) {
		cout << endl;
		mostrarJuguete(*coleccion.lista[num]);
		cout << endl;
		num++;
		mostrar(coleccion, num);
	}
}
void liberar(tColeccion& coleccion) {
	for (int i = 0; i < coleccion.contador; i++) {
		delete coleccion.lista[i];
	}
}