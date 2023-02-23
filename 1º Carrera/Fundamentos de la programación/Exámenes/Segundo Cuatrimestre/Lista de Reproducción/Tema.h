#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;


typedef struct {
	string titulo, interprete;
	int segundos;
}tTema;

void cargar(tTema& tema, istream& archivo);
void mostrar(const tTema& tema);
string devuelveTitulo(const tTema& tema);
int devuelveSegundos(const tTema& tema);
