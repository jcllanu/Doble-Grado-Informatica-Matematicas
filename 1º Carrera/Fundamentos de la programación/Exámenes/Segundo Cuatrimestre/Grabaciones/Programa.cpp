#include"Programa.h"

bool cargar(tPrograma& programa, istream& archivo) {
	bool ok;
	char aux;

	getline(archivo,programa.nombre);
	if (programa.nombre == "XXX") {
		ok = false;
	}
	else {
		ok = true;
		archivo >> programa.minutos >> programa.fecha.anno >> programa.fecha.mes >> programa.fecha.dia >> programa.fecha.hora >> programa.fecha.minuto;
		archivo.get(aux);
	}
	return ok;
}
void mostrar(const tPrograma& programa) {
	cout << left << setw(30)<<programa.nombre;
	mostrarFecha(programa.fecha);
	cout << ". Duracion " << programa.minutos << " minutos";
}
void mostrarFecha(const tFecha& fecha) {
	cout << setw(2)<<fecha.dia << "/" << setw(2) << fecha.mes << "/" << setw(4) << fecha.anno << "  (" << setw(2) << fecha.hora << ":" << setw(2) << fecha.minuto << ")";
}
bool operator<(const tPrograma& programa1, const tPrograma& programa2) {
	return programa1.nombre < programa2.nombre;
}
bool operator==(const tPrograma& programa1, const tPrograma& programa2) {
	return programa1.nombre == programa2.nombre;
}

bool yaEmitido(const tPrograma& programa) {
	bool emitido = false;
	if ( (programa.fecha.anno < 2019) || (programa.fecha.anno == 2019 && programa.fecha.mes < 6) || (programa.fecha.anno == 2019 && programa.fecha.mes == 6 && programa.fecha.dia < 5) || (programa.fecha.anno == 2019 && programa.fecha.mes == 6 && programa.fecha.dia == 5 && programa.fecha.hora <= 12)) {
		emitido = true;
	}
	return emitido;
}