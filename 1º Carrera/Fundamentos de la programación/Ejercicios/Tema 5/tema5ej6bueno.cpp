#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

//Calculadora coste de llamadas por clientes
int const MaxC = 100;
int const MaxL = 50;

typedef struct {
	string fecha;
	int duracion;
	int coste;
}tLlamada;
typedef tLlamada tdatos[MaxL];
typedef struct {
	tdatos dato;
	int contadorL;
}tListaLlamadas;
typedef struct {
	double gastoTotal;
	tListaLlamadas listaLlamadas;
	string nif;
}tCliente;
typedef tCliente tdato[MaxC];
typedef struct {
	tdato lista;
	int contadorC;
}tListaClientes;

tListaClientes leer(ifstream& archivo);
void escribir(const tListaClientes& Clientes);
bool buscar(string nif, int& pos, const tListaClientes& Clientes);
void GastoTotal(tListaClientes& Clientes);


int main() {
	system("chcp 1252");
	ifstream archivo;
	tListaClientes Clientes;

	archivo.open("llamadas.txt");
	if (!archivo.is_open()) {
		cout << "ERROR: archivo no encontrado." << endl;
	}
	else {
		Clientes = leer(archivo);
		escribir(Clientes);
	}
	system("pause");
	return 0;
}


tListaClientes leer(ifstream& archivo) {
	string nif,fecha;
	char c;
	int pos, duracion;

	tListaClientes Clientes;
	Clientes.contadorC = 0;
	archivo >> nif;

	while (nif != "X") {

		archivo >> fecha;
		archivo >> duracion;

		if (buscar(nif, pos, Clientes)) {
			Clientes.lista[pos].listaLlamadas.dato[Clientes.lista[pos].listaLlamadas.contadorL].fecha = fecha;
			Clientes.lista[pos].listaLlamadas.dato[Clientes.lista[pos].listaLlamadas.contadorL].duracion = duracion;

			if (duracion % 60 == 0) {
				Clientes.lista[pos].listaLlamadas.dato[Clientes.lista[pos].listaLlamadas.contadorL].coste = 15 + 8 * (duracion / 60);
			}
			else {
				Clientes.lista[pos].listaLlamadas.dato[Clientes.lista[pos].listaLlamadas.contadorL].coste = 15 + 8 * (1 + (duracion / 60));
			}
			Clientes.lista[pos].listaLlamadas.contadorL++;
		}
		else {
			Clientes.lista[Clientes.contadorC].listaLlamadas.contadorL = 0;
			Clientes.lista[Clientes.contadorC].nif = nif;
			Clientes.lista[Clientes.contadorC].listaLlamadas.dato[0].fecha = fecha;
			Clientes.lista[Clientes.contadorC].listaLlamadas.dato[0].duracion = duracion;

			if (duracion % 60 == 0) {
				Clientes.lista[Clientes.contadorC].listaLlamadas.dato[0].coste = 15 + 8 * (duracion / 60);
			}
			else {
				Clientes.lista[Clientes.contadorC].listaLlamadas.dato[0].coste = 15 + 8 * (1 + (duracion / 60));
			}
			Clientes.lista[Clientes.contadorC].listaLlamadas.contadorL++;
			Clientes.contadorC++;
		}
		archivo >> nif;
	}
	GastoTotal(Clientes);

	return Clientes;
}

bool buscar(string nif, int& pos, const tListaClientes& Clientes) {
	bool encontrado = false;
	int i = 0;
	while (i < Clientes.contadorC && !encontrado) {
		if (Clientes.lista[i].nif == nif) {
			encontrado = true;
			pos = i;
		}
		else {
			i++;
		}
	}
	return encontrado;
}

void escribir(const tListaClientes& Clientes) {
	cout << endl;
	for (int i = 0; i < Clientes.contadorC; i++) {
		cout << Clientes.lista[i].nif << ": " << endl << endl;
		for (int j = 0; j < Clientes.lista[i].listaLlamadas.contadorL; j++) {
			cout << "   " << Clientes.lista[i].listaLlamadas.dato[j].fecha<< "   " << 
				setw(3) << Clientes.lista[i].listaLlamadas.dato[j].duracion << " seg.   " << 
				setw(3) << Clientes.lista[i].listaLlamadas.dato[j].coste << " cent." << endl;
		}
		cout << endl << "Coste total: "<< Clientes.lista[i].gastoTotal << " €" << endl;
		cout << "__________________________________"<<endl << endl;
	}
}
void GastoTotal(tListaClientes& Clientes) {
	for (int i = 0; i < Clientes.contadorC; i++) {
		Clientes.lista[i].gastoTotal = 0;
		for (int j = 0; j < Clientes.lista[i].listaLlamadas.contadorL; j++) {
			Clientes.lista[i].gastoTotal += Clientes.lista[i].listaLlamadas.dato[j].coste;
		}
		Clientes.lista[i].gastoTotal = Clientes.lista[i].gastoTotal*0.01;
	}
}