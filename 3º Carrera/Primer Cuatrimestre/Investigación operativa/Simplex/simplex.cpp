
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <climits>
#include <iomanip>
using namespace std;

#include "fraccion.h"

bool hayOptimalidad(int n, int m, const vector<vector<fraccion>> &tablaSimplex, bool minimizacion);
bool haySolucionUnica(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<bool>& variablesBasicas, bool minimizacion);
bool haySolucionNoAcotada(int n, int m, const vector<vector<fraccion>> &tablaSimplex, bool minimizacion);
void escribirPuntoSolucion(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<bool>& variablesBasicas, const vector<int>& variablesBasicasIndices);
void escribirSolucionOptimaUnica(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<bool>& variablesBasicas, const vector<int>& variablesBasicasIndices);
void escribirSolucionesNoAcotadas(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<bool>& variablesBasicas, const vector<int>& variablesBasicasIndices, bool minimizacion);
void escribirPuntoSolucion(int n, int m, vector<vector<fraccion>> &tablaSimplex, vector<bool>& variablesBasicas, vector<int>& variablesBasicasIndices);
void localizarPivote(int n, int m, const vector<vector<fraccion>> &tablaSimplex, bool minimizacion, int& columna, int& fila);
void pivotar(int n, int m, vector<vector<fraccion>> &tablaSimplex, vector<bool>& variablesBasicas, vector<int>& variablesBasicasIndices, int columna, int fila);
void simplex(int n, int m, vector<vector<fraccion>> &tablaSimplex, vector<bool>& variablesBasicas, vector<int>& variablesBasicasIndices, bool minimizacion);
void mostrarTabla(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<int>& variablesBasicasIndices);
bool haySolucionOptimaEnDireccion(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<bool>& variablesBasicas, const vector<int>& variablesBasicasIndices, bool minimizacion);


int filaVariableBasica(int i_basica, int m, const vector<int>& variablesBasicasIndices) {
	for (int i = 0; i < m; i++) {
		if (variablesBasicasIndices[i] == i_basica)
			return i;
	}
}


bool hayOptimalidad(int n, int m, const vector<vector<fraccion>> &tablaSimplex, bool minimizacion) {
	for (int j = 0; j < n; j++) {
		if (minimizacion) {
			if (tablaSimplex[m][j] < fraccion(0)) {//Hay un coste reducido negativo
				return false;
			}
		}
		else {
			if (tablaSimplex[m][j] > fraccion(0)) {//Hay un coste reducido positivo
				return false;
			}
		}
	}
	return true;
}

bool haySolucionUnica(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<bool>& variablesBasicas, bool minimizacion) {
	for (int j = 0; j < n; j++) {
		if (tablaSimplex[m][j] == fraccion(0) && !variablesBasicas[j]) {//Hay un coste reducido cero de una variable no basica
			return false;
		}
		
	}
	return true;
}

bool haySolucionNoAcotada(int n, int m, const vector<vector<fraccion>> &tablaSimplex, bool minimizacion) {
	for (int j = 0; j < n; j++) {
		if (minimizacion && tablaSimplex[m][j] < fraccion(0) || !minimizacion && tablaSimplex[m][j] > fraccion(0)) {//Coste reducido negativo en minimizacion o positivo en maximizacion
			bool todosMenoresOIgualesQue0 = true;
			for (int i = 0; i < m; i++) {
				if (tablaSimplex[i][j] > fraccion(0)) {
					todosMenoresOIgualesQue0 = false;
					break;
				}
					
			}
			if (todosMenoresOIgualesQue0)
				return true;
		}		
	}
	return false;
}
void escribirPuntoSolucion(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<bool>& variablesBasicas, const vector<int>& variablesBasicasIndices) {
	for (int j = 0; j < n; j++) {
		cout << "x_" << j + 1 << " = ";
		if (variablesBasicas[j]) {
			tablaSimplex[filaVariableBasica(j,m, variablesBasicasIndices)][n].print(); 
		}
		else {
			cout << setw(7) << right << setfill(' ') << 0;
		}
		cout << endl;
	}
}

