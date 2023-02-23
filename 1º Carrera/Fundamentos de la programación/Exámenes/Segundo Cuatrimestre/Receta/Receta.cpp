#include"Receta.h"


double totalCalorias(const tReceta& receta);



tReceta crea() {
	tReceta receta;
	receta.contador = 0;
	receta.lista = new tComponente[0];
	cout << "Introduzca el nombre de la recta: ";
	getline(cin, receta.nombre);
	return receta;
}

void inserta(tReceta& receta, const tComponente& componente) {
	tComponentePtr listaaux;
	receta.contador++;
	listaaux = new tComponente[receta.contador];
	for (int i = 0; i < receta.contador - 1; i++) {
		listaaux[i] = receta.lista[i];
	}
	delete[] receta.lista;
	receta.lista = listaaux;
	receta.lista[receta.contador - 1] = componente;
}

void muestra(const tReceta& receta) {
	
	cout << "Receta: " << receta.nombre << endl;
	for (int i = 0; i < receta.contador; i++) {
		muestra(receta.lista[i]);
		cout << endl;
	}
	cout << "Total calorías = " << totalCalorias(receta);
}

double totalCalorias(const tReceta& receta) {
	double caloriasTotal=0;

	for (int i = 0; i < receta.contador; i++) {
		caloriasTotal += calorias(receta.lista[i]);
	}
	return caloriasTotal;
}
void liberar(tReceta& receta) {
	delete[] receta.lista;
}