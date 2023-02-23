#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

const bool MostrarMazo = false;
const bool MazoAleatorio = true;
const int Tam = 8;
const float DesviacionTipica = 1.1;
const float SyM = 7.5;
const float ValorFigura = 0.5;
const int Palos = 4;
const int Figuras = 3;
const int NoFiguras = 7;
const int TamMazo = (Figuras+ NoFiguras)*Palos;
const double PuntuacionArbitraria = 5;
typedef int tCartasPorAparecer[Tam];
typedef int tCartasMazo[TamMazo];
typedef struct {
	tCartasMazo cartasMazo;
	int cartasRobadas;
} tConjuntoCartas;

int menu();//Devuelve un entero en el rango [0,5] dependiendo del modo de juego elegido.

void modoAcuerpo();//Todas las funciones modoXcuerpo son procedimientos que se incluyen únicamente para aliviar la carga de código del main correspondiente al modoX.
float modoA(ifstream& file, int numCartas);//Recibe el mazo  y el número de cartas que se deben robar. Devuelve la puntuación obtenida. 

void modoBcuerpo();
float modoBhumano(ifstream& file, int numCartas);//Recibe el mazo  y el número máximo de cartas que se pueden robar. Devuelve la puntuación obtenida por el humano.
float modoBmaquina(ifstream& file, int numCartas, float puntosHumano);/*Recibe el mazo y el número máximo de cartas que se pueden robar. También recibe la puntuación 
del jugador humano. Devuelve la puntuación obtenida por la máquina, que robará si su puntuación es menor o igual a la del humano.*/

void modoCcuerpo();
void modoChumano(ifstream& file, tCartasPorAparecer cartas, float& puntos);/*Recibe el mazo, el array que contaviliza las cartas que quedan por salir y la puntuación 
del humano. Modifia tanto el array de las cartas que quedan por salir y como la puntuación del humano.*/
void modoCmaquina(ifstream& file, tCartasPorAparecer cartas, float puntosHumano, float& puntos);/*Recibe el mazo, el array que contaviliza las cartas que quedan por 
salir y las puntuaciones del humano y la máquina. Modifia tanto el array de las cartas que quedan por salir como la puntuación de la máqiuna.*/
bool esProbablePasarse(float puntosMaquina, const tCartasPorAparecer cartas);/*Recibe la puntuación de la máquina y el array con las cartas por aparecer. Devuelve true 
si la probabilidad de pasarse al robar una carta más excede 0.5 y false en caso contrario.*/

int determinaGanador(float puntosJugador, float puntosMaquina);//Recibe la puntuación del humano y de la máquina. Devuelve un 2 si gana la máquina y un 1 si gana el humano.

void modoDcuerpo(int partidasJugadas);
void inicializa(tConjuntoCartas & cartas);// Inicializa cartas a la lista vacía. 
void sacarCarta(tConjuntoCartas & cartas, int & carta);//Elimina la última carta de la lista "cartas" y la devuelve en "carta".
void annadirCarta(tConjuntoCartas & cartas, int carta);//Añade la carta "carta" en el extremo derecho de la lista "cartas".
void crearMazo(tConjuntoCartas & mazo);//Rellena "mazo" con 40 cartas dispuestas de forma aleatoria.
void modoDhumano(tConjuntoCartas & mazo, tCartasPorAparecer	cartas, tConjuntoCartas & cartasHumano, float & puntos);/*Recibe el mazo, el array que contaviliza las cartas que 
quedan por salir, la puntuación del humano y la lista de cartas robadas por el humano. Modifia el mazo, las cartas que quedan por salir, la puntuación del humano y las cartas 
robadas por el humano.*/
void modoDmaquina(tConjuntoCartas & mazo, tCartasPorAparecer cartas, float puntosHumano, tConjuntoCartas & cartasMaquina, float & puntos);/*Recibe el mazo, el array que 
contaviliza las cartas que quedan por salir, la puntuación del humano y de la máquina y la lista de cartas robadas por el humano. Modifia el mazo, las cartas que quedan por salir,
la puntuación de la maquina y las cartas robadas por la máquina.*/

