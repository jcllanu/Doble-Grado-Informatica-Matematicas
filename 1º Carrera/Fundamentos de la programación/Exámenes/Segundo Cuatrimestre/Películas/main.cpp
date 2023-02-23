#include"ListaPeliculas.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("chcp 1252");

	tListaPeliculas listaPeliculas, listaActor;
	string actor;
	if (cargar(listaPeliculas)) {
		cout << endl << "Introduzca el nombre de un actor: ";
		getline(cin, actor);
		listaActor = filtrarPorActor(listaPeliculas, actor);
		ordenaPorGenero(listaActor);
		ordenaListaOrdenada(listaActor);
		mostrar(listaActor);
		destruir(listaPeliculas);
	}
	else {
		cout << endl << endl << "ERROR: No se ha podido cargar la información desde el fichero." << endl << endl;
	}






	system("pause");
	return 0;
}