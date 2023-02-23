#include"ListaProgramas.h"

bool buscar(const tListaProgramas& listaProgramas, const tPrograma& programa, int &pos);
void mostrar(const tListaProgramas& listaProgramas);


bool insertar(tListaProgramas& listaProgramas, const tPrograma& programa) {
	int pos;
	bool ok;
	if (!buscar(listaProgramas, programa, pos) && listaProgramas.contador < MAX_TAM) {
		
		listaProgramas.contador++;
		for (int i = listaProgramas.contador - 1; i > pos; i--) {
			listaProgramas.lista[i] = listaProgramas.lista[i - 1];
		}
		listaProgramas.lista[pos] = new tPrograma(programa);

		if (listaProgramas.lista[pos] == NULL) {
			ok = false;
		}
		else {
			ok = true;
		}
	}
	else {
		ok = false;
	}
	return ok;
}

bool cargar(tListaProgramas& listaProgramas) {
	ifstream archivo;
	bool ok;
	tPrograma programa;

	listaProgramas.contador = 0;
	archivo.open(LECTURA);
	if (archivo.is_open()) {
		ok = true;
		while (cargar(programa, archivo) && listaProgramas.contador<MAX_TAM && ok) {
			if (!insertar(listaProgramas, programa)) {
				ok = false;
			}
		}
	}
	else {
		ok = false;
	}

	return ok;
}

tProgramaPtr selecPrograma(const tListaProgramas& listaProgramas) {
	int num;
	mostrar(listaProgramas);
	cout << endl << "Introduzca el número de uno de los programas: ";
	cin >> num;
	while (num > listaProgramas.contador || num < 1 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Número incorrecto. Introduzca el número de uno de los programas: ";
		cin >> num;
	}
	return listaProgramas.lista[num-1];
}

void destruir(tListaProgramas& listaProgramas) {
	for (int i = 0; i < listaProgramas.contador; i++) {
		delete listaProgramas.lista[i];
	}
}

bool buscar(const tListaProgramas& listaProgramas, const tPrograma& programa, int &pos) {
	int ini = 0, fin = listaProgramas.contador - 1, mitad;
	bool encontrado = false;

	while(!encontrado && ini < fin) {
		mitad = (ini + fin) / 2;
		if (*listaProgramas.lista[mitad] == programa) {
			encontrado = true;
			pos = mitad;
		}
		else if (*listaProgramas.lista[mitad] < programa) {
			ini = mitad + 1;
		}
		else {
			fin = mitad - 1;
		}
	}
	if (ini >= fin) {
		if (fin == -1) {
			pos = 0;
		}
		else if (*listaProgramas.lista[fin] == programa) {
			encontrado = true;
			pos = fin;
		}
		else if (*listaProgramas.lista[fin] < programa) {
			pos = fin + 1;
		}
		else {
			pos = fin;
		}
	}
	return encontrado;
}
void mostrar(const tListaProgramas& listaProgramas) {
	cout << endl << endl;
	for (int i = 0; i < listaProgramas.contador; i++) {
		cout << i + 1 << ".- ";
		mostrar(*listaProgramas.lista[i]);
		cout << endl;
	}
}