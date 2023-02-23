//NOMBRE Y APELLIDOS: JUAN CARLOS LLAMAS NÚÑEZ

// Comentario general sobre la solucion,
// explicando como se resuelve el problema
/*Usamos la técnica de vuelta atrás para probar todas las soluciones y descartaremos las ramas no prometedoras o inviables*/

// Definicion del espacio de soluciones y del arbol de exploracion
/*El espacio de soluciones será una n-tupla que corresponderá a cada una de las n personas con las que contamos y 
a cada persona se le asignará un valor entre 0 y m-1 que será la playa que debe limpiar
Recorreremos el árbol de exploración asignando en cada persona la playa que debe limpiar. Es un árbol con m ramas (número de playas) y de profundidad n (número de personas)*/

#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;

struct tDatos { // Datos de entrada
	int numPersonas, numPlayas, minLimpias;
	vector<int> basuraPlaya; // Basura a recoger en cada playa
	vector<vector<int>> recogePersona; // Basura que puede recoger cada persona en cada playa
};
void asignar(tDatos& d, vector<int>& solucion, int& basuraActual, int& mejorBasura, int k, int& limpias, int& mejorLimpias, bool& exito, vector<int> maximos);
int estimacion(int basuraActual, vector<int> maximos, int k);

// IMPLEMENTACION DEL ALGORITMO DE VUELTA ATRAS
// Explicaciones detalladas sobre la implementacion 
// Indicacion de los marcadores utilizados

// PODAS DE OPTIMALIDAD
// 1. Estimación de las playas que se van a poder llegar a limpiar dado una situación y evaluar si son mayores o iguales que el mínimo que se debe alcanzar
// 2. Estimación de la basura máxima que se puede llegar a recoger dada una basura actual
/*Vamos a implementar la segunda dado que resulta más fácil llevar cuenta de la cantidad máxima que pude recoger una persona en la playa adecuada e intuímos que su implementación es más sencilla*/

void resuelveCaso()
{
	// LECTURA DE LOS DATOS DE ENTRADA 
	tDatos d;
	cin >> d.numPersonas >> d.numPlayas >> d.minLimpias;
	
	for (int i = 0; i < d.numPlayas; ++i) {
		int aux;
        cin >> aux;
        d.basuraPlaya.push_back(aux);
	}

	for (int i = 0; i < d.numPersonas; ++i) {
		vector<int> aux(d.numPlayas);
		for (int &j : aux) cin >> j;
		d.recogePersona.push_back(aux);
	}
	vector<int> maximos(d.numPersonas);
	for (int i = 0; i < d.numPersonas; i++) {
		for (int j = 0; j < d.numPlayas; j++) {
			if (j == 0) {
				maximos[i]=d.recogePersona[i][j];
			}
			else {
				maximos[i] = max(d.recogePersona[i][j], maximos[i]);
			}
		}
	}
	//CALCULO Y ESCRITURA DEL RESULTADO

    // Inicializa para hacer la llamada
	int mejorBasura=0; // Cantidad maxima de basura que se puede recoger
	bool exito = false; // Se hara cierto si es posible limpiar completamente al menos minLimpias playas
	int limpias=0; // Cantidad de playas completamente limpias
	int mejorLimpias = 0;/*Numero de playas limpiadas de la solucion (puede llevar a confusión pero NO es el mejor número de playas limpias que se puede obtener sino el de la solución)*/
	  //...
	int basuraActual = 0;/*Cantidad de basura recogida en un momento determinado*/
	vector<int> solucion(d.numPersonas);/*Vector solución (se pude prescindir de él pero lo incluimos por claridad)*/
	asignar(d, solucion, basuraActual, mejorBasura,0,limpias,mejorLimpias, exito, maximos);
	// Llama aqui a tu funcion
    
	if (exito)
	{
		cout << mejorBasura << " " << mejorLimpias << "\n";
    }
	else
	{
		cout << "IMPOSIBLE\n";
	}
}


int main() {
	// Para la entrada por fichero
	#ifndef DOMJUDGE
	ifstream in("sample3.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
	#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
	#endif
	
	return 0;
}
void asignar(tDatos& d, vector<int>& solucion, int& basuraActual, int& mejorBasura, int k, int& limpias, int& mejorLimpias, bool& exito, vector<int> maximos) {
	bool aux = false;
	for (int i = 0; i < d.numPlayas; i++) {
		if (d.basuraPlaya[i] > 0) {/*Si queda basura por recoger en la playa i-ésima...*/
			solucion[k] = i;/*Probamos una asignación de la persona k-ésima a la playa i-ésima*/
			basuraActual += min(d.recogePersona[k][i], d.basuraPlaya[i]);/*Como solo se puede recoger un máximo de la basura que queda en la playa, la basura actual recogida será el mínimo entre la que queda en la playa y la que la persona k puede recoger en esa playa*/
			d.basuraPlaya[i] -= d.recogePersona[k][i];/*Marcamos la basura recogida*/
			if (d.basuraPlaya[i] <= 0) {/*Si la playa está completamente limpia aumentamos en un el número de playas limpias*/
				limpias++;
				aux = true;/*Usado para desmarcar*/
			}
			if (k + 1 == d.numPersonas){/*Si hemos llegado al último hijo comprobamos si es una solucion valida*/
				if (limpias >= d.minLimpias && basuraActual > mejorBasura) {/*Al cambiar esta condicióin por basuraActual >= mejorBasura puede variar el número de playas limpias de la solución*/
					mejorBasura = basuraActual;
					mejorLimpias = limpias;
					exito = true;
				}
			}
			else {

				if (estimacion(basuraActual, maximos, k) >= mejorBasura) {/*Hacemos una estimación de la basura máxima que se podría recoger*/
					asignar(d, solucion, basuraActual, mejorBasura, k + 1, limpias, mejorLimpias,exito,maximos);/*Si la solución es prometedora seguimos explorando el árbol*/

				}
			}
			if (aux) {/*Desmarcamos*/
				limpias--;
				aux = false;
			}
			d.basuraPlaya[i] += d.recogePersona[k][i];/*Desmarcamos*/
			basuraActual -= min(d.recogePersona[k][i], d.basuraPlaya[i]);/*Desmarcamos*/
		}
		
	}

}

int estimacion(int basuraActual, vector<int> maximos, int k) {/*Hacemos la estimación tomando como cota superior que cada persona restante limpie en la playa donde más basura pude recoger*/
	int est = basuraActual;
	for (int i = k + 1; i < maximos.size(); i++) {
		est += maximos[i];
	}

	return est;
}