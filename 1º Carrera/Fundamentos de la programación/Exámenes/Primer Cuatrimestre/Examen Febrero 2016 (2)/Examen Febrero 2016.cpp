#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;
int const N = 8;
string const Lectura = "salidas.txt";
string const Escritura = "pendientes.txt";

typedef enum { embarcando, operado, retrasado, suspendido } tEstadoVuelo;

typedef struct {
	string numVuelo;
	string destino;
	int puerta;
	int estado;
	char terminal;
}tVuelo;

typedef tVuelo tAeropuerto[N];

int menu();
bool cargar(tAeropuerto& aeropuerto);
void guardar(const tAeropuerto& aeropuerto);
void mostrarVuelo(const tAeropuerto& aeropuerto, string numVuelo);
int buscarVuelo(const tAeropuerto& aeropuerto, string numVuelo);
void actualizarVuelo(tAeropuerto& aeropuerto, int pos, int estadoVuelo);

int main() {
	system("chcp 1252");
	tAeropuerto aeropuerto;
	int op, estadoVuelo;
	string numVuelo;

	if (!cargar(aeropuerto)) {
		cout << endl << endl << "ERROR: No se ha podido realizar la operación de carga con éxito." << endl << endl;
	}
	else {
		op = menu();
		while (op != 0) {
			switch (op) {
			case 1:
			{
				cout << "Introduzca el número del vuelo que quiera consultar: ";
				cin >> numVuelo;
				mostrarVuelo(aeropuerto, numVuelo);
			}
			break;
			case 2:
			{
				cout << "Introduzca el número del vuelo que quiera actualizar: ";
				cin >> numVuelo;
				while (buscarVuelo(aeropuerto, numVuelo) == -1) {
					cout << "ERROR:  El vuelo " << numVuelo << " no se opera desde este aeropuerto." << endl << "Introduzca el número del vuelo que quiera actualizar: ";
					cin.ignore(100,'\n');
					cin >> numVuelo;
				}
				cout << "Introduzca el nuevo estado del vuelo (0 = embarcando, 1 = operado, 2 = retrasado, 3 = suspendido): ";
				cin >> estadoVuelo;
				while (estadoVuelo < 0 || estadoVuelo > 3 || cin.fail()) {
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Opción no válida. Introduzca el nuevo estado del vuelo (0/1/2/3): ";
					cin >> estadoVuelo;
				}
				actualizarVuelo(aeropuerto, buscarVuelo(aeropuerto, numVuelo), estadoVuelo);
			}
			break;
			}
			op = menu();
		}
		guardar(aeropuerto);
	}
	
	system("pause");
	return 0;
}

int menu() {
	int op;

	cout << endl << "Menú: " << endl;
	cout << "1.- Obtener información de un vuelo." << endl;
	cout << "2.- Actualizar el estado de un vuelo." << endl;
	cout << "0.- Salir." << endl;
	cout << "Seleccione una de las opciones (1/2) o finalice el programa (0): ";
	cin >> op;

	while (op < 0 || op>2 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Seleccione una de las opciones (1/2) o finalice el programa (0): ";
		cin >> op;
	}

	return op;
}

bool cargar(tAeropuerto& aeropuerto) {
	ifstream archivo;
	bool ok = true;
	tVuelo vuelo;
	int contador = 0;
	char a;

	archivo.open(Lectura);

	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		archivo >> vuelo.numVuelo;
		while (vuelo.numVuelo != "XXX" && ok && contador < N) {
			for (int i = 0; i < contador; i++) {
				if (vuelo.numVuelo == aeropuerto[i].numVuelo) {
					ok = false;
				}
			}
			archivo >> vuelo.terminal;
			archivo >> vuelo.puerta;
			archivo >> vuelo.estado;
			archivo.get(a);
			getline(archivo, vuelo.destino);
			aeropuerto[contador] = vuelo;
			contador++;
			archivo >> vuelo.numVuelo;
		}
	}
	archivo.close();
	if (contador < N) {
		ok = false;
	}
	return ok;
}
void guardar(const tAeropuerto& aeropuerto) {
	ofstream archivo;

	archivo.open(Escritura);

	for (int i = 0; i < N; i++) {
		if (aeropuerto[i].estado == retrasado || aeropuerto[i].estado == suspendido) {
			archivo << aeropuerto[i].numVuelo << " " << aeropuerto[i].terminal << " " << aeropuerto[i].puerta << " " << aeropuerto[i].estado << " " << aeropuerto[i].destino << endl;
		}
	}
	archivo << "XXX";

	archivo.close();
}
void mostrarVuelo(const tAeropuerto& aeropuerto, string numVuelo) {
	int pos;
	pos = buscarVuelo(aeropuerto, numVuelo);
	if (pos == -1) {
		cout << endl << "ERROR: El vuelo " << numVuelo << " no se opera desde este aeropuerto." << endl;
	}
	else {
		cout << endl << "Número de vuelo: " << aeropuerto[pos].numVuelo << endl;
		cout << "Destino: " << aeropuerto[pos].destino << endl;
		cout << "Terminal: " << aeropuerto[pos].terminal << endl;
		cout << "Puerta de embarque: " << aeropuerto[pos].puerta << endl;
		cout << "Estado del vuelo: ";
		if (aeropuerto[pos].estado == embarcando) {
			cout << "Embarcando";
		}
		else if (aeropuerto[pos].estado == operado) {
			cout << "Operado";
		}
		else if (aeropuerto[pos].estado == retrasado) {
			cout << "Retrasado";
		}
		else if (aeropuerto[pos].estado == suspendido) {
			cout << "Suspendido";
		}
		cout << endl;
	}
	cin.ignore(100, '\n');
}
int buscarVuelo(const tAeropuerto& aeropuerto, string numVuelo) {
	int pos = 0;
	bool encontrado = false;

	while (pos < N && !encontrado) {
		if (aeropuerto[pos].numVuelo == numVuelo) {
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
void actualizarVuelo(tAeropuerto& aeropuerto, int pos, int estadoVuelo) {
	aeropuerto[pos].estado = estadoVuelo;
}
