
// JUAN CARLOS LLAMAS NÚÑEZ Y ADRIÁN SANJUÁN ESPEJO

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include<string>

using namespace std;
class persona {
private:
	int edad; 
	string nombre; 
	
public:
	// constructora
	persona(int age = 0, string name="") {
		edad = age;
		nombre = name;
		
	}

	// observadoras
	int getedad() const { return edad; }
	string getnombre() const { return nombre; }
	
//lectura y escritura
	void read(std::istream & input = std::cin) {
		int edad;
		string nombre;
		char aux;
		input >> edad;
		input.get(aux);
		getline(input, nombre);
		*this = persona(edad,nombre);
	}
	void print(std::ostream& o = std::cout) const {
		o <<nombre;
	}

};

inline std::ostream & operator<<(std::ostream & salida, persona const& p) {
	p.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, persona & p) {
	p.read(entrada);
	return entrada;
}

#endif