int determinaGanadorModoD(float puntosJugador, float puntosMaquina, int robadasHumano, int robadasMaquina);/*Recibe la puntuación del humano y de la máquina y el numero de cartas 
que han robado ambos. Devuelve un 2 si gana la máquina y un 1 si gana el humano. (Como en el modo D para decidir el ganador no es suficiente con recibir las puntuaciones del jugador
y de la máquina, y al ser "determinaGanador" una función exigida con unos determinados parámetros, hemos preferido crear una función específica antes que añadirle otros parámetros 
"determinaGanador" */

ifstream buscarArchivo();//No recibe nada y se encarga de buscar y abrir el archivo del que se van a leer las cartas.

int aleatorio(int limitinf, int intervalo);//Devuelve un número aleatorio en el intervalo [limitinf, limitinf+intervalo).

float valor(int card);//Recibe una carta (cuyo rango de valores es [1,7]U[10,12]) y devuelve el valor o puntuación de la carta (0.5 si es una figura y el mismo que el de la carta en caso contrario)
float valorPosicion(int posicion);/*Relaciona cada posición del array con el valor de la carta que lleva asociada(0->0.5, 1->1, 2->2,...,7->7). 
Recibe la posición y devuelve el valor de las cartas de esa posición.*/
int posicionArray(int carta);//Recibe el entero correspondiente a cada una de las cartas y devuelve la posición que esté tipo de carta ocupa en el array (figura->0, 1->1, 2->2,...,7->7).

void robar(ifstream& file, float& puntuacion, int& carta);/*Recibe el mazo, la puntuacion de cualquiera de los dos jugadores y la carta. Modifica las variables de puntuacion y cartas y
escribe en pantalla la carta robada y la puntuación total que se lleva en ese momento*/

void robarModoD(tConjuntoCartas & mazo, tCartasPorAparecer restantes, tConjuntoCartas & cartas, float & puntos);/*Realiza todos los procedimientos necesarios para la acción de robar 
una carta en el modo D: extrae una carta de "mazo", la añade a la lista "cartas", actualiza la puntuación y modifica el array de cartas restantes. También escribe en pantalla las cartas 
robadas y la puntuación total*/
void rellenarCartasPorAparecer(tCartasPorAparecer cards);/*Recibe el array de las cartas que quedan por aparecer y lo inicializa: figuras(pos0) a 8 y de las posiciones 1 a la 7 a 4.*/

void mostrarMazo(const tConjuntoCartas& mazo);/*Muestra en pantalla el mazo en el estado actual*/

void escribirResultados(int partidasJugadas, float puntosHumano, float puntosMaquina, tConjuntoCartas cartasHumano, tConjuntoCartas cartasMaquina);

//
const int CartasPosibles = 14;
const int PuntosPosibles = 15;

typedef struct {
	int plantado;
	float total;
} partidas;

typedef partidas posiblesPuntos[PuntosPosibles];

typedef posiblesPuntos posiblesCartas[CartasPosibles];

void modoEcuerpo(int partidasJugadas, posiblesCartas & tabla);
void modoEhumano(tConjuntoCartas & mazo, tConjuntoCartas & cartasHumano, float & puntos);
void datos(posiblesCartas & tabla, tConjuntoCartas cartasHumano);
int posicionPosiblesPuntos(float pts);
void modoEmaquina(tConjuntoCartas & mazo, tConjuntoCartas& cartasMaquina, float& puntos, const posiblesCartas& tabla);
//

typedef double fila[PuntosPosibles];
float desviacionTipica(fila xi, fila fi);
float mediaAritmética(fila xi, fila fi);
float sumatorioFi(fila fi);
void robarmodoE(tConjuntoCartas& mazo, tConjuntoCartas& cartasHumano, float& puntos);
float estimacionPuntuacionHumano(const posiblesCartas& tabla, int robadas);

void rellenarXi(fila& xi);
void rellenarFi(fila& fi, const posiblesCartas& tabla);
float puntuacionMediaPorCartaSacada();
void rellenarTabla(posiblesCartas& tabla);





