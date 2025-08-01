#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

const bool MostrarMazo = false;
const bool MazoAleatorio = false;
const int Tam = 8;
const int TamMazo = 40;
const float SyM = 7.5;



typedef int tCartasPorAparecer[Tam];
typedef int tCartasMazo[TamMazo];
typedef struct {
	tCartasMazo cartasMazo;
	int cartasRobadas;
} tConjuntoCartas;

int menu();//Devuelve un entero en el rango [0,5] dependiendo del modo de juego elegido.

void modoAcuerpo();//Todas las funciones modoXcuerpo son procedimientos que se incluyen �nicamente para aliviar la carga de c�digo del main correspondiente al modoX.
float modoA(ifstream& file, int numCartas);//Recibe el mazo  y el n�mero de cartas que se deben robar. Devuelve la puntuaci�n obtenida. 

void modoBcuerpo();
float modoBhumano(ifstream& file, int numCartas);//Recibe el mazo  y el n�mero m�ximo de cartas que se pueden robar. Devuelve la puntuaci�n obtenida por el humano.
float modoBmaquina(ifstream& file, int numCartas, float puntosHumano);/*Recibe el mazo y el n�mero m�ximo de cartas que se pueden robar. Tambi�n recibe la puntuaci�n 
del jugador humano. Devuelve la puntuaci�n obtenida por la m�quina, que robar� si su puntuaci�n es menor o igual a la del humano.*/

void modoCcuerpo();
void modoChumano(ifstream& file, tCartasPorAparecer cartas, float& puntos);/*Recibe el mazo, el array que contaviliza las cartas que quedan por salir y la puntuaci�n 
del humano. Modifia tanto el array de las cartas que quedan por salir y como la puntuaci�n del humano.*/
void modoCmaquina(ifstream& file, tCartasPorAparecer cartas, float puntosHumano, float& puntos);/*Recibe el mazo, el array que contaviliza las cartas que quedan por 
salir y las puntuaciones del humano y la m�quina. Modifia tanto el array de las cartas que quedan por salir como la puntuaci�n de la m�qiuna.*/
bool esProbablePasarse(float puntosMaquina, const tCartasPorAparecer cartas);/*Recibe la puntuaci�n de la m�quina y el array con las cartas por aparecer. Devuelve true 
si la probabilidad de pasarse al robar una carta m�s excede 0.5 y false en caso contrario.*/

int determinaGanador(float puntosJugador, float puntosMaquina);//Recibe la puntuaci�n del humano y de la m�quina. Devuelve un 2 si gana la m�quina y un 1 si gana el humano.

void modoDcuerpo(int partidasJugadas);
void inicializa(tConjuntoCartas & cartas);// Inicializa cartas a la lista vac�a. 
void sacarCarta(tConjuntoCartas & cartas, int & carta);//Elimina la �ltima carta de la lista "cartas" y la devuelve en "carta".
void annadirCarta(tConjuntoCartas & cartas, int carta);//A�ade la carta "carta" en el extremo derecho de la lista "cartas".
void crearMazo(tConjuntoCartas & mazo);//Rellena "mazo" con 40 cartas dispuestas de forma aleatoria.
void modoDhumano(tConjuntoCartas & mazo, tCartasPorAparecer	cartas, tConjuntoCartas & cartasHumano, float & puntos);/*Recibe el mazo, el array que contaviliza las cartas que 
quedan por salir, la puntuaci�n del humano y la lista de cartas robadas por el humano. Modifia el mazo, las cartas que quedan por salir, la puntuaci�n del humano y las cartas 
robadas por el humano.*/
void modoDmaquina(tConjuntoCartas & mazo, tCartasPorAparecer cartas, float puntosHumano, tConjuntoCartas & cartasMaquina, float & puntos);/*Recibe el mazo, el array que 
contaviliza las cartas que quedan por salir, la puntuaci�n del humano y de la m�quina y la lista de cartas robadas por el humano. Modifia el mazo, las cartas que quedan por salir,
la puntuaci�n de la maquina y las cartas robadas por la m�quina.*/

