#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

const int MAX_ACTORES = 5;

typedef struct {
	int contador;
	string actores[MAX_ACTORES];
}tReparto;

void cargar(tReparto& reparto, istream& archivo);
bool aparece(const tReparto& reparto, string nombre, int& pos);