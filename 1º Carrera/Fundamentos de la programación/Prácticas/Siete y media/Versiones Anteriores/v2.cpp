#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

const int Tam = 8;
const float SyM = 7.5;
typedef int tCartasPorAparecer[Tam];

int aleatorio(int limitinf, int intervalo);//Recibe un limite inferior y el numero de valores de un intervalo y devuelve un número aleatorio en ese intervalo
float valor(int card);//Recibe una carta (cuyo rango de valores es 1,2,3,4,5,6,7,10,11,12) y devuelve el valor o puntuación de la carta (0.5 si es una figura y el mismo que el de la carta en caso contrario)
int menu();//No recibe nada y devuelve un entero en el rango [0,5] dependiendo del modo de juego elegido
ifstream buscarArchivo();//No recibe nada y se encarga de buscar y abrir el archivo del que se van a leer las cartas
void modoAcuerpo();//No recibe ni devuelve nada. Simplemente se saca del main para aliviar la carga de código del mismo
void modoBcuerpo();//No recibe ni devuelve nada. Simplemente se saca del main para aliviar la carga de código del mismo
float modoA(ifstream& file, int numCartas);//Recibe el mazo por la posición donde se deba leer y el número de cartas que se deben robar. Devuelve la puntuación obtenida 
float modoBhumano(ifstream& file, int numCartas);//Recibe el mazo por la posición donde se deba leer y el número máximo de cartas que se pueden robar. Devuelve la puntuación obtenida por el humano
float modoBmaquina(ifstream& file, int numCartas, float puntosHumano);//Recibe el mazo por la posición donde se deba leer y el número máximo de cartas que se pueden robar. También recibe la puntuación del jugador humano. Devuelve la puntuación obtenida por la máquina, que robará si su puntuación es menor o igual a la del humano
int determinaGanador(float puntosJugador, float puntosMaquina);//Recibe la puntuación del humano y de la máquina. Devuelve un 2 si gana la máquina y un 1 si gana el humano

