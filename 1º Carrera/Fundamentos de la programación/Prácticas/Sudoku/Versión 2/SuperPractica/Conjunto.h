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

void cjto_vacio(tConjunto& conjunto);
void cjto_lleno(tConjunto& conjunto);
int numElems(const tConjunto& conjunto);
bool pertenece(const tConjunto& conjunto, int num);
void annadeElemento(tConjunto& conjunto, int num);
void borraElemento(tConjunto& conjunto, int num);
bool esUnitario(const tConjunto& conjunto, int& e);
void mostrar(const tConjunto& conjunto);
