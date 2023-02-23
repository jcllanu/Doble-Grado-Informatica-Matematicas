#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;


void resolver(const vector<char>& letras, vector<int>& solucion, vector<bool>&  usados, const vector<char>&  palabra1, const vector<char>& palabra2, const vector<char>&  palabra3, int k, const char& operador, bool& encontrado);
void meter(char aux, vector<char>& letras,bool primeraLetra);
bool resuelveCaso();
bool comprobarSolucion(const vector<char>& letras, const vector<int>& solucion, const vector<char>&  palabra1, const vector<char>& palabra2, const vector<char>&  palabra3, const char& operador);
int numero(char letra, const vector<int>& solucion, const vector<char>& letras);
bool primeraLetra(int k, const vector<char>& palabra1, const vector<char>& palabra2, const vector<char>&  palabra3, const vector<char>& letras);
bool esFactible(const vector<char>& letras, const vector<int>& solucion, const vector<char>&  palabra1, const vector<char>& palabra2, const vector<char>&  palabra3, const char& operador, int k);
/*void mezclar(vector<char>& letr, const vector<char>&  palabra1, const vector<char>& palabra2, const vector<char>&  palabra3);*/
/*void quitarRepetidas(vector<char>& letras);*/
bool estaPuesta(char aux, const vector<char>& letr, int cont);


int main() {
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/
	while (resuelveCaso());


	/*#ifndef DOMJUDGE
			std::cin.rdbuf(cinbuf);
			system("PAUSE");
		#endif*/

	return 0;
}

bool resuelveCaso() {
	char aux;
	
	cin >> aux;
	if (!cin) {
		return false;
	}
	else {
		vector<char>letras;
		vector<char> palabra1;
		vector<char> palabra2;
		vector<char> palabra3;
		char operador;
		bool primeraLetra = true;
		letras.push_back(aux);
		palabra1.push_back(aux);
		cin >> aux;
		while (aux != '+' && aux != '*') {
			meter(aux,letras, primeraLetra);
			palabra1.push_back(aux);
			cin >> aux;
		}
		operador = aux;
		cin >> aux;
		while (aux != '=') {
			meter(aux, letras, primeraLetra);
			primeraLetra = false;
			palabra2.push_back(aux);
			cin >> aux;
		}
		cin >> aux;
		primeraLetra = true;
		while (aux != '\n') {
			meter(aux, letras, primeraLetra);
			primeraLetra = false;
			palabra3.push_back(aux);
			cin.get(aux);
		}
		vector<int>solucion(letras.size());
		vector<bool> usados(10);
		for (int i = 0; i < usados.size(); i++) {
			usados[i] = false;
		}
		bool encontrado = false;
		/*mezclar(letras, palabra1, palabra2, palabra3);*/
		resolver(letras, solucion, usados, palabra1, palabra2, palabra3, 0, operador, encontrado);
		return true;
	}
}
/*
void mezclar(vector<char>& letr, const vector<char>&  palabra1, const vector<char>& palabra2, const vector<char>&  palabra3) {
	vector<char> letras(palabra1.size()+ palabra2.size()+ palabra3.size());
	int contp1 = palabra1.size() - 1, contp2 = palabra2.size() - 1, contp3 = palabra3.size() - 1;
	int cont = 0;
	while (contp1 >= 0 && contp2 >= 0 && contp3 >= 0) {
		letras[cont] = palabra1[contp1];
		letras[cont + 1] = palabra2[contp2];
		letras[cont + 2] = palabra3[contp3];
		contp1--;
		contp2--;
		contp3--;
		cont += 3;
	}
	if (contp1 < 0) {
		while (contp2 >= 0 && contp3 >= 0) {
			letras[cont] = palabra2[contp2];
			letras[cont + 1] = palabra3[contp3];
			contp2--;
			contp3--;
			cont += 2;
		}
		if (contp2 <  0) {
			while (contp3 >= 0) {
				letras[cont] = palabra3[contp3];
				contp3--;
				cont ++;
			}
		}
		else {
			while (contp2 >= 0) {
				letras[cont] = palabra2[contp2];
				contp2--;
				cont++;
			}
		}
	}
	else if (contp2 < 0) {
		while (contp1 >= 0 && contp3 >= 0) {
			letras[cont] = palabra1[contp1];
			letras[cont + 1] = palabra3[contp3];
			contp1--;
			contp3--;
			cont += 2;
		}
		if (contp1 < 0) {
			while (contp3 >= 0) {
				letras[cont] = palabra3[contp3];
				contp3--;
				cont++;
			}
		}
		else {
			while (contp1 >= 0) {
				letras[cont] = palabra1[contp1];
				contp1--;
				cont++;
			}
		}
	}
	else if (contp3 < 0) {
		while (contp2 >= 0 && contp1 >= 0) {
			letras[cont] = palabra1[contp1];
			letras[cont + 1] = palabra2[contp3];
			contp1--;
			contp2--;
			cont += 2;
		}
		if (contp2 < 0) {
			while (contp1 >= 0) {
				letras[cont] = palabra1[contp1];
				contp1--;
				cont++;
			}
		}
		else {
			while (contp2 >= 0) {
				letras[cont] = palabra2[contp2];
				contp2--;
				cont++;
			}
		}
	}
	quitarRepetidas(letras);
	letr = letras;
}
void quitarRepetidas(vector<char>& letras) {
	for (int i = letras.size() - 1; i > 0; i--) {
		if (estaPuesta(letras[i], letras, i)) {
			for (int j = i + 1; j < letras.size(); j++) {
				letras[j - 1] = letras[j];
			}
			letras.pop_back();
		}
	}
}*/
bool estaPuesta(char aux, const vector<char>& letr, int cont) {
	for (int i = 0; i < cont; i++) {
		if (letr[i] == aux) {
			return true;
		}
	}
	return false;
}

