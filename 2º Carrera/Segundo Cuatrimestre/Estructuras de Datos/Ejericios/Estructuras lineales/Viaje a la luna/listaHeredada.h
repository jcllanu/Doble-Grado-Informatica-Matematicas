#pragma once
#include"list_eda.h"
#include <iostream>

template <class T>
class ListaHereda :public list<T> {
	using Nodo = typename list<T>::Nodo;
	

public:
	template<class Predicado>
	void remove_if(Predicado pred) {
		Nodo *it = this->fantasma->sig;
		while (it != this->fantasma) {
			if (pred(it->elem)) {
				Nodo* sig = it->sig;
				it->ant->sig = sig;
				sig->ant = it->ant;
				delete it;
				it = sig;
				
			}
			else {
				it = it->sig;
			}
		}
	}
};

