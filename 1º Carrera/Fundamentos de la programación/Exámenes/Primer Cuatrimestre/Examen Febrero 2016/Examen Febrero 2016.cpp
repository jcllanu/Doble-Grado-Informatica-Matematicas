#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

//Consumo clientes
//lectura, escritura, visualización y modificación de datos
int unsigned const NUM_INTERVALOS = 5;
string const Intervalos = "intervalos.txt";
string const Consumo = "consumos.txt";

typedef enum{particular, PYME, industria} tTipoCliente;

tTipoCliente const ClienteClasificar = PYME;

typedef struct {
	int extremoSup;
	int frecuencia;
}tIntervalo;
typedef tIntervalo tTabla[NUM_INTERVALOS];

typedef struct {
	double consumo;
	int tipo;
	string identificador;
}tCliente;

bool cargarIntervalos(tTabla& tabla);
bool frecuenciasConsumo(tTabla& tabla, tTipoCliente ClienteClasificar);
void mostrarTabla(const tTabla& tabla);
bool buscarIntervalo(const tTabla& tabla, const tCliente& cliente, int& pos);

int main() {
	system("chcp 1252");

	tTabla tablaFrecuencias;
	if (cargarIntervalos(tablaFrecuencias)) {
		if (frecuenciasConsumo(tablaFrecuencias, ClienteClasificar)) {
			mostrarTabla(tablaFrecuencias);
		}
		else {
			cout << endl << "ERROR: Archivo del que se pretendia cargar la información sobre los clientes no se ha encontrado." << endl << endl;
		}
		
	}
	else {
		cout << endl << "ERROR: Archivo del que se pretendia cargar la información sobre los intervalos de consumo no se ha encontrado" << endl << "o es defectuoso." << endl << endl;
	}

	system("pause");
	return 0;
}

bool cargarIntervalos(tTabla& tabla) {
	ifstream archivo;
	bool ok = true;
	int nuevo, anteriorLeido = 0, contador = 0;

	archivo.open(Intervalos);

	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		for (int i = 0; i < NUM_INTERVALOS; i++) {
			tabla[i].frecuencia = 0;
		}
		archivo >> nuevo;
		while (nuevo != -1 && ok) {
			tabla[contador].extremoSup = nuevo;
			contador++;
			if (nuevo <= anteriorLeido) {
				ok = false;
			}
			else {
				anteriorLeido = nuevo;
			}

			archivo >> nuevo;
		}
		if (contador != NUM_INTERVALOS) {
			ok = false;
		}
	}
	return ok;
}
bool frecuenciasConsumo(tTabla& tabla, tTipoCliente ClienteClasificar) {
	ifstream archivo;
	bool ok = true;
	tCliente cliente;
	int pos;
	
	archivo.open(Consumo);

	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		archivo >> cliente.consumo;
		while (cliente.consumo>-0.9 || cliente.consumo<-1.1) {
			archivo >> cliente.tipo;
			getline(archivo,cliente.identificador);
			if (cliente.tipo == ClienteClasificar && buscarIntervalo(tabla, cliente, pos)) {
				tabla[pos].frecuencia++;
			}
			archivo >> cliente.consumo;
		}
	}
	return ok;
}
bool buscarIntervalo(const tTabla& tabla, const tCliente& cliente, int& pos) {
	bool encontrado = false;

	pos = 0;
	while (pos < NUM_INTERVALOS && !encontrado) {
		if (cliente.consumo <= tabla[pos].extremoSup) {
			encontrado = true;
		}
		else {
			pos++;
		}
		
	}

	return encontrado;
}
void mostrarTabla(const tTabla& tabla) {
	cout << "Calculamos las frecuencias de consumo de los clientes de tipo ";
	if (ClienteClasificar == industria) {
		cout << "industria";
	}
	else if (ClienteClasificar == PYME) {
		cout << "PYME";
	}
	else if (ClienteClasificar == particular) {
		cout << "particular";
	}
	cout << ". Tabla de frecuencias por consumo :" << endl;
	cout << endl << "Intervalo de " << 0 << " a " << tabla[0].extremoSup << ": " << setw(9) << right << tabla[0].frecuencia << endl;
	for (int i = 1; i < NUM_INTERVALOS; i++) {
		cout << "Intervalo de "<< tabla[i-1].extremoSup <<" a " << tabla[i].extremoSup << ": " << setw(8-i) << right << tabla[i].frecuencia << endl;

	}
	cout << endl;
}