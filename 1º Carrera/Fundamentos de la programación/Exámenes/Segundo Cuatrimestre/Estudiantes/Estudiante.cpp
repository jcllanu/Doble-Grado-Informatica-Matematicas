#include"Estudiante.h"

void cargar(tEstudiante& estudiante, istream& archivo) {
	char aux;

	archivo.get(aux);
	getline(archivo, estudiante.nombre);
	archivo >> estudiante.NIF >> estudiante.fechaMatr >> estudiante.nota;
}
void mostrar(const tEstudiante& estudiante) {
	cout << setw(12) << left << estudiante.NIF << setw(3) << "-" << right << setw(7) 
		<< estudiante.fechaMatr << setw(2) << "-" << setw(5) << estudiante.nota << setw(3) << "-" << setw(20) << estudiante.nombre << endl;
}
string devuelveNIF(const tEstudiante& estudiante) {
	return estudiante.NIF;
}