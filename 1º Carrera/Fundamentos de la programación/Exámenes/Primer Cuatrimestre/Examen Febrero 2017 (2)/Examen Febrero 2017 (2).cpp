#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

//Gestión de cajeros/operaciones
//lectura, escritura, visualización y modificación de datos

int const MAX_APUNTES = 500;
int const Meses = 12;
string const ConceptoMensual = "Luz";
string const ConceptoPrimero = "Salario";

typedef struct {
	int short signed dia; 
	int short unsigned mes;
	int short unsigned anno;
}tFecha;

typedef struct {
	tFecha fecha;
	double importe;
	string concepto;
}tApunte;

typedef tApunte tApuntes[MAX_APUNTES];

typedef struct {
	tApuntes datos;
	int contador;
}tCuenta;

int menu();

bool cargarFichero(string fichero, tCuenta& cuenta);
float primeraNomina(const tCuenta& cuenta);
bool gastoLuz(int anno, const tCuenta& cuenta, float& gasto);
void mostrarCuenta(const tCuenta& cuenta);
float primeraNominaCronologicmente(const tCuenta& cuenta);

int main() {
	system("chcp 1252");
	int op;
	tCuenta cuenta;
	string fichero;
	bool ficheroCargado=false;
	float importe, importe2, gasto;
	int anno;

	op = menu();
	while (op != 0) {
		switch (op) {
		case 1:
		{
			cout << endl << "Introduzca el nombre del fichero donde tenga los datos: ";
			cin >> fichero;
			if (!cargarFichero(fichero, cuenta)) {
				cout << "ERROR: No se ha podido relizar la operación de cargado correctamente." << endl;
				ficheroCargado = false;
			}
			else {
				cout << "La operación de cargado se ha realizado con éxito." << endl;
				ficheroCargado = true;
			}
		}
		break;
		case 2:
		{
			if (!ficheroCargado) {
				cout << "ERROR: No se ha cargado ningún fichero." << endl;
			}
			else {
				importe=primeraNomina(cuenta);
				if (importe == -1) {
					cout << "No hay constancia de que le hayan ingresado una nómina." << endl;
				}
				else {
					cout << "El importe de la primera nómina de la cuenta es de " << setprecision(6) << showpoint << importe << "€." << endl;
				}
			}
			
		}
		break;
		case 3:
		{
			if (!ficheroCargado) {
				cout << "ERROR: No se ha cargado ningún fichero." << endl;
			}
			else {
				cout << "Introduzca el año del que se quiera calcular el gasto medio de luz: ";
				cin >> anno;
				if (!gastoLuz(anno, cuenta, gasto)) {
					cout << "No hay ningún recibo de luz correspondiente al año selecionado." << endl;
				}
				else {
					cout << "El gasto medio mensual de luz en el año " << anno << " fue de " << setprecision(4) << showpoint << -1*gasto << "€." << endl;
				}

			}
		}
		break;
		case 4:
		{
			if (!ficheroCargado) {
				cout << "ERROR: No se ha cargado ningún fichero." << endl;
			}
			else {
				mostrarCuenta(cuenta);
			}
		}
		break;
		case 5:
		{
			if (!ficheroCargado) {
				cout << "ERROR: No se ha cargado ningún fichero." << endl;
			}
			else {
				importe2 = primeraNominaCronologicmente(cuenta);
				if (importe2 == -1) {
					cout << "No hay constancia de que le hayan ingresado una nómina." << endl;
				}
				else {
					cout << "El importe de la primera nómina de la cuenta es de " << setprecision(6) << showpoint << importe2 << "€." << endl;
				}
			}
		}
		break;
		}
		op = menu();
	}
	



	system("pause");
	return 0;
}

