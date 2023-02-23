#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const int Tam = 14;

typedef int fila[Tam];
float desviacionTipica(fila xi, fila fi);
float mediaAritmética(fila xi, fila fi);
float sumatorioFi(fila fi);

int main() {
	system("chcp 1252");

	fila xi, fi;
	float desviacion, media;

	for (int i = 0; i < Tam; i++) {
		xi[i] = i;
	}
	for (int i = 0; i < Tam; i++) {
		fi[i] = Tam - i;
	}
	cout<< "xi fi" << endl;
	for (int i = 0; i < Tam; i++) {
		cout <<setw(2)<< xi[i] << " " << setw(2)<<fi[i] << endl;
	}
	
	desviacion=desviacionTipica(xi, fi);
	media = mediaAritmética(xi, fi);
	cout << desviacion << "   " << media;
	system("pause");
	return 0;
}
float desviacionTipica(fila xi, fila fi) {
	float sumatXi2Fi=0, desviacionTipica;

	for (int i = 0; i < Tam; i++) {
		sumatXi2Fi += pow(xi[i], 2)*fi[i];
	}
	desviacionTipica = sqrt(sumatXi2Fi / sumatorioFi(fi) - pow(mediaAritmética(xi, fi), 2));

	return desviacionTipica;
}
float mediaAritmética(fila xi, fila fi) {
	float sumatXiFi = 0;

	for (int i = 0; i < Tam; i++) {
		sumatXiFi += xi[i] * fi[i];
	}
	
	return sumatXiFi / sumatorioFi(fi);
}
float sumatorioFi(fila fi) {
	float sumatFi = 0;

	for (int i = 0; i < Tam; i++) {
		sumatFi += fi[i];
	}
	return sumatFi;
}