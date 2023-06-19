//Para el primer tipo de entrada, el esquema debe ser el siguiente :

// Nombre: Juan Carlos Llamas N��ez, Adri�n Sanju�n Espejo
// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema

//Dado un vector de naturales v y un entero n (0<=n<=10.000 ) devolver el n�mero de numeros pares
//que hay el vector.

#include <iostream>
using namespace std;
//#include <...>
//#include "..." // propios o los de las estructuras de datos de clase

// funci�n que resuelve el problema

// 
int resolver() {
	int numdatos, num, pares=0;
	cin >> numdatos;
	for (int i = 0; i < numdatos; i++) {
		cin >> num;
			if (num % 2 == 0) {
				pares++;
			}
	}
	return pares;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
void resuelveCaso() {
	int sol = resolver();
	std::cout << sol << endl;
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}