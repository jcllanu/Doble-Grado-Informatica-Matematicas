#pragma once
#include"queue.h"
#include <iostream>

template <class T>
class ColaInvertir : public queue<T> {

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

	void invertir() {
		Nodo* recorrer = this->prim;
		Nodo* anterior = nullptr;
		Nodo* siguiente = nullptr;
		this->prim = this->ult;
		this->ult = recorrer;
		while (recorrer != nullptr) {
			siguiente = recorrer->sig;
			recorrer->sig = anterior;
			anterior = recorrer;
			recorrer = siguiente;
		}
		

	}
};
