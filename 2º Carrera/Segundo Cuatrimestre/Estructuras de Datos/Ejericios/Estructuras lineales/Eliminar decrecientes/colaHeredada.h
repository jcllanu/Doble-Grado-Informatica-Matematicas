#pragma once
#include"queue_eda.h"
#include <iostream>

template <class T>
class ColaBorrarDecrecientes : public queue<T> {

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

	void borrar() {
		if (this->nelems >= 1) {
			
			Nodo* anterior = this->prim;
			Nodo* recorrer = this->prim->sig;
			while (recorrer != nullptr) {
				if (recorrer->elem < anterior->elem) {
					anterior->sig = recorrer->sig;
					delete recorrer;
					this->nelems--;
				}
				else {
					anterior = recorrer;
				}

				recorrer = anterior->sig;
			}
			this->ult = anterior;
		}

	}
};
