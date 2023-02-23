#include <iostream>
#include<fstream>
using namespace std;

double leer(ifstream& file);
double comparar(double a, double b);

int main()
{
	ifstream archivo;
	double max, num;

	archivo.open("datos.txt");
	if (archivo.is_open()) {
		num = leer(archivo);
		max = num;
		while (num != 0) {
			if (max < num) {
				max = num;
			}
			num = leer(archivo);
		}
		cout << "El mayor numero del archivo es " << max << endl;
	}
	else {
		cout << "Error: archivo no encontrado";
	}
	system("pause");
	return 0;
}


double leer(ifstream& file) {
	double num;
	file >> num;
	return num;
}