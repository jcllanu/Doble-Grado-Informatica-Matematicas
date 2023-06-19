#include<iostream>
using namespace std;

//Calculadora del elemento j-esimo de la fila i del triangulo de pascal

int pascal(int i, int j);
int main() {

	cout << pascal(6, 3);



	system("pause");
	return 0;
}


int pascal(int i,int j) {
	int p;
	if (j == 0 || j == i) {
		p = 1;
	}
	else {
		p = pascal(i - 1, j - 1) + pascal(i - 1, j);
	}
	return p;
}