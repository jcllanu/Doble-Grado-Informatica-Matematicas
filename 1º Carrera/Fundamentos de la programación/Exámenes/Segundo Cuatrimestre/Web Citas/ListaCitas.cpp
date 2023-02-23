#include "ListaCitas.h"


int busca(const tListaCitas& listaCita, const tCita& cita);


bool nuevaLista(tListaCitas& listaCita) {
	listaCita.contador = 0;
	listaCita.max = CAPACIDAD_INICIAL;
	listaCita.lista = new tCita[CAPACIDAD_INICIAL];
	return listaCita.lista != NULL;
}

bool inserta(tListaCitas& listaCita, const tCita& cita) {
	int pos = busca(listaCita, cita);
	bool ok = true;

	if (listaCita.contador >= listaCita.max) {
		if (!ampliar(listaCita)) {
			ok = false;
		}
	}
	if (ok) {
		listaCita.contador++;
		for (int i = listaCita.contador - 1; i > pos; i--) {
			listaCita.lista[i] = listaCita.lista[i - 1];
		}
		listaCita.lista[pos] = cita;
	}

	return ok;
}

bool ampliar(tListaCitas& listaCita) {
	tCitaPtr listaNueva;
	bool ok = true;
	
	listaCita.max *= 2;
	listaNueva = new tCita[listaCita.max];
	if (listaNueva == NULL) {
		ok = false;
	}
	else {
		for (int i = 0; i < listaCita.contador; i++) {
			listaNueva[i] = listaCita.lista[i];
		}
		liberar(listaCita);
		listaCita.lista = listaNueva;
	}

	return ok;
}

void muestra(const tListaCitas& listaCita) {
	cout << endl << "Lista de citas: " << endl;
	for (int i = 0; i < listaCita.contador; i++) {
		cout << "----------------------------------------------------------------------------------------" << endl;
		mostrar(*listaCita.lista[i].cliente1);
		mostrar(*listaCita.lista[i].cliente2);
		cout << "Cita en: " << listaCita.lista[i].lugar << ". Valoración: " << listaCita.lista[i].valoracion << endl;
		cout << "----------------------------------------------------------------------------------------" << endl;
	}
}

void liberar(tListaCitas& listaCita) {
	delete[] listaCita.lista;
}

int busca(const tListaCitas& listaCita, const tCita& cita) {
	int pos, mitad, ini = 0, fin = listaCita.contador - 1;
	bool encontrado = false;
	while (ini < fin && !encontrado) {
		mitad = (ini + fin) / 2;
		if (listaCita.lista[mitad].valoracion == cita.valoracion) {
			encontrado = true;
			pos = mitad;
		}
		else if (listaCita.lista[mitad].valoracion < cita.valoracion) {
			fin = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}
	}
	if (ini >= fin) {
		mitad = (ini + fin) / 2;
		if (listaCita.lista[mitad].valoracion == cita.valoracion) {
			pos = mitad;
		}
		else if (listaCita.lista[mitad].valoracion < cita.valoracion) {
			pos = mitad;
		}
		else {
			pos = mitad + 1;
		}
	}

	return pos;
}

int devuelveNumero(const tListaClientes& listaClientes) {
	return listaClientes.contador;
}
tCita devuelveCita(const tListaClientes& listaClientes) {
	tCita cita;
	int cliente1, cliente2, valoracion;
	string ciudad;

	cout << endl <<  "   Cliente 1: ";
	cin >> cliente1;
	while (cliente1< 0 || cliente1 > devuelveNumero(listaClientes)-1 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "   Cliente 1: ";
		cin >> cliente1;
	}
	cout << "   Cliente 2: ";
	cin >> cliente2;
	while (cliente2< 0 || cliente2 > devuelveNumero(listaClientes)-1 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "   Cliente 2: ";
		cin >> cliente2;
	}
	cout << "   Lugar de la cita: ";
	cin >> ciudad;
	cout << "   Valoración: ";
	cin >> valoracion;
	while (valoracion < 0 || valoracion > 5 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "   Valoración: ";
		cin >> valoracion;
	}

	cita.cliente1 = devuelveClientePtr(listaClientes, cliente1);
	cita.cliente2 = devuelveClientePtr(listaClientes, cliente2);
	cita.lugar = ciudad;
	cita.valoracion = valoracion;

	return cita;
}