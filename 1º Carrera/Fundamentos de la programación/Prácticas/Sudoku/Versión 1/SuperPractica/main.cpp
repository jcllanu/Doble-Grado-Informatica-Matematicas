#include"ListaSudokus.h"

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