int determinaGanadorModoD(float puntosJugador, float puntosMaquina, int robadasHumano, int robadasMaquina);/*Recibe la puntuaci�n del humano y de la m�quina y el numero de cartas 
que han robado ambos. Devuelve un 2 si gana la m�quina y un 1 si gana el humano. (Como en el modo D para decidir el ganador no es suficiente con recibir las puntuaciones del jugador
y de la m�quina, y al ser "determinaGanador" una funci�n exigida con unos determinados par�metros, hemos preferido crear una funci�n espec�fica antes que a�adirle otros par�metros 
"determinaGanador" */

ifstream buscarArchivo();//No recibe nada y se encarga de buscar y abrir el archivo del que se van a leer las cartas.

int aleatorio(int limitinf, int intervalo);//Dado un l�mite inferior y una longitud devuelve un n�mero aleatorio del intervalo

float valor(int card);//Recibe una carta (cuyo rango de valores es [1,7]U[10,12]) y devuelve el valor o puntuaci�n de la carta (0.5 si es una figura y el mismo que el de la carta en caso contrario)
float valorPosicion(int posicion);/*Relaciona cada posici�n del array con el valor de la carta que lleva asociada(0->0.5, 1->1, 2->2,...,7->7). 
Recibe la posici�n y devuelve el valor de las cartas de esa posici�n.*/
int posicionArray(int carta);//Recibe el entero correspondiente a cada una de las cartas y devuelve la posici�n que est� tipo de carta ocupa en el array (figura->0, 1->1, 2->2,...,7->7).

void robar(ifstream& file, float& puntuacion, int& carta);/*Recibe el mazo, la puntuacion de cualquiera de los dos jugadores y la carta. Modifica las variables de puntuacion y cartas y
escribe en pantalla la carta robada y la puntuaci�n total que se lleva en ese momento*/

void robarModoD(tConjuntoCartas & mazo, tCartasPorAparecer restantes, tConjuntoCartas & cartas, float & puntos);/*Realiza todos los procedimientos necesarios para la acci�n de robar 
una carta en el modo D: extrae una carta de "mazo", la a�ade a la lista "cartas", actualiza la puntuaci�n y modifica el array de cartas restantes. Tambi�n escribe en pantalla las cartas 
robadas y la puntuaci�n total*/
void rellenarCartasPorAparecer(tCartasPorAparecer cards);/*Recibe el array de las cartas que quedan por aparecer y lo inicializa: figuras(pos0) a 8 y de las posiciones 1 a la 7 a 4.*/

void mostrarMazo(const tConjuntoCartas& mazo);/*Muestra en pantalla el mazo en el estado actual*/


int main() {
	int modoJuego;
	int partidasJugadas = 0;

	system("chcp 1252");
	srand(time(NULL));

	modoJuego = menu();

	while (modoJuego != 0) {

		partidasJugadas++;

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
		case 4:
		{
			modoDcuerpo(partidasJugadas);
		}
		break;
		}

		modoJuego = menu();
	}

	system("pause");
	return 0;
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
		cout << "Opci�n no v�lida. Escribe el modo en el que quieras jugar (1/2/3/4/5) o finaliza el programa(0): ";
		cin >> modojuego;
	}
	return modojuego;
}

