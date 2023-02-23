#pragma once
#include"bintree.h"
#include <iostream>
#include <algorithm>


template <class T>
class bintreeExt : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:
	bintreeExt() : bintree<T>() {}
	bintreeExt(bintreeExt<T> const& l, T const& e, bintreeExt<T> const& r) : bintree<T>(l, e, r) {}


	T minimo() {
		return minimo_priv(this->raiz);
	}
	
private:
	T minimo_priv(Link raiz) {
		T mini = raiz->elem;
		if (raiz->left != nullptr)
			mini = std::min(mini, minimo_priv(raiz->left));
		if (raiz->right != nullptr)
			mini = std::min(mini, minimo_priv(raiz->right));
		return mini;
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

