#pragma once
#include"queue.h"
#include <iostream>

template <class T>
class ColaIntercambiar : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void print(std::ostream& o = std::cout) const {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			o << aux->elem << " ";
			aux = aux->sig;
		}
		o << '\n';
	}

	void intercambiar() {
		if (this->nelems >= 2) {
			Nodo* recorrer1 = this->prim;
			Nodo* recorrer2 = this->prim->sig;
			this->prim = recorrer2;
			recorrer1->sig = recorrer2->sig;
			recorrer2->sig = recorrer1;
			Nodo* anterior = recorrer1;

			recorrer1 = anterior->sig;
			while (recorrer1 != nullptr ) {
				recorrer2= recorrer1->sig;
				if (recorrer2 != nullptr) {
					anterior->sig = recorrer2;
					recorrer1->sig = recorrer2->sig;
					recorrer2->sig = recorrer1;
					anterior = recorrer1;

					recorrer1 = anterior->sig;
				}
				else {
					recorrer1 = recorrer2;
				}
			}
			this->ult = anterior;

		}
		

	}
};
