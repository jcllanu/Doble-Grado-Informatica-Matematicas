#pragma once
#include"colaDoble.h"
#include <iostream>

template <class T>
class ColaMezclar :public deque<T> {
	using Nodo = typename deque<T>::Nodo;

public:

	void print(std::ostream& o = std::cout) const {
		Nodo* aux = this->fantasma->sig;
		while (aux != this->fantasma) {
			o << aux->elem << " ";
			aux = aux->sig;
		}
		o << '\n';
	}

	void entremezclar(ColaMezclar<T>& cola) {
		Nodo* actualCola1 = this->fantasma->sig;
		Nodo* actualCola2 = cola.fantasma->sig;
		this->nelems += cola.nelems;
		while (actualCola1 != this->fantasma && actualCola2!= cola.fantasma) {
			cola.fantasma->sig = actualCola2->sig;
			cola.fantasma->sig->ant = cola.fantasma;
			
			actualCola2->sig = actualCola1->sig;
			actualCola2->sig->ant = actualCola2;

			actualCola1->sig = actualCola2;
			actualCola2->ant = actualCola1;

			actualCola1 = actualCola2->sig;
			actualCola2= cola.fantasma->sig;
		}
		if (actualCola1 == this->fantasma) {
			this->fantasma->ant->sig = cola.fantasma->sig;
			cola.fantasma->sig->ant = this->fantasma->ant;

			this->fantasma->ant = cola.fantasma->ant;
			cola.fantasma->ant->sig = this->fantasma;

			cola.fantasma->sig = cola.fantasma;
			cola.fantasma->ant = cola.fantasma;
		}
		cola.nelems = 0;

	}
};


