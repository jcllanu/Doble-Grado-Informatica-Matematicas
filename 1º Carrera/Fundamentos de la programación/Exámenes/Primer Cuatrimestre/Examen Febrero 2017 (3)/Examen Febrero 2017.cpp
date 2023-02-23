#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

int const N_ACC = 10;
string const Lectura1 = "cartera.txt";
string const Lectura2 = "semana.txt";
string const Escritura = "cartera1.txt";

typedef struct {
	string compannia;
	double precio;
	int numAcciones;
}tAccion;

typedef struct {
	char tipo;
	string compannia;
	double precio;
	int numAcciones;
}tOperacion;
typedef tAccion tCartera[N_ACC];

bool cargar(tCartera& cartera);
void mostrar(const tCartera& cartera);
int encontrarCompanyia(const tCartera& cartera, string compannia);
bool procesar(tCartera& cartera);
bool grabar(const tCartera& cartera);
double precioTotal(const tCartera& cartera);


int main() {
	system("chcp 1252");
	tCartera cartera;

	if (!cargar(cartera)) {
		cout << endl << "ERROR: No ha sido posible cargar la cartera" << endl << endl;
	}
	else {
		mostrar(cartera);
		if (!procesar(cartera)) {
			cout << "ERROR: No se ha podido cargar el fichero con la información semanal" << endl;
		}
		else {
			mostrar(cartera);
			if (!grabar(cartera)) {
				cout << endl << "ERROR: No se ha podido guardar la cartera actualizada correctamente.";
			}
			else {
				cout << endl << "La cartera actualizada se ha podido guardar con éxito.";
			}
		}
	}
	cout << endl << endl;
	system("pause");
	return 0;
}

bool cargar(tCartera& cartera) {
	ifstream archivo;
	bool ok = true, repetido = false;
	int contador = 0, pos;
	tAccion accion;

	archivo.open(Lectura1);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		archivo >> accion.compannia;
		while (accion.compannia != "#" && contador < N_ACC && ok) {
			archivo >> accion.precio;
			archivo >> accion.numAcciones;
			for (int i = 0; i < contador; i++) {
				if (cartera[i].compannia == accion.compannia && cartera[i].precio == accion.precio) {
					repetido = true;
					pos = i;
				}
			}
			if (repetido) {
				cartera[pos].numAcciones += accion.numAcciones;
				repetido = false;
			}
			else {
				cartera[contador] = accion;
				contador++;
			}
			archivo >> accion.compannia;
		}
		if (contador < N_ACC) {
			ok = false;
		}
	}
	return ok;
}
void mostrar(const tCartera& cartera) {
	cout << endl<< endl << "Cartera de acciones" << endl << endl;
	cout << "Compañía   Acciones  Precio" << endl;
	for (int i = 0; i < N_ACC; i++) {
		cout << left << setw(12) << cartera[i].compannia << right << setw(3) << cartera[i].numAcciones << right << setw(11) << setprecision(3) << cartera[i].precio << endl;
	}
	cout << "Valor Total : " << setprecision(5) << precioTotal(cartera) << endl;
}
double precioTotal(const tCartera& cartera) {
	double total=0;
	for (int i = 0; i < N_ACC; i++) {
		total += cartera[i].numAcciones*cartera[i].precio;
	}
	return total;
}
int encontrarCompanyia(const tCartera& cartera, string compannia) {
	bool encontrado = false;
	int pos = 0;

	while (!encontrado && pos < N_ACC) {
		if (cartera[pos].compannia == compannia) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}
	if (!encontrado) {
		pos = -1;
	}

	return pos;
}
bool procesar(tCartera& cartera) {
	ifstream archivo;
	tOperacion operacion;
	int pos;
	bool ok = true;

	archivo.open(Lectura2);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		cout << endl << endl << "Operaciones semanales" <<  endl;
		cout << endl << "Operación    Compañía   Número acciones/   Incidencia" << endl;
		cout << "                          Nuevo precio" << endl;
		archivo >> operacion.tipo;
		while (operacion.tipo != 'X') {
			archivo >> operacion.compannia;
			cout << setw(5) << right << operacion.tipo <<setw(10)<<" "<< setw(15) << left << operacion.compannia;
			if (operacion.tipo != 'A') {
				archivo >> operacion.numAcciones;
				cout << setw(15) << left << operacion.numAcciones;
			}
			else {
				archivo >> operacion.precio;
				cout<< setw(15) << left << operacion.precio;
			}
			pos = encontrarCompanyia(cartera, operacion.compannia);
			if (pos == -1 || (operacion.tipo != 'A' && operacion.tipo != 'V' && operacion.tipo != 'C')) {
				cout << " Error: Compañía u operación no existente." << endl;
			}
			else {
				if (operacion.tipo == 'A') {
					cout << " OK" << endl;
					cartera[pos].precio = operacion.precio;
				}
				else if(operacion.tipo == 'C'){
					cout << " OK" << endl;
					cartera[pos].numAcciones += operacion.numAcciones;
				}
				else if (operacion.tipo == 'V') {
					if (cartera[pos].numAcciones >= operacion.numAcciones) {
						cout << " OK" << endl;
						cartera[pos].numAcciones -= operacion.numAcciones;
					}
					else {
						cout << " ERROR: No tiene suficientes acciones para realizar la venta." << endl;
					}
				}
			}
			archivo >> operacion.tipo;
		}
	}
	return ok;
}
bool grabar(const tCartera& cartera) {
	ofstream archivo;
	bool ok;
	archivo.open(Escritura);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		for (int i = 0; i < N_ACC; i++) {
			archivo << cartera[i].compannia << " " << cartera[i].precio << " " << cartera[i].numAcciones << endl;
		}
		archivo << "#";
		ok = true;
	}
	return ok;
}