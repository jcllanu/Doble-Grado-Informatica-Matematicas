/*Juan Carlos Llamas Núñez y Adrián Sanjuán   Grupo: Doble Grado*/

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

const bool MostrarMazo = true;
const bool MazoAleatorio = true;
const bool MostrarTabla = true;
const int Palos = 4;
const int Figuras = 3;
const int NoFiguras = 7;
const int TamMazo = (Figuras + NoFiguras) * Palos;
const float SyM = 7.5;
const float ValorFigura = 0.5;
const int TamCartasPorAparecer = NoFiguras + 1;
//Parte Opcional
const float DesviacionTipica = 1.1;
const double PuntuacionArbitraria = 5;
const int CartasPosibles = 14;
const int PuntosPosibles = 15;
//
typedef int tCartasPorAparecer[TamCartasPorAparecer];
typedef int tCartasMazo[TamMazo];
typedef struct {
	tCartasMazo cartasMazo;
	int cartasRobadas;
} tConjuntoCartas;
//Parte Opcional
typedef struct {
	int plantado;
	float total;
} tPartidas;
typedef tPartidas tPosiblesPuntos[PuntosPosibles];
typedef tPosiblesPuntos tPosiblesCartas[CartasPosibles];
typedef double fila[PuntosPosibles];
//

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
void inicializa(tConjuntoCartas& cartas);// Inicializa cartas a la lista vacía. 
void sacarCarta(tConjuntoCartas& cartas, int & carta);//Elimina la última carta de la lista "cartas" y la devuelve en "carta".
void annadirCarta(tConjuntoCartas& cartas, int carta);//Añade la carta "carta" en el extremo derecho de la lista "cartas".
void crearMazo(tConjuntoCartas& mazo);//Rellena "mazo" con 40 cartas dispuestas de forma aleatoria.
void modoDhumano(tConjuntoCartas& mazo, tCartasPorAparecer	cartas, tConjuntoCartas& cartasHumano, float & puntos);/*Recibe el mazo, el array que contaviliza las cartas que 
quedan por salir, la puntuación del humano y la lista de cartas robadas por el humano. Modifia el mazo, las cartas que quedan por salir, la puntuación del humano y las cartas 
robadas por el humano.*/
void modoDmaquina(tConjuntoCartas& mazo, tCartasPorAparecer cartas, float puntosHumano, tConjuntoCartas& cartasMaquina, float& puntos);/*Recibe el mazo, el array que 
contaviliza las cartas que quedan por salir, la puntuación del humano y de la máquina y la lista de cartas robadas por el humano. Modifia el mazo, las cartas que quedan por salir,
la puntuación de la maquina y las cartas robadas por la máquina.*/

void escribirResultados(int partidasJugadas, float puntosHumano, float puntosMaquina, const tConjuntoCartas& cartasHumano, const tConjuntoCartas& cartasMaquina);/*Recibe las cartas 
robadas por el humano y la máquina y también su puntación. También recibe el número de pártia de la ejecución correspondiente. Es l encargada de decidir el ganador y escribir en un 
archivo de salida los resultados de la partida.*/
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

void robarModoD(tConjuntoCartas& mazo, tCartasPorAparecer restantes, tConjuntoCartas& cartas, float& puntos);/*Realiza todos los procedimientos necesarios para la acción de robar 
una carta en el modo D: extrae una carta de "mazo", la añade a la lista "cartas", actualiza la puntuación y modifica el array de cartas restantes. También escribe en pantalla las cartas 
robadas y la puntuación total*/
void rellenarCartasPorAparecer(tCartasPorAparecer cards);/*Recibe el array de las cartas que quedan por aparecer y lo inicializa: figuras(pos0) a 8 y de las posiciones 1 a la 7 a 4.*/

void mostrarMazo(const tConjuntoCartas& mazo);/*Muestra en pantalla el mazo en el estado actual*/



//Parte Opcional


