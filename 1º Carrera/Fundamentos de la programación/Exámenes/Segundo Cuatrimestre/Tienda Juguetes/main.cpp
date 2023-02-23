#include"Coleccion.h"

int menu();

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	system("chcp 1252");
	tListaJuguetes listaJuguetes;
	tColeccion coleccion;
	int op, decada, num;
	double preciomaximo;

	if (cargar(listaJuguetes)) {
		op = menu();
		while (op != 3) {
			switch (op) {
			case 1: {
				cout << endl;
				mostrar(listaJuguetes);
			}
					break;
			case 2: {
				cout << "Década (50, 60, 70, 80): ";
				cin >> decada;
				while (decada != 50 && decada != 60 && decada != 70 && decada != 80) {
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Década (50, 60, 70, 80): ";
					cin >> decada;
				}
				cout << "Precio máximo: ";
				cin >> preciomaximo;
				coleccion = crearColeccion(listaJuguetes, preciomaximo, DevuelveDecada(decada));
				num = 0;
				mostrar(coleccion, num);
				liberar(coleccion);
			}
					break;
			}
			op = menu();
		}
		liberar(listaJuguetes);
	}
	else {
		cout << endl << endl << "No se ha podido cargar la lista de juguetes." << endl << endl;
	}

	system("pause");
	return 0;
}

int menu(){
	int op;

	cout << endl << endl;
	cout << "1.- Visualizar inventario de juguetes" << endl;
	cout << "2.- Crear y mostrar una coleccion" << endl;
	cout << "3.- Salir" << endl;
	cout << "Elija una opción: ";
	cin >> op;
	while (op > 3 || op < 1 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Elija una opción: ";
		cin >> op;
	}
	return op;
}