#include"ListaEstudiante.h"

void cargar(tListaEstudiantes& listaEstudiantes, istream& archivo) {
	tEstudiante estudiante;
	int contador;
	archivo >> contador;
	listaEstudiantes.lista = new tEstudiante[contador];
	listaEstudiantes.contador = 0;
	for (int i = 0; i < contador; i++) {
		cargar(estudiante, archivo);
		inserta(listaEstudiantes, estudiante);
	}


}
bool buscar(const tListaEstudiantes& listaEstudiantes, string NIF, int &pos) {
	int ini = 0, fin = listaEstudiantes.contador - 1, mitad;
	bool encontrado = false;
	
	while (!encontrado && ini < fin) {
		mitad = (ini + fin) / 2;
		if (devuelveNIF(listaEstudiantes.lista[mitad]) == NIF) {
			encontrado = true;
			pos = mitad;
		}
		else if (devuelveNIF(listaEstudiantes.lista[mitad]) > NIF) {
			ini = mitad + 1;
		}
		else {
			fin = mitad - 1;
		}
	}
	if (ini >= fin) {
		if (fin == -1) {
			pos = 0;
		}
		else if (devuelveNIF(listaEstudiantes.lista[fin]) == NIF) {
			encontrado = true;
			pos = mitad;
		}
		else if (devuelveNIF(listaEstudiantes.lista[fin]) > NIF) {
			pos = fin + 1;
		}
		else {
			pos = fin;
		}
	}
	
	return encontrado;
}
void inserta(tListaEstudiantes& listaEstudiantes, const tEstudiante& estudiante) {
	int pos;

	if (!buscar(listaEstudiantes, devuelveNIF(estudiante),pos)) {
		
		listaEstudiantes.contador++;
		for (int i = listaEstudiantes.contador - 1; i > pos; i--) {
			listaEstudiantes.lista[i] = listaEstudiantes.lista[i - 1];
		}
		listaEstudiantes.lista[pos] = estudiante;
	}

}

void mostrar(const tListaEstudiantes& listaEstudiantes) {

	for (int i = 0; i < listaEstudiantes.contador; i++) {
		mostrar(listaEstudiantes.lista[i]);
	}
}
void destruir(tListaEstudiantes& listaEstudiantes) {
	delete[] listaEstudiantes.lista;
}


