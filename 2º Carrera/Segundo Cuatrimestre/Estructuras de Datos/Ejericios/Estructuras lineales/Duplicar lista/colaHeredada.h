#pragma once
#include "queue.h"
#include <iostream>

template <class T>
class ListaDuplica : public queue<T> {

	using Nodo = typename queue<T>::Nodo;

public:

	void print(std::ostream& o = std::cout) const {
		Nodo* aux = this->prim;
		while (aux!= nullptr) {
			o << aux->elem << " ";
			aux = aux->sig;
		}
		o << '\n';
	}

	void duplica() {
		Nodo* aux = this->prim;
		while (aux!=nullptr) {
			Nodo* nuevo = new Nodo(aux->elem, aux->sig);
			aux->sig = nuevo;
			if (nuevo->sig == nullptr) {
				this->ult = nuevo;
			}
			aux = nuevo->sig;
			
		}
		this->nelems *= 2;
	
	}
};