void modoEcuerpo(int partidasJugadas, tPosiblesCartas& tabla);
void modoEhumano(tConjuntoCartas & mazo, tConjuntoCartas& cartasHumano, float& puntos);/*Recibe el mazo, la puntuación del humano y la lista de cartas robadas por el humano. 
Modifia el mazo, la puntuación del humano y las cartas robadas por el humano.*/
void modoEmaquina(tConjuntoCartas& mazo, tConjuntoCartas& cartasMaquina, float& puntos, const tPosiblesCartas& tabla);/*Recibe el mazo y la tabla con las decisiones del humano.
Permite realizar el turno de juego a la máquina. Actualiza el mazo, las cartas de la máquina, los puntos de la máquina  */
void datos(tPosiblesCartas& tabla, tConjuntoCartas cartasHumano);/*Al finalizar cada partida esta función actualiza la tabla con las decisiones del humano. Recibe la tabla y 
las cartas que hay ido robando el humano*/
float estimacionPuntuacionHumano(const tPosiblesCartas& tabla, int robadas);/*Esta función recibe la tabla con las decisiones del humano y las cartas que ha robado el humano y estima la puntuación
que tiene el humano en base a la experiencia previa recogida en la tabla de decisiones*/

float desviacionTipica(fila xi, fila fi);/*Función que dados un tabla de dos filas xi (posibles puntuaciones con las que plantarse, e.d. 0.5, 1, 1.5 ... 7, 7.5) y fi (veces que el humano 
se ha plantado con dicha puntuacion), devuelve el resultado de aplicar la función matemática desviación típica. Esta función es f(xi,fi)=[[sumatorio((xi)^2 *fi)]/[sumatorio(fi)] - (media)^2]^0.5.
Creemos que es una herramienta útil para evaluar lo consistente o no que es el jugador humano respecto a las puntuaciones con las que se planta. Ejemplo 1: Si el jugador se planta algunas veces con 
puntuaciones muy bajas (0.5, 1, 1.5) y otras veces con puntuaciones muy altas(6, 6.5, 7), aunque la media de las puntuaciones entorno a las cuales se planta esté entorno a 4, la desviación típica 
será muy grande (del orden de 3).Ejemplo 2: Si el jugador se planta siempre con puntuaciones entre 4.5 y 6, la media saldrá aproximadamente 5 y la desviación típica tomará valores inferiores a 1.
Hemos considerado que un jugador es inconsistente con sus decisiones cuando la desviación típica es mayor que 1.1 (valor definido como la constante "DesviacionTipica".*/
float mediaAritmética(fila xi, fila fi);/*Función que dados un tabla de dos filas xi (posibles puntuaciones con las que plantarse, e.d. 0.5, 1, 1.5 ... 7, 7.5) y fi (veces que el humano 
se ha plantado con dicha puntuacion), devuelve el resultado de aplicar la función matemática media aritmética. Esta funcion es f(xi, fi)= [sumatorio( fi*xi)]/[sumatorio fi]*/
float sumatorioFi(fila fi);/*Devuelve el resultado de sumar todas las posiciones del array fi*/
void robarmodoE(tConjuntoCartas& mazo, tConjuntoCartas& cartasHumano, float& puntos);/*Realiza todos los procedimientos necesarios para la acción de robar 
una carta en el modo E: extrae una carta de "mazo", la añade a la lista "cartas" y actualiza la puntuación. También escribe en pantalla las cartas 
robadas y la puntuación total*/
void rellenarTabla(tPosiblesCartas& tabla);/*Rellena una tabla de 14 filas y 15 columnas con "0/0". En cada posición de la tabla hay dos datos. El primero indica las VECES QUE SE HA PLANTADO con la
puntuación asociada a la columna en la que está (en la columna 0, 0.5; en la columna 1, 1; en la columna 2, 1.5 ..... en la columna 15, 7.5), tras haber robado el numero de cartas asociado a la fila
donde está (en la fila 0, 1 carta robada; en la fila 1, 2 cartas robadas...). El segundo dato indica el total de VECES QUE HA PODIDO PLANTARSE.*/
void rellenarXi(fila& xi);/*Rellena el array xi con las posibles puntuaciones con las que el humano se puede plantar (en la 0, 0.5; en la 1, 1, en la 2, 1.5; ..... en la 15, 7.5)*/
void rellenarFi(fila& fi, const tPosiblesCartas& tabla);/*Rellena el array fi con la frecuencia (las veces) con la que se ha plantado el humano en cada una de las posibles  
puntuaciones con las que el humano se decide plantarse*/
float puntuacionMediaPorCartaSacada();/*Devuelve el valor de 2.95 a quien la invoque. Este valor es la puntuación media por cada carta robada en un mazo de 40 cartas con 4 palos y 3 figuras y 7 no 
figuras por palo. Cunado el jugador no es consistente con sus decisiones es el valor que se utilizará para estimar la puntuación de cada carta robada */
int posicionPosiblesPuntos(float pts);/*Asigna a cada puntuación su posicion de array correspondiente, e.d. al 0.5, 0; al 1, 1; al 1.5, 2 ... al 7.5, 14*/





