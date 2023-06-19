#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
//Gestión liga de futbol
//lectura, escritura, visualización y modificación de datos
using namespace std;

int const max_longitud = 8;
int const N = 10;
int const max_puntos = 3;
int const max_goles = 2;
string const Lectura = "liga.txt";
string const Lectura2 = "jornada.txt"; 
typedef struct{
	int puntuacion;
	string equipo;
}tEquipo;
typedef tEquipo tClasificacion[N];
typedef struct {
	string equipo1;
	string equipo2;
	int goles1;
	int goles2;
}tPartido;
typedef tPartido tJornada[N / 2];



int menu();
bool cargarLiga(tClasificacion liga);
bool cargarJornada(tJornada jornada);
void mostrarLiga(tClasificacion liga);
void mostrarJornada(tJornada jornada);
void actualizarLiga(tClasificacion liga, const tJornada& jornada);
void mostrarPrimero(const tClasificacion& liga);
void guardarLiga(const tClasificacion& liga);

int main() {
	system("chcp 1252");
	tClasificacion liga;
	tJornada jornada;
	int op;
	bool ligaCargada = false, jornadaCargada = false;

	op = menu();
	while (op != 0) {

		switch (op) {
		case 1:
		{
			if (cargarLiga(liga)) {
				ligaCargada = true;
			}
			
		}
		break;
		case 2:
		{
			if (cargarJornada(jornada)) {
				jornadaCargada = true;
			}
		}
		break;
		case 3:
		{
			if (!ligaCargada) {
				cout << "ERROR: No se ha cargado ninguna clasificación anteriormente" << endl;
			}
			else{
				mostrarLiga(liga);
			}
			
		}
		break;
		case 4:
		{
			if (!jornadaCargada) {
				cout << "ERROR: No se ha cargado ninguna jornada anteriormente" << endl;
			}
			else {
				mostrarJornada(jornada);
			}
		}
		break;
		case 5:
		{
			if (!jornadaCargada || !ligaCargada) {
				cout << "ERROR: No se ha cargado anteriormente la clasificación o la jornada" << endl;
			}
			else {
				actualizarLiga(liga, jornada);
			}
		}
		break;
		case 6:
		{
			if (!ligaCargada) {
				cout << "ERROR: No se ha cargado ninguna clasificación anteriormente" << endl;
			}
			else {
				mostrarPrimero(liga);
			}
		}
		break;
		case 7:
		{
			if (!ligaCargada) {
				cout << "ERROR: No se ha cargado ninguna clasificación anteriormente" << endl;
			}
			else {
				guardarLiga(liga);
			}
			
		}
		}


		op = menu();
	}


	system("pause");
	return 0;
}

