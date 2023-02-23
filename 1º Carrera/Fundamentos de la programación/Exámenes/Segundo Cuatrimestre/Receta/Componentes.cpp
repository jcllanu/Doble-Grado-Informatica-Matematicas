#include"Componente.h"



tComponente leeComponente(tListaIngredientes& listaIngredientes) {
	string nombreIngr;
	tComponente componente;
	int pos, ini = 0, fin = listaIngredientes.contador - 1;

	nombreIngr = selectIngred(listaIngredientes);
	pos = busca(listaIngredientes, nombreIngr, ini, fin);

	componente.ingredientePtr = listaIngredientes.lista[pos];
	cout << "Introduzca los gramos que se necesitan de este ingrediente: ";
	cin >> componente.gramos;
	while (componente.gramos <= 0 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Introduzca los gramos que se necesitan de este ingrediente: ";
		cin >> componente.gramos;
	}
	return componente;
}

void muestra(const tComponente& componente) {

	cout << "     " << setw(4) << right << componente.gramos << " gr. de " << devuelveNombre(*componente.ingredientePtr);
}

double calorias(const tComponente& componente) {

	return componente.gramos*calorias(*componente.ingredientePtr) / 100;
}