#include"ListaClientes.h"

void mostrar(const tCliente& cliente) {
	cout << setw(15) << left << cliente.login << setw(15) << cliente.fechaAlta << setw(4) << cliente.edad << setw(15) << "años" << cliente.ciudad << endl;
}
bool cargar(tListaClientes& listaClientes) {
	ifstream archivo;
	bool ok;
	tCliente cliente;

	archivo.open(LECTURA);
	if (archivo.is_open()) {
		ok = true;
		archivo >> listaClientes.contador;
		for (int i = 0; i < listaClientes.contador; i++) {
			archivo >> cliente.login >> cliente.fechaAlta >> cliente.edad >> cliente.ciudad;
			listaClientes.lista[i] = new tCliente(cliente);
			if (listaClientes.lista[i] == NULL) {
				ok = false;
			}
		}

	}
	else {
		ok = false;
	}
	return ok;
}

void mostrar(const tListaClientes& listaClientes, int& pos) {
	if (pos < listaClientes.contador) {
		cout << pos << ".- ";
		mostrar(*listaClientes.lista[pos]);
		pos++;
		mostrar(listaClientes, pos);
	}
}

void liberar(tListaClientes& listaClientes) {
	for (int i = 0; i < listaClientes.contador; i++) {
		delete listaClientes.lista[i];
	}
}

tClientePtr devuelveClientePtr(const tListaClientes& listaClientes, int pos) {
	return listaClientes.lista[pos];
}