void escribirSolucionOptimaUnica(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<bool>& variablesBasicas, const vector<int>& variablesBasicasIndices) {
	cout << "Problema con solucion optima única: " << endl;
	escribirPuntoSolucion(n, m, tablaSimplex, variablesBasicas, variablesBasicasIndices);
	cout << " y " << endl << " z  = ";
	(fraccion(0)-tablaSimplex[m][n]).print();
	cout << endl << endl;
}
//2 3 -3 5 4 -2 1 0 -1 -2 -3 3 1 0 0 0 1 0 12 11 0
void escribirSolucionesNoAcotadas(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<bool>& variablesBasicas, const vector<int>& variablesBasicasIndices, bool minimizacion) {
	cout << "Problema con solucion optima no acotada: " << endl;
	cout << "Partiendo del punto" << endl;
	escribirPuntoSolucion(n, m, tablaSimplex, variablesBasicas, variablesBasicasIndices);
	cout << endl << " y con dirrecion(es): " << endl;
	int contador = 1;
	for (int j = 0; j < n; j++) {
		if (minimizacion && tablaSimplex[m][j] < fraccion(0) || !minimizacion && tablaSimplex[m][j] > fraccion(0)) {//Coste reducido negativo en minimizacion o positivo en maximizacion
			bool todosMenoresOIgualesQue0 = true;
			for (int i = 0; i < m; i++) {
				if (tablaSimplex[i][j] > fraccion(0)) {
					todosMenoresOIgualesQue0 = false;
					break;
				}
					
			}
			if (todosMenoresOIgualesQue0) {
				cout << contador << ".-    t(";
				for (int k = 0; k < n; k++) {
					if (k == j) {
						cout << 1;
					}
					else if (!variablesBasicas[k]) {
						cout << 0;
					}
					else {
						(fraccion(0)-tablaSimplex[filaVariableBasica(k,m, variablesBasicasIndices)][j]).print();	
					}
					if (k < n - 1)
						cout << ", ";
				}
				cout << ")" << endl;
				contador++;
			}	
			
		}
	}
	cout << endl << "la funcion objetivo puede ";
	if (minimizacion)
		cout << "de";
	cout << "crecer arbitrariamente en la region factible del problema" << endl;
}
void localizarPivote(int n, int m, const vector<vector<fraccion>> &tablaSimplex, bool minimizacion, int& columna, int& fila) {
	fraccion maxAbs= fraccion(0);
	for (int j = 0; j < n; j++) {
		if (minimizacion) {
			if (tablaSimplex[m][j] < fraccion(0)) {
				if (tablaSimplex[m][j] < maxAbs) {
					maxAbs = tablaSimplex[m][j];
					columna = j;
				}
			}
		}
		else {
			if (tablaSimplex[m][j] > fraccion(0)) {//Hay un coste reducido positivo
				if (tablaSimplex[m][j] > maxAbs) {
					maxAbs = tablaSimplex[m][j];
					columna = j;
				}
			}
		}
	}
	//La columna con coste reducido maximo (en valor absoluto) es "columna" y en esa columna hay algun valor positivo
	fraccion minimoCociente = fraccion(INT_MAX);
	for (int i = 0; i < m; i++) {
		if (tablaSimplex[i][columna] > fraccion(0)) {
			if (tablaSimplex[i][n] / tablaSimplex[i][columna] < minimoCociente) {
				fila = i;
				minimoCociente = tablaSimplex[i][n] / tablaSimplex[i][columna];
			}
		}
	}

}
void pivotar(int n, int m, vector<vector<fraccion>> &tablaSimplex, vector<bool>& variablesBasicas, vector<int>& variablesBasicasIndices, int columna, int fila) {
	//Cambiamos la fila l-esima (l=fila)
	fraccion pivote = tablaSimplex[fila][columna];
	for (int j = 0; j <= n; j++) {
		tablaSimplex[fila][j] = tablaSimplex[fila][j] / pivote;
	}
	for (int i = 0; i <= m; i++) {
		if (i != fila) {
			fraccion coste_red=tablaSimplex[i][columna];
			for (int j = 0; j <= n; j++) {
				tablaSimplex[i][j] = tablaSimplex[i][j] - tablaSimplex[fila][j] * coste_red;
			}
		}
	}
	variablesBasicas[columna] = true;
	variablesBasicas[variablesBasicasIndices[fila]] = false;
	variablesBasicasIndices[fila] = columna;
}

void mostrarTabla(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<int>& variablesBasicasIndices) {
	cout << endl;
	for (int i = -1; i <= m ; i++) {
		for (int j = -1; j <= n; j++) {
			if (i == -1 && j == -1) {
				cout << setw(10) << setfill(' ') << "Tabla";
			}
			else if (i == -1) {
				if (j != n)
					cout << setw(10) << setfill(' ') << "x_" << j + 1;
					
			}
			else if (j == -1) {
				if (i == m) {
					cout << setw(13) << setfill(' ') << "Costes Red.";
				}
				else {
					cout << setw(8) << setfill(' ') << "x_" << variablesBasicasIndices[i] + 1 << "    ";
				}
				
			}
			else {
				tablaSimplex[i][j].print();
			}
		}
		cout << endl;
	}
	cout << endl;
}

