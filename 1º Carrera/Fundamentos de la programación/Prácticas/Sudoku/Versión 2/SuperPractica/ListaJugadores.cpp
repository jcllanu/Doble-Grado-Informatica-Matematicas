#include"ListaJugadores.h"
#include<fstream>
void creaListaVacia(tListaJugadores & lista) {
	lista.contador = 0;
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
		creaListaVacia(lista);
		while (!archivo.eof() && lista.contador < MAX_JUGADORES) {
			archivo >> id;
			archivo >> puntos;
			datosJugador(jugadoraux, id, puntos);
			archivo.get(aux);
			lista.lista[lista.contador] = jugadoraux;
			if (!archivo.eof()) {
				lista.contador++;
			}
		}
		ok = true;
		archivo.close();
	}
	return ok;



}
void mostrar(const tListaJugadores & lista){
	for (int i = 0; i < lista.contador; i++) {
		cout << toString(lista.lista[i]) << endl;
	}
}

bool guardar(const tListaJugadores & lista) {
	bool ok = false;
	ofstream archivo;

	archivo.open(LISTAJb);
	if (archivo.is_open()) {
		for (int i = 0; i < lista.contador; i++) {
			archivo << toString(lista.lista[i]) << endl;
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
		modificarJugador(lista.lista[pos], puntos);
	}
	else if(lista.contador < MAX_JUGADORES) {
		lista.contador++;
		for (int i = lista.contador - 2; i >= pos; i--) {
			lista.lista[i + 1] = lista.lista[i];
		}
		datosJugador(lista.lista[pos], identificador, 0);
		modificarJugador(lista.lista[pos], puntos);
	}
}

bool buscar(const tListaJugadores & lista, string id, int & pos) {
	bool encontrado = false;
	int ini = 0, fin = lista.contador - 1, mitad;

	while (ini < fin && !encontrado) {
		mitad = (ini + fin) / 2;
		if (devuelveIdentificador(lista.lista[mitad]) == id) {
			encontrado = true;
		}
		else if (id < devuelveIdentificador(lista.lista[mitad])) {
			fin = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}
	}
	if (ini == fin) {
		mitad = (ini + fin) / 2;
		if (devuelveIdentificador(lista.lista[mitad]) == id) {
			encontrado = true;
			pos = mitad;
		}
		else if (id > devuelveIdentificador(lista.lista[mitad])) {
			pos = mitad+1;
		}
		else {
			pos = mitad;
		}

	} else {
		pos = mitad;
	}
	return encontrado;
}

/*
bool buscar(const tListaJugadores & lista, string id, int & pos) {
	int ini = 0, fin=lista.contador, mitad;
	bool encontrado = false;

	
	while (ini <= fin && !encontrado) {
		mitad = (ini + fin) / 2;
		if (mitad < MAX_JUGADORES && mitad >= 0) {
			if (devuelveIdentificador(lista.lista[mitad]) == id) {
					encontrado = true;
			}
			else if (devuelveIdentificador(lista.lista[mitad]) < id) {
				ini = mitad + 1;
					
			}
			else {
				fin = mitad - 1;
					
			}
		}
			
	}
		pos = mitad;
	
	return encontrado;
}
*/
tListaJugadores ordenarPorRanking(const tListaJugadores & lista) {
	tListaJugadores nlista;
	int cont;
	bool encontrado;
	nlista.lista[0] = lista.lista[0];
	nlista.contador = 1;
	for (int i = 1; i < lista.contador; i++) {
		cont = 0;
		encontrado = false;
		while (cont < nlista.contador && !encontrado) {
			if (menor(nlista.lista[cont], lista.lista[i])) {
				encontrado = true;
			}
			else{
				cont++;
			}
		}
		nlista.contador++;
 		for (int j = nlista.contador-1; j > cont; j--) {
			nlista.lista[j] = nlista.lista[j-1];
		}
		nlista.lista[cont] = lista.lista[i];
	}
	return nlista;
}