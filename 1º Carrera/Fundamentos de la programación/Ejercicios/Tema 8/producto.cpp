#include <iostream>
#include <iomanip>
#include <string>

#include "producto.h"

using namespace std;


tProducto crear(int cod, string name, double precio, int unidades)
{
	tProducto p = { cod, name, precio, unidades };
	return p;
}

bool operator>(tProducto p1, tProducto p2)
{
	return p1.cod > p2.cod;
}

void mostrar(tProducto const & p)
{
	cout << setw(6) << right << p.cod << " ";
	cout << setw(30) << left << p.name << " ";
	cout << setw(8) << fixed << setprecision(2) << p.precio << " ";
	cout << setw(3) << right << p.unidades;
}

double activoProducto(tProducto const & p)
{
	return p.precio * p.unidades;
}

