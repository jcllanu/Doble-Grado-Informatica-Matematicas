#include"Casilla.h"
#include<Windows.h>
#include"checkML.h"


void iniciaCasilla(tCasilla & casilla) {
	casilla.estado = VACIA;
	cjto_lleno(casilla.valoresPosibles);
}

void rellenaCasilla(tCasilla & casilla, char c, bool fija) {
	if (c == ' ') {
		iniciaCasilla(casilla);
	}
	else {
		casilla.numero = int(c-'0');
		if (fija) {
			casilla.estado = FIJA;
			cjto_vacio(casilla.valoresPosibles);
		}
		else {
			casilla.estado = RELLENADA;
			cjto_vacio(casilla.valoresPosibles);
		}
	}

}

void dibujaCasilla(const tCasilla & casilla) {
	if (casilla.estado == FIJA) {
		colorFondo(1);
		cout << " " << casilla.numero << " ";
		colorFondo(0);
	}
	else if (casilla.estado == RELLENADA) {
		colorFondo(4);
		cout << " "<<casilla.numero<<" ";
		colorFondo(0);
	}
	else {
		colorFondo(0);
		cout <<"   ";
	}
	
}

void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

bool esSimple(const tCasilla & casilla, int & numero) {
	bool simple = false;

	if (casilla.estado == VACIA && esUnitario(casilla.valoresPosibles, numero)) {
		simple = true; 
	}
	return simple;
}

//Funciones añadidas

tEstado devuelveEstado(const tCasilla & casilla) {
	return casilla.estado;
}

void borraElemento(tCasilla & casilla, int num) {
	borraElemento(casilla.valoresPosibles, num);
}

int devuelveNumero(const tCasilla & casilla) {
	return casilla.numero;
}
bool pertenece(const tCasilla& casilla, int num) {
	return pertenece(casilla.valoresPosibles, num);
}
void annadeElemento(tCasilla& casilla, int num) {
	return annadeElemento(casilla.valoresPosibles, num);
}
void mostrar(const tCasilla & casilla) {
	mostrar(casilla.valoresPosibles);
}