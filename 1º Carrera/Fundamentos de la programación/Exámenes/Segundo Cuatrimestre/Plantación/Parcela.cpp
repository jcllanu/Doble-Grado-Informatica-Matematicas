#include"Parcela.h"

int buscarPos(const tParcelaPtr& puntAParcela, const tListaParcelas& listaParcelas);



void escribirParcela(const tParcela& parcela) {
	cout << setw(16) << parcela.identificador << "(" << parcela.fila << "," << parcela.columna << setw(15) << ")" << parcela.platanos << endl;
}
void guardarParcela(const tParcela& parcela, ofstream& archivo) {
	archivo << setw(16) << parcela.identificador << "(" << parcela.fila << "," << parcela.columna << setw(15) << ")" << parcela.platanos << endl;
}
bool operator<(const tParcela& parcela1, const tParcela& parcela2) {
	bool menor;

	if (parcela1.platanos < parcela2.platanos) {
		menor = true;
	}
	else {
		menor = false;
	}
	return menor;
}

void crearParcelas(const tPlantacion& plantacion, int len, tListaParcelas& listaParcelas) {
	tParcelaPtr puntAParcela;
	int pos;
	listaParcelas.contador = 0;
	for (int i = 0; i*len < devuelveFilas(plantacion); i++) {
		for (int j = 0; j*len < devuelveColumnas(plantacion); j++) {
			puntAParcela = new tParcela;
			puntAParcela->identificador = devuelveIdentificador(plantacion);
			puntAParcela->fila = i * len;
			puntAParcela->columna = j * len;
			puntAParcela->platanos= calcularPlatanosParcela(plantacion, puntAParcela->fila,puntAParcela->columna, len);
			
			pos = buscarPos(puntAParcela, listaParcelas);
			listaParcelas.contador++;
			for (int i = listaParcelas.contador-1; i > pos; i--) {
				listaParcelas.lista[i] = listaParcelas.lista[i - 1];
			}
			listaParcelas.lista[pos] = puntAParcela;

		}
	}
}

int buscarPos(const tParcelaPtr& puntAParcela, const tListaParcelas& listaParcelas) {
	int pos= listaParcelas.contador - 1;
	bool encontrado = false;

	while (!encontrado && pos >= 0) {
		if (*puntAParcela < *listaParcelas.lista[pos]) {
			encontrado = true;
		}
		else {
			pos--;
		}
	}
	return pos+1;
}

void mezclar(const tListaParcelas& listaParcelas1, const tListaParcelas& listaParcelas2, tListaParcelas& mezcla) {
	int poslista1=0;
	int poslista2=0;

	mezcla.contador = 0;
	while (mezcla.contador < listaParcelas1.contador + listaParcelas2.contador) {

		if ((poslista2 >= listaParcelas2.contador) || (*listaParcelas2.lista[poslista2] < *listaParcelas1.lista[poslista1])) {
			mezcla.lista[mezcla.contador] = listaParcelas1.lista[poslista1];
			poslista1++;
			mezcla.contador++;
		}
		else {
			mezcla.lista[mezcla.contador] = listaParcelas2.lista[poslista2];
			poslista2++;
			mezcla.contador++;
		}

	}
}

void mostrarListaParcelas(const tListaParcelas& listaParcelas, int& num) {
	if (num < listaParcelas.contador) {
		escribirParcela(*listaParcelas.lista[num]);
		num++;
		mostrarListaParcelas(listaParcelas, num);
	}
}

void liberar(tListaParcelas& listaParcelas) {
	for (int i = 0; i < listaParcelas.contador; i++) {
		delete listaParcelas.lista[i];
	}
}

int devuelvePlatanos(const tListaParcelas& listaParcelas, int pos) {
	return listaParcelas.lista[pos]->platanos;
}
tParcelaPtr devuelveParcelaPtr(const tListaParcelas& listaParcelas, int pos) {
	return listaParcelas.lista[pos];
}