#pragma once
#pragma once

// JUAN CARLOS LLAMAS NÚÑEZ

#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include <cmath>
#include <vector>

using namespace std;

typedef struct {
	int coeficiente;
	int grado;
}tPar;


class polinomio {

private:
	vector<tPar> monomios;

	void busqueda_binaria(vector<tPar> v, int ini, int fin, bool& encontrado, int& pos, int grado) {
		if (ini > fin) {
			encontrado = false;
			pos = ini;
		}
		else {
			int m = (ini + fin) / 2;
			if (grado < v[m].grado) {
				busqueda_binaria(v, ini, m - 1, encontrado, pos, grado);
			}
			else if (grado == v[m].grado) {
				encontrado = true;
				pos = m;
			}
			else {
				busqueda_binaria(v, m + 1, fin, encontrado, pos, grado);
			}
		}
	}
public:
	// constructora
	polinomio() {}

	void annadir(int grado, int coeficiente) {
		if (coeficiente != 0 && grado >= 0) {
			if (monomios.size() == 0) {
				monomios.push_back({ coeficiente,grado });
			}
			else {
				bool encontrado;
				int pos;
				busqueda_binaria(monomios, 0, monomios.size() - 1, encontrado, pos, grado);
				if (encontrado) {
					monomios[pos].coeficiente += coeficiente;
					if (monomios[pos].coeficiente == 0) {
						for (int i = pos; i < monomios.size() - 1; i++) {
							monomios[i] = monomios[i + 1];
						}
						monomios.pop_back();
					}
				}
				else {
					monomios.push_back({ coeficiente,grado });
					for (int i = monomios.size() - 2; i >= pos; i--) {
						monomios[i + 1] = monomios[i];
					}
					monomios[pos] = { coeficiente,grado };
				}
			}
		}
	}
	long long int evaluar(int x) {
		long long int resultado = 0;
		for (int i = monomios.size() - 1; i >= 1; i--) {
			resultado += monomios[i].coeficiente;
			resultado *= x;
			for (int j = 1; monomios[i].grado - j != monomios[i - 1].grado; j++) {
				resultado *= x;
			}
		}
		if (monomios.size() > 0) {
			resultado += monomios[0].coeficiente;
			for (int i = 0; i < monomios[0].grado; i++) {
				resultado *= x;
			}
		}

		return resultado;
	}
	long long int evaluar2(int x) {
		long long int resultado = 0;
		int grado = 0;
		long long int x_exp_j = 1;
		for (int i = 0; i < monomios.size(); i++) {
			while (grado < monomios[i].grado) {
				x_exp_j *= x;
				grado++;
			}
			resultado += (monomios[i].coeficiente * x_exp_j);
		}
		return resultado;
	}

};



#endif
