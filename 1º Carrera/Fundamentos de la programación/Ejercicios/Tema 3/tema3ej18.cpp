#include <iostream>
using namespace std;

bool comprobar(int a, int b);

//Secuencia	de enteros	terminada en 0(centinela) es creciente o	no
int main(){
	
	int num1, num2;
	bool creciente = true;

	cout << "Introduce una serie de numeros (0 para parar): ";
	cin >> num1;
	num2 = num1;
	while (num1 != 0) {
		if (creciente) {
			creciente = comprobar(num1, num2);
		}
		num2 = num1;
		cin >> num1;
	}
	cout << endl;
	if (creciente) {
		cout << "La sucesion es creciente.";
	}
	else {
		cout << "La sucesion no es creciente.";
	}
	cout << endl;
	system("pause");
	return 0;
}

bool comprobar(int a, int b) {
	bool final;
	if (a >= b) {
		final = true;
	}
	else {
		final = false;
	}

	return final;
}