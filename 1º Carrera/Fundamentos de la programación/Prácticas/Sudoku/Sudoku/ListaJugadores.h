#pragma once
#include"Jugador.h"

const int MAX_JUGADORES = 10;
const int DIM_INI = 5;
const string LISTAJ = "listaJugadores.txt";


typedef tJugadorPtr* tJugadorPtrPtr;

typedef struct {
	tJugadorPtrPtr listaPtr;
	int contador;
	int maximo;
}tListaJugadores;

void creaListaVacia(tListaJugadores & lista);/*Inicializa lista a una lista vac�a de tama�o DIM_INI */
bool cargar(tListaJugadores & lista);/*Incluye en lista el contenido del archivo listaJugadores.txt y devuelve true si la operaci�n se ha podido realizar*/
void mostrar(const tListaJugadores & lista);/*Muestra por pantalla el contenido de la lista de jugadores dada en orden*/
bool guardar(const tListaJugadores & lista);/*Guarda en el archivo listaJugadores.txt el contenido de la lista respetando el mismo formato que el de lectura y devuelve true si se ha podido realizar la operaci�n*/
void puntuarJugador(tListaJugadores & lista, int puntos);/*Tras pedir un identificador verifica si este se encuntra o no en la lista. Si se encuentra en lista se le suma puntos a su puntuaci�n. Si no se encuentra
														 en la lista se le a�ade (posiblemente haya que ampliar la lista) y se inicializa su puntaci�n con puntos.*/
bool buscar(const tListaJugadores & lista, string id, int & pos);/*Llama a la funcion recursiva buscar*/
bool buscar(const tListaJugadores & lista, string id, int & pos, int & ini, int & fin);/*Busca al jugador de identificador id en lista entre las posiciones ini y fin. Si este se encuentra all�, se devuelve true y
																					   en pos, la posici�n de la lista en la que est�. Si el jugador con identificador id no se encuentra en la lista se devuelve false
																					   y en pos la posici�n en la que deber�a ir para que la lista siga ordenada alfab�ticamente*/
tListaJugadores ordenarPorRanking(const tListaJugadores & lista);/*Devuelve una copia de la lista lista oredenada decrecientemente por puntos, y a igualdad de puntos crecientemente por
																 identificador*/

void ampliar(tListaJugadores & lista);/*Amplia la dimensi�n de lista a una lista del doble de su tama�o, manteniendo los jugadores que aparezcan en la lista*/
void borrarListaJugadores(tListaJugadores & lista);/*Libera exclusivamente la memoria del array de punteros a Jugador al que apunta lista.listaPtr*/
void liberarMemoria(tListaJugadores & lista);/*Libera toda la memoria din�mica de lista. Esto es cada uno de los jugadores apuntados por el array de punteros y tambi�n el array en s�*/