#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

typedef struct {
	string nombre, NIF, fechaMatr;
	int nota;
}tEstudiante;

void cargar(tEstudiante& estudiante, istream& archivo);
void mostrar(const tEstudiante& estudiante);
string devuelveNIF(const tEstudiante& estudiante);