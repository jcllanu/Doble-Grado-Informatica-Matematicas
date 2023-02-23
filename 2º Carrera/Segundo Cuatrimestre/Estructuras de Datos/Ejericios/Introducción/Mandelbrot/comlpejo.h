#pragma once

// JUAN CARLOS LLAMAS NÚÑEZ

#ifndef COMPLEJOS_H
#define COMPLEJOS_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include <cmath>

template<class T>
class complejo {
private:
	T pReal;
	T pImag;
	
public:
	// constructora
	complejo(T real, T imag) {
		pReal = real;
		pImag = imag;
	}

	// lectura
	
	void read(std::istream & input = std::cin) {
		T real, imag;

		input >> real >> imag;
		*this = complejo(real, imag);
	}
	
	// operaciones

	complejo operator+(complejo const& c) {
		pReal = pReal + c.pReal;
		pImag = pImag + c.pImag;
		return *this;
	}
	complejo operator*( complejo const c) {
		T aux = pReal;
		pReal = pReal * c.pReal - pImag * c.pImag;
		pImag = aux * c.pImag  + pImag * c.pReal;
		return *this;
	}
	T mod() {
		return sqrt(pReal*pReal + pImag * pImag);
	}
};

#endif
