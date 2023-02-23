#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;


int const MAX_LIBROS = 10;
string const Lectura = "biblioteca.txt";

typedef struct {
	int ISBN;
	string titulo;
	string autor;
	int totales;
	int prestados;
}tLibro;

typedef tLibro tLista[MAX_LIBROS];
typedef struct {
	tLista datos;
	int contador;
}tBiblioteca;

int menu();
bool cargarArchivo(tBiblioteca& biblioteca);
void insertarEjemplares(tBiblioteca& biblioteca);
bool posicionLibroISBN(const tBiblioteca& biblioteca, int& pos, int ISBN);
void mostrarBiblioteca(const tBiblioteca& biblioteca);
void mostrarLibros(const tBiblioteca& biblioteca);
bool posicionLibroAutor(const tBiblioteca& biblioteca, int& pos, string autor);
void prestamo(tBiblioteca& biblioteca);
int main() {
	system("chcp 1252");
	int op;
	tBiblioteca biblioteca;

	if (!cargarArchivo(biblioteca)) {
		cout << endl << "ERROR: La carga no se ha podido realizar con éxito." << endl << endl;
	}
	else {
		op = menu();

		while (op != 0) {
			switch (op) {
			case 1:
			{
				insertarEjemplares(biblioteca);
			}
			break;
			case 2:
			{
				mostrarBiblioteca(biblioteca);
			}
			break;
			case 3:
			{
				mostrarLibros(biblioteca);
			}
			break;
			case 4:
			{
				prestamo(biblioteca);
			}
			break;
			}
			op = menu();
		}
	}

	system("pause");
	return 0;
}


