#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;


int const NUM_ASIG = 6;
int const MAX_RES = 4;
string const ARCHIVOIN = "asignaturas.txt";
string const ARCHIVOOUT = "asignaturas1.txt";

typedef struct {
	string asignatura;
	double creditos;
	int grupos;
}tAsignatura;

typedef tAsignatura tCatalogo[NUM_ASIG];

typedef struct {
	string asignatura;
	int grupos;
}tReserva;

typedef tReserva tDatos[MAX_RES];

typedef struct {
	tDatos datos;
	int contador;
}tListaReservas;

bool cargar(tCatalogo& catalogo);
void guardar(const tCatalogo& catalogo);
void mostrarDisponibles(const tCatalogo& catalogo);
void leerReservas(tListaReservas& listaReservas);
bool buscarAsignatura(const tCatalogo& catalogo, string asignatura, int& pos);
void realizarReseva(tCatalogo& catalogo, tListaReservas& listaReservas);

int main() {
	system("chcp 1252");
	tCatalogo catalogo;
	tListaReservas listaReservas;


	if (!cargar(catalogo)) {
		cout << endl << "ERROR: La operación de carga del archivo no ha tenido éxito." << endl << endl;
	}
	else {
		
		mostrarDisponibles(catalogo);
		guardar(catalogo);
		leerReservas(listaReservas);
		realizarReseva(catalogo, listaReservas);
		mostrarDisponibles(catalogo);
		guardar(catalogo);
	}

	system("pause");
	return 0;
}
bool cargar(tCatalogo& catalogo) {
	bool ok = true;
	int contador = 0;
	ifstream archivo;
	tAsignatura asignatura;

	archivo.open(ARCHIVOIN);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		archivo >> asignatura.asignatura;
		while (contador < NUM_ASIG && ok && asignatura.asignatura != "XXX") {
			archivo >> asignatura.creditos;
			archivo >> asignatura.grupos;
			for (int i = 0; i < contador; i++) {
				if (asignatura.asignatura == catalogo[i].asignatura) {
					ok = false;
				}
			}
			catalogo[contador] = asignatura;
			contador++;
			archivo >> asignatura.asignatura;
		}
		if (contador < NUM_ASIG) {
			ok = false;
		}
	}
	return ok;
}
void guardar(const tCatalogo& catalogo) {
	ofstream archivo;

	archivo.open(ARCHIVOOUT);
	for (int i = 0; i < NUM_ASIG; i++) {
		archivo << catalogo[i].asignatura << " " << setprecision(3) << showpoint << catalogo[i].creditos << " " << catalogo[i].grupos << endl;
	}
	archivo << "XXX";
	archivo.close();
}
void mostrarDisponibles(const tCatalogo& catalogo) {
	cout << endl << "Asignaturas disponibles..." << endl;
	cout << "Asignatura  Créditos  Grupos" << endl;
	for (int i = 0; i < NUM_ASIG; i++) {
		if (catalogo[i].grupos > 0) {
			cout << "   " << setw(3) << left << catalogo[i].asignatura << setw(12) << right << setprecision(3) << showpoint << catalogo[i].creditos << setw(7) << catalogo[i].grupos << endl;
		}
	}
}
void leerReservas(tListaReservas& listaReservas) {
	tReserva reserva;
	bool repetida = false;
	int pos;

	listaReservas.contador = 0;
	cout << endl << endl << "Nombre de la asignatura (XXX para terminar): ";
	cin >> reserva.asignatura;
	while (reserva.asignatura != "XXX" &&  listaReservas.contador < MAX_RES) {
		cout << "Grupos a reservar: ";
		cin >> reserva.grupos;
		for (int i = 0; i < listaReservas.contador; i++) {
			if (reserva.asignatura == listaReservas.datos[i].asignatura) {
				repetida = true;
				pos = i;
			}
		}
		if (repetida) {
			listaReservas.datos[pos].grupos += reserva.grupos;
			repetida = false;
		}
		else {
			listaReservas.datos[listaReservas.contador] = reserva;
			listaReservas.contador++;
		}
		if (listaReservas.contador == MAX_RES) {
			cout << "¡Máximo número de reservas!" << endl << endl;
		}
		else {
			cout << "Nombre de la asignatura (XXX para terminar): ";
			cin >> reserva.asignatura;
		}
	}
	
}
bool buscarAsignatura(const tCatalogo& catalogo, string asignatura, int& pos) {
	bool encontrado = false;
	pos = 0;
	while (!encontrado && pos < NUM_ASIG) {
		if (asignatura==catalogo[pos].asignatura) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}
	return encontrado;
}
void realizarReseva(tCatalogo& catalogo, tListaReservas& listaReservas) {
	int pos;
	double totalCreditos = 0;
	
	for (int i = 0; i < listaReservas.contador; i++) {
		if (!buscarAsignatura(catalogo, listaReservas.datos[i].asignatura, pos)) {
			cout << "Asignatura desconocida: " << listaReservas.datos[i].asignatura << endl;
		}
		else if (catalogo[pos].grupos < listaReservas.datos[i].grupos) {
			cout << "Asignatura " << listaReservas.datos[i].asignatura << ": ¡No hay suficientes grupos!" << endl;
		}
		else {
			totalCreditos += catalogo[pos].creditos*listaReservas.datos[i].grupos;
			catalogo[pos].grupos -= listaReservas.datos[i].grupos;
		}
	}
	cout << endl << endl << ">>> Número de créditos reservados = " << setprecision(3) << showpoint << totalCreditos << " <<<" << endl;
}