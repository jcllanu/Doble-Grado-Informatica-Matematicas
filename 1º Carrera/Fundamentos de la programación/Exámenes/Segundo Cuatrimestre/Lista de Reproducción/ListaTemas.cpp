#include"ListaTemas.h"

bool cargar(tListaTemas& listaTemas) {
	ifstream archivo;
	bool ok;
	tTema tema;

	archivo.open(LECTURA);
	if (archivo.is_open()) {
		ok = true;
		archivo >> listaTemas.contador;
		for (int i = 0; i < listaTemas.contador; i++) {
			cargar(tema, archivo);
			listaTemas.lista[i] = new tTema(tema);
		}

	}
	else {
		ok = false;
	}
	return ok;
}
void destruir(tListaTemas& listaTemas) {
	for (int i = 0; i < listaTemas.contador; i++) {
		delete listaTemas.lista[i];
	}
}
tTemaPtr devuelveTemaPtr(const tListaTemas& listaTemas, int num) {
	return listaTemas.lista[num];
}
int devuelveTam(const tListaTemas& listaTemas) {
	return listaTemas.contador;
}