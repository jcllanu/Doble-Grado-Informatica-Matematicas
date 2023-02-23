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


	int diametro() {
		int altura;
		return diametro_priv(this->raiz, altura);
	}
	
private:
	int diametro_priv(Link raiz, int& altura) {
		if (raiz == nullptr) {
			altura = 0;
			return 0;
		}
		else {
			int alturaDer, alturaIzq;
			int diamIzq = diametro_priv(raiz->left, alturaIzq);
			int diamDer = diametro_priv(raiz->right, alturaDer);
			altura = 1 + std::max(alturaDer, alturaIzq);
			return std::max(std::max(diamIzq, diamDer), 1 + alturaDer + alturaIzq);
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

