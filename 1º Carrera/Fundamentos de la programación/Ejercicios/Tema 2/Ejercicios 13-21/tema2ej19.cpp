#include <iostream>
using namespace std;

//Operaciones 
int main()
{
	double oper1 = 1, oper2=1;
	
	char operador;
	cout << "Introduce Operando Operador Operando (0 para terminar): ";
	cin >> oper1;
	while (oper1 != 0)
	{
		cin >> operador;
		cin >> oper2;

		if (operador == '+') {

			cout << oper1 << " " << operador << " " << oper2 << " = " << oper1 + oper2 << endl;
		}
		if (operador == '-') {

			cout << oper1 << " " << operador << " " << oper2 << " = " << oper1 - oper2 << endl;
		}
		if (operador == '*') {

			cout << oper1 << " " << operador << " " << oper2 << " = " << oper1 * oper2 << endl;
		}
		if (operador == '/') {

			cout << oper1 << " " << operador << " " << oper2 << " = " << oper1 / oper2 << endl;
		}
		
		cout << "Introduce Operando Operador Operando (0 para terminar): ";
		cin >> oper1;
	}

	cout << endl;
	system("pause");
	return 0;
}