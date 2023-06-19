#include <iostream>
using namespace std;

//Nomina
// El total a ingresar es igual al sueldo bruto del empleado menos los impuestos. 
// El sueldo bruto es igual al sueldo base más los complementos más lo 
// correspondiente a las horas extra (a 23 € por hora extra). Los impuestos (IRPF) 
// son un porcentaje del sueldo bruto: sin hijos y sin mayores dependientes se 
// aplica el 24%. A ese porcentaje se le restan 2 puntos por cada hijo y 1 punto por 
// cada mayor dependiente. 

int main()
{
	system("chcp 1252");
	int hijos, mayoresdependientes,IRPF;
	double sueldobase, complementodestino, complementocargoacademico, horasextra, sueldobruto, retIRPF, sueldoneto;

	cout << "Introduce los siguientes datos para poder calcular tu sueldo neto: " << endl;
	cout << "Sueldo base: ";
	cin >> sueldobase;
	cout << "Complemento de destino: ";
	cin >> complementodestino; 
	cout << "Complemento de cargo académico: ";
	cin >> complementocargoacademico;
	cout << "Número de horas extra: ";
	cin >> horasextra;
	cout << "Número de hijos: ";
	cin >> hijos;
	cout << "Número de mayores dependientes a su cargo: ";
	cin >> mayoresdependientes;

	sueldobruto = sueldobase + complementocargoacademico + complementodestino + horasextra * 23;
	IRPF = 24 - hijos * 2 - mayoresdependientes; 
	retIRPF = sueldobruto * 0.01*IRPF;
	sueldoneto = sueldobruto - retIRPF;

	cout << endl; 
	cout << endl;
	cout << "Calculo de la nómina.-" << endl;
	cout << endl;
	cout << "Sueldo base: " << sueldobase <<" €" << endl;
	cout << "Complemento de destino: " << complementodestino << " €" << endl;
	cout << "Complemento de cargo académico: " << complementocargoacademico << " €" << endl;
	cout << "Número de horas extra: " << horasextra << " horas" << endl;
	cout << "Número de hijos: " << hijos <<  endl;
	cout << "Número de mayores dependientes a su cargo: " << mayoresdependientes << endl;
	cout << endl;
	cout << "Sueldo bruto: " << sueldobruto << " €" << endl;
	cout << "Porcentaje de IRPF: " << IRPF << " %" << endl;
	cout << "Retención por IRPF: " << retIRPF << " €" << endl;
	cout << "Sueldo neto: " << sueldoneto << " €" << endl;
	cout << endl;
	system("pause");
	return 0;
}