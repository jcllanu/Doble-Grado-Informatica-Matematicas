#include <iostream>
#include <fstream>
using namespace std;

int extraerNumero();
int calcularInverso(int a);
void escribir(int n);
ifstream input;
ofstream output;

//Numero invertido bucle input output
int main()
{
	input.open("input.txt");
	output.open("output.txt");

	if (input.is_open()){

		int num, inv;

		num = extraerNumero();

		while (num != 0) {
			
			if(num > 0){

			inv = calcularInverso(num);
			escribir(inv);
			num = extraerNumero();

			}

			else{
			num = extraerNumero();
			}
			
		}

		if(num==0){

		escribir(0);
		output.close();
		}
	}
	else {
		cout << "ERROR: Archivo no encontrado.";
	}
	input.close();
	system("pause");
	return 0;
}

int extraerNumero() {
	int n;
	input >> n;
	return n;
}
int calcularInverso(int a) {
	int invers = 0;

	while (a != 0) {
		invers = invers * 10 + a % 10;
		a = a / 10;
	}
	return invers;
}
void escribir(int n) {
	output<< n << endl;
}