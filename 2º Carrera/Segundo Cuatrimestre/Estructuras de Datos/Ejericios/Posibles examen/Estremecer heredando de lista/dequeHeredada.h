#pragma once
#include"lista.h"
#include <iostream>

template <class T>
class ListaEstremecer :public list<T> {
	using Nodo = typename deque<T>::Nodo;

public:

	void print(std::ostream& o = std::cout) const {
		Nodo* aux = this->fantasma->sig;
		while (aux != this->fantasma) {
			o << aux->elem << " ";
			aux = aux->sig;
		}
		o << '\n';
		aux = this->fantasma->ant;
		while (aux != this->fantasma) {
			o << aux->elem << " ";
			aux = aux->ant;
		}
		o << '\n';
	}

	void estremecer() {
		if (this->nelems > 2) {
			Nodo* actual = this->fantasma->sig->sig;
			Nodo* primerImpar = actual;
			Nodo* ultimoImpar = actual;
			bool seguir = true;
			while (seguir) {
				actual->sig->ant = actual->ant;
				actual->ant->sig = actual->sig;
				
				if (actual->sig == this->fantasma) {
					seguir = false;
				}else if (actual->sig->sig == this->fantasma) {
					seguir = false;
				}
				Nodo* siguienteActual = actual->sig->sig;
				if (actual != primerImpar) {
					actual->sig = ultimoImpar;
					ultimoImpar->ant = actual;
				}
				ultimoImpar = actual;
				actual = siguienteActual;

			}//Al llegar aquí this es una lista donde solo están los elementos de las posiciones pares
			this->fantasma->ant->sig = ultimoImpar;
			ultimoImpar->ant = this->fantasma->ant;
			primerImpar->sig = this->fantasma;
			this->fantasma->ant = primerImpar;
		}
	}
};


