#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

int const MAX_VIAJES = 7;
int const NUM_PREFERENCIAS = 3;
string const Lectura = "catalogoViajes.txt";
string const Escritura = "catalogoViajes.txt";

typedef enum{mochilero, turista, lujo}tCategoria;

typedef struct {
	string destino;
	int duracion;
	int plazas;
	int categoria;
}tViaje;

typedef tViaje tdatos[MAX_VIAJES];

typedef struct {
	int contador;
	tdatos datos;
}tCatalogo;

typedef string tPreferencias[NUM_PREFERENCIAS];

bool cargarCatalogo(tCatalogo& catalogo);
void mostrarViajesEnCategoria(const tCatalogo& catalogo, tCategoria categoria);
void leerPreferencias(tPreferencias& preferencias);
void guardarCatalogo(const tCatalogo& catalogo);
int buscarDestino(const tCatalogo& catalogo, string destino, tCategoria categoria);
bool hacerReserva(tCatalogo& catalogo, tCategoria categoria, const tPreferencias& preferencias, string& destinoFinal);

int main() {
	system("chcp 1252");

	tCatalogo catalogo;
	tCategoria categoria;
	tPreferencias preferencias;
	int cat;
	string destinoFinal;

	while (cargarCatalogo(catalogo)) {
		cout << "Introduzca una categoría (0 para mochilero, 1 para turista, 2 para lujo): ";
		cin >> cat;
		while (cat < 0 || cat>2 || cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Opción no valida. Introduzca una categoría (0 para mochilero, 1 para turista, 2 para lujo): ";
			cin >> cat;
		}
		if (cat == mochilero) {
			categoria = mochilero;
		}
		else if (cat == turista) {
			categoria = turista;
		}
		else {
			categoria = lujo;
		}
		mostrarViajesEnCategoria(catalogo, categoria);
		leerPreferencias(preferencias);
		if (!hacerReserva(catalogo, categoria, preferencias, destinoFinal)) {
				cout << endl << "No hay disponibilidad con esas preferencias" << endl;
		}
		else {
			cout << endl << "Reservado viaje a " << destinoFinal << endl;
			guardarCatalogo(catalogo);
		}
		cout << endl << endl;	
	}

	cout << endl << "ERROR: Archivo no encontrado." << endl << endl;

	system("pause");
	return 0;
}

bool cargarCatalogo(tCatalogo& catalogo) {
	ifstream archivo;
	tViaje viaje;
	bool ok;
	char a;

	catalogo.contador = 0;

	archivo.open(Lectura);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
		archivo >> viaje.destino;
		while (viaje.destino != "XXX" && catalogo.contador < MAX_VIAJES) {
			archivo >> viaje.duracion;
			archivo >> viaje.plazas;
			archivo >> viaje.categoria;
			archivo.get(a);
			catalogo.datos[catalogo.contador] = viaje;
			catalogo.contador++;
			archivo >> viaje.destino;
		}
	}
	return ok;
}
void mostrarViajesEnCategoria(const tCatalogo& catalogo, tCategoria categoria) {
	cout << endl << endl << "Viajes en la categoría: " << endl << endl;

	for (int i = 0; i < catalogo.contador; i++) {
		if (categoria == catalogo.datos[i].categoria) {
			cout << catalogo.datos[i].destino << ", " << catalogo.datos[i].duracion << " días, " << catalogo.datos[i].plazas << " plaza(s) disponible(s) " << endl;
		}
	}
	cout << endl;
}
void leerPreferencias(tPreferencias& preferencias) {
	string preferencia;

	cout << "Escriba sus destinos por orden de preferencia (de mayor a menor): " << endl << endl;
	for (int i = 0; i < NUM_PREFERENCIAS; i++) {
		cout << "Destino " << i + 1 << ": ";
		cin >> preferencia;
		cin.ignore(100, '\n');
		preferencias[i] = preferencia;
	}
}
void guardarCatalogo(const tCatalogo& catalogo) {
	ofstream archivo;
	
	archivo.open(Escritura);

	for (int i = 0; i < catalogo.contador; i++) {
		archivo << catalogo.datos[i].destino << " " << catalogo.datos[i].duracion << " " << catalogo.datos[i].plazas << " " << catalogo.datos[i].categoria << endl;
	}
	archivo << "XXX";

	archivo.close();
}
int buscarDestino(const tCatalogo& catalogo, string destino, tCategoria categoria) {
	int pos = 0;
	bool encontrado = false;

	while (!encontrado && pos < catalogo.contador) {
		if (destino == catalogo.datos[pos].destino && categoria == catalogo.datos[pos].categoria && catalogo.datos[pos].plazas > 0) {
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
bool hacerReserva(tCatalogo& catalogo, tCategoria categoria, const tPreferencias& preferencias, string& destinoFinal) {
	bool reservado = false;
	int contador = 0, pos;

	while (!reservado && contador < NUM_PREFERENCIAS) {
		pos = buscarDestino(catalogo, preferencias[contador], categoria);
		if (pos != -1){
			reservado = true;
			destinoFinal = preferencias[contador];
			catalogo.datos[pos].plazas--;
		}
		contador++;
	}

	return reservado;
}