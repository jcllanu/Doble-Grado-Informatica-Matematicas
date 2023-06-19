#include<iostream>
using namespace std;

//Exponencial recursiva

float potRec2(float x, int n);
int main() {

	cout << potRec2(2.2, 27);



	system("pause");
	return 0;
}

float potRec2(float x, int n) {
	float result;
	if (n == 0) {
		result = 1;
	}
	else if(n%2==0) {
		result = potRec2(x*x, n / 2);
	}
	else {
		result = x * potRec2(x, n - 1);
	}
	return result;
}