#pragma once
#include"producto.h"
#include<fstream>
#include<iostream>
const int MAX = 100;
typedef tProducto tListaProductos[MAX];
typedef struct {
	tListaProductos lista;
	int contador;
}tStock;

bool leer_stock(tStock & stock);

double activoTotal(tStock stock);
void mostrar(tStock stock);
void sort(tStock & stock);
