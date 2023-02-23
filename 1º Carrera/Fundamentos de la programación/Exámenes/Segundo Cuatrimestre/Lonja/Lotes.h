#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

typedef struct {
	string idLote, pescado;
	float peso, precio;
	long long int idComprador;
}tLote;

bool operator<(const tLote& lote1, const tLote& lote2);
bool operator==(const tLote& lote1, const tLote& lote2);
void mostrarLote(const tLote& lote);
void mostrarPrecio(const tLote& lote);
void modificarLote(tLote& lote, long long int idComprador, float precio);
string devuelveIdLote(const tLote& lote);
string devuelvePescadoLote(const tLote& lote);