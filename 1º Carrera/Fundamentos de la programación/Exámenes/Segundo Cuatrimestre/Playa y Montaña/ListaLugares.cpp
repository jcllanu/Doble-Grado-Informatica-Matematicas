#include"ListaLugares.h"

istream& operator>> (istream & in, tListaLugares & lista) {
	tLugar lugarAux;

	in >> lista.contador;
	for (int i = 0; i < lista.contador; i++) {
		in >> lugarAux.nombre >> lugarAux.precio;
		lista.lista[i] = new tLugar(lugarAux);
	}
	return in;
}

ostream& operator<< (ostream & out, tListaLugares const& lista) {
	out << endl<<endl<<setw(15) << right << "Nombre" << setw(15) << "Precio" << endl;
	for (int i = 0; i < lista.contador; i++) {
		out << setw(15) << lista.lista[i]->nombre << setw(15) << lista.lista[i]->precio << endl;
	}
	return out;
}
bool buscar(const tListaLugares& lista, string nombre, int& pos) {
	bool encontrado;

	if (pos >= lista.contador) {
		encontrado = false;
	}
	else {
		if (lista.lista[pos]->nombre == nombre) {
			encontrado = true;
		}
		else {
			pos++;
			encontrado = buscar(lista, nombre, pos);
		}

	}
	return encontrado;
}



void liberar(tListaLugares& lista) {
	for (int i = 0; i < lista.contador; i++) {
		delete lista.lista[i];
	}
}


bool cargar(tListaLugares& lista, string fichero) {
	ifstream archivo;
	bool ok;

	archivo.open(fichero); 
	if (archivo.is_open()) {
		ok = true;
		archivo >> lista;
	}
	else {
		ok = false;
	}
	return ok;
}

int precioLugar(const tLugar& lugar) {
	return lugar.precio;
}
string devuelveLugar(const tLugar& lugar) {
	return lugar.nombre;
}