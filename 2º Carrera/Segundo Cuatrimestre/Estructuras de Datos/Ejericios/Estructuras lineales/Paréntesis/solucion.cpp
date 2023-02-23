
// JUAN CARLOS LLAMAS NÚÑEZ

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "pila.h"

using namespace std;

bool resuelveCaso() {
	stack<char> pila;
	bool equilibrada = true;
	string line;
	char a;
	int i = 0;
	getline(cin, line);
	if (!cin) {
		return false;
	}
	
	while (i<line.length()) {
		a = line.at(i);
		if (a == '('||a == '[' || a == '{') {
			pila.push(a);
		}
		else if (a == ')') {
			if (!pila.empty() && pila.top() == '(') {
				pila.pop();
			}
			else {
				equilibrada = false;
			}
		}
		else if (a == ']') {
			if (!pila.empty() && pila.top() == '[') {
				pila.pop();
			}
			else {
				equilibrada = false;
			}
		}
		else if (a == '}') {
			if (!pila.empty() && pila.top() == '{') {
				pila.pop();
			}
			else {
				equilibrada = false;
			}
		}
		i++;
	}
	if (pila.empty() && equilibrada) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
