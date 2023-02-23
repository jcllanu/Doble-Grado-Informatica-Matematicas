#include <iostream>
#include<string>
#include<iomanip>
#include <math.h>
using namespace std;

int main()
{
	system("chcp 1252");

	double precio, descontado=0, trasdescontar, IVA;
	int cantidad;
	string descuento, nombre, NIF, dpostal, producto;

	cout << "Introduzca el precio del producto: ";
	cin >> precio;
	cout << "Introduzca el número de unidades: ";
	cin >> cantidad;
	cout << "¿Tiene usted algún tipo de descuento especial? (Si/No): ";
	cin >> descuento;
	cout << "Introduzca su nombre: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Introduzca su NIF: ";
	cin >> NIF;
	cout << "Introduzca su dirección postal: ";
	cin.ignore();
	getline(cin, dpostal);
	cout << "Introduzca el nombre del producto: ";
	
	getline(cin, producto);
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Factura:" << endl;
	cout << setw(50) << nombre << endl;
	cout << setw(50) << dpostal << endl;
	cout << setw(50) << NIF << endl;
	cout << endl;
	cout << "Producto: " << producto << endl;
	cout << "Precio unitario"<< endl;
	cout << setw(50) << fixed<< setprecision(2)<< precio << endl;
	cout << "Unidades" << endl;
	cout << setw(50) << cantidad << endl;
	cout << "Total" << endl;
	cout << setw(50) << cantidad * precio << endl;
	cout << "Descuento" << endl;
	if (descuento=="Si") {
		descontado = -1 * cantidad * precio*0.15;
		cout << setw(50) << descontado<< endl;
	}
	else {
		cout << setw(50) << "No aplicable" << endl;
	}
	cout << "Total tras descuento" << endl;
	trasdescontar = cantidad * precio + descontado;
	cout << setw(50) << trasdescontar << endl;
	cout << "I.V.A. (21%)" << endl;
	IVA = trasdescontar * 0.21;
	cout << setw(50) << IVA << endl;
	cout << "Precio final" << endl;
	cout << setw(50) << trasdescontar + IVA << endl;



	cout << endl;
	system("pause");
	return 0;
}