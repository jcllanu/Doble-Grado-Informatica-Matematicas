#pragma once
//
//  conjunto.h
//

#ifndef conjunto_h
#define conjunto_h

#include <stdexcept>  // std::domain_error
#include <utility>    // std::move

template <class T>
class set {
public:
	set(int tam = TAM_INICIAL); // constructor
	set(set<T> const& other); // constructor por copia
	set<T> & operator=(set<T> const& other); // operador de asignación
	~set(); // destructor
	void insert(T e); // se ha modificado para garantizar el orden en el conjunto (de mayor a menor)
	bool contains(T e) const; // podria implementarse usando la busqueda binaria al tener ahora los elementos ordenados
	void erase(T e); // no lo usamos pero habría que modificarlo para garantizar que se conserva el orden al eliminar un elemento
	bool empty() const;
	int size() const;
	T ver_menor() const; // método añadido
	void eliminar_menor(); // método añadido
private:
	const static int TAM_INICIAL = 8;
	int contador;
	int capacidad;
	T * datos;
	void amplia();
	void libera();
	void copia(set<T> const& other);
	void busqueda_binaria(int ini, int fin, bool& encontrado, int& pos, T e);
};

template <class T>
set<T>::set(int tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() {
	libera();
}

template <class T>
void set<T>::libera() {
	delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
	copia(other);
}

/** Operador de asignación */
template <class T>
set<T> & set<T>::operator=(set<T> const& other) {
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (int i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}

template <class T>
void set<T>::insert(T e) {
	bool encontrado;
	int pos;
	busqueda_binaria(0,contador-1,encontrado,pos, e);
	if (!encontrado) {
		if (contador == capacidad)
			amplia();
		for (int i = contador - 1; i >= pos; i--) {
			datos[i + 1] = datos[i];
		}
		datos[pos] = e;
		contador++;
	}
}

template <class T>
bool set<T>::contains(T e) const {
	int i = 0;
	while (i < contador && datos[i] != e)
		++i;
	return i < contador;
}

template <class T>
void set<T>::amplia() {
	T * nuevos = new T[2 * capacidad];
	for (int i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
	int i = 0;
	while (i < contador && datos[i] != e)
		++i;
	if (i < contador) {
		datos[i] = datos[contador - 1];
		--contador;
	}
	else
		throw std::domain_error("El elemento no esta");
}


template <class T>
bool set<T>::empty() const {
	return contador == 0;
}

template <class T>
int set<T>::size() const {
	return contador;
}

template <class T>
void set<T>::busqueda_binaria(int ini, int fin, bool& encontrado, int& pos, T e) {
	if (ini > fin) {
		encontrado = false;
		pos = ini;
	}
	else {
		int m = (ini + fin) / 2;
		if (e > datos[m]) {
			busqueda_binaria(ini, m - 1, encontrado, pos, e);
		}
		else if (e == datos[m]) {
			encontrado = true;
			pos = m;
		}
		else {
			busqueda_binaria(m + 1, fin, encontrado, pos, e);
		}
	}
}

template <class T>
T set<T>::ver_menor() const {
	if (!empty()) {
		return datos[contador - 1];
	}
	else {
		throw std::domain_error("El menor del vacío no está definido");
	}
}
template <class T>
void set<T>::eliminar_menor() {
	if (contador > 0) {
		contador--;
	}
	else {
		throw std::domain_error("El menor del vacío no está definido");
	}
}
#endif // conjunto_h