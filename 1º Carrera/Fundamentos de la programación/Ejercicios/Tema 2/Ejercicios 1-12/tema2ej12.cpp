#include <iostream>
#include<math.h>
using namespace std;


//Cálculo de prestamo hipotecario
int main()
{
	system("chcp 1252");

	double CapitalPrestado, InteresAnual,CuotaMensual,Ratio,CantidadAmortizada,InteresMensual,TotalPagado,InteresesPagados;
	int Plazo,Duracion;
	cout << "Introduce los siguientes datos sobre tu préstamo." << endl;
	cout << "Capital prestado: ";
	cin >> CapitalPrestado;
	cout << "Intereses anuales: ";
	cin >> InteresAnual;
	cout << "Duración del préstamo en años: ";
	cin >> Duracion;
	cout << endl;

	Plazo = 12 * Duracion;
	InteresMensual = InteresAnual / 12;
	Ratio = InteresMensual;
	CuotaMensual = (CapitalPrestado*Ratio) / (100 * (1 - pow((1 + Ratio/100), (-1 * Plazo))));
	CantidadAmortizada = CapitalPrestado;
	TotalPagado = Plazo * CuotaMensual;
	InteresesPagados = TotalPagado - CantidadAmortizada;
		
	
	cout << "El total pagado será " << TotalPagado << " €" << endl; 
	cout << "La cuota mensual es " << CuotaMensual << " €" << endl;
	cout << "La cantidad amortizada es " << CantidadAmortizada << " €" << endl;
	cout << "Los interese pagados serán " << InteresesPagados << " €" << endl;
	cout << endl;
	system("pause");
	return 0;
}