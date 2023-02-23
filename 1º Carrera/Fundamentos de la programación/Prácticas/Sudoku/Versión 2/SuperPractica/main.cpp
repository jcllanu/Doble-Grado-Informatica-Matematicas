#include"ListaJugadores.h"



int menuExterior();
void jugar(tListaJugadores& listaJugadores, const tListaSudokus& listaSudokus);

int main() {
	system("chcp 1252");

	tListaJugadores listaJugadores;
	tListaSudokus listaSudokus;
	int op;
	creaListaVacia(listaJugadores);
	creaListaVacia(listaSudokus);

	if (cargar(listaJugadores) && cargar(listaSudokus)) {
		op = menuExterior();
		while (op != 0) {
			switch (op) {
			case 1: {
				jugar(listaJugadores, listaSudokus);
			}
					break;
			case 2: {
				mostrar(listaJugadores);
			}
					break;
			case 3: {
				mostrar(ordenarPorRanking(listaJugadores));
			}
					break;
			case 4: {
				if (registrarSudoku(listaSudokus)) {
					mostrar(listaSudokus);
				}
				else {
					cout << "ERROR: No se ha podido realizar la operación por que la lista está llena o el nombre de archivo ya aparece en la lista." << endl;
				}
			}
					break;
			
			}
		
			op = menuExterior();
		}
	}
	else {
		cout << endl << "ERROR: No se han podido realizar la carga de los archivos de texto." << endl;
	}

	cout << endl << endl;
	system("pause");
	return 0;

}

void jugar(tListaJugadores& listaJugadores, const tListaSudokus& listaSudokus) {
	tSudoku sudoku;
	string nombre;
	int puntos, puntosobt;
	cout << "Lista de sudokus: " << endl;
	mostrar(listaSudokus);
	cout << "Introduce el nombre del sudoku elegido: ";
	cin >> nombre;
	while (!buscarFichero(listaSudokus, nombre) || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción incorrecta. Introduce el nombre del sudoku elegido: ";
		cin >> nombre;
	}
	puntos = puntosDeUnSudoku(listaSudokus, nombre);
	datosSudoku(sudoku, nombre, puntos);
	puntosobt = jugarUnSudoku(sudoku);
	cout << "Has obtenido " << puntosobt << " puntos." << endl;
	if (puntosobt > 0) {
		puntuarJugador(listaJugadores, puntosobt);
	}
	
}

int menuExterior() {
	int op;
	cout << endl << "1.- Jugar" << endl;
	cout << "2.- Ver jugadores ordenados por identificador" << endl;
	cout << "3.- Ver jugadores ordenados por puntos" << endl;
	cout << "4.- Incorporar sudoku" << endl;
	cout << "0.- Salir" << endl << endl;
	cout << "Elija una funcionalidad(1/2/3/4) o vuelva al menú princial(0): ";
	cin >> op;

	while (op < 0 || op > 4 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción incorrecta. Elija una funcionalidad(1/2/3/4) o vuelva al menú princial(0): ";
		cin >> op;
	}
	return op;
}

/*
int main() {
	system("chcp 1252");
	int op;
	tListaSudokus l;
	tJuego juego;
	tSudoku sudoku;
	if (!cargar(l)) {
		cout << "No se ha podido cargar la lista de sudokus";
	}
	else {
		cout << "1.- Jugar" << endl;
		cout << "0.- Salir" << endl;
		cout << "Opción: ";
		cin >> op;
		while (op != 0) {
			cout << "Lista de sudokus: " << endl;
			mostrar(l);
			cout << "Introduce el nombre del sudoku elegido: ";
			cin >> sudoku.nombre;
			cout << "Introduce los puntos del sudoku elegido: ";
			cin >> sudoku.puntos;
			cout<<"Has obtenido "<<jugarUnSudoku(sudoku)<<" puntos."<<endl;

			cout << "1.- Jugar" << endl;
			cout << "0.- Salir" << endl;
			cout << "Opción: ";
			cin >> op;
		}

	}


	system("pause");
	return 0;

}

tListaSudokus lista;
	creaListaVacia(lista);
	if (cargar(lista)) {
		mostrar(lista);
		while (true) {
			if (registrarSudoku(lista)) {
				mostrar(lista);
			}
			else {
				cout << "ERROR: No se ha podido realizar la operación por que la lista está llena o el nombre de archivo ya aparece en la lista." << endl;
			}
		}
		guardar(lista);
	}
	else {
		cout << "ERORR";
	}



		tListaJugadores lista;

	creaListaVacia(lista);
	if (cargar(lista)) {
		mostrar(lista);
		while (true) {
			puntuarJugador(lista, 5);
			mostrar(lista);
		}
		guardar(lista);
	}
	else {
		cout << "ERORR";
	}


*/