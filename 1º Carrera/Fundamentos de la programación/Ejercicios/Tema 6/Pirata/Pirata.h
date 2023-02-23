#pragma once
#include<iostream>
#include<ctime>
using namespace std;

typedef enum{PIRATA, TESORO, PUENTE, AGUA, TIERRA}tCasilla;
typedef enum{NR,S,E,W}tDireccion;
int const N = 10;
typedef struct {
	int x, y;
}tCoor;
typedef struct {
	tCasilla matriz[N][N];
	tCoor pirata, tesoro;
}tIsla;



void inicializarTablero(tIsla& isla);
tDireccion direccion();
void dibujar(const tIsla& isla);
void mover(tIsla& isla, tDireccion direccion);
bool CasillaMuerte(tIsla& isla);
bool CasillaTesoro(tIsla& isla);
void confirmarMovimiento(tIsla& isla);
