// Juan Carlos Llamas Adri�n Sanju�n
// Soluci�n al programa del juez de fp.fdi.ucm.es
// "M�xima cota de un mapa topogr�fico"

#include <iostream>
#include <fstream>
using namespace std;

// Aqu� la definici�n de tipos de datos 
// ------------------------------------

const int MAX_FILAS = 500;
const int MAX_COLUMNAS = 500;

typedef struct {
	int matriz[MAX_FILAS][MAX_COLUMNAS];
	int fila, columna;
} tmatriz;

typedef struct {
	int x, y;
} tposicion;


// Aqu� los prototipos
// --------------------

// Resuelve un caso de prueba
bool resuelveCaso();
// Carga de la matriz
bool cargaMatriz(tmatriz & m);
// Busca el m�ximo de una matriz
int maximoMatriz(const tmatriz & m, tposicion& p);


// El main no ten�is que tocarlo para este ejercicio
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
		// B�squeda del m�ximo
		
		tposicion p;
		int maximo = maximoMatriz(m, p);
		cout << maximo << ' ' << p.x << ' ' << p.y << endl;
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

// Tu trabajo empieza aqu�
// -----------------------
// Busca el m�ximo de una matriz
int maximoMatriz(const tmatriz & m, tposicion& p){
	int maximo;
	maximo = m.matriz[0][0];
	p.x = 0;
	p.y = 0;
	for (int i = 0; i < m.fila; i++) {
		for (int j = 0; j < m.columna; j++) {
			if (maximo < m.matriz[i][j]) {
				maximo = m.matriz[i][j];
				p.x = i; 
				p.y = j;
			}
		}
	}
	// implementar
	return maximo;
}
