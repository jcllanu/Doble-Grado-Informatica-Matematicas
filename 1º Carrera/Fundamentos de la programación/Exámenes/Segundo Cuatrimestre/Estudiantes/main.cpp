#include"ListaGrupos.h"

//Gestion de estudiantes matriculados en un	curso universitario,separados	por	grupos.	El programa	constará de	4
//módulos: Estudiante, ListaEstudiantes, ListaGrupos y main

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