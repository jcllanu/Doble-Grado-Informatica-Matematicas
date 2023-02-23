#include"Grabaciones.h"

void ampliar(tListaGrabaciones& listaGrabaciones);


void crear(tListaGrabaciones& listaGrabaciones) {
	listaGrabaciones.contador = 0;
	listaGrabaciones.lista = new tGrabacion[CAP_INI];
	listaGrabaciones.maximo = CAP_INI;
}
bool solapan(const tGrabacion& grabacion1, const tGrabacion& grabacion2) {
	return grabacion1.programaPtr == grabacion2.programaPtr;
}
bool insertar(tListaGrabaciones& listaGrabaciones, const tGrabacion& grabacion) {
	bool ok = true;
	int contador = 0;
	if (listaGrabaciones.contador >= listaGrabaciones.maximo) {
		ampliar(listaGrabaciones);
	}
	while (ok && contador < listaGrabaciones.contador) {
		ok = !solapan(listaGrabaciones.lista[contador], grabacion);
		contador++;
	}
	if (ok) {
		listaGrabaciones.lista[listaGrabaciones.contador] = grabacion;
		listaGrabaciones.contador++;
	}
	return ok;
}
void mostrar(const tListaGrabaciones& listaGrabaciones) {
	for (int i = 0; i < listaGrabaciones.contador; i++) {
		if (!listaGrabaciones.lista[i].grabado) {
			mostrar(*listaGrabaciones.lista[i].programaPtr);
			cout << endl;
		}
	}
}
void destruir(tListaGrabaciones& listaGrabaciones) {
	delete[] listaGrabaciones.lista;
}

void ampliar(tListaGrabaciones& listaGrabaciones) {
	tGrabacionPtr nuevalista;

	listaGrabaciones.maximo *= 2;
	nuevalista = new tGrabacion[listaGrabaciones.maximo];
	for (int i = 0; i < listaGrabaciones.contador; i++) {
		nuevalista[i] = listaGrabaciones.lista[i];
	}
	destruir(listaGrabaciones);
	listaGrabaciones.lista = nuevalista;
}

tGrabacion grabar(const tProgramaPtr& programaPtr) {
	tGrabacion grabacion;
	grabacion.programaPtr = programaPtr;
	if (yaEmitido(*programaPtr)) {
		grabacion.grabado = true;
	}
	else {
		grabacion.grabado = false;
	}
	return grabacion;
}