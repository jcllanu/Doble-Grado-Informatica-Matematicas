#include"Juguete.h"

string DevuelveDecadaString(tDecada decada);

double precioVenta(const tJuguete& juguete) {
	double precioVenta;

	switch (int(juguete.decada)) {
	case 0: 
	{
		precioVenta = juguete.precioBase*(1 + ANNOS50_PER);
	}
	break;
	case 1:
	{
		precioVenta = juguete.precioBase*(1 + ANNOS60_PER);
	}
	break;
	case 2:
	{
		precioVenta = juguete.precioBase*(1 + ANNOS70_PER);
	}
	break;
	case 3:
	{
		precioVenta = juguete.precioBase*(1 + ANNOS80_PER);
	}
	break;
	}
	return precioVenta;
}

void mostrarJuguete(const tJuguete& juguete) {
	cout << juguete.identificador << endl;
	cout << "	Década: " << DevuelveDecadaString(juguete.decada) << endl;
	cout << "	" << juguete.unidades << " unidades" << endl;
	cout << "	Precio base: " << setprecision(2) << fixed << juguete.precioBase << "	Precio venta: " << setprecision(2) << fixed << precioVenta(juguete);
}

tDecada DevuelveDecada(int num) {
	tDecada decada;

	if (num == 50) {
		decada = annos50;
	}
	else if(num == 60) {
		decada = annos60;
	}
	else if (num == 70) {
		decada = annos70;
	}
	else if (num == 80) {
		decada = annos80;
	}
	return decada;
}

tJuguete devuelveJuguete(string identificador, long int unidades, tDecada decada, double precio) {
	tJuguete juguete;

	juguete.decada = decada;
	juguete.identificador = identificador;
	juguete.unidades = unidades;
	juguete.precioBase = precio;

	return juguete;
}

string devuelveIdentificador(const tJuguete& juguete) {
	return juguete.identificador;
}

void annadir(tJuguete& juguete, long int unidades) {
	juguete.unidades += unidades;
}

int devuelveUnidades(const tJuguete& juguete) {
	return juguete.unidades;
}

tDecada DevuelveDecada(const tJuguete& juguete) {
	return juguete.decada;
}

double DevuelvePrecio(const tJuguete& juguete) {
	return juguete.precioBase;
}

string DevuelveDecadaString(tDecada decada) {
	string decad;
	switch (int(decada)) {
	case 0: {
		decad = "Años 50";
		}
			break;
	case 1: {
		decad = "Años 60";
	}
			break;
	case 2: {
		decad = "Años 70";
	}
			break;
	case 3: {
		decad = "Años 80";
	}
			break;
	}
	return decad;
}