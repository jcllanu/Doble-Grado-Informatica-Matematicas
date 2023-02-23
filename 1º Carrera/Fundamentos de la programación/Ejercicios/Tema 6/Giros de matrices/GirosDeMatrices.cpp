// Juan Carlos Llamas
// Solución al programa del juez de fp.fdi.ucm.es
// "Giro matrices"

#include <iostream>
#include <fstream>
using namespace std;

// Aquí la definición de tipos de datos 
// ------------------------------------

const int MAX_FILAS = 50;
const int MAX_COLUMNAS = 50;

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
bool cargaMatriz(tmatriz & m);
// Busca el máximo de una matriz
tmatriz girarmatriz(const tmatriz& m);


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
	tmatriz m, girada;
	int numGiros, grados, total = 0, giros;
	if (cargaMatriz(m)){
		// Búsqueda del máximo
		cin >> numGiros;
		for (int i = 0; i < numGiros; i++) {
			cin >> grados;
			total += grados;
		}
		giros = (total % 360)/90;
		girada = m;
		for (int i = 0; i < giros; i++) {
			girada = girarmatriz(girada);
		}
		for (int i = 0; i < girada.fila; i++) {
			for (int j = 0; j < girada.columna; j++) {
				cout << girada.matriz[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		resuelto = true;
	}
	else{
		resuelto = false;
	}
	return resuelto;
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

// Tu trabajo empieza aquí
// -----------------------
// Busca el máximo de una matriz
tmatriz girarmatriz(const tmatriz& m){
	tmatriz girada;
	girada.columna = m.fila;
	girada.fila = m.columna;

	for (int i = 0; i < girada.fila; i++) {
		for (int j = 0; j < girada.columna; j++) {
			girada.matriz[i][j] = m.matriz[girada.columna-j-1][i];
		}
	}

	return girada;
}
