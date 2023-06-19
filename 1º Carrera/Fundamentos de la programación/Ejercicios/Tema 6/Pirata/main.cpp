#include"Pirata.h"

//Juego del pirata
int main() {
	bool encontrado = false;
	bool muerto = false;
	int contador = 0;
	tIsla isla;

	srand(time(NULL));

	inicializarTablero(isla);
	dibujar(isla);
	while (!encontrado && contador < 50 && !muerto) {
		mover(isla, direccion());
		if (CasillaMuerte(isla)) {
			muerto = true;
		}
		else if (CasillaTesoro(isla)) {
			encontrado = true;
		}
	
		confirmarMovimiento(isla);
		contador++;
		dibujar(isla);
		cout << endl << endl;
	}
	system("pause");
	return 0;
}