#include <iostream>
using namespace std;



int main()
{
	int a = 0, b = 0, c = 0;


	cout << "Introduce el primer número: ";
	cin >> a;
	cout << "Introduce el segundo número: ";
	cin >> b;
	cout << "Introduce el tercer número: ";
	cin >> c;

	if (a > b || a == b) {
		if (b > c || b == c) {
			cout << c << "," << b << "," << a;
		}
		else {
			if (c > a || a == c) {
				cout << b << "," << a << "," << c;
			}
			else {
				cout << b << "," << c << "," << a;
			}
		}
		
	}
	else {
		if (a > c || a == c) {
			cout << c << "," << a << "," << b;
		}
		else {
			if (c > b || b == c) {
				cout << a << "," << b << "," << c;
			}
			else {
				cout << a << "," << c << "," << b;
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}