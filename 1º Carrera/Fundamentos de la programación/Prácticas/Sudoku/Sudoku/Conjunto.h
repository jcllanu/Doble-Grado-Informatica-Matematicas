#pragma once
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int const N = 9;
typedef struct {
	bool elementos[N];
	int numElem;
}tConjunto;

void cjto_vacio(tConjunto& conjunto); //Inicializa el n�mero elementos de un tConjunto a 0 y cada uno de los booleanos del conjunto a false.
void cjto_lleno(tConjunto& conjunto); //Inicializa el n�mero elementos de un tConjunto a 9 y cada uno de los booleanos del conjunto a true.
int numElems(const tConjunto& conjunto); //Devuelve el n�mero de elementos de un tConjunto.
bool pertenece(const tConjunto& conjunto, int num); //Devuelve un booleano en funci�n de si un elemento ('num') se encuentra en un tConjunto con el valor true o false.
void annadeElemento(tConjunto& conjunto, int num); //Suma 1 al n�mero de elementos de un tConjunto y coloca la posici�n/valor 'num' de su lista de elementos a true.
void borraElemento(tConjunto& conjunto, int num); //Resta 1 al n�mero de elementos de un tConjunto y coloca la posici�n/valor 'num' de su lista de elementos a false.
bool esUnitario(const tConjunto& conjunto, int& e); //Devuelve un booleano indicando si el n�mero de elementos de la lista de un tConjunto es 1 (true) o mayor que 1 (false). El par�metro 'e' toma el valor del �nico elemento de la lista en caso de que el conjunto sea unitario.
void mostrar(const tConjunto& conjunto); //Muestra por consola los elementos de la lista de un tConjunto.