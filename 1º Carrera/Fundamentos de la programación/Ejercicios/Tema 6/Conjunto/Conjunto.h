#pragma once
#include<iostream>
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
void addElemento(tConjunto& conjunto, int num);
void delElemento(tConjunto& conjunto, int num);
bool esUnitario(const tConjunto& conjunto);
void Mostrar(const tConjunto& conjunto);
