#include<iostream>
#include<iomanip>
using namespace std;


int main(){
	int a = 10;
	char b = 'x';
	double c = 3.33333;
	cout << a << c << b << endl;
	cout << setw(5) << a << setw(10) << setprecision(2)
	<< c << b << endl;
	cout << setw(5) << setprecision(2) << c << setw(10)
	<< b << setw(10) << a << endl;
	system("pause");
	return 0;
}

