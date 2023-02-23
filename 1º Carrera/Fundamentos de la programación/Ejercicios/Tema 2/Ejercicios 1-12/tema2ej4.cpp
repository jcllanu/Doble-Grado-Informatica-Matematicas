#include <iostream>
using namespace std;


int main()
{
	int segundos, minutos, horas, tiempo;
	cout << "Introduce tiempo en segundos: ";
	cin >> tiempo;
	horas = tiempo / 3600;
	tiempo = tiempo % 3600;
	minutos = tiempo / 60;
	segundos = tiempo % 60;
	cout << horas << "h " << minutos << "m " << segundos << "s " << endl;
	system("pause");
	return 0;
}