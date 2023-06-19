#include <iostream>
#include<math.h>
using namespace std;


//Operaciones
int main()
{
	system("chcp 1252");

	double x,y, Pi = 3.141592, resultado, e=2.718281;
	cout << "Introduce dos números reales." << endl;
	cout << "Primer número: ";
	cin >> x;
	cout << "Segundo número: ";
	cin >> y;
	resultado = pow(pow(1.531, (x + y)) + (abs(pow(e, x) - pow(e, y))*(sin(x) - tan(y))) / (log10(y)*(pow(Pi,x))), 0.5);
	cout << "f(" << x << "," << y << ")= "<<resultado << endl;
	system("pause");
	return 0;
}