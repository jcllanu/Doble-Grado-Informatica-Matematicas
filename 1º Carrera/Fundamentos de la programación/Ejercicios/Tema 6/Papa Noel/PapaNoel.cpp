// Juan Carlos LLamas Núñez
// Solución al programa del juez de fp.fdi.ucm.es
// "Papa Noel"

#include <iostream>
#include <fstream>
using namespace std;

// Aquí la definición de tipos de datos 
// ------------------------------------

const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;

typedef struct {
	int matriz[MAX_FILAS][MAX_COLUMNAS];
	int fila, columna;
} tmatriz;

typedef struct {
	int x, y;
} tposicion;


// Aquí los prototipos
// --------------------

// Resuelve un caso de prueba
bool resuelveCaso();
// Carga de la matriz
tmatriz operator*(const tmatriz& a, const tmatriz& b);
istream& operator>> (istream & in, tmatriz & m);
ostream& operator<< (ostream & out, tmatriz const& c);

// El main no tenéis que tocarlo para este ejercicio
// --------------------------------------------------
int main() {
	#ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	while (resuelveCaso());

	#ifndef DOMJUDGE
		std::cin.rdbuf(in.rdbuf());
		system("PAUSE");
	#endif

	return 0;
}




// Resuelve un caso de prueba
// No tocarlo para este ejercicio
// -------------------------------
bool resuelveCaso() {
	bool resuelto = false;
	tmatriz a, b, c;

	cin >> a;
	cin >> b;
	if (!cin.fail()) {
		c = a * b;
		resuelto = true;
		cout << c;
	}
	return resuelto;
}


tmatriz operator*(const tmatriz& a, const tmatriz& b) {
	tmatriz c;
	int suma;
	c.fila = a.fila;
	c.columna = b.columna;

	for (int i = 0; i < c.fila; i++) {
		for (int j = 0; j < c.columna; j++) {
			suma = 0;
			for (int k = 0; k < a.columna; k++) {
				suma += a.matriz[i][k] * b.matriz[k][j];
			}
			c.matriz[i][j] = suma;
		}
	}

	return c;
}
istream& operator>> (istream & in, tmatriz & m) {
	in >> m.fila >> m.columna;
	for (int i = 0; i < m.fila; ++i) {
		for (int j = 0; j < m.columna; ++j) {
			in >> m.matriz[i][j];
		}
	}
	return in;
}
ostream& operator<< (ostream & out, tmatriz const& c) {

	for (int i = 0; i < c.fila; i++) {
		for (int j = 0; j < c.columna-1; j++) {
			out << c.matriz[i][j] << " ";
		}
		out << c.matriz[i][c.columna - 1];
		out << endl;
	}
	out << endl;
	return out;
}
