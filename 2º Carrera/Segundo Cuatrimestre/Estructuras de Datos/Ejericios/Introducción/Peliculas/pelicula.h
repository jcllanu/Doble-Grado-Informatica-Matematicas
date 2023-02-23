#pragma once

#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include"horas.h"
#include<string>
using namespace std;
class pelicula {
private:
    horas horaInicial; 
    horas horaFinal;
	string titulo;
public:
    // constructora
   pelicula(horas horaIni=NULL, horas duracion=NULL, string title="") {
	   horaFinal = horaIni + duracion;
	   horaInicial = horaIni;
	   titulo = title;
    }

    // operador de comparación
    bool operator<(pelicula const& p) const {
        return horaFinal<p.horaFinal|| (horaFinal == p.horaFinal && titulo<p.titulo);
    }

    void read(std::istream& input = std::cin) {
		horas horaIni, duracion;
		string title;
		horaIni.read(input);
		duracion.read(input);
		getline(input,title);
		*this = pelicula(horaIni, duracion, title);
    }
    void print(std::ostream& o = std::cout) const {
		horaFinal.print(o);
		o << " " << titulo;
    }

};

inline std::ostream & operator<<(std::ostream & salida, pelicula const& h) {
	h.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, pelicula & h) {
	h.read(entrada);
	return entrada;
}
#endif
