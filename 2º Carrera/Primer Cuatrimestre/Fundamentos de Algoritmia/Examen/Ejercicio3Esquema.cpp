//NOMBRE Y APELLIDOS: JUAN CARLOS LLAMAS N��EZ

// Comentario general sobre la solucion,
// explicando como se resuelve el problema
/*Usamos la t�cnica de vuelta atr�s para probar todas las soluciones y descartaremos las ramas no prometedoras o inviables*/

// Definicion del espacio de soluciones y del arbol de exploracion
/*El espacio de soluciones ser� una n-tupla que corresponder� a cada una de las n personas con las que contamos y 
a cada persona se le asignar� un valor entre 0 y m-1 que ser� la playa que debe limpiar
Recorreremos el �rbol de exploraci�n asignando en cada persona la playa que debe limpiar. Es un �rbol con m ramas (n�mero de playas) y de profundidad n (n�mero de personas)*/

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
// 1. Estimaci�n de las playas que se van a poder llegar a limpiar dado una situaci�n y evaluar si son mayores o iguales que el m�nimo que se debe alcanzar
// 2. Estimaci�n de la basura m�xima que se puede llegar a recoger dada una basura actual
/*Vamos a implementar la segunda dado que resulta m�s f�cil llevar cuenta de la cantidad m�xima que pude recoger una persona en la playa adecuada e intu�mos que su implementaci�n es m�s sencilla*/

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
	int mejorLimpias = 0;/*Numero de playas limpiadas de la solucion (puede llevar a confusi�n pero NO es el mejor n�mero de playas limpias que se puede obtener sino el de la soluci�n)*/
	  //...
	int basuraActual = 0;/*Cantidad de basura recogida en un momento determinado*/
	vector<int> solucion(d.numPersonas);/*Vector soluci�n (se pude prescindir de �l pero lo incluimos por claridad)*/
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
		if (d.basuraPlaya[i] > 0) {/*Si queda basura por recoger en la playa i-�sima...*/
			solucion[k] = i;/*Probamos una asignaci�n de la persona k-�sima a la playa i-�sima*/
			basuraActual += min(d.recogePersona[k][i], d.basuraPlaya[i]);/*Como solo se puede recoger un m�ximo de la basura que queda en la playa, la basura actual recogida ser� el m�nimo entre la que queda en la playa y la que la persona k puede recoger en esa playa*/
			d.basuraPlaya[i] -= d.recogePersona[k][i];/*Marcamos la basura recogida*/
			if (d.basuraPlaya[i] <= 0) {/*Si la playa est� completamente limpia aumentamos en un el n�mero de playas limpias*/
				limpias++;
				aux = true;/*Usado para desmarcar*/
			}
			if (k + 1 == d.numPersonas){/*Si hemos llegado al �ltimo hijo comprobamos si es una solucion valida*/
				if (limpias >= d.minLimpias && basuraActual > mejorBasura) {/*Al cambiar esta condici�in por basuraActual >= mejorBasura puede variar el n�mero de playas limpias de la soluci�n*/
					mejorBasura = basuraActual;
					mejorLimpias = limpias;
					exito = true;
				}
			}
			else {

				if (estimacion(basuraActual, maximos, k) >= mejorBasura) {/*Hacemos una estimaci�n de la basura m�xima que se podr�a recoger*/
					asignar(d, solucion, basuraActual, mejorBasura, k + 1, limpias, mejorLimpias,exito,maximos);/*Si la soluci�n es prometedora seguimos explorando el �rbol*/

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

int estimacion(int basuraActual, vector<int> maximos, int k) {/*Hacemos la estimaci�n tomando como cota superior que cada persona restante limpie en la playa donde m�s basura pude recoger*/
	int est = basuraActual;
	for (int i = k + 1; i < maximos.size(); i++) {
		est += maximos[i];
	}

	return est;
}