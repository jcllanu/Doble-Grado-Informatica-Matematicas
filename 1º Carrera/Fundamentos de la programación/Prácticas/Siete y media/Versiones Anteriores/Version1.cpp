#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int aleatorio(int limitinf, int intervalo);
float valor(int card);
int menu();
ifstream buscarArchivo();
void modoAcuerpo();
void modoBcuerpo();
float modoA(ifstream& file, int numCartas);
float modoBhumano(ifstream& file, int numCartas);
float modoBmaquina(ifstream& file, int numCartas, float puntosHumano);
int determinaGanador(float puntosJugador, float puntosMaquina);

int main() {

	int modoJuego;
	system("chcp 1252");
	srand(time(NULL));

	modoJuego = menu();

	while (modoJuego != 0) {
		switch (modoJuego) {
		case 1:
		{
			modoAcuerpo();
		}
		break;
		case 2:
		{
			modoBcuerpo();
		}
		break;
		}

		modoJuego = menu();
	}

	system("pause");
	return 0;
}

int aleatorio(int limitinf, int intervalo) {
	int final = limitinf + rand() % intervalo;
	return final;
}

float valor(int card) {
	float puntos;
	if (card > 7) {
		puntos = 0.5;
	}
	else {
		puntos = card;
	}

	return puntos;
}

int menu() {

	int modojuego;

	cout << endl << "Modos de juego: " << endl;
	cout << "	1.- Modo A: descripción" << endl;
	cout << "	2.- Modo B: descripción" << endl;
	cout << "	0.- Salir" << endl;
	cout << "Escribe el modo en el que quieras jugar (1/2) o finaliza el programa(0): ";
	cin >> modojuego;

	while (modojuego < 0 || modojuego>2 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Escribe el modo en el que quieras jugar (1/2) o finaliza el programa(0): ";
		cin >> modojuego;
	}
	return modojuego;
}

ifstream buscarArchivo() {
	ifstream baraja;
	string nombreArchivo;
	cout << "Introduce el nombre del archivo donde tengas la baraja: ";
	cin >> nombreArchivo;
	baraja.open(nombreArchivo);
	if (baraja.is_open()) {

		return baraja;
	}
	else {
		cout << "ERROR: No se ha encontrado el archivo";
	}
}

void modoAcuerpo() {

	int numCartas;
	ifstream mazo;
	float puntuacionJugadorHumano, puntuacionJugadorMaquina;

	mazo = buscarArchivo();
	numCartas = aleatorio(3, 3);
	cout << endl << "Cartas del jugador: " << endl;
	puntuacionJugadorHumano = modoA(mazo, numCartas);

	if (puntuacionJugadorHumano > 7.5) {
		puntuacionJugadorMaquina = 0;
	}
	else {
		cout << "Cartas de la máquina: " << endl;
		puntuacionJugadorMaquina = modoA(mazo, numCartas);
	}
	if (determinaGanador(puntuacionJugadorHumano, puntuacionJugadorMaquina) == 1) {
		cout << "¡Has ganado!" << endl;
	}
	else {
		cout << "La máquina ha ganado." << endl;
	}
	mazo.close();
}

float modoA(ifstream& file, int numCartas) {
	float puntuacion = 0;
	double carta;
	while (numCartas > 0 && puntuacion <= 7.5) {
		file >> carta;
		cout << "	Carta: " << setw(2) << right << carta;
		puntuacion = puntuacion + valor(carta);
		cout << " - Puntuación total: " << setw(3) << left << puntuacion << endl;
		numCartas--;
	}
	cout << endl;
	return puntuacion;
}

void modoBcuerpo() {
	int max_cartas;
	ifstream mazo;
	float puntuacionJugadorHumano, puntuacionJugadorMaquina;

	mazo = buscarArchivo();
	max_cartas = aleatorio(3, 3);

	cout <<endl<< "Número máximo de cartas: " << max_cartas << endl;
	cout << endl << "Cartas del jugador: " << endl;

	puntuacionJugadorHumano = modoBhumano(mazo, max_cartas);

	if (puntuacionJugadorHumano > 7.5) {
		puntuacionJugadorMaquina = 0;
	}
	else {
		cout << endl << "Cartas de la máquina: " << endl;
		puntuacionJugadorMaquina = modoBmaquina(mazo, max_cartas, puntuacionJugadorHumano);
	}

	if (determinaGanador(puntuacionJugadorHumano, puntuacionJugadorMaquina) == 1) {
		cout << "¡Has ganado!" << endl;
	}
	else {
		cout << "La máquina ha ganado." << endl;
	}
	mazo.close();
}

float modoBhumano(ifstream& file, int numCartas) {

	int cartasRobadas = 0;
	float puntuacion = 0;
	double carta;
	char decision;

	file >> carta;
	cout << "	Carta: " << setw(2) << right << carta;
	puntuacion = puntuacion + valor(carta);
	cout << " - Puntuación total: " << setw(3) << left << puntuacion;
	cartasRobadas++;

	while (cartasRobadas < numCartas && puntuacion <= 7.5) {
		cout << "  ¿Robas(R) o te plantas(P)? ";
		cin >> decision;
		if (decision == 'R') {
			cartasRobadas++;
			file >> carta;
			cout << "	Carta: " << setw(2) << right << carta;
			puntuacion = puntuacion + valor(carta);
			cout << " - Puntuación total: " << setw(3) << left << puntuacion ;
		}
		else {
			cartasRobadas = numCartas + 1;
		}
	}
	cout << endl;
	return puntuacion;
}

float modoBmaquina(ifstream& file, int numCartas, float puntosHumano) {
	int cartasRobadas = 0;
	float puntuacion = 0;
	double carta;

	file >> carta;
	cout << "	Carta: " << setw(2) << right << carta;
	puntuacion = puntuacion + valor(carta);
	cout << " - Puntuación total: " << setw(3) << left << puntuacion;
	cartasRobadas++;

	while (cartasRobadas < numCartas) {
		if (puntuacion <= puntosHumano) {
			cartasRobadas++;
			cout << "  (La máquina decide robar carta)" << endl;
			file >> carta;
			cout << "	Carta: " << setw(2) << right << carta;
			puntuacion = puntuacion + valor(carta);
			cout << " - Puntuación total: " << setw(3) << left << puntuacion;
		}
		else {
			cartasRobadas = numCartas + 1;
		}
	}
	cout << endl << endl;
	return puntuacion;
}

int determinaGanador(float puntosJugador, float puntosMaquina) {
	int ganador;
	if (puntosJugador > 7.5) {
		cout << "Te has pasado." << endl;
		ganador = 2;
	}
	else if (puntosMaquina > 7.5) {
		cout << "La máquina se ha pasado." << endl;
		ganador = 1;
	}
	else if (puntosJugador > puntosMaquina) {
		cout << "Enhorabuena. La puntación de la máquina ha sido " << puntosMaquina << " y la tuya " << puntosJugador << endl;
		ganador = 1;
	}
	else if (puntosJugador < puntosMaquina) {
		cout << "Mala suerte. Tu puntuacion ha sido " << puntosJugador << " y la de la maquina " << puntosMaquina << endl;
		ganador = 2;
	}
	else if (puntosJugador == puntosMaquina) {
		ganador = aleatorio(1, 2);
		cout << "Las puntuaciones son iguales pero el azar ha decido que..." << endl;
	}

	return ganador;
}
