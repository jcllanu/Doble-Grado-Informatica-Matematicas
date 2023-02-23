// Juan Carlos Llamas
// Solución al programa del juez de fp.fdi.ucm.es
// "Buscando a"

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
void resuelveCaso(const tmatriz & m, const tmatriz & a);
// Carga de la matriz
bool cargaMatriz(tmatriz & m);
// Busca el máximo de una matriz
bool propiedad(const tmatriz& m, const tmatriz& a, int contador1, int contador2);


// El main no tenéis que tocarlo para este ejercicio
// --------------------------------------------------
int main() {
	#ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	tmatriz m,a;
	bool resuelto = true;
	while (cargaMatriz(m) && cargaMatriz(a) && resuelto) {
		resuelveCaso(m,a);
	}
	#ifndef DOMJUDGE
		std::cin.rdbuf(in.rdbuf());
		system("PAUSE");
	#endif

	return 0;
}




// Resuelve un caso de prueba
// No tocarlo para este ejercicio
// -------------------------------
void resuelveCaso(const tmatriz & m, const tmatriz & a) {
	bool encontrado = false;
	int contador1 = 0, contador2;

	while (!encontrado && contador1 < (m.fila - a.fila + 1)) {
		contador2 = 0;
		while (!encontrado && contador2 < (m.columna - a.columna + 1)) {
			if (propiedad(m, a, contador1, contador2)) {
				encontrado = true;
				cout << contador1 << " " << contador2 << endl;
			}
			contador2++;
		}
		contador1++;
	}
	if (!encontrado) {
		cout << "NO" << endl;
	}
	
}


// Carga de la matriz
bool cargaMatriz(tmatriz & m){
	bool cargada;
	cin >> m.fila >> m.columna;
	if (!cin){
		cargada = false;
	}
	else{
		for (int i = 0; i < m.fila; ++i){
			for (int j = 0; j < m.columna; ++j){
				cin >> m.matriz[i][j];
			}
		}
		cargada = true;
	}
	return cargada;
}

bool propiedad(const tmatriz& m, const tmatriz& a, int contador1, int contador2) {
	bool coinciden = true;
	int i = 0, j;

	while (coinciden && i < a.fila) {
		j = 0;
		while (coinciden && j < a.columna) {
			if (a.matriz[i][j] != m.matriz[contador1 + i][contador2 + j]) {
				coinciden = false;
			}
			else {
				j++;
			}
		}
		if (coinciden) {
			i++;
		}
	}

	return coinciden;
}
