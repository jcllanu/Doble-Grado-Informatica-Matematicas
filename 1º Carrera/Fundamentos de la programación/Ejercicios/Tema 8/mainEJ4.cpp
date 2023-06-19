#include <iostream>
#include <string.h>
#include "listaProductos.h"

using namespace std;

//Gestión de productos y de stock

int main(){
	tStock l;
	bool b = leer_stock(l);
	sort(l);
	cout << "El activo total es:  " << activoTotal(l) << endl;
	mostrar(l);
	system("pause");
}