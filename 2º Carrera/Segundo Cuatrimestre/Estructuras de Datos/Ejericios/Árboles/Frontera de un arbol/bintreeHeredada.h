#pragma once
#include"bintree.h"
#include <iostream>
#include <vector>


template <class T>
class bintreeExt : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:
	bintreeExt() : bintree<T>() {}
	bintreeExt(bintreeExt<T> const& l, T const& e, bintreeExt<T> const& r) : bintree<T>(l, e, r) {}


	std::vector<T> frontera() {
		std::vector<T> front;
		frontera_priv(this->raiz, front);
		return front;
	}
	
private:
	void frontera_priv(Link raiz, std::vector<T> & front) {
		if (raiz != nullptr) {
			if (raiz->left == nullptr && raiz->right == nullptr) {
				front.push_back(raiz->elem);
			}
			else {
				frontera_priv(raiz->left, front);
				frontera_priv(raiz->right, front);
			}
		}
	}

	
};

template <typename T>
bintreeExt<T> leerArbolExt(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolExt(vacio);
		auto dr = leerArbolExt(vacio);
		return { iz, raiz, dr };
	}
}

