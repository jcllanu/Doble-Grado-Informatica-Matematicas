#include"Conjunto.h"
#include"checkML.h"

void cjto_vacio(tConjunto & c) {
	for (int i = 0; i < N; i++) {
		c.elementos[i] = false;
	}
	c.numElem = 0;
}

void cjto_lleno(tConjunto & c) {
	for (int i = 0; i < N; i++) {
		c.elementos[i] = true;
	}
	c.numElem = N;
}

bool pertenece(const tConjunto & c, int e) {
	return c.elementos[e - 1];
}

void annadeElemento(tConjunto & c, int e) {
	if (!c.elementos[e - 1]) {
		c.elementos[e - 1] = true;
		c.numElem++;
	}
}

void borraElemento(tConjunto & c, int e) {
	if (c.elementos[e - 1]) {
		c.elementos[e - 1] = false;
		c.numElem--;
	}
}

int numElems(const tConjunto & c) {
	return c.numElem;
}

bool esUnitario(const tConjunto & c, int & e) {
	bool unit = (numElems(c) == 1);
	if (unit) {
		e = 0;
		while (!c.elementos[e]) {
			e++;
		}
		e++;
	}
	return unit;
}

void mostrar(const tConjunto & c) {
	for (int i = 0; i < N; i++) {
		if (c.elementos[i]) {
			cout << i + 1 << " ";
		}
	}
}