void modoAcuerpo() {

	int numCartas;
	ifstream mazo;
	float puntuacionJugadorHumano, puntuacionJugadorMaquina;

	mazo = buscarArchivo();
	numCartas = aleatorio(3, 3);
	cout << endl << "Cartas del jugador: ";
	puntuacionJugadorHumano = modoA(mazo, numCartas);

	if (puntuacionJugadorHumano > SyM) {
		puntuacionJugadorMaquina = 0;
	}
	else {
		cout << endl << endl << "Cartas de la m�quina: ";
		puntuacionJugadorMaquina = modoA(mazo, numCartas);
	}
	if (determinaGanador(puntuacionJugadorHumano, puntuacionJugadorMaquina) == 1) {
		cout << "�Has ganado!" << endl;
	}
	else {
		cout << "La m�quina ha ganado." << endl;
	}
	mazo.close();
}
float modoA(ifstream& file, int numCartas) {
	float puntuacion = 0;
	int carta;

	while (numCartas > 0 && puntuacion <= SyM) {
		cout << endl;
		robar(file, puntuacion, carta);
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
	cout << endl << "N�mero m�ximo de cartas: " << max_cartas << endl;
	puntuacionJugadorHumano = modoBhumano(mazo, max_cartas);

	if (puntuacionJugadorHumano > SyM) {
		puntuacionJugadorMaquina = 0;
	}
	else {
		puntuacionJugadorMaquina = modoBmaquina(mazo, max_cartas, puntuacionJugadorHumano);
	}

	if (determinaGanador(puntuacionJugadorHumano, puntuacionJugadorMaquina) == 1) {
		cout << "�Has ganado!" << endl;
	}
	else {
		cout << "La m�quina ha ganado." << endl;
	}
	mazo.close();
}
float modoBhumano(ifstream& file, int numCartas) {
	int carta, decision, cartasRobadas = 1;
	float puntuacion = 0;

	cout << endl << "Cartas del jugador: " << endl;
	robar(file, puntuacion, carta);

	while (cartasRobadas < numCartas && puntuacion <= SyM) {
		cout << "  �Robas(1) o te plantas(2)? ";
		cin >> decision;

		while (decision < 1 || decision > 2 || cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Opci�n no v�lida. �Robas(1) o te plantas(2)? ";
			cin >> decision;
		}

		if (decision == 1) {
			robar(file, puntuacion, carta);
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
	int carta, cartasRobadas = 1;
	float puntuacion = 0;
	bool superarHumano = false;

	cout << endl << endl << "Cartas de la m�quina: " << endl;
	robar(file, puntuacion, carta);

	while (cartasRobadas < numCartas && !superarHumano) {

		if (puntuacion <= puntosHumano) {
			cartasRobadas++;
			cout << "  (La m�quina decide robar carta)" << endl;
			robar(file, puntuacion, carta);
		}
		else {
			superarHumano = true;
		}
	}

	if (superarHumano) {
		cout << "  (La m�quina deja de robar carta)";
	}
	else {
		cout << "  (La m�quina ha llegado al n�mero m�ximo de cartas que puede robar)";
	}
	cout << endl;
	return puntuacion;
}

void modoCcuerpo() {

	ifstream mazo;
	float puntuacionJugadorHumano = 0, puntuacionJugadorMaquina = 0;
	tCartasPorAparecer cartas;
	rellenarCartasPorAparecer(cartas);

	mazo = buscarArchivo();
	modoChumano(mazo, cartas, puntuacionJugadorHumano);

	if (puntuacionJugadorHumano > SyM) {
		puntuacionJugadorMaquina = 0;
	}
	else {
		modoCmaquina(mazo, cartas, puntuacionJugadorHumano, puntuacionJugadorMaquina);
	}

	if (determinaGanador(puntuacionJugadorHumano, puntuacionJugadorMaquina) == 1) {
		cout << "�Has ganado!" << endl;
	}
	else {
		cout << "La m�quina ha ganado." << endl;
	}
	mazo.close();
}
void modoChumano(ifstream& file, tCartasPorAparecer cartas, float& puntos) {
	bool roba = true;
	int carta, decision;

	cout << endl << "Cartas del jugador: " << endl;
	robar(file, puntos, carta);
	cartas[posicionArray(carta)]--;

	while (puntos <= SyM && roba) {
		cout << "  �Robas(1) o te plantas(2)? ";
		cin >> decision;

		while (decision < 1 || decision > 2 || cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Opci�n no v�lida. �Robas(1) o te plantas(2)? ";
			cin >> decision;
		}

		if (decision == 1) {
			robar(file, puntos, carta);
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

	cout << endl << "Cartas de la maquina: " << endl;
	robar(file, puntos, carta);
	cartas[posicionArray(carta)]--;

	while (puntos < puntosHumano) {
		cout << "  (La m�quina decide robar carta)" << endl;
		robar(file, puntos, carta);
		cartas[posicionArray(carta)]--;
	}
	if (puntos == puntosHumano) {

		if (esProbablePasarse(puntos, cartas)) {
			cout << setw(74) << right << "(La maquina no asume el riesgo)";
		}
		else {
			cout << setw(71) << right << "(La maquina asume el riesgo)"<<endl;
			robar(file, puntos, carta);
			cartas[posicionArray(carta)]--;
		}
	}
	else {
		cout << "  (La m�quina deja de robar)";
	}
	cout << endl;
}
bool esProbablePasarse(float puntosMaquina, const tCartasPorAparecer cartas) {
	bool pasarse;
	float puntosRestantes = SyM - puntosMaquina;
	int cartasTotal = 0, cartasExcede = 0;

	for (int i = 0; i < Tam; i++) {

		if (valorPosicion(i) > puntosRestantes) {
			cartasExcede += cartas[i];
		}
		cartasTotal += cartas[i];
	}

	if (double(cartasExcede) / cartasTotal < 0.5) {
		pasarse = false;
	}
	else {
		pasarse = true;
	}
	cout << "  (La probabilidad de pasarse es " << setprecision(5) << double(cartasExcede) / cartasTotal << ")" << endl;
	return pasarse;
}

int determinaGanador(float puntosJugador, float puntosMaquina) {
	int ganador;

	cout << endl;
	if (puntosJugador > SyM) {
		cout << "Te has pasado.";
		ganador = 2;
	}
	else if (puntosMaquina > SyM) {
		cout << "La m�quina se ha pasado.";
		ganador = 1;
	}
	else if (puntosJugador > puntosMaquina) {
		cout << "La puntaci�n de la m�quina ha sido " << puntosMaquina << " y la tuya " << puntosJugador;
		ganador = 1;
	}
	else if (puntosJugador < puntosMaquina) {
		cout << "Tu puntuacion ha sido " << puntosJugador << " y la de la maquina " << puntosMaquina;
		ganador = 2;
	}
	else if (puntosJugador == puntosMaquina) {
		cout << "Ambas puntuaciones son " << puntosJugador << ", pero el azar ha decido que...";
		ganador = aleatorio(1, 2);
	}
	cout << endl;
	return ganador;
}

void modoDcuerpo(int partidasJugadas) {
	tConjuntoCartas mazo, cartasHumano, cartasMaquina;
	tCartasPorAparecer restantes;
	ifstream deck;
	ofstream resultados;
	string result, part;
	float puntosHumano = 0, puntosMaquina = 0;

	inicializa(mazo);
	if (MazoAleatorio) {
		crearMazo(mazo);
	}
	else {
		deck = buscarArchivo();
		for (int i = TamMazo - 1; i >= 0; i--) {
			deck >> mazo.cartasMazo[i];
		}
		mostrarMazo(mazo);
	}
	
	rellenarCartasPorAparecer(restantes);
	modoDhumano(mazo, restantes, cartasHumano, puntosHumano);

	if (puntosHumano > SyM) {
		puntosMaquina = 0;
		cartasMaquina.cartasRobadas = 0;
	}
	else {
		modoDmaquina(mazo, restantes, puntosHumano, cartasMaquina, puntosMaquina);
	}

	part = to_string(partidasJugadas);
	result = "partida";
	result += part;
	result += ".txt";
	resultados.open(result);
	resultados << "Partida " << partidasJugadas << ":" << endl << "Ganador: ";

	if (determinaGanadorModoD(puntosHumano, puntosMaquina, cartasHumano.cartasRobadas, cartasMaquina.cartasRobadas) == 1) {
		cout << "�Has ganado!" << endl;
		resultados << "Jugador Humano" << endl;
	}
	else {
		cout << "La m�quina ha ganado." << endl;
		resultados << "Jugador Maquina" << endl;
	}
	resultados << "Puntuaci�n Humano: " << puntosHumano << "    Cartas Humano: ";
	for (int i = 0; i < cartasHumano.cartasRobadas; i++) {
		resultados << cartasHumano.cartasMazo[i] << " ";
	}
	resultados << endl << "Puntuaci�n Maquina: " << puntosMaquina << "    Cartas Maquina: ";
	for (int i = 0; i < cartasMaquina.cartasRobadas; i++) {
		resultados << cartasMaquina.cartasMazo[i] << " ";
	}

	resultados.close();
}
void inicializa(tConjuntoCartas & cartas) {
	cartas.cartasRobadas = 0;
}
void sacarCarta(tConjuntoCartas & cartas, int & carta) {
	int r = 1 + cartas.cartasRobadas;
	carta = cartas.cartasMazo[TamMazo - r];
	cartas.cartasRobadas++;
}
void annadirCarta(tConjuntoCartas & cartas, int carta) {
	int pos = cartas.cartasRobadas;
	cartas.cartasMazo[pos] = carta;
	cartas.cartasRobadas++;
}
void crearMazo(tConjuntoCartas & mazo) {
	int aux, pos;

	for (int i = 1; i <= 10; i++) {
		for (int j = (i - 1) * 4; j < i * 4; j++) {
			if (i < 8) {
				mazo.cartasMazo[j] = i;
			}
			else {
				mazo.cartasMazo[j] = i + 2;
			}
		}
	}
	if (MostrarMazo) {
		cout << endl << "Mazo sin barajar: ";
		for (int i = 0; i < TamMazo; i++) {
			cout << mazo.cartasMazo[i] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < TamMazo - 1; i++) {
		pos = aleatorio(0, 40);
		aux = mazo.cartasMazo[i];
		mazo.cartasMazo[i] = mazo.cartasMazo[pos];
		mazo.cartasMazo[pos] = aux;
	}
	if (MostrarMazo) {
		cout << "Mazo barajado: ";
		for (int i = 0; i < 40; i++) {
			cout << mazo.cartasMazo[i] << " ";
		}
		cout << endl;
	}
}
void modoDhumano(tConjuntoCartas & mazo, tCartasPorAparecer cartas, tConjuntoCartas & cartasHumano, float & puntos) {
	bool roba = true;
	int carta, decision;

	inicializa(cartasHumano);
	cout << endl << "Turno del jugador: " << endl << endl;
	robarModoD(mazo, cartas, cartasHumano, puntos);
	while (puntos <= SyM && roba) {
		cout << "  �Robas(1) o te plantas(2)? ";
		cin >> decision;

		while (decision < 1 || decision > 2 || cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Opci�n no v�lida. �Robas(1) o te plantas(2)? ";
			cin >> decision;
		}

		if (decision == 1) {
			if (MostrarMazo) {
				cout << endl;
			}
			robarModoD(mazo, cartas, cartasHumano, puntos);
		}
		else {
			roba = false;
		}
	}
	cout << endl;
}
void modoDmaquina(tConjuntoCartas & mazo, tCartasPorAparecer cartas, float puntosHumano, tConjuntoCartas & cartasMaquina, float & puntos) {
	int carta, robadasHumano;

	robadasHumano = mazo.cartasRobadas;
	inicializa(cartasMaquina);
	cout << endl << "Turno de la maquina: " << endl << endl;
	robarModoD(mazo, cartas, cartasMaquina, puntos);

	while (puntos < puntosHumano) {
		cout << "  (La m�quina decide robar carta)" << endl;
		if (MostrarMazo) {
			cout << endl;
		}
		robarModoD(mazo, cartas, cartasMaquina, puntos);
	}
	if (puntos == puntosHumano) {

		if (robadasHumano > cartasMaquina.cartasRobadas) {
			cout << "  (La m�quina deja de robar)";
		}
		else if (robadasHumano < cartasMaquina.cartasRobadas) {
			cout << "  (La m�quina decide robar carta)" << endl;
			if (MostrarMazo) {
				cout << endl;
			}
			robarModoD(mazo, cartas, cartasMaquina, puntos);
			cout << "  (La m�quina deja de robar)";
		}
		else if (esProbablePasarse(puntos, cartas)) {
			if (!MostrarMazo) {
				cout << setw(94) << right << "(La maquina no asume el riesgo)" << left << endl;
			}
			else {
				cout << "  (La maquina no asume el riesgo)" << endl << endl;
			}
		}
		else {
			if (!MostrarMazo) {
				cout << setw(91) << right << "(La maquina asume el riesgo)" << left << endl;
			}
			else {
				cout << "  (La maquina asume el riesgo)" << endl << endl;
			}
			
			robarModoD(mazo, cartas, cartasMaquina, puntos);
			cout << "  (La m�quina deja de robar)";
		}
	}
	else {
		cout << "  (La m�quina deja de robar)";
	}
	cout << endl;
}

int determinaGanadorModoD(float puntosJugador, float puntosMaquina, int robadasHumano, int robadasMaquina) {
	int ganador;

	cout << endl;
	if (puntosJugador > SyM) {
		cout << "Te has pasado.";
		ganador = 2;
	}
	else if (puntosMaquina > SyM) {
		cout << "La m�quina se ha pasado.";
		ganador = 1;
	}
	else if (puntosJugador > puntosMaquina) {
		cout << "La puntaci�n de la m�quina ha sido " << puntosMaquina << " y la tuya " << puntosJugador;
		ganador = 1;
	}
	else if (puntosJugador < puntosMaquina) {
		cout << "Tu puntuacion ha sido " << puntosJugador << " y la de la maquina " << puntosMaquina;
		ganador = 2;
	}
	else if (puntosJugador == puntosMaquina) {
		cout << "Ambas puntuaciones son " << puntosJugador;
		if (robadasHumano < robadasMaquina) {
			cout << ", pero t� has conseguido llegar a ella robando menos cartas. ";
			ganador = 1;
		}
		else if (robadasHumano > robadasMaquina) {
			cout << ", pero la m�quina ha conseguido llegar a ella robando menos cartas. ";
			ganador = 2;
		}
		else if (robadasHumano == robadasMaquina) {
			cout << " y ambos hab�is robado el mismo n�mero de cartas, pero el azar ha decido que...";
			ganador = aleatorio(1, 2);
		}
	}
	cout << endl;
	return ganador;
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
float valorPosicion(int posicion) {
	float valor;

	if (posicion == 0) {
		valor = 0.5;
	}
	else {
		valor = posicion;
	}
	return valor;
}

void robar(ifstream& file, float& puntuacion, int& carta) {
	file >> carta;
	cout << "	Carta: " << setw(2) << right << carta;
	puntuacion += valor(carta);
	cout << " - Puntuaci�n total: " << setw(3) << left << puntuacion;
}
void robarModoD(tConjuntoCartas & mazo, tCartasPorAparecer restantes, tConjuntoCartas & cartas, float & puntos){
	int carta;

	sacarCarta(mazo, carta);
	puntos += valor(carta);
	annadirCarta(cartas, carta);
	restantes[posicionArray(carta)]--;

	cout << "  Cartas robadas: ";

	for (int i = 0; i < cartas.cartasRobadas; i++) {
		cout << setw(2) << left << cartas.cartasMazo[i] << " ";
	}
	cout << setw(40 - 3 * cartas.cartasRobadas) << right << "Puntuaci�n total: " << setw(3) << puntos << left;
	mostrarMazo(mazo);
}

void rellenarCartasPorAparecer(tCartasPorAparecer cards) {
	
	cards[0] = 12;
	for (int i = 1; i <= Tam - 1; i++) {
		cards[i] = 4;
	}
}

void mostrarMazo(const tConjuntoCartas& mazo) {
	if (MostrarMazo) {
		cout << endl << "  [Mazo actual: ";
		for (int i = 0; i < TamMazo - mazo.cartasRobadas; i++) {
			cout << mazo.cartasMazo[i] << " ";
		}
		cout << "]" << endl << endl;
	}
}
