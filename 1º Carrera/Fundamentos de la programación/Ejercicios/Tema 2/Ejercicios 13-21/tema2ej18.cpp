#include <iostream>
#include<string>
using namespace std;

int main()
{
	int num=0, i=1;
	while (num < 1 ||num > 100) {
		cout << "Introduce un numero entre 1 y 100: ";
		cin >> num;
	}
	while (i <= 10) {

		cout << i << " x " << num << " = " << i * num << endl;
		i++;
	}
	system("pause");
	return 0;
}