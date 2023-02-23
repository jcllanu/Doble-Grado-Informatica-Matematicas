#include"Cuadrilla.h"
#include <fstream>

void guardarCuadrilla(const tCuadrilla& cuadrilla, ofstream& archivo);


void leerCuadrilla(tCuadrilla& cuadrilla, ifstream& archivo) {
	archivo >> cuadrilla.identificador;/*Esto se hace asi?????*/
	archivo >> cuadrilla.maxPlatanos;/*igual falta archivo.get*/
}
void escribirCuadrilla(const tCuadrilla& cuadrilla) {
	cout << "  "<<setw(16) << cuadrilla.identificador << setw(12) << cuadrilla.maxPlatanos;
	escribirParcela(*cuadrilla.punteroaParcela);
}
void guardarCuadrilla(const tCuadrilla& cuadrilla, ofstream& archivo) {
	archivo<< "  " << setw(16) << cuadrilla.identificador << setw(12) << cuadrilla.maxPlatanos;
	guardarParcela(*cuadrilla.punteroaParcela, archivo);
}


bool operator<(const tCuadrilla& cuadrilla1, const tCuadrilla& cuadrilla2) {
	bool menor;

	if (cuadrilla1.maxPlatanos < cuadrilla2.maxPlatanos) {
		menor = true;
	}
	else {
		menor = false;
	}

	return menor;
}
void inicializarListaCuadrillas(tListaCuadrillas& listaCuadrillas, int num) {
	listaCuadrillas.lista = new tCuadrilla[num];
}
tListaCuadrillas crearListaCuadrilla() {
	ifstream archivo;
	tListaCuadrillas listaCuadrillas;
	tCuadrilla cuadrilla;
	archivo.open(LECTURA_CUADRILLAS);
	if (!archivo.is_open()) {
		listaCuadrillas.contador = 0;
	}
	else {
		archivo >> listaCuadrillas.contador;
		inicializarListaCuadrillas(listaCuadrillas, listaCuadrillas.contador);
		for (int i = 0; i < listaCuadrillas.contador; i++) {
			leerCuadrilla(cuadrilla, archivo);
			listaCuadrillas.lista[i] = cuadrilla;
		}
	}

	return listaCuadrillas;
}

void asignarParcela(tListaCuadrillas& listaCuadrillas, const tListaParcelas& listaParcelas) {
	int platanosQueRecoger;
	int contador = 0;

	for (int i = 0; i < listaParcelas.contador; i++) {
		platanosQueRecoger = devuelvePlatanos(listaParcelas, i);
		while (platanosQueRecoger > 0) {
			listaCuadrillas.lista[contador].punteroaParcela = devuelveParcelaPtr(listaParcelas, i);
			platanosQueRecoger -= listaCuadrillas.lista[contador].maxPlatanos;
			contador++;
		}

	}
}
void mostrarAsignaciones(const tListaCuadrillas& listaCuadrilla) {
	cout << endl << endl << "Parcela asignada a cada cuadrilla:" << endl << endl << setw(15) << "Cuadrilla" << setw(15) << "Capacidad" << setw(15) << "Plantación" << setw(13) << "Parcela" << setw(20) << "Platanos en parcela" << endl << endl;
	for (int i = 0; i < listaCuadrilla.contador; i++) {
		escribirCuadrilla(listaCuadrilla.lista[i]);
	}
	cout << endl << endl;
}


void liberar(tListaCuadrillas& listaCuadrillas) {
	delete[] listaCuadrillas.lista;
}
bool guardar(const tListaCuadrillas& listaCuadrilla) {
	ofstream archivo;
	bool ok;
	archivo.open("Salida.txt");
	if (archivo.is_open()) {

		archivo << left << setw(15) << "Cuadrilla" << setw(15) << "Capacidad" << setw(15) << "Plantación" << setw(13) << "Parcela" << setw(20) << "Platanos en parcela" << endl << endl;
		for (int i = 0; i < listaCuadrilla.contador; i++) {
			guardarCuadrilla(listaCuadrilla.lista[i], archivo);
		}
		archivo.close();
		ok = true;
	}
	else {
		ok = false;
	}
	return ok;
}