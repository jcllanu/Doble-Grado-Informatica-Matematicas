#include"ListaCompradores.h" 

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("chcp 1252");

	tListaLonja listaLonja;
	tComprador comprador;
	long long int numCompr;
	float precio;
	tListaCompradores listaCompradores;


	if (cargar(listaLonja)) {
		inicializar(listaCompradores);
		for (int i = 0; i < numLotes(listaLonja); i++) {
			mostrarLote(obtenerLote(listaLonja, i));
			cout << endl << "Introduzca comprador: ";
			cin >> numCompr;
			cout << "Introduzca precio: ";
			cin >> precio;
			comprador = devuleveComprador(numCompr, precio);
			insertar(listaCompradores, comprador);
			modificarLote(obtenerLote(listaLonja, i), numCompr, precio);
			
		}

		mostrar(listaCompradores);
		mostrar(listaLonja);
		liberar(listaCompradores);
		liberar(listaLonja);
	}
	else {
		cout << endl << endl << "No se ha podido cargar la información desde el fichero" << endl << endl;
	}




	system("pause");
	return 0;
}