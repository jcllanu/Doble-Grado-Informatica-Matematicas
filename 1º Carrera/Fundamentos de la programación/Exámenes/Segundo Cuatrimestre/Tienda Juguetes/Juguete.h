#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

typedef enum{annos50, annos60, annos70, annos80}tDecada;

const double ANNOS50_PER = 0.2;
const double ANNOS60_PER = 0.15;
const double ANNOS70_PER = 0.1;
const double ANNOS80_PER = 0.05;

typedef struct {
	string identificador;
	tDecada decada;
	long int unidades;
	double precioBase;
}tJuguete;


double precioVenta(const tJuguete& juguete);
void mostrarJuguete(const tJuguete& juguete);
tDecada DevuelveDecada(int num);
tJuguete devuelveJuguete(string identificador, long int unidades, tDecada decada, double precio);
string devuelveIdentificador(const tJuguete& juguete);
void annadir(tJuguete& juguete, long int unidades);
int devuelveUnidades(const tJuguete& juguete);
tDecada DevuelveDecada(const tJuguete& juguete);
double DevuelvePrecio(const tJuguete& juguete);