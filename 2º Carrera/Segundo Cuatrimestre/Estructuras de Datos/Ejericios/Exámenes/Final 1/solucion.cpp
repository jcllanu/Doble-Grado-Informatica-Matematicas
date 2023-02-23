
// JUAN CARLOS LLAMAS NÚÑEZ (DG18)

//Explicación de la solución:
//Para resolver este problema lo hacemos en dos etapas:
//En primer lugar insertamos llamamos actualOther al primer nodo de la lista other. Este nodo lo quitamos de la lista other cambiando los punteros de 
//los elemntos anterior y siguiente (other.fantasma y actualOther->sig). Ahora insertamos este nodo detrás de actual1, que es el puntero al nodo detrás
//del cual hay que insertar el siguiente elemnto y que iremos avanazando debiamente. Para ello cambiamos los punteroes necesarios de actual1, otherActual y actual1->sig.
//Por último actualizamos el valor de actualOther que vuelve a ser other.fantasma->sig y de actual1, que pasa a ser el elemeento siguiente al antiguo otherActual.
//Repetimos este proceso hasta que se acban los elemntos que intercalar de una de las dos lista, es decir, o actual1 o otherActual son el fantasma de sus respectivas listas enlazadas.
// En ese caso solo queda insertar los elementos restantes de la lista que no  ha quedado vacía en this. 
//Aquí empiza la segunda etapa: Si la que ha quedado vacía es other entonces hemos terminado porque los otros elemntos 
//que originalmente ya estaban en lista han quedado bien enlazados. Si, en cambio, hemos llegado a this->fantasma con actual, hay que insertar todos los elementos que quedan en other al final.
//Para ello basta enlazar el ultimo elemento (this->fantasma->ant) de this con el primero de other (actualOther) y el ultimo de other con el fantasma.
//Después realizamos las operaciones necesarias para que other pase a ser la lista vacía.

//El coste es lineal en el núero de elementos de la lista menor. Para cada uno de estos elementos hay que hacer una serie de opereaciones constantes como cambiar punteros.
// Es decir si una lista tiene N elementos y otra M, con N<M hay que hacer un bucle con N vueltas en el que se tratan los N primeros elementos de ambas listas. 
//Los M-N elementos de la lista más grande solo requieren de operaciones constantes (cambiar punteros)

//s20623

#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class EntremezclarListas : public deque<int> {
public:
	// imprime la lista
	void print(std::ostream& o = std::cout) const {
		Nodo* actual = this->fantasma->sig;
		while (actual != this->fantasma) {
			o << actual->elem << ' ';
			actual = actual->sig;
		}
	}

	// modifica this para entremezclar sus elementos con los de other
	void entremezclar(EntremezclarListas & other) {
		Nodo* actual1 = this->fantasma->sig;
		Nodo* actualOther = other.fantasma->sig;
		while (actual1 != this->fantasma && actualOther != other.fantasma) {

			//Quitar actualOther de other
			other.fantasma->sig = actualOther->sig;
			actualOther->sig->ant = other.fantasma;
			other.nelems--;

			//Enlazar actual1->sig y actualOther
			actual1->sig->ant = actualOther;
			actualOther->sig = actual1->sig;

			//Enlazar actual1 y actualOther
			actual1->sig = actualOther;
			actualOther->ant = actual1;

			this->nelems++;

			//Actualizar
			actual1 = actualOther->sig;
			actualOther = other.fantasma->sig;
			
		}
		if (actualOther == other.fantasma) {
			//NADA
		}
		else {
			//Enlazar el último de this con el primero de other
			this->fantasma->ant->sig = other.fantasma->sig;
			other.fantasma->sig->ant = this->fantasma->ant;
			//enlazar el ultimo de other con el fantasma de this
			other.fantasma->ant->sig = this->fantasma;
			this->fantasma->ant = other.fantasma->ant;


			//Operaciones para dejar las listas coherentes
			other.fantasma->sig = other.fantasma;
			other.fantasma->ant = other.fantasma;

			this->nelems += other.nelems;
			other.nelems = 0;
		}
	}

};


/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, EntremezclarListas const& a) {
	a.print(o);
	return o;
}

EntremezclarListas leerLista() {
	EntremezclarListas lista;
	int n, val;
	cin >> n; // tamaño
	while (n--) {
		cin >> val;
		lista.push_back(val);
	}
	return lista;
}

void resuelveCaso() {
	auto lista1 = leerLista();
	auto lista2 = leerLista();

	lista1.entremezclar(lista2);

	cout << lista1 << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//  system("PAUSE");
#endif
	return 0;
}
