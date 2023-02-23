#include"ListaOpciones.h"


int buscarPos(const tListaOpc& listaOpc, tOpc opcion);
void ampliar(tListaOpc& lista);
int precioOpc(const tOpc& opcion);

ostream& operator<< (ostream & out, tListaOpc const& lista) {
	out << endl << "------------------------------------------------------" << endl;
	for (int i = 0; i < lista.contador; i++) {
		out << "Viaje: " << devuelveLugar(*lista.lista[i].OpcPlaya) << " y " << devuelveLugar(*lista.lista[i].OpcSierra) << ", precio: " << lista.lista[i].precioTotal << endl;
		out << "------------------------------------------------------" << endl;
	}
	return out;
}


void liberar(tListaOpc& lista) {
	delete[] lista.lista;
}

void nuevoViaje(tListaOpc& listaOpc, const tListaLugares& playa, const tListaLugares& sierra) {
	string play, sierr;
	int posPlaya = 0, posSierra = 0, poslista;
	tOpc nuevoViaje;

	cout << endl <<"Elige un lugar con playa:";
	cout << playa;
	cout << "Lugar: ";
	cin >> play;
	while (!buscar(playa, play, posPlaya)) {
		cout << "Elige un lugar con playa: ";
		cin >> play;
		posPlaya = 0;
	}



	cout << endl << "Elige un lugar con sierra:";
	cout << sierra;
	cout << "Lugar: ";
	cin >> sierr;
	while (!buscar(sierra, sierr, posSierra)) {
		cout << "Elige un lugar con sierra: ";
		cin >> sierr;
		posSierra = 0;
	}


	nuevoViaje.OpcPlaya = playa.lista[posPlaya];
	nuevoViaje.OpcSierra = sierra.lista[posSierra];
	nuevoViaje.precioTotal = precioOpc(nuevoViaje);
	poslista = buscarPos(listaOpc, nuevoViaje);
	if (listaOpc.contador == listaOpc.maximo) {
		ampliar(listaOpc);
	}
	listaOpc.contador++;
	for (int i = listaOpc.contador - 1; i > poslista; i--) {
		listaOpc.lista[i] = listaOpc.lista[i - 1];
	}
	listaOpc.lista[poslista] = nuevoViaje;
}

int buscarPos(const tListaOpc& listaOpc, tOpc opcion) {
	bool encontrado = false;
	int contador = 0;
	
	while (!encontrado && contador < listaOpc.contador) {
		if (precioOpc(opcion) <= precioOpc(listaOpc.lista[contador])) {
			encontrado = true;
		}
		else {
			contador++;
		}
	}

	return contador;
}


int precioOpc(const tOpc& opcion) {
	return precioLugar(*opcion.OpcPlaya) + precioLugar(*opcion.OpcSierra);
}

void ampliar(tListaOpc& lista) {
	tOpcPtr listaNueva;

	lista.maximo *= 2;
	listaNueva = new tOpc[lista.maximo];
	for (int i = 0; i < lista.contador; i++) {
		listaNueva[i] = lista.lista[i];
	}
	liberar(lista);
	lista.lista = listaNueva;
}

void crearListaOpc(tListaOpc& lista) {
	lista.contador = 0;
	lista.maximo = TAM_INCIAL;
	lista.lista = new tOpc[TAM_INCIAL];
}
