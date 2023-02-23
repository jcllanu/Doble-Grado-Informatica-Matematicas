#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;


typedef struct {
	int anno, mes, dia, hora, minuto;
}tFecha;

typedef struct {
	string nombre;
	tFecha fecha;
	int minutos;
}tPrograma;

bool cargar(tPrograma& programa, istream& archivo);
void mostrar(const tPrograma& programa);
void mostrarFecha(const tFecha& fecha);
bool operator<(const tPrograma& programa1, const tPrograma& programa2);
bool operator==(const tPrograma& programa1, const tPrograma& programa2);
bool yaEmitido(const tPrograma& programa);