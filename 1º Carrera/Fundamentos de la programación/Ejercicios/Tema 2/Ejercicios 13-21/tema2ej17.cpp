#include <iostream>
#include<string>
using namespace std;

//Conversor de medidas anglosajonas a internacionales. El
// programa lee un número real seguido de un espacio y una letra.
//p -> pulgadas;
//m -> millas;
//f -> grados Fahrenheit;
//g -> galones líquidos;
//o -> onzas;
//l -> libras
// nueva unidad
//cm -> centímetros;
//m -> metros;
//c -> grados Celsius;
//l -> litros;
//gr -> gramos;
//kg -> kilogramos).

int main()
{
	double cantidad = 1;
	const double pulgadacm = 2.54, millam = 1609.34;
	string unidad;
	cout << "Introduce una cantidad en una medida anglosajona: ";
	cin >> cantidad;
	while (cantidad!=0)
	{
		cin >> unidad;

		if (unidad == "p") {
			cantidad *= pulgadacm;
			unidad = "cm";
			cout << "Eso equivale a " << cantidad << " " << unidad << endl;
		}
		if (unidad == "m") {
			cantidad *= millam;
			unidad = "m";
			cout << "Eso equivale a " << cantidad << " " << unidad << endl;
		}
		cout << "Introduce una cantidad en una medida anglosajona: ";
		cin >> cantidad;
	}

	cout << endl;
	system("pause");
	return 0;
}