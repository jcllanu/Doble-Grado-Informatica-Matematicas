#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;
//Gestión campeonato de cartas online
//lectura, escritura, visualización y modificación de datos
int const N = 12;
string const Lectura = "equipos.txt";
string const Escritura = "equiposs.txt";

typedef struct {
	string nombre;
	int jugadas;
	int ganadas;
	int categoria;
	bool disponible;
}tEquipo;

typedef tEquipo tCampeonato[N];

typedef enum{principiante, intermedio, avanzado, experto}tCategoria;

int menu();
bool cargarDatos(tCampeonato& campeonato);
void guardarDatos(const tCampeonato& campeonato);
bool buscarEquipo(const tCampeonato& campeonato, string equipo, int& pos);
bool buscarContrario(const tCampeonato& campeonato, int categoria, string equipo1, string& equipo);
void jugarPartida(tCampeonato& campeonato);
void apuntarResultado(tCampeonato& campeonato);
void actualizarGanador(tCampeonato& campeonato, int pos);
void actualizarPerdedor(tCampeonato& campeonato, int pos);

int main() {
	system("chcp 1252");
	int op, pos1, pos2;
	tCampeonato campeonato;
	string equipo1, equipo2;

	if (!cargarDatos(campeonato)) {
		cout << endl << "ERROR: No se ha podido cargar el archivo correctamente." << endl << endl;
	}
	else {
		op = menu();
		while (op != 0) {
			switch (op)
			{
			case 1:
			{
				jugarPartida(campeonato);
			}
			break;
			case 2:
			{
				apuntarResultado(campeonato);
			}
			break;
			}
			op = menu();
		}
		guardarDatos(campeonato);
	}

	system("pause");
	return 0;
}

int menu() {
	int op;

	cout << endl << "Menú:" << endl;
	cout << "1.- Jugar partida" << endl;
	cout << "2.- Apuntar resultado" << endl;
	cout << "0.- Salir" << endl;
	cout << "Eliga una de las opciones (1/2) o finalice el programa (0): ";
	cin >> op;

	while (op < 0 || op>2 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Eliga una de las opciones (1/2) o finalice el programa (0): ";
		cin >> op;
	}

	return op;
}
bool cargarDatos(tCampeonato& campeonato) {
	ifstream archivo;
	bool ok = true;
	tEquipo equipo;
	int contador = 0;
	char a;

	archivo.open(Lectura);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		getline(archivo, equipo.nombre);
		while (equipo.nombre != "XXX" && contador < N) {
			archivo >> equipo.categoria;
			archivo >> equipo.jugadas;
			archivo >> equipo.ganadas;
			archivo >> equipo.disponible;
			archivo.get(a);
			campeonato[contador] = equipo;
			contador++;
			getline(archivo, equipo.nombre);
		}
		if (contador < N) {
			ok = false;
		}
	}

	return ok;
}
void guardarDatos(const tCampeonato& campeonato) {
	ofstream archivo;

	archivo.open(Escritura);
	for (int i = 0; i < N; i++) {
		archivo << campeonato[i].nombre << endl << campeonato[i].categoria << " " << campeonato[i].jugadas << " " << campeonato[i].ganadas << " " << campeonato[i].disponible << endl;
	}
	archivo << "XXX";
	archivo.close();
}
bool buscarEquipo(const tCampeonato& campeonato, string equipo, int& pos) {
	bool encontrado = false;

	pos = 0;
	while (!encontrado && pos < N) {
		if (equipo == campeonato[pos].nombre) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}

	return encontrado;
}
bool buscarContrario(const tCampeonato& campeonato, int categoria, string equipo1, string& equipo2) {
	int max;
	bool alMenosUno = false;
	for (int i = 0; i < N; i++) {
		if (campeonato[i].categoria == categoria && campeonato[i].disponible && equipo1!= campeonato[i].nombre) {
			if (!alMenosUno) {
				alMenosUno = true;
				max = i;
			}
			else if (campeonato[max].jugadas > campeonato[i].jugadas){
				max = i;
			}
		}
	}
	if (alMenosUno) {
		equipo2 = campeonato[max].nombre;
	}
	return alMenosUno;
}
void jugarPartida(tCampeonato& campeonato) {
	int pos1;
	string equipo1, equipo2;

	cin.ignore(100, '\n');
	cout << endl << "Introduzca el nombre clave de su equipo: ";
	getline(cin, equipo1);
	while (!buscarEquipo(campeonato, equipo1, pos1)) {
		cout << "Ese nombre no se encuentra en nuestra base de datos. Introduzca el nombre clave de su equipo: ";
		getline(cin, equipo1);
	}
	if (!buscarContrario(campeonato, campeonato[pos1].categoria, equipo1, equipo2)) {
		cout << "No se ha encontrado nigún rival que esté actualmente disponible en su categoría." << endl;
		cout << "El estado de su equipo se actualiza a 'Disponible para jugar'" << endl;
		campeonato[pos1].disponible = true;
	}
	else {
		cout << endl << "Su rival es: " << equipo2 << endl << endl;
	}
}
void apuntarResultado(tCampeonato& campeonato) {
	int pos1, pos2, perdidas1, perdidas2;
	string equipo1, equipo2;

	cin.ignore(100, '\n');
	cout << endl << "Introduzca el nombre clave del equipo ganador: ";
	getline(cin, equipo1);
	cout << endl << "Introduzca el nombre clave del equipo perdedor: ";
	getline(cin, equipo2);

	while (!buscarEquipo(campeonato, equipo1, pos1) || !buscarEquipo(campeonato, equipo2, pos2)) {
		cout << "Alguno de los nombres no se encuentra en la base de datos. Introduzcalos de nuevo." << endl;
		cout << endl << "Introduzca el nombre clave del equipo ganador: ";
		getline(cin, equipo1);
		cout << endl << "Introduzca el nombre clave del equipo perdedor: ";
		getline(cin, equipo2);
	}
	actualizarGanador(campeonato, pos1);
	actualizarPerdedor(campeonato, pos2);
}
void actualizarGanador(tCampeonato& campeonato, int pos) {
	int perdidas;

	campeonato[pos].jugadas++;
	campeonato[pos].ganadas++;
	perdidas = campeonato[pos].jugadas - campeonato[pos].ganadas;

	if (campeonato[pos].ganadas - perdidas > 25 && campeonato[pos].categoria < experto) {
		campeonato[pos].categoria++;
		campeonato[pos].ganadas = 0;
		campeonato[pos].jugadas = 0;
	}
	if (perdidas > 20 && campeonato[pos].categoria > principiante) {
		campeonato[pos].categoria--;
		campeonato[pos].ganadas = 0;
		campeonato[pos].jugadas = 0;
	}
	campeonato[pos].disponible = false;
}
void actualizarPerdedor(tCampeonato& campeonato, int pos) {
	int perdidas;

	campeonato[pos].jugadas++;
	perdidas = campeonato[pos].jugadas - campeonato[pos].ganadas;
	if (campeonato[pos].ganadas - perdidas > 25 && campeonato[pos].categoria < experto) {
		campeonato[pos].categoria++;
		campeonato[pos].ganadas = 0;
		campeonato[pos].jugadas = 0;
	}
	if (perdidas > 20 && campeonato[pos].categoria > principiante) {
		campeonato[pos].categoria--;
		campeonato[pos].ganadas = 0;
		campeonato[pos].jugadas = 0;
	}
	campeonato[pos].disponible = false;
}