int main() {
	int modoJuego;
	int partidasJugadas = 0;
	//
	posiblesCartas tabla;
	//
	system("chcp 1252");
	srand(time(NULL));

	modoJuego = menu();
	rellenarTabla(tabla);
	
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
		case 5:
		{
			modoEcuerpo(partidasJugadas, tabla);
		}
		break;
		}

		modoJuego = menu();
	}
	//
	for (int i = 0; i < CartasPosibles; i++) {
		cout << endl;
		for (int j = 0; j < PuntosPosibles; j++) {
			cout << tabla[i][j].plantado << "/" << tabla[i][j].total << " ";
		}
	}
	//
	cout << endl;
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
		cout << "Opción no válida. Escribe el modo en el que quieras jugar (1/2/3/4/5) o finaliza el programa(0): ";
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
		cout << endl << endl << "Cartas de la máquina: ";
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
	int carta, decision, cartasRobadas = 1;
	float puntuacion = 0;

	cout << endl << "Cartas del jugador: " << endl;
	robar(file, puntuacion, carta);

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

	cout << endl << endl << "Cartas de la máquina: " << endl;
	robar(file, puntuacion, carta);

	while (cartasRobadas < numCartas && !superarHumano) {

		if (puntuacion <= puntosHumano) {
			cartasRobadas++;
			cout << "  (La máquina decide robar carta)" << endl;
			robar(file, puntuacion, carta);
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
		cout << "¡Has ganado!" << endl;
	}
	else {
		cout << "La máquina ha ganado." << endl;
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
		cout << "  ¿Robas(1) o te plantas(2)? ";
		cin >> decision;

		while (decision < 1 || decision > 2 || cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Opción no válida. ¿Robas(1) o te plantas(2)? ";
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
		cout << "  (La máquina decide robar carta)" << endl;
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
		cout << "  (La máquina deja de robar)";
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
		cout << "La máquina se ha pasado.";
		ganador = 1;
	}
	else if (puntosJugador > puntosMaquina) {
		cout << "La puntación de la máquina ha sido " << puntosMaquina << " y la tuya " << puntosJugador;
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

	escribirResultados(partidasJugadas, puntosHumano, puntosMaquina, cartasHumano, cartasMaquina);
}
void escribirResultados(int partidasJugadas, float puntosHumano, float puntosMaquina, tConjuntoCartas cartasHumano, tConjuntoCartas cartasMaquina) {
	ofstream resultados;
	string part, result;

	part = to_string(partidasJugadas);
	result = "partida" + part + ".txt";
	resultados.open(result);
	resultados << "Partida " << partidasJugadas << ":" << endl << "Ganador: ";

	if (determinaGanadorModoD(puntosHumano, puntosMaquina, cartasHumano.cartasRobadas, cartasMaquina.cartasRobadas) == 1) {
		cout << "¡Has ganado!" << endl;
		resultados << "Jugador Humano" << endl;
	}
	else {
		cout << "La máquina ha ganado." << endl;
		resultados << "Jugador Maquina" << endl;
	}
	resultados << "Puntuación Humano: " << puntosHumano << "    Cartas Humano: ";
	for (int i = 0; i < cartasHumano.cartasRobadas; i++) {
		resultados << cartasHumano.cartasMazo[i] << " ";
	}
	resultados << endl << "Puntuación Maquina: " << puntosMaquina << "    Cartas Maquina: ";
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
		for (int j = (i - 1) * Palos; j < i * Palos; j++) {
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
		pos = aleatorio(0, TamMazo);
		aux = mazo.cartasMazo[i];
		mazo.cartasMazo[i] = mazo.cartasMazo[pos];
		mazo.cartasMazo[pos] = aux;
	}
	if (MostrarMazo) {
		cout << "Mazo barajado: ";
		for (int i = 0; i < TamMazo; i++) {
			cout << mazo.cartasMazo[i] << " ";
		}
		cout << endl;
	}
}
void modoDhumano(tConjuntoCartas & mazo, tCartasPorAparecer cartas, tConjuntoCartas & cartasHumano, float & puntos) {
	bool roba = true;
	int decision;

	inicializa(cartasHumano);
	cout << endl << "Turno del jugador: " << endl << endl;
	robarModoD(mazo, cartas, cartasHumano, puntos);
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
	int  robadasHumano;

	robadasHumano = mazo.cartasRobadas;
	inicializa(cartasMaquina);
	cout << endl << "Turno de la maquina: " << endl << endl;
	robarModoD(mazo, cartas, cartasMaquina, puntos);

	while (puntos < puntosHumano) {
		cout << "  (La máquina decide robar carta)" << endl;
		if (MostrarMazo) {
			cout << endl;
		}
		robarModoD(mazo, cartas, cartasMaquina, puntos);
	}
	if (puntos == puntosHumano) {

		if (robadasHumano > cartasMaquina.cartasRobadas) {
			cout << "  (La máquina deja de robar)";
		}
		else if (robadasHumano < cartasMaquina.cartasRobadas) {
			cout << "  (La máquina decide robar carta)" << endl;
			if (MostrarMazo) {
				cout << endl;
			}
			robarModoD(mazo, cartas, cartasMaquina, puntos);
			cout << "  (La máquina deja de robar)";
		}
		else {
			if (esProbablePasarse(puntos, cartas)) {
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
				cout << "  (La máquina deja de robar)";
			}
		}
	}
	else {
		cout << "  (La máquina deja de robar)";
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
		cout << "La máquina se ha pasado.";
		ganador = 1;
	}
	else if (puntosJugador > puntosMaquina) {
		cout << "La puntación de la máquina ha sido " << puntosMaquina << " y la tuya " << puntosJugador;
		ganador = 1;
	}
	else if (puntosJugador < puntosMaquina) {
		cout << "Tu puntuacion ha sido " << puntosJugador << " y la de la maquina " << puntosMaquina;
		ganador = 2;
	}
	else if (puntosJugador == puntosMaquina) {
		cout << "Ambas puntuaciones son " << puntosJugador;
		if (robadasHumano < robadasMaquina) {
			cout << ", pero tú has conseguido llegar a ella robando menos cartas. ";
			ganador = 1;
		}
		else if (robadasHumano > robadasMaquina) {
			cout << ", pero la máquina ha conseguido llegar a ella robando menos cartas. ";
			ganador = 2;
		}
		else if (robadasHumano == robadasMaquina) {
			cout << " y ambos habéis robado el mismo número de cartas, pero el azar ha decido que...";
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

	while (!baraja.is_open()) {

		cout << "ERROR: No se ha encontrado el archivo" << endl;
		cout << "Introduce el nombre del archivo donde tengas la baraja: ";
		cin >> nombreArchivo;
		baraja.open(nombreArchivo);
	}
	return baraja;
}

int aleatorio(int limitinf, int intervalo) {
	int final = limitinf + rand() % intervalo;

	return final;
}

float valor(int card) {
	float puntos;

	if (card > NoFiguras) {
		puntos = ValorFigura;
	}
	else {
		puntos = card;
	}

	return puntos;
}
int posicionArray(int carta) {
	int posicion;

	if (carta > NoFiguras) {
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
		valor = ValorFigura;
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
	cout << " - Puntuación total: " << setw(3) << left << puntuacion;
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
	cout << setw(40 - 3 * cartas.cartasRobadas) << right << "Puntuación total: " << setw(3) << puntos << left;
	mostrarMazo(mazo);
}

void rellenarCartasPorAparecer(tCartasPorAparecer cards) {
	
	cards[0] = Palos*Figuras;
	for (int i = 1; i <= Tam - 1; i++) {
		cards[i] = Palos;
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

//
void modoEcuerpo(int partidasJugadas, posiblesCartas& tabla) {
	tConjuntoCartas mazo, cartasHumano, cartasMaquina;
	ifstream deck;
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
	modoEhumano(mazo, cartasHumano, puntosHumano);

	if (puntosHumano > SyM) {
		puntosMaquina = 0;
		cartasMaquina.cartasRobadas = 0;
	}
	else {
		modoEmaquina(mazo, cartasMaquina, puntosMaquina, tabla);
	}
	if (determinaGanador(puntosHumano, puntosMaquina) == 1) {
		cout << "¡Has ganado!" << endl;
	}
	else {
		cout << "La máquina ha ganado." << endl;
	}
	datos(tabla, cartasHumano);
}

void modoEhumano(tConjuntoCartas & mazo, tConjuntoCartas & cartasHumano, float& puntos) {
	bool roba = true;
	int decision;

	inicializa(cartasHumano);
	cout << endl << "Turno del jugador: " << endl << endl;
	robarmodoE( mazo, cartasHumano, puntos);

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
			if (MostrarMazo) {
				cout << endl;
			}
			robarmodoE(mazo, cartasHumano, puntos);
		}
		else {
			roba = false;
		}
	}	
	cout << endl;
}

void datos(posiblesCartas & tabla, tConjuntoCartas cartasHumano) {
	float pts = 0;
	for (int i = 0; i < cartasHumano.cartasRobadas; i++) {
		pts += valor(cartasHumano.cartasMazo[i]);
		if (i == cartasHumano.cartasRobadas - 1 && pts <= SyM) {
			tabla[i][posicionPosiblesPuntos(pts)].plantado++;
			tabla[i][posicionPosiblesPuntos(pts)].total++;
		}
		else if (pts<=SyM) {
			tabla[i][posicionPosiblesPuntos(pts)].total++;
		}
	}
}

int posicionPosiblesPuntos(float pts) {
	int pos;
	pos = 2*pts - 1;
	return pos;
}

void modoEmaquina(tConjuntoCartas & mazo, tConjuntoCartas& cartasMaquina, float& puntos, const posiblesCartas& tabla) {
	int carta, robadasHumano;
	fila fi, xi;

	inicializa(cartasMaquina);
	robadasHumano = mazo.cartasRobadas;
	cout << endl << "Turno de la maquina: " << endl << endl;
	rellenarXi(xi);
	rellenarFi(fi,tabla);
	
	cout << endl << "Desviacion típica: " << desviacionTipica(xi, fi) << endl;
	if (desviacionTipica(xi, fi) < DesviacionTipica) {		//Jugador consistente

		cout << "Estimación: ";
		if (estimacionPuntuacionHumano(tabla, robadasHumano)>SyM) {
			cout << estimacionPuntuacionHumano(tabla, robadasHumano) << " puntos. La estimacion no es real por lo que la máquina se plantará al alcanzar la puntuación arbitraria de " << PuntuacionArbitraria << " puntos." << endl << endl;
			
			while (puntos < PuntuacionArbitraria) {
				
				robarmodoE(mazo, cartasMaquina, puntos);
				if (puntos < PuntuacionArbitraria) {
					cout << "  (La máquina decide robar carta)" << endl;
				}
				else {
					cout << "  (La máquina deja de robar)" << endl;
				}
			}
		}
		else {
			cout << estimacionPuntuacionHumano(tabla, robadasHumano) << " puntos." << endl << endl;

			while (puntos < estimacionPuntuacionHumano(tabla, robadasHumano)) {

				robarmodoE(mazo, cartasMaquina, puntos);
				if (puntos < estimacionPuntuacionHumano(tabla, robadasHumano)) {
					cout << "  (La máquina decide robar carta)" << endl;
				}
				else {
					cout << "  (La máquina deja de robar)" << endl;
				}
			}	
		}
	}
	else {
		cout << "Estimación: " << robadasHumano * puntuacionMediaPorCartaSacada() << " puntos.";

		if (robadasHumano * puntuacionMediaPorCartaSacada() > SyM) {

			cout << " La estimacion no es real por lo que la máquina se plantará al alcanzar la puntuación arbitraria de " << PuntuacionArbitraria << " puntos." << endl << endl;

			while (puntos < PuntuacionArbitraria) {
				robarmodoE(mazo, cartasMaquina, puntos);
				if (puntos < PuntuacionArbitraria) {
					cout << "  (La máquina decide robar carta)" << endl;
				}
				else {
					cout << "  (La máquina deja de robar)" << endl;
				}
			}
		}
		else {
			cout << endl << endl;
			while (puntos < robadasHumano*puntuacionMediaPorCartaSacada()) {
				robarmodoE(mazo, cartasMaquina, puntos);
				if (puntos < robadasHumano*puntuacionMediaPorCartaSacada()) {
					cout << "  (La máquina decide robar carta)" << endl;
				}
				else {
					cout << "  (La máquina deja de robar)" << endl;
				}
			}
		
		}
	}
}
float desviacionTipica(fila xi, fila fi) {
	float sumatXi2Fi = 0, desviacionTipica;

	for (int i = 0; i < PuntosPosibles; i++) {
		sumatXi2Fi += pow(xi[i], 2)*fi[i];
	}
	if (sumatorioFi(fi) != 0) {
		desviacionTipica = sqrt(sumatXi2Fi / sumatorioFi(fi) - pow(mediaAritmética(xi, fi), 2));
	}
	else {
		desviacionTipica = DesviacionTipica;
	}
	return desviacionTipica;
}
float mediaAritmética(fila xi, fila fi) {
	float sumatXiFi = 0;

	for (int i = 0; i < PuntosPosibles; i++) {
		sumatXiFi += xi[i] * fi[i];
	}

	return sumatXiFi / sumatorioFi(fi);
}
float sumatorioFi(fila fi) {
	float sumatFi = 0;

	for (int i = 0; i < PuntosPosibles; i++) {
		sumatFi += fi[i];
	}
	return sumatFi;
}
float estimacionPuntuacionHumano(const posiblesCartas& tabla, int robadas) {
	double ponderacion = 0, estimacion = 0, final;
	fila xi;

	rellenarXi(xi);

	for (int i = 0; i < PuntosPosibles; i++) {
		if (tabla[robadas-1][i].total != 0) {
			ponderacion += tabla[robadas-1][i].plantado / tabla[robadas-1][i].total;
		}
	}
	for (int i = 0; i < PuntosPosibles; i++) {
		if (tabla[robadas - 1][i].total != 0) {
			estimacion += (tabla[robadas - 1][i].plantado / tabla[robadas - 1][i].total)*xi[i];
		}
	}
	if (estimacion == 0) {
		final = robadas * puntuacionMediaPorCartaSacada();
	}
	else if (ponderacion != 0) {
		final = estimacion / ponderacion;
	}
	else {
		final = robadas * puntuacionMediaPorCartaSacada();
	}
	
	return final;

}
void robarmodoE(tConjuntoCartas& mazo, tConjuntoCartas& cartasHumano, float& puntos) {
	int carta;

	sacarCarta(mazo, carta);
	puntos += valor(carta);
	annadirCarta(cartasHumano, carta);

	cout << "  Cartas robadas: ";

	for (int i = 0; i < cartasHumano.cartasRobadas; i++) {
		cout << setw(2) << left << cartasHumano.cartasMazo[i] << " ";
	}
	cout << setw(40 - 3 * cartasHumano.cartasRobadas) << right << "Puntuación total: " << setw(3) << puntos << left;
	mostrarMazo(mazo);
}
void rellenarXi(fila& xi) {
	for (int i = 0; i < PuntosPosibles; i++) {
		xi[i] = 0.5*(i + 1);
	}
}
void rellenarFi(fila& fi, const posiblesCartas& tabla) {
	for (int i = 0; i < PuntosPosibles; i++) {
		fi[i] = 0;
		for (int j = 0; j < CartasPosibles; j++) {
			fi[i] += tabla[j][i].plantado;
		}
	}
}
void rellenarTabla(posiblesCartas& tabla) {
	for (int i = 0; i < CartasPosibles; i++) {
		for (int j = 0; j < PuntosPosibles; j++) {
			tabla[i][j].plantado = 0;
			tabla[i][j].total = 0;
		}
	}
}
float puntuacionMediaPorCartaSacada() {
	float final = 0;
	for (int i = 1; i <= NoFiguras; i++) {
		final += i;
	}
	for (int i = 1; i <= Figuras; i++) {
		final += ValorFigura;
	}
	final = final / (Figuras + NoFiguras);
	return final;
}