void meter(char aux, vector<char>& letras, bool primeraLetra) {

	int cont = 0;
	bool encontrado = false;
	while (cont < letras.size() && !encontrado) {
		if (letras[cont] == aux) {
			encontrado = true;
		}
		cont++;
	}
	if (!encontrado) {
		if (primeraLetra) {
			letras.insert(letras.begin(), aux);
		}
		else {
			letras.push_back(aux);
		}
	
	}

}
void resolver(const vector<char>& letras, vector<int>& solucion, vector<bool>&  usados, const vector<char>&  palabra1, const vector<char>& palabra2, const vector<char>&  palabra3, int k, const char& operador, bool& encontrado) {
	for (int i = 0; i <= 9 && !encontrado; i++) {
		if (i == 0) {
			if (primeraLetra(k, palabra1, palabra2, palabra3, letras)) {
				solucion[k] = i;
				if (!usados[i]) {
					usados[i] = true;
					if (k + 1 == solucion.size()) {
						if (comprobarSolucion(letras, solucion, palabra1, palabra2, palabra3, operador)) {
							encontrado = true;
						}
					}
					else {
						if ((k+1)%3 == 0) {
							if (esFactible(letras, solucion,palabra1, palabra2, palabra3,operador,k)) {
								resolver(letras, solucion, usados, palabra1, palabra2, palabra3, k + 1, operador, encontrado);
							}
						}
						else {
							resolver(letras, solucion, usados, palabra1, palabra2, palabra3, k + 1, operador, encontrado);
						}
						

					}

					usados[i] = false;
				}
			}
		}
		else {
			solucion[k] = i;
			if (!usados[i]) {
				usados[i] = true;
				if (k + 1 == solucion.size()) {
					if (comprobarSolucion(letras, solucion, palabra1, palabra2, palabra3, operador)) {
						encontrado = true;
					}
				}
				else {
					resolver(letras, solucion, usados, palabra1, palabra2, palabra3, k + 1, operador, encontrado);

				}

				usados[i] = false;
			}
		}
		

	}
}
bool esFactible(const vector<char>& letras, const vector<int>& solucion, const vector<char>&  palabra1, const vector<char>& palabra2, const vector<char>&  palabra3, const char& operador, int k) {
	/*int cifras = (k+1) / 3;
	long long int numero1 = 0, numero2 = 0, numero3 = 0;
	long long int pot10 = 1;
	for (int i = 0; i < cifras; i++) {
		numero1 += numero(palabra1[i], solucion, letras) * pot10;
		pot10 *= 10;
	}
	pot10 = 1;
	for (int i = 0; i < cifras; i++) {
		numero2 += numero(palabra2[i], solucion, letras) * pot10;
		pot10 *= 10;
	}
	pot10 = 1;
	for (int i = 0; i < cifras; i++) {
		numero3 += numero(palabra3[i], solucion, letras) * pot10;
		pot10 *= 10;
	}

	if (operador == '+') {
		if ((numero1 + numero2)%pot10 == numero3%pot10){
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if ((numero1 * numero2) % pot10 == numero3 % pot10) {
			return true;
		}
		else {
			return false;
		}
	}*/

	long long int numero1 = 0, numero2 = 0, numero3 = 0;
	numero1 = numero(palabra1[0], solucion, letras);
	numero2 = numero(palabra2[0], solucion, letras);
	numero3 = numero(palabra3[0], solucion, letras);


	if (operador == '+') {
		if ((numero1 + numero2) % 10 == numero3) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if ((numero1 * numero2) % 10 == numero3) {
			return true;
		}
		else {
			return false;
		}
	}
}
bool comprobarSolucion(const vector<char>& letras, const vector<int>& solucion, const vector<char>&  palabra1, const vector<char>& palabra2, const vector<char>&  palabra3, const char& operador) {
	long long int numero1 = 0, numero2 = 0, numero3 = 0;
	long long int pot10 = 1;
	for (int i = palabra1.size() - 1; i >= 0; i--) {
		numero1 += numero(palabra1[i],solucion,letras) * pot10;
		pot10 *= 10;
	}
	pot10 = 1;
	for (int i = palabra2.size() - 1; i >= 0; i--) {
		numero2 += numero(palabra2[i], solucion, letras) * pot10;
		pot10 *= 10;
	}
	pot10 = 1;
	for (int i = palabra3.size() - 1; i >= 0; i--) {
		numero3 += numero(palabra3[i], solucion, letras) * pot10;
		pot10 *= 10;
	}
	if (operador == '+') {
		if (numero1 + numero2 == numero3 && !(numero(palabra1[0], solucion, letras) == 0 && palabra1.size() > 1) && !(numero(palabra2[0], solucion, letras) == 0 && palabra2.size() > 1) && !(numero(palabra3[0], solucion, letras) == 0 && palabra3.size() > 1)) {
			cout << numero1;
			cout << " + ";
			cout << numero2;
			cout << " = ";
			cout << numero3;
			cout << endl;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (numero1 * numero2 == numero3 && !(numero(palabra1[0], solucion, letras) == 0 && palabra1.size() > 1) && !(numero(palabra2[0], solucion, letras) == 0 && palabra2.size() > 1) && !(numero(palabra3[0], solucion, letras) == 0 && palabra3.size() > 1)) {
			cout << numero1;
			cout << " * ";
			cout << numero2;
			cout << " = ";
			cout << numero3;
			cout << endl;
			return true;
		}
		else {
			return false;
		}
	}
}

int numero(char letra, const vector<int>& solucion, const vector<char>& letras) {
	int cont = 0;
	bool encontrado = false;
	while (cont < letras.size() && !encontrado) {
		if (letras[cont] == letra) {
			encontrado = true;
		}else{
			cont++;
		}
	
	}
	return solucion[cont];
}
bool primeraLetra(int k, const vector<char>& palabra1, const vector<char>& palabra2, const vector<char>&  palabra3, const vector<char>& letras) {

	if (letras[k] == palabra1[0] && palabra1.size() > 1 || letras[k] == palabra2[0] && palabra2.size() > 1 || letras[k] == palabra2[0] && palabra2.size() > 1) {
		return false;
	}
	else {
		return true;
	}
}