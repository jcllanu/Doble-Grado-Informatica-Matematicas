
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "queue.h"
#include "stack.h"

using namespace std;
bool es_vocal(char c) {
	return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
}
void volcar_pila(stack<char>& pila_consonantes, string& X) {
	while (!pila_consonantes.empty()) {
		X += pila_consonantes.top();
		pila_consonantes.pop();
	}
}

string decodifica(string const& mensaje) {
	string X;
	queue<char> cola_inicio;
	stack<char> pila_fin;
	stack<char> pila_consonantes;
	char c;
	int N = 0;
	//Fase 1
	for (char c : mensaje) {
		if (N % 2 == 0) {
			cola_inicio.push(c);
		}
		else {
			pila_fin.push(c);
		}
		N++;
	}
	
	//Fase 2
	for (int i = 0; i < N; i++) {
		if (!cola_inicio.empty()) {
			c = cola_inicio.front();
			cola_inicio.pop();
		}
		else {
			c = pila_fin.top();
			pila_fin.pop();
		}
		if (es_vocal(c)) {
			volcar_pila(pila_consonantes, X);
			X += c;
		}
		else {
			pila_consonantes.push(c);
		}
	}
	volcar_pila(pila_consonantes, X);
	return X;
}
bool resuelveCaso() {
	string mensaje;
	getline(cin, mensaje);
	if (!cin) {
		return false;
	}
	cout << decodifica(mensaje)<<'\n';

	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	while(resuelveCaso());


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
