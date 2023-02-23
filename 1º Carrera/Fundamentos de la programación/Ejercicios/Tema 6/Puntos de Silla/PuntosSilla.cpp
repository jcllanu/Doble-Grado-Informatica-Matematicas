// Nombre y apellidos
// Solución al programa del juez de fp.fdi.ucm.es
// "Máxima cota de un mapa topográfico"

#include <iostream>
#include <fstream>
#include<string>
using namespace std;

// Aquí la definición de tipos de datos 
// ------------------------------------

const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;

typedef struct {
	int valor;
	bool minColumna;
	bool maxColumna;
	bool minFila;
	bool maxFila;
}tbloque;
typedef struct {
	tbloque matriz[MAX_FILAS][MAX_COLUMNAS];
	int fila, columna;
} tmatriz;
typedef struct {
	int x;
	int y;
}tCoor;
// Aquí los prototipos
// --------------------

// Resuelve un caso de prueba
bool resuelveCaso();
// Carga de la matriz
bool cargaMatriz(tmatriz & m);
// Busca el máximo de una matriz
string puntsilla(tmatriz & m);


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
	tmatriz m;
	if (cargaMatriz(m)){
		// Búsqueda del máximo
		
		
		string res =puntsilla(m);
		cout << res << endl;
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
	if (m.fila == 0 || m.columna == 0){
		cargada = false;
	}
	else{
		for (int i = 0; i < m.fila; ++i){
			for (int j = 0; j < m.columna; ++j){
				cin >> m.matriz[i][j].valor;
			}
		}
		cargada = true;
	}
	return cargada;
}

// Tu trabajo empieza aquí
// -----------------------
// Busca el máximo de una matriz
string puntsilla(tmatriz & m){
	int maxFila, minFila, maxColumna, minColumna;
	string a = "NO";
	for (int i = 0; i < m.fila; i++) {
		maxFila = m.matriz[i][0].valor;
		minFila = m.matriz[i][0].valor;
		for (int j = 1; j < m.columna; j++) {
			if (m.matriz[i][j].valor > maxFila) {
				maxFila = m.matriz[i][j].valor;
			}
			if (m.matriz[i][j].valor < minFila) {
				minFila = m.matriz[i][j].valor;
			}
		}
		for (int j = 0; j < m.columna; j++) {
			if (m.matriz[i][j].valor == maxFila) {
				m.matriz[i][j].maxFila = true;
			}
			else {
				m.matriz[i][j].maxFila = false;
			}
			if (m.matriz[i][j].valor == minFila) {
				m.matriz[i][j].minFila = true;
			}
			else {
				m.matriz[i][j].minFila = false;
			}
		}
	}
	for (int j = 0; j < m.columna; j++) {
		maxColumna = m.matriz[0][j].valor;
		minColumna = m.matriz[0][j].valor;
		for (int i = 1; i < m.fila; i++) {
			if (m.matriz[i][j].valor > maxColumna) {
				maxColumna = m.matriz[i][j].valor;
			}
			if (m.matriz[i][j].valor < minColumna) {
				minColumna = m.matriz[i][j].valor;
			}
		}
		for (int i = 0; i < m.fila; i++) {
			if (m.matriz[i][j].valor == maxColumna) {
				m.matriz[i][j].maxColumna = true;
			}
			else {
				m.matriz[i][j].maxColumna = false;
			}
			if (m.matriz[i][j].valor == minColumna) {
				m.matriz[i][j].minColumna = true;
			}
			else {
				m.matriz[i][j].minColumna = false;
			}
		}
	}
	for (int i = 0; i < m.fila; i++) {
		for (int j = 0; j < m.columna; j++) {
			if ((m.matriz[i][j].maxColumna && m.matriz[i][j].minFila) || (m.matriz[i][j].maxFila && m.matriz[i][j].minColumna)) {
				a = "SI";
			}
		}
	}
	return a;
}
