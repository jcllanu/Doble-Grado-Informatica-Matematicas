#include"Conjunto.h"


void cjto_vacio(tConjunto& conjunto) {
	for (int i = 0; i < N; i++) {
		conjunto.elementos[i] = false;
	}
	conjunto.numElem=0;
}
void cjto_lleno(tConjunto& conjunto) {
	for (int i = 0; i < N; i++) {
		conjunto.elementos[i] = true;
	}
	conjunto.numElem = N;
}
int numElems(const tConjunto& conjunto) {
	return conjunto.numElem;
}
bool pertenece(const tConjunto& conjunto, int num) {
	return conjunto.elementos[num - 1];
}
void annadeElemento(tConjunto& conjunto, int num) {
	if (!conjunto.elementos[num - 1]) {
		conjunto.elementos[num - 1] = true;
		conjunto.numElem++;
	}

}
void borraElemento(tConjunto& conjunto, int num) {
	if (conjunto.elementos[num - 1]) {
		conjunto.elementos[num - 1] = false;
		conjunto.numElem--;
	}
}
bool esUnitario(const tConjunto& conjunto, int& e) {
	bool unit = (conjunto.numElem == 1);
	if (unit) {
		e = 0;
		while (!conjunto.elementos[e]) {
			e++;
		}
		e++;
	}
	return unit;
}
void mostrar(const tConjunto& conjunto) {
	for (int i = 0; i < N; i++) {
		if (conjunto.elementos[i]) {
			cout << i + 1 << " ";
		}
	}
}
