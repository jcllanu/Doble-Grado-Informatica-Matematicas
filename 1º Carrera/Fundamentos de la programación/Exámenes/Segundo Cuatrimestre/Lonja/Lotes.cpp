#include"Lotes.h"

bool operator<(const tLote& lote1, const tLote& lote2) {
	bool menor;

	if (lote1.pescado < lote2.pescado || (lote1.pescado == lote2.pescado && lote1.idLote < lote2.idLote)) {
		menor = true;
	}
	else {
		menor = false;
	}

	return menor;
}
bool operator==(const tLote& lote1, const tLote& lote2) {
	bool igual;

	if (lote1.idLote == lote2.idLote) {
		igual = true;
	}
	else {
		igual = false;
	}
	return igual;
}
void mostrarLote(const tLote& lote) {
	cout << endl;
	cout << "Lote: " << setw(10) << right << lote.idLote << setw(25) << right << "Peso del lote: " << setprecision(2) << fixed << lote.peso << endl;
	cout<<"Tipo: "<< setw(10) << right << lote.pescado << setw(28) << right << "Precio de salida: " << setprecision(2) << fixed << lote.precio << endl;
}
void mostrarPrecio(const tLote& lote) {

	cout << "Lote: " << setw(10) << right << lote.idLote << setw(21) << right << "Comprador: " <<  lote.idComprador<< endl;
	cout << "Tipo: " << setw(10) << right << lote.pescado << setw(28) << right << "Precio de compra: " << setprecision(2) << fixed << lote.precio << endl;
}
void modificarLote(tLote& lote, long long int idComprador, float precio) {
	lote.idComprador = idComprador;
	lote.precio = precio;
}
string devuelveIdLote(const tLote& lote) {
	return lote.idLote;
}
string devuelvePescadoLote(const tLote& lote) {
	return lote.pescado;
}