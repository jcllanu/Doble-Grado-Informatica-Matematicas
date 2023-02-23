//JUAN CARLOS LLAMAS NÚÑEZ


#ifndef autoescuela_h
#define autoescuela_h

#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>

using libro = std::string;
using artista = std::string;

class ventaLibros {
	std::unordered_map<libro, int> libros;
	std::unordered_map<libro, std::pair<int,std::list<libro>::iterator>> ventas;//El primer entero indica el numero de ejemplares vendidos y 
	//el segundo el iterador a la posición que ocupa dentro de los que tiene un numero determinado de ejemplares vendidos
	std::map<int,std::list<libro>> ventasPorEjemplares;

public:
	//Para el análisis del coste, llamamos N a la cantidad de números de ejemplares vendidos distintos, es decir, si se han vendido 4 ejemplares del libro A,  
	//4 ejemplares del libro B, 4 ejemplares del libro C y 4 ejemplares del libro D entonces N=1. Si se hubieran vendido 4 ejemplares del libro A,  
	//3 ejemplares del libro B, 2 ejemplares del libro C y 1 ejemplares del libro D entonces N=4. N es por tanto el número de claves del diccionario ventasporEjemplares


	void nuevoLibro(int n, libro const& l) {//O(1)
		libros[l] += n;
	}

	void comprar(libro const& l) {//O(log(N))
		auto it = libros.find(l);
		if (it == libros.end()) {
			throw std::invalid_argument("Libro no existente");
		}
		else {
			if (it->second == 0) {
				throw std::out_of_range("No hay ejemplares");
			}
			else {
				it->second--;
				//Contabilizar venta
				ventas[l].first++;
				int numEjemplaresAnt = ventas[l].first - 1;
				if (numEjemplaresAnt != 0) {
					ventasPorEjemplares[numEjemplaresAnt].erase(ventas[l].second);
					if (ventasPorEjemplares[numEjemplaresAnt].empty())
						ventasPorEjemplares.erase(numEjemplaresAnt);
				}
				ventasPorEjemplares[numEjemplaresAnt + 1].push_front(l);
				ventas[l].second = ventasPorEjemplares[numEjemplaresAnt + 1].begin();
				
			}
		}
	}


	bool estaLibro(libro const& l) {//O(1)
		return libros.count(l) == 1;
	}


	void elimLibro(libro const& l) {//O(log(N))
		libros.erase(l);
		auto it = ventas.find(l);
		if (it != ventas.end()) {
			int pos = it->second.first;
			ventasPorEjemplares[pos].erase(it->second.second);
			if (ventasPorEjemplares[pos].empty())
				ventasPorEjemplares.erase(pos);
			
			ventas.erase(l);
		}
	}

	int numEjemplares(libro const& l) {//O(1)
		auto it = libros.find(l);
		if (it == libros.end()) {
			throw std::invalid_argument("Libro no existente");
		}
		else {
			return it->second;
		}
	}

	std::vector<libro> top10() {//O(1) Realmente es constante porque tomamos los 10 primeros elementos que nos encontramos
		std::vector<libro> dev;
		if (ventasPorEjemplares.size() != 0) {
			auto it = --ventasPorEjemplares.end();
			while (it != ventasPorEjemplares.begin() && dev.size() < 10) {
				for (libro l : it->second) {
					dev.push_back(l);
					if (dev.size() == 10)
						break;
				}
				--it;
			}
			if (dev.size() < 10) {
				for (libro l : it->second) {
					dev.push_back(l);
					if (dev.size() == 10)
						break;
				}
			}
		}

		return dev;
	}
};
#endif