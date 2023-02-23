/*Juan Carlos Llamas Núñez
	2º DG FAL*/

#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

typedef struct {
	int tiempo, puntuacion;
	double tiempoEntrepunt;
}tCancion;
bool resuelveCaso();
double puntuacionEstimada(const vector<tCancion>& canciones, int tiempoCara, int k, int tiempoActual1, int tiempoActual2, int puntActual);
int divide(vector<tCancion>& canciones, int start, int end);
void quicksort(vector<tCancion>& canciones, int start, int end);
void mochila2(const vector<tCancion>& canciones, int tiempoCara, vector<int>&solucion, int k, int& tiempoActual1, int& tiempoActual2, int& puntActual, int& mejorPunt);

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while(resuelveCaso());
	
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}


bool resuelveCaso() {
	int numCanciones, tiempoCara;
	cin >> numCanciones;
	if (numCanciones == 0) {
		return false;
	}
	else {
		cin >> tiempoCara;
		vector<tCancion> canciones(numCanciones);
		vector<int> solucion(numCanciones);
		for (int i = 0; i < numCanciones; i++) {
			cin >> canciones[i].tiempo>> canciones[i].puntuacion;
			canciones[i].tiempoEntrepunt = double(canciones[i].tiempo) / canciones[i].puntuacion;
			
		}
		quicksort(canciones, 0, canciones.size() - 1);/*Ordenamos para que puntuacion[0]/tiempo[0] >= p[1]/t[1] >= ... >= p[numCanciones-1]/t[numCanciones-1] y así poder aplicar el algoritmo para resolver el problema de la mochia*/
		int puntActual = 0, mejorPunt = 0, tiempoActual1 = 0, tiempoActual2 = 0;
	
		mochila2(canciones, tiempoCara, solucion, 0, tiempoActual1, tiempoActual2, puntActual, mejorPunt);
		cout << mejorPunt << endl;
		return true;
	}
	
}


double puntuacionEstimada(const vector<tCancion>& canciones, int tiempoCara, int k, int tiempoActual1, int tiempoActual2, int puntActual) {
	int hueco = 2 * tiempoCara - tiempoActual1 - tiempoActual2;
	double estimacion = puntActual;
	int cont = k + 1;
	while (cont < canciones.size() && canciones[cont].tiempo <= hueco) {
		hueco -= canciones[cont].tiempo;
		estimacion += canciones[cont].puntuacion;
		cont++;
	}
	if (cont < canciones.size()) {
		estimacion += (double(hueco) / canciones[cont].tiempo)*canciones[cont].puntuacion;
	}

	return estimacion;
}


// Función para dividir el array y hacer los intercambios
int divide(vector<tCancion>& canciones, int start, int end) {
	int left;
	int right;
	double pivot;
	tCancion temp;

	pivot = canciones[start].tiempoEntrepunt;
	left = start;
	right = end;

	// Mientras no se cruzen los índices
	while (left < right) {
		while (canciones[right].tiempoEntrepunt > pivot) {
			right--;
		}

		while ((left < right) && (canciones[left].tiempoEntrepunt <= pivot)) {
			left++;
		}

		// Si todavía no se cruzan los indices seguimos intercambiando
		if (left < right) {
			temp = canciones[left];
			canciones[left] = canciones[right];
			canciones[right] = temp;
		}
	}

	// Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
	temp = canciones[right];
	canciones[right] = canciones[start];
	canciones[start] = temp;

	// La nueva posición del pivot
	return right;
}

// Función recursiva para hacer el ordenamiento
void quicksort(vector<tCancion>& canciones, int start, int end){
	int pivot;

	if (start < end) {
		pivot = divide(canciones, start, end);

		// Ordeno la lista de los menores
		quicksort(canciones, start, pivot - 1);

		// Ordeno la lista de los mayores
		quicksort(canciones, pivot + 1, end);
	}
}
void mochila2(const vector<tCancion>& canciones, int tiempoCara, vector<int>&solucion, int k, int& tiempoActual1, int& tiempoActual2, int& puntActual, int& mejorPunt) {
	for (int i = 2; i >=0; i--) {
		
		if (i == 0) {//No cogemos la canción k
			solucion[k] = 0;
			double puntEstimada = puntuacionEstimada(canciones, tiempoCara, k, tiempoActual1,tiempoActual2, puntActual);
			if (puntEstimada > mejorPunt) {/*Si es prometedora, es decir, si la estimación es mayor o iual que la mejor solución para la segunda cara*/
				if (k + 1 == solucion.size()) {/*Si es la última canción seleccionable*/
					if (puntActual > mejorPunt) {
						mejorPunt = max(puntActual, puntActual);
						/*mejorSolucion = solucion;*/
					}
				}
				else {/*Si no es la última canción seleccionable avanzamos al siguiente hijo*/
					mochila2(canciones, tiempoCara, solucion, k + 1, tiempoActual1, tiempoActual2, puntActual, mejorPunt);
				}
			}
		}
		else if (i == 1) {//Cogemos la canción k para la primera cara
			solucion[k] = 1;

			tiempoActual1 += canciones[k].tiempo;/*Marcamos el tiempo de la canción*/
			puntActual += canciones[k].puntuacion;/*Actualizamos el valor de la puntuación actual*/
			if (tiempoActual1 <= tiempoCara) {/*Si esta última canción seleccionada cabe en la primera cara del casete*/
				if (k + 1 == solucion.size()) {/*Si es la última canción seleccionable*/
					mejorPunt = max(mejorPunt, puntActual);
				}
				else {
					mochila2(canciones, tiempoCara, solucion, k + 1, tiempoActual1, tiempoActual2, puntActual, mejorPunt);
				}
			}
			tiempoActual1 -= canciones[k].tiempo;/*Desmarcamos el tiempo de la canción*/
			puntActual -= canciones[k].puntuacion;/*Desactualizamos el valor de la puntuación actual*/

		}
		else {
			solucion[k] = 2;
			tiempoActual2 += canciones[k].tiempo;/*Marcamos el tiempo de la canción*/
			puntActual += canciones[k].puntuacion;/*Actualizamos el valor de la puntuación actual*/

			if (tiempoActual2 <= tiempoCara) {/*Si esta última canción seleccionada cabe en la segunda cara del casete*/
				if (k + 1 == solucion.size()) {/*Si es la última canción seleccionable*/
					mejorPunt = max(mejorPunt, puntActual);
				}
				else {
					mochila2(canciones, tiempoCara, solucion, k + 1, tiempoActual1, tiempoActual2, puntActual, mejorPunt);
				}
			}
			tiempoActual2 -= canciones[k].tiempo;/*Desmarcamos el tiempo de la canción*/
			puntActual -= canciones[k].puntuacion;/*Desactualizamos el valor de la puntuación actual*/
		}
	}
	
}