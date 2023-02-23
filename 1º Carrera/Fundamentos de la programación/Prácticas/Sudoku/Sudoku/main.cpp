#include"ListaJugadores.h"
#include"checkML.h"


int menuPrincipal();/*Muestra por pantalla el menú principal de la aplicación y devuelve un entero en el intervalo [0, 4] según la opción elegida por el usuario*/
void jugar(tListaJugadores& listaJugadores, const tListaSudokus& listaSudokus);/*Dada una lista de jugadores y una lista de sudokus permite al usuario elegir uno
																			   de los sudokus de la lista, jugar ese sudoku y puntuar al jugador*/
void guardar(const tListaJugadores& listaJugadores, const tListaSudokus& listaSudokus);/*Guarda en archivos de texto el contenido de ListaJugadores y listaSudokus*/


int main() {
	system("chcp 1252");
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	tListaJugadores listaJugadores, listaRanking;
	tListaSudokus listaSudokus;
	int op;

	creaListaVacia(listaJugadores);
	creaListaVacia(listaSudokus);

	if (cargar(listaJugadores) && cargar(listaSudokus)) {
		op = menuPrincipal();

		while (op != 0) {
			switch (op) {
			case 1: {
				jugar(listaJugadores, listaSudokus);
			}
					break;
			case 2: {
				cout << endl << "Lista de jugadores:";
				mostrar(listaJugadores);
			}
					break;
			case 3: {
				cout << endl << "Lista de jugadores ordenados por ranking:";
				listaRanking = ordenarPorRanking(listaJugadores);
				mostrar(listaRanking);
				borrarListaJugadores(listaRanking);

			}
					break;
			case 4: {
				if (registrarSudoku(listaSudokus)) {
					cout << endl << "Lista de sudokus: " << endl << endl;
					mostrar(listaSudokus);
				}
				else {
					cout << "ERROR: No se ha podido realizar la operación por que la lista está llena o el nombre de archivo ya aparece en la lista." << endl;
				}
			}
					break;
			
			}
		
			op = menuPrincipal();
		}
		cout << endl << endl;

		guardar(listaJugadores, listaSudokus);
	}
	else {
		cout << endl << "ERROR: No se han podido realizar la carga de los archivos de texto." << endl;
	}
	liberarMemoria(listaJugadores);

	cout << endl << endl;
	system("pause");
	return 0;

}

void jugar(tListaJugadores& listaJugadores, const tListaSudokus& listaSudokus) {
	tSudoku sudoku;
	int num;
	int puntos, puntosobt;

	cout << endl << "Lista de sudokus: " << endl << endl;
	mostrar(listaSudokus);
	cout << endl << "Introduce el número del sudoku elegido: ";
	cin >> num;
	num = num - 1;

	while ( num<0|| num>=devuelveContador(listaSudokus)|| cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción incorrecta. Introduce el número del sudoku elegido: ";
		cin >> num;
		num = num - 1;
	}
	
	
	puntosobt = jugarUnSudoku(devuelveSudoku(listaSudokus,num));

	if (puntosobt != -1) {
		cout << "Has obtenido " << puntosobt << " puntos." << endl << endl;
	}
	if (puntosobt > 0) {
		puntuarJugador(listaJugadores, puntosobt);
	}
}

int menuPrincipal() {
	int op;
	cout << endl << " 1.- Jugar" << endl;
	cout << " 2.- Ver jugadores ordenados por identificador" << endl;
	cout << " 3.- Ver jugadores ordenados por puntos" << endl;
	cout << " 4.- Incorporar sudoku" << endl;
	cout << " 0.- Salir" << endl << endl;
	cout << "Elija una de las opciones (1/2/3/4) o finalice el programa (0): ";
	cin >> op;

	while (op < 0 || op > 4 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción incorrecta. Elija una de las opciones (1/2/3/4) o finalice el programa (0): ";
		cin >> op;
	}
	return op;
}

void guardar(const tListaJugadores& listaJugadores, const tListaSudokus& listaSudokus) {
	if (guardar(listaJugadores)) {
		cout << "Se ha guardado con éxito la lista de jugadores." << endl;
	}
	else {
		cout << "No se ha podido guardar con éxito la lista de jugadores." << endl;
	}
	if (guardar(listaSudokus)) {
		cout << "Se ha guardado con éxito la lista de sudokus." << endl;
	}
	else {
		cout << "No se ha podido guardar con éxito la lista de sudokus." << endl;
	}
}