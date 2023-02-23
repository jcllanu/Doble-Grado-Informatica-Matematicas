#pragma once
#include"queue.h"
#include <iostream>

template <class T>
class ColaInsertar :public queue<T>{
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

	void insertar(ColaInsertar<T>& cola, int n) {
		if (n <= this->nelems) {
			if (n == 0) {
				cola.ult->sig = this->prim;
				this->prim = cola.prim;
			}
			else if (n == this->nelems) {
				this->ult->sig = cola.prim;
				this->ult = cola.ult;
			}
			else {
				Nodo* recorrer = this->prim;
				Nodo* aux;
				for (int i = 0; i < n - 1; i++) {
					recorrer = recorrer->sig;
				}
				aux = recorrer->sig;
				recorrer->sig = cola.prim;
				while (recorrer->sig != nullptr) {
					recorrer = recorrer->sig;
				}
				recorrer->sig = aux;
				
			}
			this->nelems += cola.nelems;
			cola.prim = cola.ult = nullptr;
			cola.nelems = 0;
		}
		else {
			throw std::domain_error("datos invalidos");
		}
	}
};
