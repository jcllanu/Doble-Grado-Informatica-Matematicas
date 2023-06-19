#include"Cuadrilla.h"

//Gesti´çon de plantación de plátanos y cuadrillas de trabajo
int main() {
	system("chcp 1252");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	string fichero1, fichero2;
	int lado, num = 0;
	tPlantacion plantacion1, plantacion2;
	tListaParcelas listaParcelas1, listaParcelas2, listaParcelas;
	tListaCuadrillas listaCuadrillas;


	cout << "Introduzca la longiud del lado de las parcelas a crear: ";
	cin >> lado;
	cout << "Nombre del fichero de la primera plantación: ";
	cin >> fichero1;
	if (!cargar(plantacion1, fichero1)) {
		cout << "No se ha podido cargar";
	}
	else {
		cout << "Nombre del fichero de la segunda plantación: ";
		cin >> fichero2;
		if (!cargar(plantacion2, fichero2)) {
			cout << "No se ha podido cargar";
		}
		else {
			crearParcelas(plantacion1, lado, listaParcelas1);
			crearParcelas(plantacion2, lado, listaParcelas2);
			mezclar(listaParcelas1, listaParcelas2, listaParcelas);
			cout << endl <<"Lista de parcelas: "<<endl<<endl<< left << setw(15) << "Plantacion" << setw(13) << "Parcela" << setw(17) << "Platanos en parcela" << endl << endl;;
			mostrarListaParcelas(listaParcelas, num);
			listaCuadrillas = crearListaCuadrilla();
			asignarParcela(listaCuadrillas, listaParcelas);
			mostrarAsignaciones(listaCuadrillas);
			guardar(listaCuadrillas);
			liberar(listaParcelas);
			liberar(listaCuadrillas);
		}
	}

	


	system("pause");
	return 0;
}