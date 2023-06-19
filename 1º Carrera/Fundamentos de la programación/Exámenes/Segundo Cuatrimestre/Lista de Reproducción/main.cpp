#include"ListaReproduccion.h"


//Elaboración de listas de reproducción musicales a partir de una lista maestra
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("chcp 1252");
	srand(1);

	tListaTemas listaTemas;
	string nombre;
	int numTemas;
	tListaReproduccion listaReproduccion;

	if (cargar(listaTemas)) {
		cout << endl << endl << "Nombre: ";
		getline(cin, nombre);
		cout << "Número de temas: ";
		cin >> numTemas;
		while (devuelveTam(listaTemas) < numTemas) {
			cout << "El número de temas supera al tamaño de la lista de temas." << endl;
			cout << "Introduzca un número entre 1 y " << devuelveTam(listaTemas)<<": ";
			cin >> numTemas;
		}
		listaReproduccion = nueva(numTemas, nombre);
		generarListaRep(listaReproduccion, listaTemas, numTemas);
		mostrar(listaReproduccion);
		cout << endl << endl << "Cambio de orden: último al primero" << endl << endl;
		modificarOrden(listaReproduccion, numTemas - 1, 0);
		mostrar(listaReproduccion);
		cout << endl << endl << "Cambio de orden: segundo al último" << endl << endl;
		modificarOrden(listaReproduccion, 1, numTemas - 1);
		mostrar(listaReproduccion);
		if (numTemas >= 4) {
			cout << endl << endl << "Cambio de orden: segundo al cuarto" << endl << endl;
			modificarOrden(listaReproduccion, 1, 3);
			mostrar(listaReproduccion);
		}
		destruir(listaReproduccion);
		destruir(listaTemas);
		
	}
	else {
		cout << endl << endl << "ERROR: no se ha podido cargar la informcaión de fichero" << endl << endl;
	}


	system("pause");
	return 0;
}

