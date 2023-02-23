#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;
typedef enum { papelería, alimentación, limpieza, informática }tClase;
int const NUM_CLASES = informática + 1;
int const NP = 5;
string const Lectura = "proveedores.txt";
string const Escritura = "proveedores1.txt";


typedef struct {
	string nif;
	tClase clase;
	int pedidos;
	double total;
}tProveedor;


typedef double tGastoxClase [NUM_CLASES];

typedef tProveedor tEmpresa[NP];

int menu();
bool cargar(tEmpresa& empresa);
void guardar(const tEmpresa& empresa);
string enumerado2(tClase clase);
bool nuevoPedido(tEmpresa& empresa, double coste, string nif);
int buscarProveedor(const tEmpresa& empresa, string nif);
void mostrarXintervalo(const tEmpresa& empresa, int inf, int sup);
void totalesXclase(const tEmpresa& empresa, tGastoxClase& tabla);
void opcion1(tEmpresa& empresa);
void opcion2(const tEmpresa& empresa);
void opcion3(const tEmpresa& empresa);

int main() {
	system("chcp 1252");
	tEmpresa empresa;
	int op;

	if (!cargar(empresa)) {
		cout << endl << "ERROR: No se ha podido cargar el archivo correctamente." << endl << endl;
	}
	else {
		op = menu();
		while (op != 0) {
			switch (op) {
			case 1:
			{
				opcion1(empresa);
			}
			break;
			case 2:
			{
				opcion2(empresa);
			}
			break;
			case 3:
			{
				opcion3(empresa);
			}
			break;
			}
			op = menu();
		}
		guardar(empresa);
	}


	system("pause");
	return 0;
}

void opcion1(tEmpresa& empresa) {
	string nif;
	double coste;

	cout << endl << "Introduzca un NIF: ";
	cin >> nif;
	cin.ignore(100, '\n');
	cout << "Introduzca el coste del nuevo pedido: ";
	cin >> coste;
	cin.ignore(100, '\n');
	if (!nuevoPedido(empresa, coste, nif)) {
		cout << "ERROR: No se ha podido realizar dicha operación porque el NIF era desconocido." << endl;
	}
	else {
		cout << "Operación realizada con éxito." << endl;
	}
}
void opcion2(const tEmpresa& empresa) {
	int sup, inf;

	cout << endl << "Límite inferior del intervalo: ";
	cin >> inf;
	cin.ignore(100, '\n');
	cout << "Límite superior del intervalo: ";
	cin >> sup;
	cin.ignore(100, '\n');
	while (inf < 0 || sup < inf || cin.fail()) {
		cin.clear();
		cout << "ERROR: Datos incorrectos. Introduzcalos de nuevo." << endl;
		cout << endl << "Límite inferior del intervalo: ";
		cin >> inf;
		cin.ignore(100, '\n');
		cout << "Límite superior del intervalo: ";
		cin >> sup;
		cin.ignore(100, '\n');
	}
	mostrarXintervalo(empresa, inf, sup);

}
void opcion3(const tEmpresa& empresa) {
	tGastoxClase tabla;
	totalesXclase(empresa, tabla);
	cout << endl;
	for (int i = 0; i < NUM_CLASES; i++) {
		cout << left << setw(15) << enumerado2(tClase(i)) << right << setw(6) << setprecision(2) << fixed << tabla[i]<< endl;
	}
}
int menu() {
	int op;

	cout << endl << "Menú:" << endl;
	cout << "1.- Nuevo pedido" << endl;
	cout << "2.- Proveedores con número de pedidos en un intervalo" << endl;
	cout << "3.- Gastos por clase de proveedor " << endl;
	cout << "0.- Salir" << endl;
	cout << "Introduzca una opción (1/2/3) o finalice el programa (0): ";
	cin >> op;

	while (op < 0 || op>3 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Introduzca una opción (1/2/3) o finalice el programa (0): ";
		cin >> op;
	}

	return op;
}
bool cargar(tEmpresa& empresa) {
	bool ok = true;
	ifstream archivo;
	int contador = 0;
	tProveedor proveedor;
	int aux;

	archivo.open(Lectura);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		archivo >> proveedor.nif;
		while (proveedor.nif != "X" && contador < NP) {
			archivo >> aux;
			proveedor.clase = tClase(aux);
			archivo >> proveedor.pedidos;
			archivo >> proveedor.total;
			empresa[contador] = proveedor;
			contador++;
			archivo >> proveedor.nif;
		}
		if (contador < NP) {
			ok = false;
		}
	}
	archivo.close();

	return ok;
}


string enumerado2(tClase clase) {
	string claseStr;

	switch (clase) {
	case 0:
	{
		claseStr = "Papelería";
	}
	break;
	case 1:
	{
		claseStr = "Alimentación";
	}
	break;
	case 2:
	{
		claseStr = "Limpieza";
	}
	break;
	case 3:
	{
		claseStr = "Informática";
	}
	break;
	}

	return claseStr;
}

void guardar(const tEmpresa& empresa) {
	ofstream archivo;
	archivo.open(Escritura);

	for (int i = 0; i < NP; i++) {
		archivo << empresa[i].nif << " " << empresa[i].clase << " " << empresa[i].pedidos << " " << empresa[i].total << endl;
	}
	archivo << "X";
	archivo.close();
}
bool nuevoPedido(tEmpresa& empresa, double coste, string nif) {
	bool ok;
	int pos;

	pos = buscarProveedor(empresa, nif);

	if (pos == -1) {
		ok = false;
	}
	else {
		ok = true;
		empresa[pos].pedidos++;
		empresa[pos].total += coste;
	}

	return ok;
}
int buscarProveedor(const tEmpresa& empresa, string nif) {
	int pos = 0;
	bool encontrado = false;

	while (!encontrado && pos < NP) {
		if (nif == empresa[pos].nif) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}

	if (!encontrado) {
		pos = -1;
	}

	return pos;
}
void mostrarXintervalo(const tEmpresa& empresa, int inf, int sup) {
	cout << endl;
	cout << endl << "Listado de proveedores con gastos entre " << inf<< " y " << sup << ":" << endl;

	for (int i = 0; i < NP; i++) {
		if (empresa[i].pedidos <= sup && empresa[i].pedidos >= inf) {
			cout << left << setw(11) << empresa[i].nif << setw(15) << enumerado2(empresa[i].clase) << setw(3) << empresa[i].pedidos << setw(15) << fixed<< setprecision(2) << right << empresa[i].total << endl;
		}
	}
}
void totalesXclase(const tEmpresa& empresa, tGastoxClase& tabla) {

	for (int i = 0; i < NUM_CLASES; i++) {
		tabla[i] = 0;
	}
	for (int i =0; i<NP; i++){
		tabla[empresa[i].clase] += empresa[i].total;
	}
}