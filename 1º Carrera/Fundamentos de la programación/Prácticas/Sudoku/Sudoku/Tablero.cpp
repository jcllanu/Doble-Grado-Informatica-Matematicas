#include"Tablero.h"
#include<fstream>
#include<string>
#include"checkML.h"

void actualizarTablero(tTablero tablero);/*Actualiza los valores posibles de todas las casillas de tablero*/
void recorrerBorrar(tTablero tablero, tCoor pos);/*Dada una poscion y un tablero borra los valores posibles de la casilla cuyas coordenadas son pos. Para ello se recorre la fila pos.x, la comluna pos.y
												 y la región donde se encuentra pos*/
void recorrerAnnadir(tTablero tablero, tCoor pos, int c);/*Dada una coordenada pos añade a los valores posibles de todas las casillas vacias de la fila pos.x, la columna pos.y y la región donde se encuentra pos
														 el valor c*/
void Ast();/*Escribe un arterísco de color turquesa (3) en pantalla*/
void recorrerAfectadas(tTablero tablero, tCoor pos); //Actualiza los valores posibles de las casillas afectadas por pos.



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
	tCoor pos = { fila,col };
	if (devuelveEstado(tablero[fila][col]) == VACIA && pertenece(tablero[fila][col], c)) {
		ok = true;
		rellenaCasilla(tablero[fila][col], char(c)+'0');
		recorrerAfectadas(tablero, pos);

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

	if (devuelveEstado(tablero[fila][col]) == VACIA) {
		cout << endl << "Los valores posibles son: ";
		mostrar(tablero[fila][col]);
		cout << endl;
	}
	else if(devuelveEstado(tablero[fila][col]) == FIJA){
		cout << endl << "Esta casilla es fija y no tiene valores posibles." << endl;
	}
	else {
		cout << endl << "Esta casilla está rellenada y no tiene valores posibles." << endl;
	}
}

void rellenarSimples(tTablero tablero) {
	int numero;
	tCoor pos;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (esSimple(tablero[i][j], numero)) {
				rellenaCasilla(tablero[i][j], char(numero)+'0');
				pos.x = i;
				pos.y = j;
				recorrerAfectadas(tablero, pos);
			}
		}
	}

	
	
}

void Ast() {
	colorFondo(3);
	cout << "*";
	colorFondo(0);
} 

void recorrerAfectadas(tTablero tablero, tCoor pos) {
	int aux1, aux2;
	tCoor posaux;

	for (int i = 0; i < N; i++) {
		if (devuelveEstado(tablero[pos.x][i]) == VACIA) {
			iniciaCasilla(tablero[pos.x][i]);
			posaux.x = pos.x;
			posaux.y = i;
			recorrerBorrar(tablero, posaux);
		}
		if (devuelveEstado(tablero[i][pos.y]) == VACIA) {
			iniciaCasilla(tablero[i][pos.y]);
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
				iniciaCasilla(tablero[i][j]);
				posaux.x = i;
				posaux.y = j;
				recorrerBorrar(tablero, posaux);
			}
		}
	}
}