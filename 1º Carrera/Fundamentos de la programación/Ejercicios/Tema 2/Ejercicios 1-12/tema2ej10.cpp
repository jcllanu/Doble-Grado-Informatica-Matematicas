#include <iostream>
using namespace std;



int main()
{
	system("chcp 1252");

	double lado1, lado2, alfagr, alfarad,Pi=3.141592,area;
	cout << "Introduce dos lados del triangulo y el �ngulo que forman y yo te dir� su �rea." << endl;
	cout<<"Lado 1: ";
	cin >> lado1;
	cout << "Lado 2: ";
	cin >> lado2;
	cout << "�ngulo en grados: ";
	cin >> alfagr;
	alfarad = alfagr * Pi / 180;
	area = 0.5*sin(alfarad)*lado1*lado2;
	cout << "El �rea del tri�ngulo es " << area << " unidades cuadradas" << endl;
	system("pause");
	return 0;
}