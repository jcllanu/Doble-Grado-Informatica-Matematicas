#include <iostream>
using namespace std;

int numero();
int inverso(int a);
void escribir(int n, int i);

int main()
{
	int num,inv;
	num = numero();
	inv = inverso(num);
	escribir(num, inv);
	system("pause");
	return 0;
}

int numero() {
	int n;
	cout << "Introduce un numero entero positivo: ";
	cin >> n;
	return n;
}
int inverso(int a) {
	int invers=0;

	while (a != 0) {
		invers = invers * 10 + a % 10;
		a = a / 10;
	}
	return invers;
}
void escribir(int n, int i) {
	cout << "El inverso de " << n << " es " << i << endl;
}