int menu() {
	int op;

	cout << endl << "Menu: " << endl;
	cout << "   1.- Cargar cuenta de fichero" << endl;
	cout << "   2.- Importe de la primera nómina (por orden de lectura del archivo)" << endl;
	cout << "   3.- Gasto medio de luz en un año" << endl;
	cout << "   4.- Mostrar por pantalla" << endl;
	cout << "   5.- Importe de la primera nómina (por orden cronológico)" << endl;
	cout << "   0.- Salir" << endl;
	cout << "Elige una de las opciones (1/2/3/4/5) o finaliza el programa (0): ";
	cin >> op;
	while (op < 0 || op>5 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Elige una de las opciones (1/2/3/4/5) o finaliza el programa (0): ";
		cin >> op;
	}

	return op;
}
bool cargarFichero(string fichero, tCuenta& cuenta) {
	ifstream archivo;
	bool ok;
	tApunte apunte;
	char a;

	cuenta.contador = 0;
	archivo.open(fichero);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
		archivo >> apunte.fecha.dia;
		while (apunte.fecha.dia != -1 && cuenta.contador < MAX_APUNTES) {
			archivo >> apunte.fecha.mes;
			archivo >> apunte.fecha.anno;
			archivo >> apunte.importe;
			archivo >> apunte.concepto;
			archivo.get(a);
			cuenta.datos[cuenta.contador] = apunte;
			cuenta.contador++;
			archivo >> apunte.fecha.dia;
		}
	}

	return ok;
}
float primeraNomina(const tCuenta& cuenta) {
	bool encontrado = false;
	int contador = 0;
	float nomina = -1;

	while (!encontrado && contador <cuenta.contador) {
		if (cuenta.datos[contador].concepto == ConceptoPrimero) {
			nomina = cuenta.datos[contador].importe;
			encontrado = true;
		}
		contador++;
	}
	return nomina;
}
bool gastoLuz(int anno, const tCuenta& cuenta, float& gasto) {
	float total = 0;
	int veces = 0;
	bool ok;

	for (int i = 0; i < cuenta.contador; i++){
		if (cuenta.datos[i].concepto == ConceptoMensual && anno == cuenta.datos[i].fecha.anno) {
			total += cuenta.datos[i].importe;
			veces++;
		}
	}
	if (veces == 0) {
		ok = false;
	}
	else{
		ok = true;
		gasto = total / Meses;
	}
	return ok;
}
void mostrarCuenta(const tCuenta& cuenta) {
	cout << endl << "   Fecha        Importe                 Concepto" << endl << endl;
	for (int i = 0; i < cuenta.contador; i++) {
		cout <<setw(2)<< cuenta.datos[i].fecha.dia << "/" << setw(2) << cuenta.datos[i].fecha.mes << "/" << setw(4) << cuenta.datos[i].fecha.anno << "   " << setw(10)<<setprecision(6)<<cuenta.datos[i].importe << "     " << setw(20)<<right<<cuenta.datos[i].concepto << endl;
	}
}
float primeraNominaCronologicmente(const tCuenta& cuenta) {
	bool encontrado = false;
	int contador = 0;
	bool primeraVez = true;
	tApunte primeraNomina;

	for (int i = 0; i < cuenta.contador; i++) {
		if (cuenta.datos[i].concepto == ConceptoPrimero) {
			if (primeraVez) {
				primeraVez = false;
				primeraNomina = cuenta.datos[i];
			}
			else {
				if ((cuenta.datos[i].fecha.anno < primeraNomina.fecha.anno) || ((cuenta.datos[i].fecha.anno == primeraNomina.fecha.anno) && (cuenta.datos[i].fecha.mes < primeraNomina.fecha.mes)) || ((cuenta.datos[i].fecha.anno == primeraNomina.fecha.anno) && (cuenta.datos[i].fecha.mes == primeraNomina.fecha.mes) && (cuenta.datos[i].fecha.dia == primeraNomina.fecha.dia))) {
					primeraNomina = cuenta.datos[i];
				}
			}
		}
	}
	if (primeraVez) {
		primeraNomina.importe = -1;
	}
	return primeraNomina.importe;
}