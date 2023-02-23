
//Juan Carlos Llamas


#include <iostream>
#include <fstream>
using namespace std;

#include "deque_eda.h"

class EngordarLista : public deque<int> {
	using Nodo = deque<int>::Nodo;
public:
	// imprime la lista enlazada
	void print(std::ostream & o = std::cout) const {
		Nodo* aux = this->fantasma->sig;
		while (aux != this->fantasma) {
			o << aux->elem << " ";
			aux = aux->sig;
		}

	}

	// introduce los elementos de other (una lista enlazada)
	// en la lista representada por this alternativamente al principio y al final
	void engordar(EngordarLista & secundaria) {
		int tamSec = secundaria.size();
		for (int i = 0; i < tamSec; i++) {
			Nodo* insertado;
			insertado = secundaria.fantasma->sig;
			insertado->sig->ant = secundaria.fantasma;
			secundaria.fantasma->sig = insertado->sig;
			if (i % 2 == 0) {
				this->fantasma->sig->ant = insertado;
				insertado->sig = this->fantasma->sig;
				this->fantasma->sig = insertado;
				insertado->ant = this->fantasma;
			}
			else {
				this->fantasma->ant->sig = insertado;
				insertado->ant = this->fantasma->ant;
				this->fantasma->ant = insertado;
				insertado->sig = this->fantasma;

			}
			--secundaria.nelems;
			this->nelems++;
		}
	}
};


inline std::ostream& operator<<(std::ostream & o, EngordarLista const& lista) {
	lista.print(o);
	return o;
}

EngordarLista leerLista() {
	EngordarLista lista;
	int n, val;
	std::cin >> n; // tamaño
	while (n--) {
		std::cin >> val;
		lista.push_back(val);
	}
	return lista;
}


void resuelveCaso() {
	auto lista1 = leerLista();
	auto lista2 = leerLista();
	lista1.engordar(lista2);
	std::cout << lista1 << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	cin >> casos;
	while (casos--) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
