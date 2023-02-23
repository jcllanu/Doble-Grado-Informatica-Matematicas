#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

int const MAX = 100;
string const Entrada = "clase.txt";
string const Salida = "clase1.txt";

typedef struct {
	string nombre;
	string apellidos;
	int edad;
	string nif;
	double nota;
}tAlumno;

typedef tAlumno tDatos[MAX];

typedef struct {
	tDatos datos;
	int contador;
}tLista;

int menu();
bool cargar(tLista& lista);
void guardar(const tLista& lista);
bool annadirEstudiante(tLista& lista);
void leerEstudiante(tAlumno& alumno);
void eliminarEstudiante(tLista& lista, int pos);
bool posEstudiante(const tLista& lista, int& pos, string nif);
void calificar(tLista& lista);
int mayorNota(const tLista& lista);
double media(const tLista& lista);
void mostrar(const tLista& lista);
void listado(const tLista& lista);


int main() {
	system("chcp 1252");
	tLista lista;
	int op, pos;
	string nif;

	if (!cargar(lista)) {
		cout << "ERROR: Archivo no encontrado." << endl;
	}
	else {
		op = menu();
		while (op != 0) {
			switch (op) {
			case 1: {
				if (annadirEstudiante(lista)) {
					cout << "Estudiante añadido correctamente" << endl;
				}
				else {
					cout << "ERROR: Lista completa" << endl;
				}
			}
			break;
			case 2: {
				cout << "NIF del estudiante a eliminar: ";
				cin >> nif;
				if (!posEstudiante(lista, pos, nif)) {
					cout << "ERROR: NIF incorrecto" << endl;
				}
				else {
					eliminarEstudiante(lista, pos);
				}
			}
			break;
			case 3: {
				calificar(lista);
			}
			break;
			case 4: {
				listado(lista);
			}
			break;
			}
			op = menu();
		}
		guardar(lista);
	}



	system("pause");
	return 0;
}
int menu() {
	int op;
	cout << endl;
	cout << "1.- Añadir estudiante" << endl;
	cout << "2.- Eliminar estudiante" << endl;
	cout << "3.- Calificar" << endl;
	cout << "4.- Mostrar listado" << endl;
	cout << "0.- Salir " << endl;
	cout << "Opción: ";
	cin >> op;
	cout << endl;
	return op;
}
bool cargar(tLista& lista) {
	ifstream archivo;
	bool ok;
	tAlumno alumno;
	char a;

	lista.contador = 0;
	archivo.open(Entrada);

	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
		getline(archivo, alumno.nombre);
		while (alumno.nombre != "XXX" && lista.contador < MAX) {
			getline(archivo, alumno.apellidos);
			archivo >> alumno.edad;
			archivo >> alumno.nif;
			archivo >> alumno.nota;
			archivo.get(a);
			lista.datos[lista.contador] = alumno;
			lista.contador++;
			getline(archivo, alumno.nombre);
		}
	}

	archivo.close();
	return ok;
}
void guardar(const tLista& lista) {
	ofstream archivo;

	archivo.open(Salida);
	for (int i = 0; i < lista.contador; i++) {
		archivo << lista.datos[i].nombre << endl << lista.datos[i].apellidos << endl << lista.datos[i].edad << endl << lista.datos[i].nif << endl << lista.datos[i].nota << endl;
	}
	archivo << "XXX";
	archivo.close();
}
bool annadirEstudiante(tLista& lista) {
	tAlumno alumno;
	bool ok;

	if (lista.contador < MAX) {
		ok = true;
		leerEstudiante(alumno);
		lista.datos[lista.contador] = alumno;
		lista.contador++;
	}
	else {
		ok = false;
	}
	return ok;
}
void leerEstudiante(tAlumno& alumno) {
	cout << "Nombre: ";
	cin.ignore(100, '\n');
	getline(cin, alumno.nombre);
	cout << "Apellidos: ";
	getline(cin, alumno.apellidos);
	cout << "Edad: ";
	cin >> alumno.edad;
	cout << "NIF: ";
	cin >> alumno.nif;
	alumno.nota = -1;
}
void eliminarEstudiante(tLista& lista, int pos) {
	for (int i = pos; i < lista.contador; i++) {
		lista.datos[i] = lista.datos[i + 1];
	}
	lista.contador--;
}
bool posEstudiante(const tLista& lista, int& pos, string nif) {
	bool encontrado = false;

	pos = 0;
	while (!encontrado && pos < lista.contador) {
		if (lista.datos[pos].nif == nif) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}
	return encontrado;
}
void calificar(tLista& lista) {
	for (int i = 0; i < lista.contador; i++) {
		if (lista.datos[i].nota == -1) {
			cout << "Nombre: " << lista.datos[i].nombre << endl;
			cout << "Apellidos: " << lista.datos[i].apellidos << endl;
			cout << "Calificación: ";
			cin >> lista.datos[i].nota;
			cout << endl;
		}
	}
}
double media(const tLista& lista) {
	double media = 0, suma = 0;

	if (lista.contador != 0) {
		for (int i = 0; i < lista.contador; i++) {
			suma += lista.datos[i].nota;
		}
		media = suma / lista.contador;
	}

	return media;
}
int mayorNota(const tLista& lista) {
	double max = lista.datos[0].nota;
	int pos = 0;

	for (int i = 1; i < lista.contador; i++) {
		if (lista.datos[i].nota > max) {
			max = lista.datos[i].nota;
			pos = i;
		}
	}
	return pos;
}
void mostrar(const tLista& lista) {
	for (int i = 0; i < lista.contador; i++) {
		cout <<left<< setw(20) << lista.datos[i].nombre << setw(20) << lista.datos[i].apellidos << setw(12) << lista.datos[i].nif << setw(8) << setprecision(2) << fixed << lista.datos[i].nota << setw(2) << lista.datos[i].edad << endl;
	}
}
void listado(const tLista& lista) {
	mostrar(lista);
	cout << endl << endl << "La mayor nota es " << lista.datos[mayorNota(lista)].nota << " y la nota media es " << media(lista) << endl << endl;
}