int main() {
	int modoJuego;
	int partidasJugadas = 0;
	tPosiblesCartas tabla;
	
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
	if (MostrarTabla) {
		cout << endl << "    (Puntuaciones con las que te puedes plantar)" << endl;
		cout << "     0.5  1  1.5  2  2.5  3  3.5  4  4.5  5  5.5  6  6.5  7  7.5 " << endl;
		for (int i = 0; i < CartasPosibles; i++) {
			cout << endl <<setw(2)<< i+1 << "   ";
			for (int j = 0; j < PuntosPosibles; j++) {
				cout << tabla[i][j].plantado << "/" << tabla[i][j].total << " ";
			}
		}
	}
	cout << endl << "^" << endl << "(Cartas que has podido robar)" << endl;
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

	for (int i = 0; i < TamCartasPorAparecer; i++) {

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
		cout << "La puntación de la máquina ha sido " << puntosMaquina << " puntos y la tuya " << puntosJugador << " puntos.";
		ganador = 1;
	}
	else if (puntosJugador < puntosMaquina) {
		cout << "Tu puntuacion ha sido " << puntosJugador << " puntos y la de la maquina " << puntosMaquina << " puntos.";
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
	rellenarCartasPorAparecer(restantes);
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
void inicializa(tConjuntoCartas& cartas) {
	cartas.cartasRobadas = 0;
}
void sacarCarta(tConjuntoCartas& cartas, int & carta) {
	int r = 1 + cartas.cartasRobadas;
	carta = cartas.cartasMazo[TamMazo - r];
	cartas.cartasRobadas++;
}
void annadirCarta(tConjuntoCartas& cartas, int carta) {

	cartas.cartasMazo[cartas.cartasRobadas] = carta;
	cartas.cartasRobadas++;
}
void crearMazo(tConjuntoCartas& mazo) {
	int aux, pos;

	for (int i = 1; i <= Figuras + NoFiguras; i++) {
		for (int j = (i - 1) * Palos; j < i * Palos; j++) {
			if (i <= NoFiguras) {
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
void modoDhumano(tConjuntoCartas& mazo, tCartasPorAparecer cartas, tConjuntoCartas& cartasHumano, float& puntos) {
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
void modoDmaquina(tConjuntoCartas& mazo, tCartasPorAparecer cartas, float puntosHumano, tConjuntoCartas& cartasMaquina, float& puntos) {
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

void escribirResultados(int partidasJugadas, float puntosHumano, float puntosMaquina, const tConjuntoCartas& cartasHumano, const tConjuntoCartas& cartasMaquina) {
	ofstream resultados;
	string partida, result;

	partida = to_string(partidasJugadas);
	result = "partida" + partida + ".txt";
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
void robarModoD(tConjuntoCartas& mazo, tCartasPorAparecer restantes, tConjuntoCartas& cartas, float& puntos){
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
	for (int i = 1; i <= TamCartasPorAparecer - 1; i++) {
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

//Parte Opcional
void modoEcuerpo(int partidasJugadas, tPosiblesCartas& tabla) {
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
void modoEhumano(tConjuntoCartas& mazo, tConjuntoCartas& cartasHumano, float& puntos) {
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
void modoEmaquina(tConjuntoCartas& mazo, tConjuntoCartas& cartasMaquina, float& puntos, const tPosiblesCartas& tabla) {
	int carta, robadasHumano;
	fila fi, xi;

	inicializa(cartasMaquina);
	robadasHumano = mazo.cartasRobadas;
	cout << endl << "Turno de la maquina: " << endl << endl;
	rellenarXi(xi);
	rellenarFi(fi, tabla);

	cout << endl << "Desviacion típica: " << desviacionTipica(xi, fi) << endl;
	if (desviacionTipica(xi, fi) < DesviacionTipica) {		//Jugador consistente

		cout << "Estimación: ";
		if (estimacionPuntuacionHumano(tabla, robadasHumano) > SyM) {
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
	else {		//Jugador inconsistente
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
void datos(tPosiblesCartas& tabla, tConjuntoCartas cartasHumano) {
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
float estimacionPuntuacionHumano(const tPosiblesCartas& tabla, int robadas) {
	double ponderacion = 0, estimacion = 0, final;
	fila xi;

	rellenarXi(xi);

	for (int i = 0; i < PuntosPosibles; i++) {//(*1)
		if (tabla[robadas - 1][i].total != 0) {
			ponderacion += tabla[robadas - 1][i].plantado / tabla[robadas - 1][i].total;
		}
	}
	for (int i = 0; i < PuntosPosibles; i++) {//(*2)
		if (tabla[robadas - 1][i].total != 0) {
			estimacion += (tabla[robadas - 1][i].plantado / tabla[robadas - 1][i].total)*xi[i];
		}
	}
	if (estimacion == 0) { //e.d. no se ha plantado nunca con "robadas" cartas
		final = robadas * puntuacionMediaPorCartaSacada();//no tenemos ningún dato así que suponemos que que su puntuación será el numero de cartas que haya robado por 2.95
	}
	else if (ponderacion != 0) {//e.d. ha tenido alguna oportunidad de plantarse con "robadas" cartas.

		final = estimacion / ponderacion;/*estimamos que la puntuación con la que se ha plantado ha sido la media ponderada de las puntuaciones con las que se ha plantado en 
											el pasado cunado se ha plantado con "robadas " cartas. Se le da más peso a las puntuaciónes con las que el jugador ha sido más consistente al plantarse.
											Por ejemplo: Imaginemos que el humano se ha plantado 3 veces con 2 cartas. Cuando estas sumaban 6 se ha plantado las dos veces de dos posibles y cuando 
											sumaban 5 se ha plantado 1 vez de dos posibles. En este caso se tendrá que por (*1) ponderación valdrá 1/2 + 2/2 = 1.5 y por (*2) la variable estimacion
											valdrá (1/2)*5 +(2/2)*6 = 8.5. Por tanto la estimación final será 8.5/1.5 = 5.66666. Como habíamos anunciado se le dá más peso a las puntuaciones en las 
											que el humano ha sido más consistente al plantarse.*/
	}
	else {//e.d. no ha tenido alguna oportunidad de plantarse con "robadas" cartas.
		final = robadas * puntuacionMediaPorCartaSacada();//no tenemos ningún dato así que suponemos que que su puntuación será el numero de cartas que haya robado por 2.95
	}

	return final;

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
void rellenarFi(fila& fi, const tPosiblesCartas& tabla) {
	for (int i = 0; i < PuntosPosibles; i++) {
		fi[i] = 0;
		for (int j = 0; j < CartasPosibles; j++) {
			fi[i] += tabla[j][i].plantado;
		}
	}
}
void rellenarTabla(tPosiblesCartas& tabla) {
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
int posicionPosiblesPuntos(float pts) {
	int pos;
	pos = 2 * pts - 1;
	return pos;
}