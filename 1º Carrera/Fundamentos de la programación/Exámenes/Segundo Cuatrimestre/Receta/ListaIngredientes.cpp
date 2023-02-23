#include"ListaIngredientes.h"

void inserta(tListaIngredientes& listaIngredientes, const tIngrediente& ingrediente) {
	bool encontrado = false;
	int pos = 0;
	while (!encontrado && pos < listaIngredientes.contador) {
		if (ingrediente.nombre <= listaIngredientes.lista[pos]->nombre) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}
	listaIngredientes.contador++;

	for (int i = listaIngredientes.contador - 1; i >= pos; i--) {
		listaIngredientes.lista[i] = listaIngredientes.lista[i - 1];
	}
	listaIngredientes.lista[pos]= new tIngrediente(ingrediente);
}

bool carga(tListaIngredientes& listaIngredientes) {
	ifstream archivo;
	bool ok;
	tIngrediente ingredienteAux;
	char aux;

	listaIngredientes.contador = 0;
	archivo.open("ingredientes.txt");
	if(archivo.is_open()) {
		ok = true;
		archivo >> ingredienteAux.calorias;
		while (ingredienteAux.calorias != -1 && listaIngredientes.contador < MAX_INGREDIENTES) {
			archivo.get(aux);
			getline(archivo, ingredienteAux.nombre);
			inserta(listaIngredientes, ingredienteAux);
			archivo >> ingredienteAux.calorias;
		}
	}
	else {
		ok = false;
	}

	return ok;

}

string selectIngred(const tListaIngredientes& listaIngredientes) {
	int num;

	for (int i = 0; i < listaIngredientes.contador; i++) {
		cout << i + 1 << ".- " << setw(20) << left << listaIngredientes.lista[i]->nombre << listaIngredientes.lista[i]->calorias << " calorías" << endl;
	}
	cout << endl << endl << "Introduzca el número del ingrediente elegido (entre 1 y " << listaIngredientes.contador << "): ";
	cin >> num;
	while (num<1 || num>listaIngredientes.contador || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << endl << "Introduzca el número del ingrediente elegido (entre 1 y " << listaIngredientes.contador << "): ";
		cin >> num;
	}

	return listaIngredientes.lista[num - 1]->nombre;
}

int busca(const tListaIngredientes& listaIngredientes, string nombre, int& ini, int& fin) {
	int mitad = (ini + fin) / 2;
	int pos;
	if (ini < fin) {
		if (listaIngredientes.lista[mitad]->nombre == nombre) {
			pos = mitad;
		}
		else if (listaIngredientes.lista[mitad]->nombre < nombre) {
			ini = mitad + 1;
			pos = busca(listaIngredientes, nombre, ini, fin);
		}
		else {
			fin = mitad - 1;
			pos = busca(listaIngredientes, nombre, ini, fin);
		}

	}
	else {
		if (listaIngredientes.lista[mitad]->nombre == nombre) {
			pos = mitad;
		}
		else if (listaIngredientes.lista[mitad-1]->nombre < nombre) {
			pos = mitad - 1;
		}
		else if (listaIngredientes.lista[mitad + 1]->nombre < nombre){
			pos = mitad + 1;
		}
		else {
			pos = -1;
		}
	}
	return pos;
}

string devuelveNombre(const tIngrediente& ingrediente) {
	return ingrediente.nombre;
}
double calorias(const tIngrediente& ingrediente) {
	return ingrediente.calorias;
}
void liberar(tListaIngredientes& listaIngredientes) {
	for (int i = 0; i < listaIngredientes.contador; i++) {
		delete listaIngredientes.lista[i];
	}
}