int menu() {
	int op;
	cout << endl << "Menú: ";
	cout << endl << "  1.- Cargar datos de la clasificación" << endl;
	cout << "  2.- Cargar datos de la jornada" << endl;
	cout << "  3.- Mostrar la clasificación" << endl;
	cout << "  4.- Mostrar la jornada" << endl;
	cout << "  5.- Actualizar clasificación" << endl;
	cout << "  6.- Mostrar primer clasificado" << endl;
	cout << "  7.- Grabar datos" << endl;
	cout << "  0.- Salir" << endl;
	cout << "Selecione una de las opciones (1/2/3/4/5/6/7) o finalice el programa (0): ";
	cin >> op;
	while (op < 0 || op>7 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Selecione una de las opciones (1/2/3/4/5/6/7) o finalice el programa (0): ";
		cin >> op;
	}
	return op;
}
bool cargarLiga(tClasificacion liga) {
	ifstream archivo;
	bool ok;
	tEquipo equipo;
	char a;

	archivo.open(Lectura);
	if (!archivo.is_open()) {
		cout << "ERROR: Archivo no encontrado" << endl;
		ok = false;
	}
	else {
		ok = true;
		for (int i = 0; i < N; i++) {
			archivo >> equipo.equipo;
			archivo >> equipo.puntuacion;
			archivo.get(a);
			liga[i] = equipo;
		}
	}
	archivo.close();
	return ok;
}
bool cargarJornada(tJornada jornada){
	ifstream archivo;
	bool ok=true, repetido=false, encontrado;
	tPartido partido;
	char a;

	archivo.open(Lectura2);
	if (!archivo.is_open()) {
		cout << "ERROR: Archivo no encontrado" << endl;
		encontrado = false;
	}
	else {
		encontrado = true;
		for (int i = 0; i < N/2; i++) {
			archivo >> partido.equipo1;
			archivo >> partido.goles1;
			archivo >> partido.equipo2;
			archivo >> partido.goles2;
			archivo.get(a);
			if (partido.equipo1 == partido.equipo2) {
				cout << "ERROR: Archivo con dos equipos iguales." << endl;
				repetido = true;
			}
			for (int j = 0; j < i; j++) {
				if (partido.equipo1 == jornada[j].equipo1 || partido.equipo1 == jornada[j].equipo2 || partido.equipo2 == jornada[j].equipo1 || partido.equipo2 == jornada[j].equipo2) {
					cout << "ERROR: Archivo con dos equipos iguales." << endl;
					repetido = true;
				}
			}
			jornada[i] = partido;
		}
	}
	if (repetido || !encontrado) {
		ok = false;
	}
	archivo.close();
	return ok;
}
void mostrarLiga(tClasificacion liga) {
	cout << endl << "Clasificación:" << endl << endl << left << setw(max_longitud) << "Equipo" << right << setw(max_puntos) << "|   Puntos" << endl <<"--------+-----------"<< endl;
	for (int i = 0; i < N; i++) {
		cout << left << setw(max_longitud) << liga[i].equipo <<"|   "<< right << setw(max_puntos) << liga[i].puntuacion << endl;
	}
	cout << endl;
}
void mostrarJornada(tJornada jornada) {
	cout << endl << setw(max_longitud + 3 * max_goles) << "Jornada" << endl << "_____________________" << endl;
	for (int i = 0; i < N/2; i++) {
		cout << left << setw(max_longitud) << jornada[i].equipo1 << right << setw(max_goles) << jornada[i].goles1 << "-" << left << setw(max_goles) << jornada[i].goles2 << right << setw(max_longitud) << jornada[i].equipo2 <<endl;
	}
	cout << endl;
}
void actualizarLiga(tClasificacion liga, const tJornada& jornada) {
	int ptosEqp1, ptosEqp2;

	for (int i = 0; i < N / 2; i++) {
		if (jornada[i].goles1 > jornada[i].goles2) {//gana casa
			ptosEqp1 = 3;
			ptosEqp2 = 0;
		}
		else if (jornada[i].goles1 < jornada[i].goles2) {//gana visitante
			ptosEqp1 = 0;
			ptosEqp2 = 3;
		}
		else {//empatan
			ptosEqp1 = 1;
			ptosEqp2 = 1;
		}
		for (int j = 0; j < N; j++) {
			if (liga[j].equipo == jornada[i].equipo1) {
				liga[j].puntuacion += ptosEqp1;
			}
			if (liga[j].equipo == jornada[i].equipo2) {
				liga[j].puntuacion += ptosEqp2;
			}
		}

	}
}
void mostrarPrimero(const tClasificacion& liga) {
	int max, i=0;
	string lider;

	max = liga[i].puntuacion;
	lider = liga[i].equipo;
	i++;
	while (i < N) {
		if (liga[i].puntuacion > max) {
			max = liga[i].puntuacion;
			lider = liga[i].equipo;
		}
		i++;
	}
	cout << "El lider de la clasificación es " << lider << ", con " << max << " puntos." << endl;
}
void guardarLiga(const tClasificacion& liga) {
	ofstream archivo;

	archivo.open(Lectura);
	for (int i = 0; i < N; i++) {
		archivo << liga[i].equipo << " " << liga[i].puntuacion << endl;
	}
	archivo.close();

}