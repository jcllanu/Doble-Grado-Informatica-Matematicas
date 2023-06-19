#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//Ordenaciones

typedef struct {
	int num;
	char car;
}tRegistro;

const int N = 10;

typedef struct {
	tRegistro elementos[N];
	int contador;
}tLista;

typedef const tRegistro* tPtr;

typedef struct {
	tPtr punt[N];
	int contador;
}tListaPtr;

void porNum(const tLista& lista, tListaPtr& ord);
void porCar(const tLista& lista, tListaPtr& ord);
void mostrar(const tListaPtr& ord);
void buscaPar(const tListaPtr& ord, int num, tPtr &punt);
tPtr buscaRet(const tListaPtr& ord, int num);

int main() {
	system("chcp 1252");
	tLista lista = { 12,'c',5,'g',3,'s',27,'u',2,'a',31,'j',16,'d',8,'k',12,'l',9,'r',N };
	tListaPtr ord;
	tPtr puntero;
	for (int i = 0; i < lista.contador; i++) {
		ord.punt[i] = NULL;
	}

	porNum(lista, ord);
	cout << "Ordenados por número: " << endl << endl;
	mostrar(ord);

	buscaPar(ord, 16, puntero);
	if (puntero == NULL) {
		cout << "No encontrado";
	}
	else {
		cout << "Encontrado." << endl;
		cout << "Número: " << (*puntero).num << endl;
		cout << "Letra: " << (*puntero).car << endl << endl;
	}
	puntero = buscaRet(ord, 5);
	if (puntero == NULL) {
		cout << "No encontrado";
	}
	else {
		cout << "Encontrado." << endl;
		cout << "Número: " << (*puntero).num << endl;
		cout << "Letra: " << (*puntero).car << endl << endl;
	}
	system("pause");
	return 0;
}

void porNum(const tLista& lista, tListaPtr& ord) {
	int cont = 0;
	bool encontrado = false;
	tPtr aux;
	ord.contador = lista.contador;

	for (int i = 0; i < lista.contador; i++) {
		ord.punt[i] = &lista.elementos[i];
	}

	for (int i = 1; i < ord.contador; i++) {
		cont = 0;
		encontrado = false;
		while (cont < i && !encontrado) {
			if ((*ord.punt[i]).num < (*ord.punt[cont]).num) {
				encontrado = true;
			}
			else {
				cont++;
			}
		}
		aux = ord.punt[i];
		for (int j = i; j > cont; j--) {
			ord.punt[j] = ord.punt[j - 1];
		}
		ord.punt[cont] = aux;
	}

}

void porCar(const tLista& lista, tListaPtr& ord) {
	int cont = 0;
	bool encontrado = false;
	tPtr aux;
	ord.contador = lista.contador;

	for (int i = 0; i < lista.contador; i++) {
		ord.punt[i] = &lista.elementos[i];
	}

	for (int i = 1; i < ord.contador; i++) {
		cont = 0;
		encontrado = false;
		while (cont < i && !encontrado) {
			if ((*ord.punt[i]).car < (*ord.punt[cont]).car) {
				encontrado = true;
			}
			else {
				cont++;
			}
		}
		aux = ord.punt[i];
		for (int j = i; j > cont; j--) {
			ord.punt[j] = ord.punt[j - 1];
		}
		ord.punt[cont] = aux;
	}

}

void mostrar(const tListaPtr& ord) {
	cout << endl << endl;
	for (int i = 0; i < ord.contador; i++) {
		cout << "Registro " << i + 1 << ": " << endl;
		cout << "Número: " << (*ord.punt[i]).num << endl;
		cout << "Letra: " << (*ord.punt[i]).car << endl << endl;
	}

}

void buscaPar(const tListaPtr& ord, int num, tPtr& punt) {
	bool encontrado = false;
	int contador = 0;

	while (!encontrado && contador < ord.contador) {
		if ((*ord.punt[contador]).num == num) {
			encontrado = true;
		}
		else {
			contador++;
		}
	}
	if (encontrado) {
		punt = ord.punt[contador];
	}
	else {
		punt = NULL;
	}

}

tPtr buscaRet(const tListaPtr& ord, int num) {
	bool encontrado = false;
	int contador = 0;
	tPtr punt;

	while (!encontrado && contador < ord.contador) {
		if ((*ord.punt[contador]).num == num) {
			encontrado = true;
		}
		else {
			contador++;
		}
	}
	if (encontrado) {
		punt = ord.punt[contador];
	}
	else {
		punt = NULL;
	}

	return punt;
}