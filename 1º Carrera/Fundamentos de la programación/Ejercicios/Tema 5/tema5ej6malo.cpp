#include<iostream>
#include<string>
#include<fstream>
using namespace std;
const int MaxC = 100;
const int MaxL = 50;

typedef struct {
	int dia;
	int mes;
	int ano;
} tFecha;

typedef struct{
	tFecha fecha;
	int duracion;
	int coste;
} tLlamada;

typedef tLlamada tListaLlamadas[MaxL];

typedef struct {
	tListaLlamadas listaL;
	int contadorL;
}tLlamadas;

typedef struct {
	string nif;
	int gastoTotal;
	tLlamadas llamadas;
}tCliente;

typedef tCliente tListaClientes[MaxC];

typedef struct {
	tListaClientes listaC;
	int contadorC;
}tClientes;

tClientes cargarDatos(ifstream & archivo);
void datos(const tClientes & Clientes);




int main() {
	system("chcp 1252");
	ifstream archivo;
	tClientes Clientes;

	archivo.open("llamadas.txt");
	if (archivo.is_open()) {
		Clientes = cargarDatos(archivo);
		datos(Clientes);

	}




	archivo.close();



	system("pause");
	return 0;
}

tClientes cargarDatos(ifstream & archivo) {
	string nif;
	int dia, ano, mes;
	int duracion;
	char c;
	tClientes Clientes;
	bool esta = false;
	int pos;

	Clientes.contadorC = 0;

	archivo >> nif;
	archivo >> dia;
	archivo.get(c);
	archivo >> mes;
	archivo.get(c);
	archivo >> ano;
	archivo.get(c);
	archivo >> duracion;

	Clientes.listaC[0].nif = nif;
	Clientes.contadorC++;
	Clientes.listaC[0].llamadas.contadorL = 0;
	Clientes.listaC[0].llamadas.listaL[0].duracion = duracion;
	Clientes.listaC[0].llamadas.listaL[0].fecha.ano = ano;
	Clientes.listaC[0].llamadas.listaL[0].fecha.mes = mes;
	Clientes.listaC[0].llamadas.listaL[0].fecha.dia = dia;
	if (duracion % 60 == 0) {
		Clientes.listaC[0].llamadas.listaL[0].coste = 15 + (8 * (duracion / 60));
	}
	else {
		Clientes.listaC[0].llamadas.listaL[0].coste = 15 + (8 * ((duracion / 60)+1));
	}
	Clientes.listaC[0].llamadas.contadorL++;

	
	archivo >> nif;

	while (nif != "X") {

		for (int i = 0; i < Clientes.contadorC; i++) {
			if (Clientes.listaC[i].nif == nif) {
				esta = true;
				pos = i;
			}
		}

		archivo >> dia;
		archivo.get(c);
		archivo >> mes;
		archivo.get(c);
		archivo >> ano;
		archivo.get(c);
		archivo >> duracion;

		if (esta) {
			Clientes.listaC[pos].llamadas.listaL[Clientes.listaC[pos].llamadas.contadorL].duracion = duracion;
			Clientes.listaC[pos].llamadas.listaL[Clientes.listaC[pos].llamadas.contadorL].fecha.ano = ano;
			Clientes.listaC[pos].llamadas.listaL[Clientes.listaC[pos].llamadas.contadorL].fecha.mes = mes;
			Clientes.listaC[pos].llamadas.listaL[Clientes.listaC[pos].llamadas.contadorL].fecha.dia = dia;
			if (duracion % 60 == 0) {
				Clientes.listaC[pos].llamadas.listaL[Clientes.listaC[pos].llamadas.contadorL].coste = 15 + (8 * (duracion / 60));
			}
			else {
				Clientes.listaC[pos].llamadas.listaL[Clientes.listaC[pos].llamadas.contadorL].coste = 15 + (8 * ((duracion / 60) + 1));
			}
			Clientes.listaC[pos].llamadas.contadorL++;
		}
		else {
			Clientes.listaC[Clientes.contadorC].nif = nif;
			
			Clientes.listaC[Clientes.contadorC].llamadas.contadorL = 0;
			Clientes.listaC[Clientes.contadorC].llamadas.listaL[0].duracion = duracion;
			Clientes.listaC[Clientes.contadorC].llamadas.listaL[0].fecha.ano = ano;
			Clientes.listaC[Clientes.contadorC].llamadas.listaL[0].fecha.mes = mes;
			Clientes.listaC[Clientes.contadorC].llamadas.listaL[0].fecha.dia = dia;
			if (duracion % 60 == 0) {
				Clientes.listaC[Clientes.contadorC].llamadas.listaL[0].coste = 15 + (8 * (duracion / 60));
			}
			else {
				Clientes.listaC[Clientes.contadorC].llamadas.listaL[0].coste = 15 + (8 * ((duracion / 60) + 1));
			}
			Clientes.listaC[Clientes.contadorC].llamadas.contadorL++;
			Clientes.contadorC++;
		}

		archivo >> nif;
	}

	for (int i = 0; i < Clientes.contadorC; i++) {
		for (int j = 0; j < Clientes.listaC[i].llamadas.contadorL; j++) {
			Clientes.listaC[i].gastoTotal += Clientes.listaC[i].llamadas.listaL[j].coste;
		}
	}

	return Clientes;
}

void datos(const tClientes & Clientes) {
	for (int i = 0; i < Clientes.contadorC; i++) {
		cout << Clientes.listaC[i].nif << endl;
		for (int j = 0; j < Clientes.listaC[i].llamadas.contadorL; j++) {
			cout << "  " << Clientes.listaC[i].llamadas.listaL[j].fecha.dia << "/" << Clientes.listaC[i].llamadas.listaL[j].fecha.mes <<
				"/" << Clientes.listaC[i].llamadas.listaL[j].fecha.ano << " " << Clientes.listaC[i].llamadas.listaL[j].duracion << " seg. " <<
				Clientes.listaC[i].llamadas.listaL[j].coste << " cent." << endl;
		}
		cout << "Coste total de las llamadas: " << Clientes.listaC[i].gastoTotal << " cent." << endl;
	}
}