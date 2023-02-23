#include <iostream>
using namespace std;


int main()
{
	double notafinal, examen1, examenfinal, practica1, practica2, actividad;
	cout << "Introduce la nota en el primer exámen: ";
	cin >> examen1;
	cout << "Introduce la nota en la primera practica: ";
	cin >> practica1;
	cout << "Introduce la nota en la segunda pratica: ";
	cin >> practica2;
	cout << "Introduce la nota en el exámen final: ";
	cin >> examenfinal;
	cout << "Introduce la nota en la actividad adicional: ";
	cin >> actividad;
	if (practica1>=5 && practica2>=5 && examenfinal>=4)
	{
		notafinal = 0.15*actividad + 0.1*practica1 + 0.1*practica2 + 0.15*examen1 + 0.5*examenfinal;
		cout << "Tu nota final es: " << notafinal << endl;
	}
	else
	{
		notafinal = 0.15*actividad + 0.1*practica1 + 0.1*practica2 + 0.15*examen1 + 0.5*examenfinal;
		cout << "Tu nota final es: " <<notafinal<<", pero estás suspenso."<<endl;
	}


	system("pause");
	return 0;
}