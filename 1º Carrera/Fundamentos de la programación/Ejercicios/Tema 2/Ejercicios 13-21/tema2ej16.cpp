#include <iostream>
using namespace std;

//Par impar
int main()
{
	int num = 1;
	while (num!=0) {
		cout << "Introduce un numero: ";
		cin >> num;
		if (num > 0) {
			if (num % 2 == 0) {
				cout << num << " es par." << endl;
			}
			else {
				cout << num << " es impar." << endl;
			}
		}
	}

	system("pause");
	return 0;
}