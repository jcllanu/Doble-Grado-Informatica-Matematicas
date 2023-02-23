#include <iostream>
using namespace std;


int main()
{
	double fahr, cels;
	cout << "Introduce una temperatura en grados fahrenheit: " << endl;
	cin >> fahr;
	cels = 5 * (fahr - 32) / 9;
	cout << "Eso son " << cels << "ºC" << endl;
	system("pause");
	return 0;
}