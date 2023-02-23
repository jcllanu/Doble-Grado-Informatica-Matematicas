#include"Juego.h"
#include"checkML.h"

int submenu();/*Muestra por pantalla el submenú de la aplicación y devuelve un entero en el intervalo [0, 5] según la opción elegida por el usuario*/
void verPosibles(const tJuego & juego);/*Permite ejecutar la funcionalidad de ver valores posibles (opción 1 del submenú)*/
void colocarValor(tJuego & juego);/*Permite ejecutar la funcionalidad de colocar un valor en un sudoku (opción 2 del submenú)*/
void borrarValor(tJuego & juego);/*Permite ejecutar la funcionalidad de borrar un valor del sudoku (opción 3 del submenú)*/

void iniciaJuego(tJuego & juego, const tSudoku & sudoku) {
	juego.resuelto = false;
	juego.sudoku = sudoku;
	iniciaTablero(juego.tablero);	
}

void mostrarJuego(const tJuego & juego) {
	cout << endl << endl;
	cout << "       ";
	mostrarSudoku(juego.sudoku);
	dibujarTablero(juego.tablero);
}

void mostrarSudoku(const tSudoku & sudoku) {
	cout << "Nombre del sudoku: " << sudoku.nombre << endl;
	cout << "       Puntos por resolverlo: " << sudoku.puntos << endl << endl;
}

bool cargaJuego(tJuego & juego, const tSudoku & sudoku) {
	return cargarTablero(sudoku.nombre, juego.tablero);
}

int jugarUnSudoku(const tSudoku & sudoku) {
	tJuego juego;
	int op, puntos = 0;

	iniciaJuego(juego, sudoku);
	if (!cargaJuego(juego, sudoku)) {
		cout << "No fue posible cargar el juego." << endl;
		puntos = -1;
	}
	else {
		mostrarJuego(juego);

		op = submenu();
		while (op != 0) {
			switch (op) {
			case 1: {
				verPosibles(juego);
			}
					break;
			case 2: {
				colocarValor(juego);
			}
					break;
			case 3: {
				borrarValor(juego);
			}
					break;
			case 4: {
				cargaJuego(juego, sudoku);
				dibujarTablero(juego.tablero);
			}
					break;
			case 5: {
				rellenarSimples(juego.tablero);
				dibujarTablero(juego.tablero);
			}
					break;
			}
			if (tableroLleno(juego.tablero)) {
				op = 0;
				puntos = sudoku.puntos;
				cout << "		¡Sudoku resulto!" << endl << endl;
			}
			else {
				op = submenu();
			}
		}
	}
	return puntos;
}

void verPosibles(const tJuego & juego) {
	int filas = 0, columnas = 0;

	while (filas < 1 || filas > N || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Introduzca la fila: ";
		cin >> filas;
	}
	while (columnas < 1 || columnas  >N || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Introduzca la columna: ";
		cin >> columnas;
	}

	mostrarPosibles(juego.tablero, filas - 1, columnas - 1);
	dibujarTablero(juego.tablero);
	cout << endl;
}

void colocarValor(tJuego & juego) {
	int filas = 0, columnas = 0, valor = 0;

	while (cin.fail() || valor <1 || valor >N) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Nuevo valor: ";
		cin >> valor;
	}	
	while (filas < 1 || filas > N || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Introduzca la fila: ";
		cin >> filas;
	}
	while (columnas < 1 || columnas  >N || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Introduzca la columna: ";
		cin >> columnas;
	}
	if (!ponerNum(juego.tablero, filas - 1, columnas - 1, valor)) {
		cout << "No fue posible poner el número.";
	}
	cout << endl << endl;
	dibujarTablero(juego.tablero);
	cout << endl;
}

void borrarValor(tJuego & juego) {
	int filas = 0, columnas = 0;

	while (filas < 1 || filas > N || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Introduzca la fila: ";
		cin >> filas;
	}
	while (columnas < 1 || columnas  > N || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Introduzca la columna: ";
		cin >> columnas;
	}
	if (!borrarNum(juego.tablero, filas - 1, columnas - 1)) {
		cout << "No fue posible borrar el número.";
	}
	cout << endl << endl;
	dibujarTablero(juego.tablero);
	cout << endl;
}


int submenu() {
	int op;
	cout << endl << " 1.- Ver posibles valores de una casilla vacía" << endl;
	cout << " 2.- Colocar valor en una casilla" << endl;
	cout << " 3.- Borrar valor de una casilla" << endl;
	cout << " 4.- Reiniciar el tablero" << endl;
	cout << " 5.- Autocompletar celdas simples" << endl;
	cout << " 0.- Abortar la resolución y volver al menú principal" << endl << endl;
	cout << "Elija una funcionalidad(1/2/3/4/5) o vuelva al menú princial(0): ";
	cin >> op;
	
	while (op < 0 || op>5 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción incorrecta. Elija una funcionalidad(1/2/3/4/5) o vuelva al menú princial(0): ";
		cin >> op;
	}
	return op;
}

void datosSudoku(tSudoku & sudoku, string nombre, int puntos) {
	sudoku.nombre = nombre;
	sudoku.puntos = puntos;
}

string devuelveSudoku(const tSudoku &sudoku) {
	string aux = to_string(sudoku.puntos);

	return sudoku.nombre + " " + aux;
}
string devuelveNombre(const tSudoku &sudoku) {
	return sudoku.nombre;
}
int devuelvePuntos(const tSudoku &sudoku) {
	return sudoku.puntos;
}

bool operator<(const tSudoku & sudoku1, const tSudoku & sudoku2) {
	bool menor = false;

	if(devuelvePuntos(sudoku1) == devuelvePuntos(sudoku2)) {
		if (devuelveNombre(sudoku1) < devuelveNombre(sudoku2)) {
			menor = true;
		}
	}
	else if(devuelvePuntos(sudoku1) < devuelvePuntos(sudoku2)) {
		menor = true;
	}

	return menor;
}