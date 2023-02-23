#include <iostream>
#include<fstream>;
using namespace std;

bool triangular(int num);

int main() {
	int numero;
	bool esTriangular;
	ifstream enteros;
	enteros.open("enteros.txt");
	if (enteros.is_open()) {
		
		enteros >> numero;
		while (numero != 0) {

			esTriangular = triangular(numero);

			if (esTriangular) {
				cout << "El numero " << numero << " es triangular" << endl;
			}
			else {
				cout << "El numero " << numero << " no es triangular" << endl;
			}
			enteros >> numero;
		}
		
	}
	else {
		cout << "ERROR: Archivo no encontrado" << endl;
	}
	system("pause");
	return 0;
}

bool triangular(int num) {
	int contador = 1, suma=0;
	bool final;
	while (suma < num) {
		suma += contador;
		contador++;
	}
	if (suma == num) {
		final = true;
	}
	else {
		final = false;
	}

	return final;

}
