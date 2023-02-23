#include"ListaGrupos.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("chcp 1252");

	tListaGrupos listaGrupos;
	string nif;
	int pos = 0;
	if (cargar(listaGrupos)) {
		mostrar(listaGrupos);
		cout << endl << endl << "NIF: ";
		cin >> nif;
		if (buscar(listaGrupos, nif, pos)) {
			cout << "Grupo: " << devuelveIdentificador(listaGrupos, pos) << endl << endl;
		}
		else {
			cout << endl << "Ningun estudiante tiene ese DNI" << endl << endl;
		}
		destruir(listaGrupos);
	}
	else {
		cout << "ERROR";
	}




	system("pause");
	return 0;
}