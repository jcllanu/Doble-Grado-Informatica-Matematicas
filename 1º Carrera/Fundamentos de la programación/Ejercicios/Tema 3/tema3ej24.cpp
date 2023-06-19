#include <iostream>
#include<fstream>;
#include<string>;
using namespace std;

//Leer palabras.txt	(con xxx como centinela) hasta 50 palabras
//menú:	mostrar	la lista de palabras, localizar	una	palabra	(indicará su posición),
//contar las apariciones de una palabra, localizar la primera palabra de más de	 una longitud dada,	
//desplazar	la  lista de palabras (cada	palabra	pasa a la siguiente	posición del array;	la última a la primera	posición) y	salir.

const int tamano = 50;
typedef string tLista[tamano];

int menu();
void leerPalabras(tLista lista, int & tam);
void mostrarLista(const tLista lista, int tam);
void posicionPalabra(const tLista lista, int tam);
void apatricionesPalabra(const tLista lista, int tam);
void localizarLongitud(const tLista lista, int tam);
void desplazarLista(tLista lista, int tam);


int main() {

	int tam=0;
	int modo;
	tLista lista;
	system("chcp 1252");
	leerPalabras(lista, tam);

	modo = menu();

	while (modo != 0) {
		switch (modo) {
		case 1:
		{
			mostrarLista(lista, tam);
		}
		break;
		case 2:
		{
			posicionPalabra(lista, tam);
		}
		break;
		case 3:
		{
			apatricionesPalabra(lista, tam);
		}
		break;
		case 4:
		{
			localizarLongitud(lista, tam);
		}
		break;
		case 5:
		{
			desplazarLista(lista, tam);
		}
		break;
		}

		modo = menu();
	}

	system("pause");
	return 0;
}

int menu() {

	int modojuego;

	cout << endl << "Modos de juego: " << endl;
	cout << "	1.- Modo A: Mostrar lista de palabras" << endl;
	cout << "	2.- Modo B: Localizar palabra" << endl;
	cout << "	3.- Modo C: Contar apariciones de una palabra" << endl;
	cout << "	4.- Modo D: Localizar palabra con una longitud mayor a una dada" << endl;
	cout << "	5.- Modo E: Desplazar lista de palabras" << endl;
	cout << "	0.- Salir" << endl;
	cout << "Escribe el modo en el que quieras jugar (1/2/3/4/5) o finaliza el programa(0): ";
	cin >> modojuego;

	while (modojuego < 0 || modojuego>5 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Opción no válida. Escribe el modo que quieras (1/2/3/4/5) o finaliza el programa(0): ";
		cin >> modojuego;
	}
	return modojuego;
}

void leerPalabras(tLista lista, int & tam) {
	ifstream archivo;
	archivo.open("palabras.txt");
	if (archivo.is_open()) {
		archivo >> lista[tam];
		while (lista[tam] != "XXX" && tam+1<tamano) {
			tam++;
			archivo >> lista[tam];
		}
		lista[tam] = "";
		archivo.close();
	}
	else {
		cout << "ERROR: Archivo no encontrado." << endl;

	}
	
}

void mostrarLista(const tLista lista, int tam) {
	for (int i = 0; i < tam; i++) {
		cout << i+1 << ".- " << lista[i] << endl;
	}
}

void posicionPalabra(const tLista lista, int tam) {
	string palabra;
	int contador=0;
	cout << "¿Qué palabra quieres localizar? ";
	cin >> palabra;
	while (lista[contador] != palabra && contador < tam) {
		contador++;
	}

	if (lista[contador] == palabra) {
		cout << "La palabra " << palabra << " se encuentra en la posición " << contador+1 << endl;
	}
	else {
		cout << "Palabra no encontrada." << endl;
	}
	
}
void apatricionesPalabra(const tLista lista, int tam) {
	string palabra;
	int apariciones = 0;
	cout << "¿Qué palabra quieres contar? ";
	cin >> palabra;
	for (int i = 0; i < tam; i++) {
		if (lista[i] == palabra) {
			apariciones++;
		}
	}
	cout << "La palabra " << palabra << " aparece " << apariciones << " veces." << endl;
}
void localizarLongitud(const tLista lista, int tam) {

	int longitud, contador = 0;
	cout << "Introduce una longitud: ";
	cin >> longitud;
	while (lista[contador].length() <= longitud && contador < tam) {
		contador++;
	}

	if (lista[contador].length() > longitud) {
		cout << "La primera palabra con más de " << longitud << " caracteres es " << lista[contador] << " y está en la posición "<<contador+1<<endl;
	}
	else {
		cout << "No hay ninguna palabra de longitud mayor que " << longitud << endl;
	}
}
void desplazarLista(tLista lista, int tam) {
	string aux;
	aux = lista[tam - 1];
	for (int i = tam - 1; i > 0; i--) {
		lista[i] = lista[i - 1];
	}
	lista[0] = aux;
}