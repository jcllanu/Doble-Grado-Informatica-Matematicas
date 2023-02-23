#include"ListaCitas.h"

int menu();

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("chcp 1252");

	tListaCitas listaCitas;
	tListaClientes listaClientes;
	tCita cita;
	int op , pos;
	
	
	
	if (cargar(listaClientes)) {
		if (nuevaLista(listaCitas)) {
			op = menu();
			while (op != 0) {
				switch (op) {
				case 1: {
					pos = 0;
					cout << endl;
					mostrar(listaClientes, pos);
				}break;
				case 2: {
					cout << endl << "Cita entre dos clientes. Elija dos números: " << endl;
					pos = 0;
					mostrar(listaClientes, pos);
					cita = devuelveCita(listaClientes);
					if (!inserta(listaCitas, cita)) {
						cout << endl << endl << "No hay sufiente memoria en el heap." << endl << endl;
					}
					
				}break;
				case 3: {
					muestra(listaCitas);

				}break;

				}
				op = menu();
			}
			liberar(listaCitas);
			liberar(listaClientes);
		}
		else {
			cout << endl << endl << "No hay sufiente memoria en el heap." << endl << endl;
		}
	}
	else {
		cout << endl << endl << "No se ha podido cargar la información de fichero." << endl << endl;
	}


	system("pause");
	return 0;
}

int menu() {
	int op;

	cout << endl << "1.- Mostrar lista de clientes" << endl;
	cout << "2.- Nueva cita" << endl;
	cout << "3.- Mostrar todas las citas (ordenadas por valoración)" << endl;
	cout << "0.- Salir" << endl;
	cout << "Elija una de las opciones (1/2/3) o finalice el programa (0): ";
	cin >> op;
	while (op < 0 || op>3 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Elija una de las opciones (1/2/3) o finalice el programa (0): ";
		cin >> op;
	}

	return op;
}

