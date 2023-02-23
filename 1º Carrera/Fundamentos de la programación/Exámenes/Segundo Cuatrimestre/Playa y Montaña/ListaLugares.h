#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

const int MAX = 100;


typedef struct{
	string nombre;
	int precio;
}tLugar;

typedef tLugar *tLugarPtr;

typedef struct {
	tLugarPtr lista[MAX];
	int contador;
}tListaLugares;


istream& operator>> (istream & in, tListaLugares & lista);
ostream& operator<< (ostream & out, tListaLugares const& lista);
bool buscar(const tListaLugares& lista, string nombre, int& pos);
void liberar(tListaLugares& lista);
bool cargar(tListaLugares& lista, string fichero);
int precioLugar(const tLugar& lugar);
string devuelveLugar(const tLugar& lugar);