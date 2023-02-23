#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

const int NUM_PLAYERS = 6;
const string Entrada = "players.txt";
typedef struct {
	string nombre;
	string equipo;
	int partidos;
	int minutos;
	int goles;
}tJugador;

typedef tJugador tListaJugadores[NUM_PLAYERS];

int menu();
bool cargar(tListaJugadores& lista);
void filtrarLista(const tListaJugadores& lista, string equipo);
void actualizarJugador(tListaJugadores& lista, string jugador, int minutos, int goles);
void consultarMaxGoleador(const tListaJugadores& lista);


int main() {
	system("chcp 1252");
	tListaJugadores listaJugadores;
	int op, goles, minutos;
	string equipo, nombre;

	if (!cargar(listaJugadores)) {
		cout << endl << "ERROR: El archivo no se ha podido cargar correctamente." << endl << endl;
	}
	else {
		op = menu();
		while (op != 0) {
			switch (op) {
			case 1: {
				cout << endl << "Introduce el código del equipo para ver a sus jugadores o 'TODOS' para ver todos los jugadores de la lista: ";
				cin >> equipo;
				filtrarLista(listaJugadores, equipo);
			}
			break;
			case 2: {
				cout << "Introduzca los datos del último partido del jugador a actualizar." << endl;
				cout << "Nombre: ";
				cin >> nombre;
				cout << "Minutos: ";
				cin >> minutos;
				cout << "Goles: ";
				cin >> goles;
				actualizarJugador(listaJugadores, nombre, minutos, goles);
			}
			break;
			case 3: {
				consultarMaxGoleador(listaJugadores);
			}
			break;
			}
			op = menu();
		}
	}
	cout << endl;
	system("pause");
	return 0;
}


int menu() {
	int op;

	cout << endl << "Menú:" << endl;
	cout << "1.- Filtrar lista" << endl;
	cout << "2.- Actualizar jugador" << endl;
	cout << "3.- Consultar máximo goleador" << endl;
	cout << "0.- Salir" << endl;
	cout << "Introduzca una de las opciones (1/2/3) o finalice el program (0): ";
	cin >> op;

	while (op < 0 || op>3 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Introduzca una de las opciones (1/2/3) o finalice el program (0): ";
		cin >> op;
	}

	return op;
}
bool cargar(tListaJugadores& lista) {
	ifstream archivo;
	bool ok = true;
	int contador = 0;
	tJugador jugador;
	char a;

	archivo.open(Entrada);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		archivo >> jugador.nombre;
		while (jugador.nombre != "XXX" && contador < NUM_PLAYERS && ok) {
			archivo >> jugador.equipo;
			archivo >> jugador.partidos;
			archivo >> jugador.minutos;
			archivo >> jugador.goles;
			if ((jugador.partidos < 0) || (jugador.minutos < 0) || (jugador.goles < 0) || (jugador.partidos * 90 < jugador.minutos) || (jugador.partidos == 0 && (jugador.minutos > 0 || jugador.goles > 0))) {
				ok = false;
			}
			if ((jugador.equipo != "BCN") && (jugador.equipo != "RMA") && (jugador.equipo != "ATM") && (jugador.equipo != "VIL") && (jugador.equipo != "ATB")) {
				ok = false;
			}
			archivo.get(a);
			lista[contador] = jugador;
			contador++;
			archivo >> jugador.nombre;
		}
		if (contador < NUM_PLAYERS) {
			ok = false;
		}
	}

	return ok;
}
void filtrarLista(const tListaJugadores& lista, string equipo) {
	bool algunJugador = false;
	if (equipo == "TODOS") {
		cout << endl<< "Nombre de todos los jugadores registrados: " << endl << endl;
	}
	else {
		cout << endl << "Jugadores de " << equipo << ":" << endl << endl;
	}
	for (int i = 0; i < NUM_PLAYERS; i++) {
		if (equipo == "TODOS") {
			cout << lista[i].nombre << endl;
			algunJugador = true;
		}
		else if (equipo == lista[i].equipo) {
			cout << lista[i].nombre << endl;
			algunJugador = true;
		}
	}
	if (!algunJugador) {
		cout << "No se ha encontrado ningún jugador de " << equipo << endl;
	}
}
void actualizarJugador(tListaJugadores& lista, string jugador, int minutos, int goles) {
	bool encontrado = false;
	int pos = 0 ;

	while (!encontrado && pos < NUM_PLAYERS) {
		if (jugador == lista[pos].nombre) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}

	if (!encontrado) {
		cout << endl << "ERROR: Jugador no encontrado." << endl;
	}
	else if (minutos < 0) {
		cout << endl << "ERROR: Los minutos no pueden ser negativos." << endl;
	}
	else if (minutos > 90) {
		cout << endl << "ERROR: Los minutos no pueden superar la duración de un partido (90 min)." << endl;
	}
	else if (goles < 0 ){
		cout << endl << "ERROR: Los goles no pueden ser negativos." << endl;
	}
	else if (minutos == 0 && goles > 0) {
		cout << endl << "ERROR: No puede haber marcado jugando 0 minutos." << endl;
	}
	else {
		lista[pos].goles += goles;
		lista[pos].minutos += minutos;
		lista[pos].partidos++;
		cout << endl << endl << "Jugador actualizado:" << endl << endl;
		cout << "Nombre: " << lista[pos].nombre << endl;
		cout << "Partidos jugados: " << lista[pos].partidos << endl;
		cout << "Minutos jugados: " << lista[pos].minutos<< endl;
		cout << "Goles marcados: " << lista[pos].goles << endl;

	}
}
void consultarMaxGoleador(const tListaJugadores& lista) {
	int maxGoles = lista[0].goles;
	
	for (int i = 1; i < NUM_PLAYERS; i++) {
		if (lista[i].goles > maxGoles) {
			maxGoles = lista[i].goles;
		}
	}cout << endl << "Máximo(s) goleador(es) con " << maxGoles <<" goles: " << endl << endl;
	for (int i = 0; i < NUM_PLAYERS; i++) {
		if (maxGoles == lista[i].goles) {
			cout << "Nombre: " << setw(15) << left << lista[i].nombre << "Equipo: " << setw(5) << lista[i].equipo << endl << "Partidos jugados: " << setw(5)
				<< lista[i].partidos << "Minutos jugados: " << setw(6) << lista[i].minutos << endl << endl;
		}
	}
}