#include"ListaReproduccion.h"


//Elaboraci�n de listas de reproducci�n musicales a partir de una lista maestra
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
		cout << "N�mero de temas: ";
		cin >> numTemas;
		while (devuelveTam(listaTemas) < numTemas) {
			cout << "El n�mero de temas supera al tama�o de la lista de temas." << endl;
			cout << "Introduzca un n�mero entre 1 y " << devuelveTam(listaTemas)<<": ";
			cin >> numTemas;
		}
		listaReproduccion = nueva(numTemas, nombre);
		generarListaRep(listaReproduccion, listaTemas, numTemas);
		mostrar(listaReproduccion);
		cout << endl << endl << "Cambio de orden: �ltimo al primero" << endl << endl;
		modificarOrden(listaReproduccion, numTemas - 1, 0);
		mostrar(listaReproduccion);
		cout << endl << endl << "Cambio de orden: segundo al �ltimo" << endl << endl;
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
		cout << endl << endl << "ERROR: no se ha podido cargar la informcai�n de fichero" << endl << endl;
	}


	system("pause");
	return 0;
}

