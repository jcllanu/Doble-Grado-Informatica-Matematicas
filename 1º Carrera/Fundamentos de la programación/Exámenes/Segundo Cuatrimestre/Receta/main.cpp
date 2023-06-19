#include"Receta.h"

int menu();
//Gestión de recetas a partir de una lista maestra de ingredientes

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("chcp 1252");

	tListaIngredientes listaIngredientes;
	tReceta receta;
	int op;
	if (!carga(listaIngredientes)) {
		cout << endl << endl << "No ha sido posible cargar la lista de ingredientes" << endl << endl;
	}
	else {
		cout << endl << endl;
		receta = crea();
		op = menu();
		while (op != 0) {
			switch (op) {
			case 1: {
				inserta(receta, leeComponente(listaIngredientes));
			}
					break;
			case 2: {
				muestra(receta);
			}
					break;
			}
			op = menu();
		}
		liberar(receta);
		liberar(listaIngredientes);
	}


	system("pause");
	return 0;
}

int menu() {
	int op;
	cout << endl << endl;
	cout << "1.- Añadir un ingrediente a la receta" << endl;
	cout << "2.- Mostrar el estado actual de la receta" << endl;
	cout << "0.- Salir" << endl;
	cout << "Elija una opción (1/2) o finalice el programa(0): ";
	cin >> op;

	while (op < 0 || op>2 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Elija una opción (1/2) o finalice el programa(0): ";
		cin >> op;
	}
	cout << endl << endl;
	return op;
}