#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;
int const NUM_PRODUCTOS = 4;
int const MAX_CESTA = NUM_PRODUCTOS;
typedef struct {
	string codigo;
	string descripcion;
	float precio;
	bool oferta;
}tInfoProducto;
typedef tInfoProducto tCatalogo[NUM_PRODUCTOS];
typedef struct{
	string codigo;
	int unidades;
}tProducto;
typedef tProducto tLista [MAX_CESTA];
typedef struct {
	tLista datos;
	int contador;
}tCesta;

int menu();
bool cargar(tCatalogo& catalogo);
void mostrarProductos(const tCatalogo& catalogo);
void llenarCesta(tCesta& cesta, const tCatalogo& catalogo);
bool estaEnCatalogo(string codigo, const tCatalogo& catalogo);
bool posCesta(string codigo, const tCesta& cesta, int& pos);
void guardar(const tCesta& cesta, const tCatalogo& catalogo);
float precioLinea(int i, const tCesta& cesta, const tCatalogo& catalogo);
bool estaEnOferta(string codigo, const tCatalogo& catalogo, float& precio);

int main() {
	system("chcp 1252");
	int op;
	tCatalogo catalogo;
	tCesta cesta;
	cesta.contador = 0;
	if (cargar(catalogo)) {
		op = menu();
		while (op != 0) {

			switch (op) {
			case 1:
			{
				mostrarProductos(catalogo);
				llenarCesta(cesta, catalogo);
			}
			break;
			case 2:
			{
				guardar(cesta,catalogo);
			}
			}


			op = menu();
		}
	}
	else {
		cout << "ERROR: Archivo de carga no encontrado." << endl;
	}
	

	system("pause");
	return 0;
}
int menu() {
	int op;

	cout << "1.- Añadir producto a la cesta" << endl;
	cout << "2.- Confirmar pedido" << endl;
	cout << "0.- Salir" << endl;
	cout << "Selecione una de las opciones (1/2) o finalice el programa (0): ";
	cin >> op;
	while (op < 0 || op>2 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Selecione una de las opciones (1/2) o finalice el programa (0): ";
		cin >> op;
	}
	return op;
}
bool cargar(tCatalogo& catalogo) {
	ifstream archivo;
	bool encontrado;
	string codigo, descripcion;
	float precio;
	bool oferta;


	archivo.open("productos.txt");
	if (!archivo.is_open()) {
		encontrado = false;
	}
	else {
		encontrado = true;
		for (int i = 0; i < NUM_PRODUCTOS; i++) {
			archivo >> codigo;
			archivo >> precio;
			archivo >> oferta;
			getline(archivo, descripcion);
			catalogo[i].codigo = codigo;
			catalogo[i].precio = precio;
			catalogo[i].oferta = oferta;
			catalogo[i].descripcion = descripcion;
		}
	}
	archivo.close();
	return encontrado;
}
void mostrarProductos(const tCatalogo& catalogo) {
	cout << endl << "Codigo    Descripcion                   Precio" << endl;
	for (int i = 0; i < NUM_PRODUCTOS; i++) {
		cout << setw(5) << left << catalogo[i].codigo << "     " << setw(30) << left << catalogo[i].descripcion << setw(5) << setprecision(3) << catalogo[i].precio;
		if (catalogo[i].oferta == 1) {
			cout << "   En oferta";
		}
		cout << endl;
	}
}
void llenarCesta(tCesta& cesta, const tCatalogo& catalogo) {
	string codigo;
	int unidades, pos = 0;
	char sobreescribir;

	cout << endl << "Introduzca el código del producto que quiera añadir a la cesta (XXX para terminar): ";
	cin >> codigo;
	while (codigo != "XXX") {
		if (!estaEnCatalogo(codigo,catalogo)) {
			cout << "Ese producto no se encuentra en nuestro catálogo." << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		else {
			cout << "Introduzca el número de unidades que desa del producto con código " << codigo << ": ";
			cin >> unidades;
			while (unidades < 0 || cin.fail()) {
				cout << "Número incorrecto. Introduzca el número de unidades: ";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> unidades;
			}
			if (posCesta(codigo, cesta, pos)) {
				cout << "Ya había añadido a la cesta " << cesta.datos[pos].unidades << " unidades de este producto." << endl;
				cout << "¿Desea sustituir las antiguas unidades por las indicadas? (S/N): ";
				cin >> sobreescribir;
				if (sobreescribir == 'S') {
					cesta.datos[pos].unidades = unidades;
				}
			}
			else {
				cesta.datos[pos].unidades = unidades;
				cesta.datos[pos].codigo = codigo;
				cesta.contador++;
			}
		}
		cout << endl << "Introduzca el código del producto que quiera añadir a la cesta (XXX para terminar): ";
		cin >> codigo;
	}

}
bool estaEnCatalogo(string codigo, const tCatalogo& catalogo) {
	bool encontrado=false;
	int pos = 0;
	while (!encontrado && pos < NUM_PRODUCTOS) {
		if (codigo == catalogo[pos].codigo) {
			encontrado = true;
		}
		pos++;
	}
	return encontrado;
}
bool posCesta(string codigo, const tCesta& cesta, int& pos) {
	bool encontrado = false;
	while (!encontrado && pos < cesta.contador) {
		if (codigo == cesta.datos[pos].codigo) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}
	return encontrado;
}
void guardar(const tCesta& cesta, const tCatalogo& catalogo) {
	ofstream archivo;
	archivo.open("compra.txt");
	float precio, total = 0;;
	for (int i = 0; i < cesta.contador; i++) {
		precio = precioLinea(i, cesta, catalogo);
		total += precio;
		archivo << cesta.datos[i].codigo << "   " << setw(2) << cesta.datos[i].unidades << "   " << setw(10) << setprecision(4) << precio << endl;
	}
	archivo << "XXX";
	cout << endl << "El precio total de la compra es de " << total << "€" << endl << endl;

	archivo.close();
}
float precioLinea(int i, const tCesta& cesta, const tCatalogo& catalogo) {
	float total, precio;
	if (estaEnOferta(cesta.datos[i].codigo, catalogo, precio)) {
		if (cesta.datos[i].unidades % 2 == 0) {
			total = cesta.datos[i].unidades*precio / 2;
		}
		else {
			total = (cesta.datos[i].unidades + 1)*precio / 2;
		}
	}
	else {
		total = cesta.datos[i].unidades*precio;
	}
	return total;
}
bool estaEnOferta(string codigo, const tCatalogo& catalogo, float& precio) {
	
	int pos = 0;
	while (codigo!= catalogo[pos].codigo) {
		pos++;
	}
	precio = catalogo[pos].precio;
	return catalogo[pos].oferta;
}