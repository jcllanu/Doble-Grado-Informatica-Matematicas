#include"Pirata.h"
#include<iomanip>

using namespace std;
char enumerado(tCasilla casilla);
int aleatorio(int inf, int intervalo);

void inicializarTablero(tIsla& isla) {
	for (int i = 0; i < N; i += N - 1) {
		for (int j = 0; j < N; j++) {
			isla.matriz[i][j] = AGUA;
			isla.matriz[j][i] = AGUA;
		}
	}
	isla.matriz[0][N - 1] = PUENTE;
	isla.matriz[N-1][0] = PUENTE;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			isla.matriz[i][j] = TIERRA;
		}
	}
	isla.pirata.x = aleatorio(1, N - 2);
	isla.pirata.y = aleatorio(1, N - 2);
	isla.matriz[isla.pirata.x][isla.pirata.y] = PIRATA;
	isla.tesoro.x = aleatorio(1, N - 2);
	isla.tesoro.y = aleatorio(1, N - 2);
	while (isla.tesoro.x == isla.pirata.x && isla.pirata.y == isla.tesoro.y) {
		isla.tesoro.x = aleatorio(1, N - 2);
		isla.tesoro.y = aleatorio(1, N - 2);
	}
	isla.matriz[isla.tesoro.x][isla.tesoro.y] = TESORO;
}
tDireccion direccion() {
	return tDireccion(aleatorio(0, 4));
}
void dibujar(const tIsla& isla) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N ; j++) {
			cout << setw(2) << enumerado(isla.matriz[i][j]);
		}
		cout << endl;
	}
}
int aleatorio(int inf, int intervalo) {
	int al;
	al = rand() % (intervalo)+inf;
	return al;
}
char enumerado(tCasilla casilla) {
	char final;
	switch (int(casilla)) {
	case 0: {
		final = 'P';
	}
			break;
	case 1: {
		final = 'T';
	}
			break;
	case 2: {
		final = 'M';
	}
			break;
	case 3: {
		final = 'A';
	}
			break;
	case 4: {
		final = ' ';
	}
			break;
	}
	return final;
}
void mover(tIsla& isla, tDireccion direccion) {
	switch (int(direccion)) {
	case 0: {
		isla.pirata.x -= 1;
	}
			break;
	case 1: {
		isla.pirata.x += 1;
	}
			break;
	case 2: {
		isla.pirata.y += 1;
	}
			break;
	case 3: {
		isla.pirata.y -= 1;
	}
			break;
	}
}
bool CasillaMuerte(tIsla& isla) {
	bool si = false;
	if (isla.matriz[isla.pirata.x] [isla.pirata.y]==AGUA) {
		si = true;
	}
	return si;
}
bool CasillaTesoro(tIsla& isla) {
	bool si = false;
	if (isla.pirata.x == isla.tesoro.x && isla.pirata.y == isla.tesoro.y) {
		si = true;
	}
	return si;
}
void confirmarMovimiento(tIsla& isla) {
	int i = 0, j;
	bool encontrado = false;
	while ( i < N && !encontrado) {
		j = 0;
		while (j < N && !encontrado) {
			if (isla.matriz[i][j] == PIRATA) {
				isla.matriz[i][j] = TIERRA;
				encontrado = true;
			}
			j++;
		}
		i++;
	}
	isla.matriz[isla.pirata.x][isla.pirata.y] = PIRATA;

}