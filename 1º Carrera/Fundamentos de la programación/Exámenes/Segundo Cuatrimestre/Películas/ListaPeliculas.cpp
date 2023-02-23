#include"ListaPeliculas.h"

bool cargar(tListaPeliculas& listaPeliculas) {
	ifstream archivo;
	tPelicula pelicula;
	bool ok;
	char a;
	archivo.open(LECTURA);
	if (archivo.is_open()) {
		ok = true;
		archivo >> listaPeliculas.contador;
		archivo.get(a);
		for (int i = 0; i < listaPeliculas.contador; i++) {
			cargar(pelicula, archivo);
			listaPeliculas.lista[i] = new tPelicula(pelicula);
		}
		archivo.close();
	}
	else {
		ok = false;
	}


	return ok;
}
tListaPeliculas filtrarPorActor(const tListaPeliculas& listaPeliculas, string nombre) {
	tListaPeliculas nuevaLista;
	tPelicula pelicula;
	nuevaLista.contador = 0;

	for (int i = 0; i < listaPeliculas.contador; i++) {
		if (interviene(*listaPeliculas.lista[i], nombre)) {
			nuevaLista.lista[nuevaLista.contador] = listaPeliculas.lista[i];
			nuevaLista.contador++;
		}
	}

	return nuevaLista;
}
void mostrar(const tListaPeliculas& listaPeliculas) {
	cout << endl;
	if (listaPeliculas.contador == 0) {
		cout << "Este actor no ha participado en ninguna película de esta colección." << endl;
	}
	else {
		for (int i = 0; i < listaPeliculas.contador; i++) {
			mostrar(*listaPeliculas.lista[i]);
			cout << "---" << endl;
		}
	}
	cout << endl;

}
void ordenaPorGenero(tListaPeliculas& listaPeliculas) {
	int min;
	tPeliculaPtr aux;
	for (int i = 0; i < listaPeliculas.contador; i++) {
		min = i;
		for (int j = i+1; j < listaPeliculas.contador; j++) {
			if (menorGen(*listaPeliculas.lista[j], *listaPeliculas.lista[min])) {
				min = j;
			}
		}
		aux = listaPeliculas.lista[min];
		for (int k = min; k > i; k--) {
			listaPeliculas.lista[k] = listaPeliculas.lista[k - 1];
		}
		listaPeliculas.lista[i] = aux;
	}
}
void ordenaPorValoracion(tListaPeliculas& listaPeliculas) {
	int max;
	tPeliculaPtr aux;
	for (int i = 0; i < listaPeliculas.contador; i++) {
		max = i;
		for (int j = i + 1; j < listaPeliculas.contador; j++) {
			if (mayorVal(*listaPeliculas.lista[j], *listaPeliculas.lista[max])) {
				max = j;
			}
		}
		aux = listaPeliculas.lista[max];
		for (int k = max; k > i; k--) {
			listaPeliculas.lista[k] = listaPeliculas.lista[k - 1];
		}
		listaPeliculas.lista[i] = aux;
	}



}

void destruir(tListaPeliculas& listaPeliculas) {
	for (int i = 0; i < listaPeliculas.contador; i++) {
		delete listaPeliculas.lista[i];
	}
}
void ordenaListaOrdenada(tListaPeliculas& listaPeliculas) {
	int inicio = 0, contador;
	tListaPeliculas listaAux;

	while (inicio < listaPeliculas.contador) {
		contador = inicio + 1;
		while (contador < listaPeliculas.contador && devuelveGenero(*listaPeliculas.lista[inicio]) == devuelveGenero(*listaPeliculas.lista[contador])) {
			contador++;
		}
		listaAux.contador = contador - inicio;
		for (int i = 0; i < listaAux.contador; i++) {
			listaAux.lista[i] = listaPeliculas.lista[inicio + i];
		}
		ordenaPorValoracion(listaAux);
		for (int i = inicio; i < contador; i++) {
			listaPeliculas.lista[i] = listaAux.lista[i - inicio];
		}
		inicio = contador;
	}
}

