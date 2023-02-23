#pragma once

#include <string>
using namespace std;

typedef struct {
	int cod;
	string name;
	double precio;
	int unidades;
} tProducto;

tProducto crear(int cod, string name, double precio, int unidades);
bool operator> (tProducto p1, tProducto p2);
double activoProducto(tProducto const &p);


void mostrar(tProducto const & p);