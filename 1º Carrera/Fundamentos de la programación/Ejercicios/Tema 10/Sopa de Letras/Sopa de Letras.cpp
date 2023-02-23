#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 20;

typedef struct {
	char tablero[MAX][MAX];
	int filas, columnas;
}tSopa;

typedef struct {
	int x;
	int y;
}tCoor;

typedef tCoor tDirecciones[8];
const tDirecciones DIRECCIONES = {-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
typedef enum{NW, N, NE, W, E, SW, S, SE}tDir;

typedef struct {
	string palabra[MAX];
	int contador;
}tListaBuscadas;

bool leeSopa(tSopa& s, tListaBuscadas& l);
bool compruebaPosDir(const tSopa& s, string palabra, tCoor pos, tDir dir);
bool buscaDir(const tSopa& s, string palabra, tCoor pos, tDir& dir);
bool buscaPalabra(const tSopa& s, string palabra, tCoor& pos, tDir& dir);
tCoor operator+(tCoor op1, tCoor op2);
tCoor operator-(tCoor op1, tCoor op2);
void resuelve(const tSopa& s, const tListaBuscadas& l);
string toStringDireccion(tDir dir);
void mostrar(const tSopa& s);




int main() {
	system("chcp 1252");

	tSopa s;
	tListaBuscadas l;

	if (leeSopa(s, l)) {
		mostrar(s);
		resuelve(s, l);
	}
	else {
		cout << "ERROR";
	}
	cout << endl;
	system("pause");
	return 0;
}

void mostrar(const tSopa& s) {
	cout << endl << "        ";

	for (int i = 0; i < s.columnas; i++) {
		cout << i + 1 << " ";
	}
	cout << endl << endl;
	
	for (int i = 0; i < s.filas; i++) {
		cout << "     " << i + 1 << "  ";
		for (int j = 0; j < s.columnas; j++) {
			cout << s.tablero[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "  Direcciones: " << endl;
	cout << endl << "        NW  N   NE";
	cout << endl << "        W       E";
	cout << endl << "        SW  S   SE";
	cout << endl << endl;
}



bool leeSopa(tSopa& s, tListaBuscadas& l) {
	ifstream archivo;
	bool ok;
	char a;
	string aux;
	archivo.open("sopa.txt");
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
		archivo >> s.filas;
		archivo >> s.columnas;
		archivo.get(a);
		for (int i = 0; i < s.filas; i++) {
			for (int j = 0; j < s.columnas; j++) {
				archivo.get(a);
				s.tablero[i][j] = a;
			}
			archivo.get(a);
		}
		archivo >> l.contador;
		archivo.get(a);
		for (int j = 0; j < l.contador; j++) {
			getline(archivo, l.palabra[j]);
		}
		archivo.close();
	}

	return ok;
}

tCoor operator+(tCoor op1, tCoor op2) {
	tCoor result;
	result.x = op1.x + op2.x;
	result.y = op1.y + op2.y;

	return result;
}
tCoor operator-(tCoor op1, tCoor op2) {
	tCoor result;
	result.x = op1.x - op2.x;
	result.y = op1.y - op2.y;

	return result;
}
bool compruebaPosDir(const tSopa& s, string palabra, tCoor pos, tDir dir) {
	bool esta = true;
	int cont = 0;
	tCoor nuevapos;
	nuevapos = pos;
	while (esta && (cont < palabra.size())) {
		if (palabra[cont] != s.tablero[nuevapos.x][nuevapos.y]) {
			esta = false;
		}
		nuevapos = nuevapos + DIRECCIONES[dir];
		if (nuevapos.x >= s.filas || nuevapos.y >= s.columnas || nuevapos.x < 0 || nuevapos.y < 0) {
			nuevapos = nuevapos - DIRECCIONES[dir];
			while (!(nuevapos.x >= s.filas || nuevapos.y >= s.columnas || nuevapos.x < 0 || nuevapos.y < 0)) {
				nuevapos = nuevapos - DIRECCIONES[dir];
			}
			nuevapos = nuevapos + DIRECCIONES[dir];
		}
		cont++;
	}

	return esta;
}

bool buscaDir(const tSopa& s, string palabra, tCoor pos, tDir& dir) {
	bool esta = false;
	int cont = 0;

	while (!esta && cont < 8) {
		if (compruebaPosDir(s, palabra, pos, tDir(cont))) {
			esta = true;
			dir = tDir(cont);
		}
		cont++;
	}

	return esta;
}

bool buscaPalabra(const tSopa& s, string palabra, tCoor& pos, tDir& dir) {
	bool esta = false;

	pos.x = 0;
	while (!esta && pos.x < s.filas) {
		pos.y = 0;
		while (!esta && pos.y < s.columnas) {
			if (buscaDir(s, palabra, pos, dir)) {
				esta = true;
			}
			else{
				pos.y++;
			}
		}
		if (!esta) {
			pos.x++;
		}
	}
	return esta;
}
void resuelve(const tSopa& s, const tListaBuscadas& l) {
	tCoor pos;
	tDir dir;
	for (int i = 0; i < l.contador; i++) {
		if (buscaPalabra(s, l.palabra[i], pos, dir)) {
			cout << "Encontrada " << setw(7) << left << l.palabra[i] << " en la posicion (" << pos.x + 1 << "," << pos.y + 1 << ") con la direccion " << toStringDireccion(dir) << endl;
		}
		else {
			cout << "No encontrada " << l.palabra[i] << endl;
		}
	}


}
string toStringDireccion(tDir dir) {
	string direccion;

	switch (dir) {
	case NW:
	{
		direccion = "NW";
	}
	break;
	case N:
	{
		direccion = "N";
	}
	break;
	case NE:
	{
		direccion = "NE";
	}
	break;
	case W:
	{
		direccion = "W";
	}
	break;
	case E:
	{
		direccion = "E";
	}
	break;
	case SW:
	{
		direccion = "SW";
	}
	break;
	case S:
	{
		direccion = "S";
	}
	break;
	case SE:
	{
		direccion = "SE";
	}
	break;
	}

	return direccion;
}