#include <iostream>
using namespace std;

int main()
{
	int x = 12, y = 3;
	double sigma = 2.1836, lambda = 1.11695, alfa = 328.67, f;

	f = 3 * ((x + sigma * y) / (x*x - y * y)) - lambda * (alfa - 13.7);

	cout << "El valor de sigma es: " << sigma << endl;
	cout << "El valor de x es: " << x << endl;
	cout << "El valor de y es: " << y << endl;
	cout << "El valor de lambada es: " << lambda << endl;
	cout << "El valor de alfa es: " << alfa << endl;
	cout << "El valor de f es: " << f << endl;

	system("pause");
	return 0;
}