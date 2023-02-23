#include <iostream>
#include<string>
using namespace std;



int main()
{
	string a , b , c ;


	cout << "Introduce la primera palabra: ";
	cin >> a;
	cout << "Introduce la segunda palabra: ";
	cin >> b;
	cout << "Introduce la tercera palabra: ";
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