int menu() {
	int op;

	cout << endl << "Menú:" << endl;
	cout << "1.- Insertar ejemplares de un libro." << endl;
	cout << "2.- Mostrar biblioteca." << endl;
	cout << "3.- Mostrar libros de un autor." << endl;
	cout << "4.- Prestamo." << endl;
	cout << "0.- Salir." << endl;
	cout << "Eliga una de las opciones (1/2/3/4) o finalice el programa (0): ";
	cin >> op;

	while (op < 0 || op > 4 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Eliga una de las opciones (1/2/3/4) o finalice el programa (0): ";
		cin >> op;
	}

	return op;
}
bool cargarArchivo(tBiblioteca& biblioteca) {
	ifstream archivo;
	bool ok;
	tLibro libro;
	char a;

	archivo.open(Lectura);
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
		biblioteca.contador = 0;
		archivo >> libro.ISBN;
		while (biblioteca.contador < MAX_LIBROS && libro.ISBN != -1 && ok) {
			archivo.get(a);
			getline(archivo, libro.titulo);
			archivo >> libro.autor;
			archivo >> libro.totales;
			archivo >> libro.prestados;
			if (libro.totales < libro.prestados) {
				ok = false;
			}
			biblioteca.datos[biblioteca.contador] = libro;
			biblioteca.contador++;
			archivo >> libro.ISBN;
		}
	}
	archivo.close();

	return ok;
}
void insertarEjemplares(tBiblioteca& biblioteca) {
	int ISBN, ejemplares, pos = 0;
	string autor, titulo;
	char a;
	
	cout << endl << "Intruduzca el ISBN de los ejemplares que quiera añadir: ";
	cin >> ISBN;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Intruduzca el ISBN de los ejemplares que quiera añadir: ";
		cin >>ISBN;
	}
	cout << "Intruduzca el número de ejemplares que quiera añadir: ";
	cin >> ejemplares;
	cin.get(a);
	while (cin.fail() || ejemplares <= 0) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Intruduzca el número de ejemplares que quiera añadir: ";
		cin >> ejemplares;
		cin.get(a);
	}

	if (posicionLibroISBN(biblioteca, pos, ISBN)) {
		biblioteca.datos[pos].totales += ejemplares;
	}
	else if (biblioteca.contador < MAX_LIBROS) {
		cout << "Intruduzca el nombre del autor: ";
		getline(cin, autor);
		while (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Intruduzca el nombre del autor: ";
			getline(cin, autor);
		}
		cout << "Intruduzca el título del libro: ";
		getline(cin, titulo);
		while (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Intruduzca el título del libro: ";
			getline(cin, titulo);
		}
		biblioteca.datos[pos].autor = autor;
		biblioteca.datos[pos].ISBN = ISBN;
		biblioteca.datos[pos].titulo = titulo;
		biblioteca.datos[pos].totales = ejemplares;
		biblioteca.datos[pos].prestados = 0;
		biblioteca.contador++;
	}
	else {
		cout << "Biblioteca llena. No puede introducir ejemplares nuevos." << endl;
	}
}
bool posicionLibroISBN(const tBiblioteca& biblioteca, int& pos, int ISBN) {
	bool esta = false;
	
	while (!esta && pos < biblioteca.contador) {
		if (ISBN == biblioteca.datos[pos].ISBN) {
			esta = true;
		}
		else {
			pos++;
		}
	}
	return esta;
}
bool posicionLibroAutor(const tBiblioteca& biblioteca, int& pos, string autor) {
	bool esta = false;

	while (!esta && pos < biblioteca.contador) {
		if (autor == biblioteca.datos[pos].autor) {
			esta = true;
		}
		else {
			pos++;
		}
	}
	return esta;
}
void mostrarBiblioteca(const tBiblioteca& biblioteca) {
	cout << endl << "Título                                       Autor            ISBN          Totales      En préstamo" << endl << endl;
	for (int i = 0; i < biblioteca.contador; i++) {
		cout << left << setw(35) << biblioteca.datos[i].titulo << right << setw(15) << biblioteca.datos[i].autor << setw(15) << biblioteca.datos[i].ISBN << setw(15) <<
			biblioteca.datos[i].totales << setw(15) << biblioteca.datos[i].prestados << endl;
	}
}
void mostrarLibros(const tBiblioteca& biblioteca) {
	string autor;
	int pos = 0;

	cout << "Introduzca el nombre del autor del que quiera buscarlos los libros: ";
	cin >> autor;

	if (!posicionLibroAutor(biblioteca, pos, autor)) {
		cout << "No hay ningún libro del autor que ha introducido." << endl;
	}
	else {
		cout << endl << "Libro: " << setw(35)<<left<<biblioteca.datos[pos].titulo;
		cout << "  Estado: ";
		if (biblioteca.datos[pos].totales > biblioteca.datos[pos].prestados) {
			cout << "Disponible";
		}
		else {
			cout << "No disponible";
		}
		pos++;
		while (posicionLibroAutor(biblioteca, pos, autor)) {
			cout << endl << "Libro: " << setw(35) << left << biblioteca.datos[pos].titulo;
			cout << "  Estado: ";
			if (biblioteca.datos[pos].totales > biblioteca.datos[pos].prestados) {
				cout << "Disponible";
			}
			else {
				cout << "No disponible";
			}
			pos++;
		}
		cout << endl;
	}
}
void prestamo(tBiblioteca& biblioteca) {
	int ISBN, pos = 0;

	cout << endl << "Intruduzca el ISBN del libro que quiera adquirir: ";
	cin >> ISBN;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Intruduzca el ISBN de los ejemplares que quiera añadir: ";
		cin >> ISBN;
	}
	if (!posicionLibroISBN(biblioteca, pos, ISBN)) {
		cout << "El libro buscado no se encuentra en la biblioteca." << endl;
	}
	else if (biblioteca.datos[pos].totales > biblioteca.datos[pos].prestados) {
		cout << "El préstamo ha sido realizado con éxito." << endl;
		biblioteca.datos[pos].prestados++;
	}
	else {
		cout << "Lo sentimos. Ahora mismo ese libro no está disponible." << endl;
	}
}