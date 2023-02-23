#include"Grabaciones.h"

int menu();



int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("chcp 1252");

	tListaGrabaciones listaGrabaciones;
	tListaProgramas listaProgramas;
	tGrabacion grabacion;
	int op;

	if (cargar(listaProgramas)) {
		crear(listaGrabaciones);
		op = menu();
		while (op != 3) {
			switch (op) {
			case 1: {
				grabacion = grabar(selecPrograma(listaProgramas));
				if (insertar(listaGrabaciones, grabacion)) {
					cout << endl << "Se ha programado la grabación con éxito." << endl << endl << endl << endl;
				}
				else {
					cout << endl << "ERROR: No se ha podido programar la grabación." << endl;
				}
			}break;
			case 2: {
				cout << endl <<"Lista de grabaciones programadas aún no emitidas: "<< endl << endl;
				mostrar(listaGrabaciones);
				cout << endl << endl << endl << endl;
			}break;
			}
			op = menu();
		}
		destruir(listaGrabaciones);
		destruir(listaProgramas);
	}
	else {
		cout << endl << endl << "ERROR: No se ha podido realizar con éxito la carga desde fichero." <<endl << endl;
	}

	system("pause");
	return 0;
}

int menu() {
	int op;
	cout << endl << "1.- Programar un grabación nueva." << endl;
	cout << "2.- Mostrar grabaciones programadas hasta ahora." << endl;
	cout << "3.- Salir." << endl;
	cout << "Opción: ";
	cin >> op;
	while (op < 1 || op>3 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción: ";
		cin >> op;
	}

	return op;
}