#pragma once
#include"queue_eda.h"
#include <iostream>

template <class T>
class ColaBorrar : public queue<T> {

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
		if (this->nelems >= 2) {
			Nodo* recorrer = this->prim;
			Nodo* par;
			while (recorrer->sig != nullptr && recorrer->sig->sig != nullptr) {
				par = recorrer->sig;
				recorrer->sig = recorrer->sig->sig;
				delete par;
				this->nelems--;
				recorrer = recorrer->sig;
			}
			if (recorrer->sig != nullptr) {
				this->nelems--;
				delete recorrer->sig;
				recorrer->sig = nullptr;
				this->ult = recorrer;
			}
		}

	}
};
