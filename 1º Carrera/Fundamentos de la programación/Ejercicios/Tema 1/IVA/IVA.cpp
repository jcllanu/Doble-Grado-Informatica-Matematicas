#include<iostream>
using namespace std;

int main()
{

	int unidades;
	float precio, siniva, coniva;

	cout<<"Introdce un numero de unidades: ";
	cin>>unidades;
	cout<<"Introdce el precio unitario (en €): ";
	cin>>precio;

	siniva=unidades*precio;
	coniva=siniva * 1.21;

	cout<<" "<<endl;
 	cout<<"El precio sin IVA es: "<<endl;
	cout<<unidades<<" unidades x "<<precio<<" € la unidad = "<<siniva<<" €"<<endl;
	cout<<" "<<endl;
	cout<<"El precio con IVA es: "<<endl;
	cout<<siniva<<" € x 1.21 = "<<coniva<<" €"<<endl;

	return 0;
}