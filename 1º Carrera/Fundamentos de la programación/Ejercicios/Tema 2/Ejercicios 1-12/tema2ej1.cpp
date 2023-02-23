#include <iostream>
using namespace std;


int main()
{
	double altura=26.79, r=14.5, pi=3.141592, resultado,r2;
	r2 = r * r;
	resultado = pi * r2*altura / 3;
	cout << "El volumen del cono es " << resultado << endl;
	system("pause");
	return 0;
}