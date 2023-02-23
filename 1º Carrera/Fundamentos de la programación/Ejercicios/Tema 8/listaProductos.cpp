#include"listaProductos.h"
//void insertar(tStock & stock);
bool leer_stock(tStock & stock) {
	ifstream archivo;
	tProducto producto;
	int codigo, uds;
	double precio;
	string nombre;
	bool ok = false;
	stock.contador = 0;
	archivo.open("stock.txt");
	if (archivo.is_open()){
		ok = true;
		archivo >> codigo;
		while (stock.contador < MAX && codigo != -1) {
			archivo >> nombre;
			archivo >> precio;
			archivo >> uds;
			stock.lista[stock.contador] = crear(codigo, nombre, precio, uds);
			stock.contador++;
			archivo >> codigo;
		}
	}


	return ok;
}

double activoTotal(tStock stock) {
	double suma=0;
	for (int i = 0; i < stock.contador; i++) {
		suma += activoProducto(stock.lista[i]);
	}
	return suma;
}
void mostrar(tStock stock) {
	for (int i = 0; i < stock.contador; i++) {
		mostrar(stock.lista[i]);
		cout << endl;
	}
}
void sort(tStock & stock){
	tProducto aux;
	bool encontrado;
	int cont;
 	for (int i = 1; i < stock.contador; i++) {
		aux = stock.lista[i];
		cont = i - 1;
		encontrado = false;
		while (!encontrado && cont >= 0) {
			if (aux > stock.lista[cont]) {
				stock.lista[cont + 1] = stock.lista[cont];
				cont--;
			}
			else {
				encontrado = true;
				
			}
		}
		stock.lista[cont + 1] = aux;
	}
}
/*void insertar(tStock & stock) {

}*/