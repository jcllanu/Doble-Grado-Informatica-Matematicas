#include <iostream>
using namespace std;

double fahr();
double fahr_cels(double f);
void cels(double c, double f);


//Conversor Fahrenheit a Celsius
int main()
{
	system("chcp 1252");
	double f, c;
	f = fahr();
	c = fahr_cels(f);
	cels(c, f);
	system("pause");
	return 0;
}

double fahr() {
	double fahrenheit;
	cout << "Introduce una temperatura en grados fahrenheit: " << endl;
	cin >> fahrenheit;
	return fahrenheit;
}

double fahr_cels(double f) {
	double celsius;
	celsius = 5 * (f - 32) / 9;
	return celsius;
}

void cels(double c, double f) {
	cout << f << "ºF son " << c << "ºC." << endl;
}