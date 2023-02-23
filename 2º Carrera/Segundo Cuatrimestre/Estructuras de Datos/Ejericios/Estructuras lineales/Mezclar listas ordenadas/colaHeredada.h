#pragma once
#include"queue.h"
#include <iostream>

template <class T>
class ColaMezclar :public queue<T> {
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

	void mezclar(ColaMezclar<T>& cola) {
		Nodo* recorreC1 = this->prim;
		Nodo* recorreC2 = cola.prim;
		Nodo* ultimoOrdenado;
		if (this->nelems == 0) {
			this->nelems = cola.nelems;
			this->prim = cola.prim;
			this->ult = cola.ult;
			cola.nelems = 0;
			cola.ult = cola.prim = nullptr;
		}
		else if (cola.nelems != 0) {
			if (recorreC2->elem < recorreC1->elem) {
				this->prim = recorreC2;
				ultimoOrdenado = recorreC2;
				recorreC2 = recorreC2->sig;
			}
			else {
				ultimoOrdenado = recorreC1;
				recorreC1 = recorreC1->sig;
			}
			while (recorreC1 != nullptr && recorreC2 != nullptr) {
				if (recorreC2->elem < recorreC1->elem) {
					ultimoOrdenado->sig = recorreC2;
					ultimoOrdenado = recorreC2;
					recorreC2 = recorreC2->sig;
				}
				else {
					ultimoOrdenado->sig = recorreC1;
					ultimoOrdenado = recorreC1;
					recorreC1 = recorreC1->sig;
				}
			}
			if (recorreC1 == nullptr) {
				ultimoOrdenado->sig = recorreC2;
				this->ult = cola.ult;
			}
			else {
				ultimoOrdenado->sig = recorreC1;
			}
			this->nelems += cola.nelems;
			cola.nelems = 0;
			cola.ult = cola.prim = nullptr;
		}
	}
};

