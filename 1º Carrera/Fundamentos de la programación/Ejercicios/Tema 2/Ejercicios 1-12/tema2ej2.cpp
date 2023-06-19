#include <iostream>
using namespace std;

//Volumen de un cono con un radio de la base de 14,5 y una altura de 26,79.

int main()
{
	double altura = 26.79, radio=14.5, volumen;
	volumen = 3.141592 * radio * radio *altura / 3;
	cout << "El volumen del cono es " << volumen << endl;
	system("pause");
	return 0;
}