void modoCcuerpo();//No recibe ni devuelve nada. Simplemente se saca del main para aliviar la carga de código del mismo
void modoChumano(ifstream& file, tCartasPorAparecer cartas, float& puntos);//Recibe el mazo por la posición donde se deba leer, el array que contaviliza las cartas que quedan por salir y la puntuación del humano. No devuelve nada pero su interacción con el programa es que modifia tanto el array de las cartas que quedan por salir como la puntuación del humano
void modoCmaquina(ifstream& file, tCartasPorAparecer cartas, float puntosHumano, float& puntos);//Recibe el mazo por la posición donde se deba leer, el array que contaviliza las cartas que quedan por salir y las puntuaciones del humano y la máquina. No devuelve nada pero su interacción con el programa es que modifia tanto el array de las cartas que quedan por salir como la puntuación de la máqiuna.
bool esProbablePasarse(float puntosMaquina, const tCartasPorAparecer cartas);//Recibe la puntuación de la máquina y el array con las cartas por aparecer. Devuelve true si la probabilidad de pasarse al robar una carta más excede 0.5 y false en caso contrario. 
int posicionArray(int carta);//Recibe el entero correspondiente a cada una de las cartas y devuelve la posición que esté tipo de carta ocupa en el array (figura-0, 1-1, 2-2,...,7-7)
void robar(ifstream& file, float& puntuacion);//

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
		case 3:
		{
			modoCcuerpo();
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
	cout << "	1.- Modo A" << endl;
	cout << "	2.- Modo B" << endl;
	cout << "	3.- Modo C" << endl;
	cout << "	4.- Modo D" << endl;
	cout << "	5.- Modo E" << endl;
	cout << "	0.- Salir" << endl;
	cout << "Escribe el modo en el que quieras jugar (1/2/3/4/5) o finaliza el programa(0): ";
	cin >> modojuego;

	while (modojuego < 0 || modojuego>5 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Escribe el modo en el que quieras jugar (1/2/3/4/5) o finaliza el programa(0): ";
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

	if (puntuacionJugadorHumano > SyM) {
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

	while (numCartas > 0 && puntuacion <= SyM) {
		robar(file, puntuacion);
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
	cout << endl << "Número máximo de cartas: " << max_cartas << endl;
	puntuacionJugadorHumano = modoBhumano(mazo, max_cartas);

	if (puntuacionJugadorHumano > SyM) {
		puntuacionJugadorMaquina = 0;
	}
	else {
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

	int cartasRobadas = 1;
	float puntuacion = 0;
	int decision;

	cout << endl << "Cartas del jugador: " << endl;
	robar(file, puntuacion);

	while (cartasRobadas < numCartas && puntuacion <= SyM) {
		cout << "  ¿Robas(1) o te plantas(2)? ";
		cin >> decision;
		while (decision < 1 || decision > 2 || cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Opción no válida. ¿Robas(1) o te plantas(2)? ";
			cin >> decision;
		}
		if (decision == 1) {
			robar(file, puntuacion);
			cartasRobadas++;
		}
		else {
			cartasRobadas = numCartas + 1;
		}
	}
	cout << endl;
	return puntuacion;
}

float modoBmaquina(ifstream& file, int numCartas, float puntosHumano) {
	int cartasRobadas = 1;
	float puntuacion = 0;
	bool superarHumano = false;

	cout << endl << "Cartas de la máquina: " << endl;
	robar(file, puntuacion);
	while (cartasRobadas < numCartas && !superarHumano) {
		if (puntuacion <= puntosHumano) {
			cartasRobadas++;
			cout << "  (La máquina decide robar carta)" << endl;
			robar(file, puntuacion);
		}
		else {
			superarHumano = true;
		}
	}
	if (superarHumano) {
		cout << "  (La máquina deja de robar carta)";
	}
	else {
		cout << "  (La máquina ha llegado al número máximo de cartas que puede robar)";
	}
	cout << endl << endl;
	return puntuacion;
}

int determinaGanador(float puntosJugador, float puntosMaquina) {
	int ganador;

	if (puntosJugador > SyM) {
		cout << "Te has pasado." << endl;
		ganador = 2;
	}
	else if (puntosMaquina > SyM) {
		cout << "La máquina se ha pasado." << endl;
		ganador = 1;
	}
	else if (puntosJugador > puntosMaquina) {
		cout << "La puntación de la máquina ha sido " << puntosMaquina << " y la tuya " << puntosJugador << endl;
		ganador = 1;
	}
	else if (puntosJugador < puntosMaquina) {
		cout << "Tu puntuacion ha sido " << puntosJugador << " y la de la maquina " << puntosMaquina << endl;
		ganador = 2;
	}
	else if (puntosJugador == puntosMaquina) {
		cout << "Ambas puntuaciones son" << puntosJugador << ", pero el azar ha decido que..." << endl;
		ganador = aleatorio(1, 2);
	}
	return ganador;
}

void modoCcuerpo() {

	ifstream mazo;
	float puntuacionJugadorHumano = 0, puntuacionJugadorMaquina = 0;
	tCartasPorAparecer cartas;

	cartas[0] = 12;
	for (int i = 1; i <= 7; i++) {
		cartas[i] = 4;
	}

	mazo = buscarArchivo();
	modoChumano(mazo, cartas, puntuacionJugadorHumano);

	if (puntuacionJugadorHumano > SyM) {
		puntuacionJugadorMaquina = 0;
	}
	else {
		modoCmaquina(mazo, cartas, puntuacionJugadorHumano, puntuacionJugadorMaquina);
	}
	if (determinaGanador(puntuacionJugadorHumano, puntuacionJugadorMaquina) == 1) {
		cout << "¡Has ganado!" << endl;
	}
	else {
		cout << "La máquina ha ganado." << endl;
	}
	mazo.close();
}

void modoChumano(ifstream& file, tCartasPorAparecer cartas, float& puntos) {
	bool roba = true;
	int carta;
	int decision;

	cout << endl << "Cartas del jugador: " << endl;
	robar(file, puntos);
	cartas[posicionArray(carta)]--;

	while (puntos <= SyM && roba) {
		cout << "  ¿Robas(1) o te plantas(2)? ";
		cin >> decision;
		while (decision < 1 || decision > 2 || cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Opción no válida. ¿Robas(1) o te plantas(2)? ";
			cin >> decision;
		}
		if (decision == 1) {
			robar(file, puntos);
			cartas[posicionArray(carta)]--;
		}
		else {
			roba = false;
		}
	}
	cout << endl;
}

void modoCmaquina(ifstream& file, tCartasPorAparecer cartas, float puntosHumano, float& puntos) {
	int carta;
	file >> carta;
	cout << endl << "Cartas de la maquina: " << endl;
	robar(file, puntos);
	cartas[posicionArray(carta)]--;

	while (puntos < puntosHumano) {
		cout << "  (La máquina decide robar carta)" << endl;
		robar(file, puntos);
		cartas[posicionArray(carta)]--;
	}
	if (puntos == puntosHumano) {
		if (esProbablePasarse(puntos, cartas)) {
			cout << "La maquina no asume riesgo." << endl;
		}
		else {
			cout << "La maquina asume riesgo." << endl;
			robar(file, puntos);
			cartas[posicionArray(carta)]--;
		}
	}
	else {
		cout << "La máquina no roba más" << endl; /*este cout me sobra*/
	}
	cout << endl << endl;

}

bool esProbablePasarse(float puntosMaquina, const tCartasPorAparecer cartas) {
	bool excede;
	float puntosRestantes, cartasTotal = 0, cartasExcede = 0;
	puntosRestantes = SyM - puntosMaquina;
	for (int i = 0; i < Tam; i++) {
		if (i > puntosRestantes) {
			cartasExcede += cartas[i];
		}
		cartasTotal += cartas[i];
	}

	if (cartasExcede / cartasTotal < 0.5) {
		excede = false;
	}
	else {
		excede = true; 
	}

	return excede;
}

int posicionArray(int carta) {
	int posicion;
	if (carta > 7) {
		posicion = 0;
	}
	else {
		posicion = carta;
	}

	return posicion;
}

void robar(ifstream& file, float& puntuacion) {
	int carta;
	file >> carta;
	cout << "	Carta: " << setw(2) << right << carta;
	puntuacion = puntuacion + valor(carta);
	cout << " - Puntuación total: " << setw(3) << left << puntuacion << endl;
}
