// Juan Carlos Llamas
// Solución al programa del juez de fp.fdi.ucm.es
// "Tridiagonal"

#include <iostream>
#include <iomanip>
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
const int incF[4] = {1, 0, -1, 0};
const int incC[4] = {0, 1, 0, -1};
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
	bool resuelto = false, encontrado = false;
	tmatriz m;
	int suma, sumaMAX, contador = 0, pos;
	if (cargaMatriz(m)){
		sumaMAX= m.matriz[0][0]+ m.matriz[0][1] + m.matriz[1][0];

		for (int i = 1; i < m.fila; i++) {
			suma = m.matriz[i][i];

			if(i == m.fila-1){
				suma += m.matriz[i][i - 1] + m.matriz[i - 1][i];
			}
			else {
				for (int j = 0; j < 4; j++) {
					suma += m.matriz[i + incF[j]][i + incC[j]];
				}
			}
			if (suma > sumaMAX) {
				sumaMAX = suma;
			}
		}
		while (!encontrado) {
			if (contador == 0) {
				suma = m.matriz[0][0] + m.matriz[0][1] + m.matriz[1][0];
				if (suma == sumaMAX) {
					encontrado = true;
					pos = 0;
				}
			}
			else if (contador == m.fila - 1) {
				suma = m.matriz[m.fila - 1][m.fila - 1] + m.matriz[m.fila - 1][m.fila - 2] + m.matriz[m.fila - 2][m.fila - 1];
				if (suma == sumaMAX) {
					encontrado = true;
					pos = m.fila - 1;
				}
			}
			else{
				suma = m.matriz[contador][contador];
				for (int j = 0; j < 4; j++) {
					suma += m.matriz[contador + incF[j]][contador + incC[j]];
				}
			
				if (suma == sumaMAX) {
					encontrado = true;
					pos = contador;
				}
			}
			contador++;
		}
		
		cout << pos << " " << sumaMAX << endl;
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
	cin >> m.fila;
	m.columna = m.fila;
	if (!cin){
		cargada = false;
	}
	else{
		for (int i = 0; i < m.fila; ++i){
			for (int j = 0; j < m.columna; ++j){
				m.matriz[i][j] = 0;
			}
		}
		for (int i = 0; i < m.fila; ++i) {
			cin >> m.matriz[i][i];
		}
		for (int i = 0; i < m.fila - 1; ++i) {
			cin >> m.matriz[i][i+1];
		}
		for (int i = 0; i < m.fila - 1; ++i) {
			cin >> m.matriz[i+1][i];
		}
		cargada = true;
	}
	return cargada;
}



