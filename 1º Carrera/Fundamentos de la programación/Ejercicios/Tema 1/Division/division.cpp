#include<iostream>

using namespace std;

int main()
{
	int dividendo, divisor, cociente, resto;
	cout << "Introduce el dividendo:" << endl;
	cin >> dividendo;
	cout << "Introduce el divisor:" << endl;
	cin >> divisor;
	cociente = dividendo / divisor;
	resto = dividendo % divisor;
	cout<<"El cociente de la división de "<<dividendo
		<<" entre "<<divisor<<" es "<<cociente<<", y el resto "<<resto<<endl;
	
	system("pause");
	return 0;
}