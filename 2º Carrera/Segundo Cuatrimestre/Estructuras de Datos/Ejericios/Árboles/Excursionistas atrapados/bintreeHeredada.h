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


	std::pair<int,int> gruposRescate() {
		return gruposRescate_priv(this->raiz);
	}
	
private:
	std::pair<int, int> gruposRescate_priv(Link raiz) {
		if (raiz == nullptr) {
			return { 0,0 };
		}
		else {
			std::pair<int, int> solIzq = gruposRescate_priv(raiz->left);
			std::pair<int, int> solDer = gruposRescate_priv(raiz->right);
			std::pair<int, int> sol;
			sol.first = (solIzq.first == 0 && solDer.first == 0 && raiz->elem != 0 ? 1 : solDer.first + solIzq.first);
			sol.second = raiz->elem + std::max(solDer.second, solIzq.second);
			return sol;
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

