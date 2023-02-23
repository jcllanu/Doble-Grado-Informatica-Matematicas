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





	int altura() {
		return altura_priv(this->raiz);
	}
	int nodos() {
		return nodos_priv(this->raiz);
	}
	int hojas() {
		return hojas_priv(this->raiz);
	}
private:
	int altura_priv(Link raiz) {
		if (raiz == nullptr) {
			return 0;
		}
		else {
			return 1 + std::max(altura_priv(raiz->left), altura_priv(raiz->right));
		}
	}

	int nodos_priv(Link raiz) {
		if (raiz == nullptr) {
			return 0;
		}
		else {
			return 1 + nodos_priv(raiz->left) + nodos_priv(raiz->right);
		}
	}

	int hojas_priv(Link raiz) {
		if (raiz == nullptr) {
			return 0;
		}
		else {
			return hojas_priv(raiz->left) + hojas_priv(raiz->right) + (raiz->left==nullptr && raiz->right == nullptr ? 1 : 0);
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

