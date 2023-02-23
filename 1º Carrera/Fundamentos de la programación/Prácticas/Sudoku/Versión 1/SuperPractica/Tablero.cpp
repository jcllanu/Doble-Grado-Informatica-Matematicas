#include"Tablero.h"
#include<fstream>
#include<string>

void actualizarTablero(tTablero tablero);
void recorrerBorrar(tTablero tablero, tCoor pos);
void recorrerAnnadir(tTablero tablero, tCoor pos, int c);
void Ast();

void iniciaTablero(tTablero tablero) {
	for (int i = 0; i < N; i++) {
		for (int j = 0;j < N; j++) {
			iniciaCasilla(tablero[i][j]);

		}
	}
}

bool cargarTablero(string nombreFichero, tTablero tablero) {
	ifstream archivo;
	bool cargado;
	char c;

	archivo.open(nombreFichero);
	if (!archivo.is_open()) {
		cargado = false;
	}
	else {
		cargado = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				archivo.get(c);
				rellenaCasilla(tablero[i][j], c, true);
			}
			archivo.get(c);
		}
		actualizarTablero(tablero);
		archivo.close();
	}

	return cargado;
}

void actualizarTablero(tTablero tablero) {
	tCoor pos;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (devuelveEstado(tablero[i][j]) == VACIA) {
				pos.x = i;
				pos.y = j;
				recorrerBorrar(tablero, pos);
			}
		}

	}
}

void recorrerBorrar(tTablero tablero, tCoor pos) {
	int aux1, aux2;
	for (int i = 0; i < N; i++) {
		if (devuelveEstado(tablero[pos.x][i]) == FIJA || devuelveEstado(tablero[pos.x][i]) == RELLENADA) {
			borraElemento(tablero[pos.x][pos.y], devuelveNumero(tablero[pos.x][i]));
		}
		if (devuelveEstado(tablero[i][pos.y]) == FIJA || devuelveEstado(tablero[i][pos.y]) == RELLENADA) {
			borraElemento(tablero[pos.x][pos.y], devuelveNumero(tablero[i][pos.y]));
		}
	}
	aux1 = (pos.x / 3) * 3;
	aux2 = (pos.y / 3) * 3;
	for (int i = aux1; i < aux1 + 3; i++) {
		for (int j = aux2; j < aux2 + 3; j++) {
			if (devuelveEstado(tablero[i][j]) == FIJA || devuelveEstado(tablero[i][j]) == RELLENADA) {
				borraElemento(tablero[pos.x][pos.y], devuelveNumero(tablero[i][j]));
			}
		}
	}
}

void dibujarTablero(const tTablero tablero) {
	cout << endl;
	cout << "	";
	for (int i = 0; i < 31; i++) {
		Ast();
	}
	cout << endl;
	for (int k = 0; k < 3; k++) {
		for (int i = 3*k; i < 3 * (k+1); i++) {
			cout << "	";
			Ast();
			for (int l = 0; l < 3; l++) {
				for (int j = 3*l; j < 3*(l+1); j++) {
					dibujaCasilla(tablero[i][j]);
				}
				Ast();
			}
			cout << endl;
		}
		cout << "	";
		for (int i = 0; i < 31; i++) {
			Ast();
		}
		cout << endl;
	}
	cout << endl;
}

bool ponerNum(tTablero tablero, int fila, int col, int c) {
	bool ok = false;

	if (devuelveEstado(tablero[fila][col]) == VACIA && pertenece(tablero[fila][col], c)) {
		ok = true;
		rellenaCasilla(tablero[fila][col], char(c)+'0');
		actualizarTablero(tablero);

	}
	
	return ok;

}
bool borrarNum(tTablero tablero, int fila, int col) {
	bool ok = false;
	tCoor pos;
	int valor = devuelveNumero(tablero[fila][col]);
	pos.x = fila;
	pos.y = col;

	if (devuelveEstado(tablero[fila][col]) == RELLENADA) {
		ok = true;
		rellenaCasilla(tablero[fila][col], ' ');
		recorrerBorrar(tablero, pos);

		recorrerAnnadir(tablero, pos, valor);

	}

	return ok;
}
void recorrerAnnadir(tTablero tablero, tCoor pos, int c) {
	int aux1, aux2;
	tCoor posaux;
	for (int i = 0; i < N; i++) {
		if (devuelveEstado(tablero[pos.x][i]) == VACIA) {
			annadeElemento(tablero[pos.x][i], c);
			posaux.x = pos.x;
			posaux.y = i;
			recorrerBorrar(tablero, posaux);
		}
		if (devuelveEstado(tablero[i][pos.y]) == VACIA) {
			annadeElemento(tablero[i][pos.y], c);
			posaux.x = i;
			posaux.y = pos.y;
			recorrerBorrar(tablero, posaux);
		}
	}
	aux1 = (pos.x / 3) * 3;
	aux2 = (pos.y / 3) * 3;
	for (int i = aux1; i < aux1 + 3; i++) {
		for (int j = aux2; j < aux2 + 3; j++) {
			if (devuelveEstado(tablero[i][j]) == VACIA) {
				annadeElemento(tablero[i][j], c);
				posaux.x = i;
				posaux.y = j;
				recorrerBorrar(tablero, posaux);
			}
		}
	}

}
bool tableroLleno(const tTablero tablero) {
	bool lleno = true;
	int c1 = 0, c2;
	while (lleno && c1 < N) {
		c2 = 0;
		while (lleno && c2 < N) {
			if (devuelveEstado(tablero[c1][c2]) == VACIA) {
				lleno = false;
			}
			c2++;
		}
		c1++;
	}

	return lleno;
}

void mostrarPosibles(const tTablero tablero, int fila, int col) {
	mostrar(tablero[fila][col]);
}

void rellenarSimples(tTablero tablero) {
	int numero;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (esSimple(tablero[i][j], numero)) {
				rellenaCasilla(tablero[i][j], char(numero)+'0');
			}
		}
	}
	actualizarTablero(tablero);
	
}
void Ast() {
	colorFondo(3);
	cout << "*";
	colorFondo(0);
}
