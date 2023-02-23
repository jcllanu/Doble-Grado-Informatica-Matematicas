#include"ListaReproduccion.h"

int aleatorio(int inferior, int superior);
string tiempoReproduccion(const tListaReproduccion& listaReproduccion);



tListaReproduccion nueva(int dim, string nombre) {
	tListaReproduccion listaReproduccion;
	listaReproduccion.nombre = nombre;
	listaReproduccion.contador = 0;
	listaReproduccion.lista = new tElemento[dim];

	return listaReproduccion;
}
void insertar(tListaReproduccion& listaReproduccion, const tElemento& elemento) {
	listaReproduccion.lista[listaReproduccion.contador] = elemento;
	listaReproduccion.contador++;
}
bool buscar(const tListaReproduccion& listaReproduccion, string titulo, int& pos) {
	bool encontrado;

	if (pos >= listaReproduccion.contador) {
		encontrado = false;
	}
	else {
		if (devuelveTitulo(*listaReproduccion.lista[pos].temaPtr) == titulo) {
			encontrado = true;
		}
		else {
			pos++;
			encontrado = buscar(listaReproduccion, titulo, pos);
		}
	}

	return encontrado;
}
void mostrar(const tListaReproduccion& listaReproduccion) {
	cout << "  Lista: " << listaReproduccion.nombre << endl << endl;
	for (int i = 0; i < listaReproduccion.contador; i++) {
		cout << setw(5) << i+1 << ".- ";
		mostrar(*listaReproduccion.lista[i].temaPtr);
		cout << "(" << listaReproduccion.lista[i].valoracion << ")" << endl;
	}
	cout << "  Tiempo de reproducción: " << tiempoReproduccion(listaReproduccion) << endl << endl;
}



void modificarOrden(tListaReproduccion& listaReproduccion, int origen, int destino) {
	tElemento elementoAux;
	elementoAux = listaReproduccion.lista[origen];
	if (origen < destino) {
		for (int i = origen; i < destino; i++) {
			listaReproduccion.lista[i] = listaReproduccion.lista[i + 1];
		}
		listaReproduccion.lista[destino] = elementoAux;
	}
	else if (origen > destino) {
		for (int i = origen; i > destino; i--) {
			listaReproduccion.lista[i] = listaReproduccion.lista[i - 1];
		}
		listaReproduccion.lista[destino] = elementoAux;
	}
}

void destruir(tListaReproduccion& listaReproduccion) {
	delete[] listaReproduccion.lista;
}

string tiempoReproduccion(const tListaReproduccion& listaReproduccion) {
	int segTotales = 0, seg, min;
	for (int i = 0; i < listaReproduccion.contador; i++) {
		segTotales += devuelveSegundos(*listaReproduccion.lista[i].temaPtr);
	}
	min = segTotales / 60;
	seg = segTotales % 60;
	return to_string(min) + ":" + to_string(seg);
}

void generarListaRep(tListaReproduccion& listaReproduccion, const tListaTemas& listaTemas, int numTemas) {
	int pos;
	tArrayBool array;
	tElemento elemento;

	array.lista = new bool[devuelveTam(listaTemas)];
	for (int i = 0; i < devuelveTam(listaTemas); i++) {
		array.lista[i] = false;
	}
	for (int i = 0; i < numTemas; i++) {
		pos = aleatorio(0, devuelveTam(listaTemas)-1);
		while(array.lista[pos]){
			pos = aleatorio(0, devuelveTam(listaTemas) - 1);
		}
		array.lista[pos] = true;
		elemento.temaPtr = devuelveTemaPtr(listaTemas, pos);
		elemento.valoracion = aleatorio(0, 10);
		insertar(listaReproduccion, elemento);
	}
	delete[]array.lista;
}
int aleatorio(int inferior, int superior) {
	return (rand() % (superior - inferior + 1))+ inferior;
}