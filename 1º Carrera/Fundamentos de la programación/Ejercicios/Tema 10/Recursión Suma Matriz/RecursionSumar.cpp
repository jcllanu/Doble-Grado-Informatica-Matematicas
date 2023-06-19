
#include <iostream>
#include <fstream>
using namespace std;

//Dada una matriz de enteros y una fila, columna,  sumar los datos positivos
//que se encuentran en la entrada dada, en las 8 posiciones adyacentes y en las posiciones adyacentes a
//los valores positivos que se van sumando, recursivamente
//Si el valor de la entrada no es positivo, el resultado sera cero.

int const F[] = { -1,-1,-1,0,0,1,1,1 };
int const C[] = { -1,0,1,-1,1,-1,0,1 };

typedef struct {
	int valor;
	bool sumado, visitado;
}tCasilla;

typedef struct {
	tCasilla matriz[100][100];
	int filas, columnas;
}tMatriz;


void suma(tMatriz& a, int x, int y, int &sum);
bool resuelveCaso();
bool cargaMatriz(tMatriz & a);



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


bool resuelveCaso() {
	bool resuelto = false;
	tMatriz a;
	int x, y, sum;
	if (cargaMatriz(a)){
		cin >> x >> y;
		while (x >= 0 && y >= 0) {
			sum = 0;
			for (int i = 0; i < a.filas; i++) {
				for (int j = 0; j < a.columnas; j++) {
					a.matriz[i][j].sumado = false;
					a.matriz[i][j].visitado = false;
				}
			}
			a.matriz[x][y].visitado = true;
			suma(a, x, y, sum);
			cout << sum << endl;
			cin >> x >> y;
		}
	
		resuelto = true;
	}
	else{
		resuelto = false;
	}
	return resuelto;
}


// Carga de la matriz
bool cargaMatriz(tMatriz & a){
	bool cargada;
	cin >> a.filas >> a.columnas;
	if (!cin){
		cargada = false;
	}
	else{
		for (int i = 0; i < a.filas; ++i){
			for (int j = 0; j < a.columnas; ++j){
				cin >> a.matriz[i][j].valor;
			}
		}
		cargada = true;
	}
	return cargada;
}

void suma(tMatriz& a, int x, int y, int &sum) {
	int nx, ny;

	if (a.matriz[x][y].valor > 0) {
		if (!a.matriz[x][y].sumado) {
			sum += a.matriz[x][y].valor;
			a.matriz[x][y].sumado = true;
		}
		for (int i = 0; i < 8; i++) {
			nx = x + F[i];
			ny = y + C[i];
			if (nx < a.filas && nx >= 0 && ny < a.columnas && ny >= 0 && !a.matriz[nx][ny].visitado) {
				a.matriz[nx][ny].visitado = true;
				suma(a, nx, ny, sum);

			}

		}

	}
}