//3 10 3 2 3 2 1 0 0 0 1 0 12 30 0
bool haySolucionOptimaEnDireccion(int n, int m, const vector<vector<fraccion>> &tablaSimplex, const vector<bool>& variablesBasicas, const vector<int>& variablesBasicasIndices, bool minimizacion) {
	for (int j = 0; j < n; j++) {
		if (tablaSimplex[m][j] == fraccion(0) && !variablesBasicas[j]) {//Hay un coste reducido cero de una variable no basica
			bool algunoPositivo = false;
			for (int i = 0; i < m; i++) {
				if (tablaSimplex[i][j] > fraccion(0)) {
					algunoPositivo = true;
					break;
				}
			}
			if (!algunoPositivo) {
				return true;
			}
		}

	}
	return false;
}

void simplex(int n, int m, vector<vector<fraccion>> &tablaSimplex, vector<bool>& variablesBasicas, vector<int>& variablesBasicasIndices, bool minimizacion) {
	mostrarTabla(n, m, tablaSimplex, variablesBasicasIndices);
	if (hayOptimalidad(n,m, tablaSimplex, minimizacion)) {
		if (haySolucionUnica(n, m, tablaSimplex, variablesBasicas, minimizacion)) {
			//Hemos encontrado la unica solucion optima
			escribirSolucionOptimaUnica(n, m,tablaSimplex,variablesBasicas,variablesBasicasIndices);
			
		}
		else {
			cout << "Problema con solución optima múltiple: " << endl;
			if (haySolucionOptimaEnDireccion(n, m, tablaSimplex, variablesBasicas, variablesBasicasIndices, minimizacion)) {
				//Hay una solucion optima a lo largo de una direccion

			}
			else {
				//Hay solucion optima entre dos puntos

			}
			
		}
	}
	else if (haySolucionNoAcotada(n, m, tablaSimplex, minimizacion)) {
		escribirSolucionesNoAcotadas(n, m, tablaSimplex, variablesBasicas, variablesBasicasIndices, minimizacion);
		//Mirar despues las posibles soluciones no acotadas desde otros puntos?
	}
	else {
		//Hay que pivotar
		int columna, fila;
		localizarPivote(n,m, tablaSimplex, minimizacion, columna, fila);
		pivotar(n, m, tablaSimplex, variablesBasicas, variablesBasicasIndices, columna, fila);
		simplex(n, m, tablaSimplex, variablesBasicas, variablesBasicasIndices, minimizacion);
	}
	
}
int main() {
	system("chcp 1252");
	int n, m;
	cout << "Introduce el número de variables (n): ";
	cin >> n;
	cout << "Introduce el número de resticciones (m): ";
	cin >> m;
	if (m > n) {
		cout << "ERROR";
		system("pause");
		return 0;
	}
	vector<vector<fraccion>> tablaSimplex(m+1,vector<fraccion> (n+1));
	cout << "Introduce las variables básicas: ";
	int aux;
	vector<bool> variablesBasicas(n,false);
	vector<int> variablesBasicasIndices(m);
	for (int i = 0; i < m; i++) {
		cin >> aux;
		variablesBasicas[aux-1] = true;
		variablesBasicasIndices[i] = aux - 1;
	}
	cout << "Introduce la tabla del Simplex de una solución básica factible por columnas"<<endl<<"(incluye los costes reducidos y la última columna): ";
	fraccion auxiliar;
	for (int j = 0; j <= n; j++) {
		for (int i = 0; i <= m; i++) {
			auxiliar.read();
			tablaSimplex[i][j] = auxiliar;
		}
	}
	//Comprobación de que está la matriz identidad y los costes reducidos de las variables basicas son 0
	for (int j = 0; j < n; j++) {
		if(variablesBasicas[j])
			for (int i = 0; i <= m; i++) {
				if (i != j) {
					if (tablaSimplex[filaVariableBasica(i, m, variablesBasicasIndices)][j] != fraccion(0)) {
						cout << "ERROR";
						system("pause");
						return 0;
					}
						
				}
				else {
					if (tablaSimplex[filaVariableBasica(i, m, variablesBasicasIndices)][j] != fraccion(1)) {
						cout << "ERROR";
						system("pause");
						return 0;
					}
				}
			}
	}
	//Comprobacion de que los valores que toman las variables son positivos
	for (int i = 0; i < m; i++) {
		if (tablaSimplex[i][n] < fraccion(0)) {
			cout << "ERROR";
			system("pause");
			return 0;
		}
				
	}
	int min;
	cout << "Introduce un uno si es un problema de minimización u otro número si es de maximización: ";
	cin >> min;
	bool minimizacion;
	if (min == 1)
		minimizacion = true;
	else
		minimizacion = false;
	simplex(n, m, tablaSimplex, variablesBasicas, variablesBasicasIndices, minimizacion);
	system("pause");
	return 0;
}


