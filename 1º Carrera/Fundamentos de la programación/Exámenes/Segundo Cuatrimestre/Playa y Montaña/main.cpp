#include"ListaOpciones.h"

int menu();

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("chcp 1252");

	tListaLugares playa, sierra;
	tListaOpc listaOpc;
	int op;



	if (cargar(playa, "Playas.txt") && cargar(sierra, "Sierras.txt")) {
		crearListaOpc(listaOpc);
		op = menu();
		while (op != 0) {
			switch (op) {
			case 1: {
				cout << endl << "Destinos de playa: ";
				cout << playa;
			}break;
			case 2: {
				cout << endl << "Destinos de montaña: ";
				cout << sierra;
			}break;
			case 3: {
				nuevoViaje(listaOpc, playa, sierra);
			}break;
			case 4: {
				cout << listaOpc;

			}break;
			}
			op = menu();
		}
		liberar(listaOpc);
		liberar(playa);
		liberar(sierra);
	}
	else {
		cout << endl << endl << "No se han podido cargar los archivos." << endl << endl;
	}

	cout << endl;

	system("pause");
	return 0;
}


int menu() {
	int op;

	cout << endl << "1.- Mostrar lugares con playa." << endl;
	cout << "2.- Mostrar lugares con montaña." << endl;
	cout << "3.- Introduce un nuevo posible viaje." << endl;
	cout << "4.- Mostrar todas las configuraciones de viaje." << endl;
	cout << "0.- Terminar." << endl;
	cout << "Elige un opción (1/2/3/4) o finaliza el programa: ";
	cin >> op;
	while (op < 0 || op>4 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Elige un opción (1/2/3/4) o finaliza el programa: ";
		cin >> op;
	}

	return op;
}