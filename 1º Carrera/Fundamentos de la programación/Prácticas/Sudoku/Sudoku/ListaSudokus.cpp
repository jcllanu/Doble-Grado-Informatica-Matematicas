#include"ListaSudokus.h"
#include<fstream>
#include"checkML.h"

void creaListaVacia(tListaSudokus & lista) {
	lista.contador = 0;
}

bool cargar(tListaSudokus & lista) {
	bool ok = false;
	string nombre;
	int puntos;
	char aux;
	tSudoku sudokuaux;
	ifstream archivo;

	archivo.open(LISTAS);
	if (archivo.is_open()) {
		creaListaVacia(lista);
		archivo >> nombre;
		while (!archivo.eof() && lista.contador < MAX_SUDOKUS) {
			archivo >> puntos;
			datosSudoku(sudokuaux, nombre, puntos);
			archivo.get(aux);
			lista.lista[lista.contador] = sudokuaux;
			lista.contador++;
			archivo >> nombre;
		}
		ok = true;
		archivo.close();
	}
	return ok;
}

void mostrar(const tListaSudokus & lista) {
	for (int i = 0; i < lista.contador; i++) {
		cout << "  " << i + 1 << ".-  ";
		mostrarSudoku(lista.lista[i]);
	}
}

bool guardar(const tListaSudokus & lista) {
	bool ok = false;
	ofstream archivo;

	archivo.open(LISTAS);
	if (archivo.is_open()) {
		for (int i = 0; i < lista.contador; i++) {
			archivo << devuelveSudoku(lista.lista[i]) << endl;
		}
		ok = true;
		archivo.close();
	}
	return ok;
}

bool registrarSudoku(tListaSudokus & lista) {
	bool ok;
	tSudoku sudokuaux;
	string nombre;
	int puntos, pos;

	cout << "Introduce el nombre del nuevo sudoku (incluye '.txt'): ";
	cin >> nombre;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Se ha producido un error. Vuelva a introducir el nombre del nuevo sudoku (incluye '.txt'): ";
		cin >> nombre;
	}
	cout << "Introduce los puntos conseguidos por resolverlo: ";
	cin >> puntos;
	while (cin.fail() || puntos < 0) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Se ha producido un error. Vuelva a introducir los puntos conseguidos por resolverlo: ";
		cin >> puntos;
	}
	if (buscarFichero(lista, nombre) || lista.contador >= MAX_SUDOKUS) {
		ok = false;
	}
	else {
		ok = true;
		datosSudoku(sudokuaux, nombre, puntos);
		pos = buscarPos(lista, sudokuaux);

		lista.contador++;
		for (int i = lista.contador - 2; i >= pos; i--) {
			lista.lista[i + 1] = lista.lista[i];
		}
		lista.lista[pos] = sudokuaux;
		
	}
	return ok;
}

bool buscarFichero(const tListaSudokus & lista, string nombreFich) {
	bool encontrado = false;
	int contador = 0;

	while (!encontrado && contador < lista.contador) {
		if (devuelveNombre(lista.lista[contador]) == nombreFich) {
			encontrado = true;
		}
		else {
			contador++;
		}
	}
	return encontrado;
}

int buscarPos(const tListaSudokus & lista, const tSudoku & sudoku) {

	int ini = 0, fin = lista.contador - 1, mitad, pos;

	while (ini < fin) {
		mitad = (ini + fin) / 2;
		if (sudoku < lista.lista[mitad]) {
			fin = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}
	}
	if (ini == fin) {
		mitad = (ini + fin) / 2;
		if (sudoku < lista.lista[mitad]) {
			pos = mitad;
		}
		else {
			pos = mitad + 1;
		}
	}
	else {
		pos = mitad;
	}
	return pos;
}

int devuelveContador(const tListaSudokus& lista) {
	return lista.contador;
}
tSudoku devuelveSudoku(const tListaSudokus& lista, int num) {
	return lista.lista[num];
}