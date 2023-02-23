#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;



const int MAX = 100;

typedef struct {
	string identificador;
	int matriz[MAX][MAX];
	int numF, numC;
}tPlantacion;

bool cargar(tPlantacion & plantacion, string fichero);
int calcularPlatanosParcela(const tPlantacion & plantacion, int fila, int col, int len);
int devuelveFilas(const tPlantacion & plantacion);
int devuelveColumnas(const tPlantacion & plantacion);
string devuelveIdentificador(const tPlantacion & plantacion);