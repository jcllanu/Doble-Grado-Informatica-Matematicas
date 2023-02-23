#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

const int MAX_CLIENTES = 50;
const string LECTURA = "clientes.txt";

typedef struct {
	string login, fechaAlta, ciudad;
	int edad;
}tCliente;

typedef tCliente *tClientePtr;

typedef struct {
	tClientePtr lista[MAX_CLIENTES];
	int contador;
}tListaClientes;



void mostrar(const tCliente& cliente);
bool cargar(tListaClientes& listaClientes);
void mostrar(const tListaClientes& listaClientes, int& pos);
void liberar(tListaClientes& listaClientes);
tClientePtr devuelveClientePtr(const tListaClientes& listaClientes, int pos);