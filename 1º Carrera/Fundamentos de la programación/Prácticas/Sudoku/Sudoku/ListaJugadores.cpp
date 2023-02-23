#include"ListaJugadores.h"
#include<fstream>
#include"checkML.h"

void creaListaVacia(tListaJugadores & lista) {
	lista.contador = 0;
	lista.maximo = DIM_INI;
	lista.listaPtr = new tJugadorPtr[DIM_INI];
	if (lista.listaPtr == NULL) {
		cout << "Advertencia: no se ha podido crear la lista (memoria completa).";
	}

}

bool cargar(tListaJugadores & lista) {
	bool ok = false;
	string id;
	int puntos;
	char aux;
	tJugador jugadoraux;
	ifstream archivo;

	
	archivo.open(LISTAJ);
	if (archivo.is_open()) {
		ok = true;
		archivo >> id;
		while (!archivo.eof() && ok) {
			if (lista.contador == lista.maximo) {
				ampliar(lista);
			}
			
			archivo >> puntos;
			datosJugador(jugadoraux, id, puntos);
			archivo.get(aux);

			lista.listaPtr[lista.contador] = new tJugador(jugadoraux);
			if (lista.listaPtr[lista.contador] == NULL) {
				ok = false;
			}
			lista.contador++;
			archivo >> id;
		}
		
		archivo.close();
	}
	return ok;
}
void mostrar(const tListaJugadores & lista){
	cout << endl << endl;
	for (int i = 0; i < lista.contador; i++) {
		cout << "   "<<i+1<<".- "<<toString(*(lista.listaPtr[i])) << endl;
	}
}

bool guardar(const tListaJugadores & lista) {
	bool ok = false;
	ofstream archivo;

	archivo.open(LISTAJ);
	if (archivo.is_open()) {
		for (int i = 0; i < lista.contador; i++) {
			archivo << toString(*(lista.listaPtr[i])) << endl;
		}
		ok = true;
		archivo.close();
	}

	return ok;
}
void puntuarJugador(tListaJugadores & lista, int puntos) {
	string identificador;
	int pos;

	cout << "Introduzca el identificador: ";
	cin >> identificador;
	if (buscar(lista, identificador, pos)) {
		modificarJugador(*(lista.listaPtr[pos]), puntos);
	}
	else {
		if (lista.contador == lista.maximo) {
			ampliar(lista);
		}
		lista.contador++;
		for (int i = lista.contador - 2; i >= pos; i--) {
			lista.listaPtr[i + 1] = lista.listaPtr[i];
		}
		lista.listaPtr[pos] = new tJugador;
		if (lista.listaPtr[pos] == NULL) {
			cout << "Advertencia: no se ha podido añadir el jugador a la lista (memoria completa).";
		}
		else {
			datosJugador(*(lista.listaPtr[pos]), identificador, 0);
			modificarJugador(*(lista.listaPtr[pos]), puntos);
		}
	}
}

bool buscar(const tListaJugadores & lista, string id, int & pos) {
	int ini = 0, fin = lista.contador - 1;

	return	buscar(lista, id, pos, ini, fin);
}

bool buscar(const tListaJugadores & lista, string id, int & pos, int & ini, int & fin) {
	bool encontrado = false;
	int mitad = (ini + fin) / 2;;
	if (ini < fin && !encontrado) {
		if (devuelveIdentificador(*(lista.listaPtr[mitad])) == id) {
			encontrado = true;
			pos = mitad;
		}
		else if (id < devuelveIdentificador(*(lista.listaPtr[mitad]))) {
			fin = mitad - 1;
			encontrado = buscar(lista, id, pos, ini, fin);
		}
		else {
			ini = mitad + 1;
			encontrado = buscar(lista, id, pos, ini, fin);
		}
	}
	else if (ini == fin) {
		if (devuelveIdentificador(*(lista.listaPtr[mitad])) == id) {
			encontrado = true;
			pos = mitad;
		}
		else if (id > devuelveIdentificador(*(lista.listaPtr[mitad]))) {
			pos = mitad + 1;
		}
		else {
			pos = mitad;
		}

	}
	else {
		pos = mitad + 1;
		
	}
	
	return encontrado;
}

tListaJugadores ordenarPorRanking(const tListaJugadores & lista) {
	tListaJugadores nlista;
	int cont;
	bool encontrado;
	nlista.maximo = lista.maximo;
	nlista.listaPtr = new tJugadorPtr[lista.maximo];/*if(NULL)*/
	if (nlista.listaPtr == NULL) {
		cout << "Advertencia: no se ha podido realizar a operación (memoria completa).";
	}
	nlista.listaPtr[0] = lista.listaPtr[0];
	nlista.contador = 1;
	for (int i = 1; i < lista.contador; i++) {
		cont = 0;
		encontrado = false;
		while (cont < nlista.contador && !encontrado) {
			if (menor(*(nlista.listaPtr[cont]), *(lista.listaPtr[i]))) {
				encontrado = true;
			}
			else{
				cont++;
			}
		}
		nlista.contador++;
 		for (int j = nlista.contador-1; j > cont; j--) {
			nlista.listaPtr[j] = nlista.listaPtr[j-1];
		}
		nlista.listaPtr[cont] = lista.listaPtr[i];
	}
	return nlista;
}


void ampliar(tListaJugadores & lista) {
	lista.maximo *= 2;
	tJugadorPtrPtr aux = new tJugadorPtr[lista.maximo];
	
	if (aux == NULL) {
		cout << "Advertencia: no se ha podido ampliar la lista (memoria completa).";
	}
	else {
		for (int i = 0; i < lista.contador; i++) {
			aux[i] = lista.listaPtr[i];
		}
		for (int i = lista.contador; i < lista.maximo; i++) {
			aux[i] = NULL;
		}
		borrarListaJugadores(lista);
		lista.listaPtr = aux;
	}
}

void borrarListaJugadores(tListaJugadores & lista) {
	delete[]lista.listaPtr;
}

void liberarMemoria(tListaJugadores & lista) {
	for (int i = 0; i < lista.contador; i++) {
		delete lista.listaPtr[i];
	}
	borrarListaJugadores(lista);
}