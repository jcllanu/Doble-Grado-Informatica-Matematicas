#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

bool esPosible(const vector<int>& numeros, int k, vector<char>& operadores, int resultado);
bool operar(int izq, int der, char op, int&result);

char operador(int i);
bool resuelveCaso() {
	int resultado;
	cin >> resultado;
	if (!cin) {
		return false;
	}
	else {
		vector<int> numeros(5);
		for (int i = 0; i < numeros.size(); i++) {
			cin >> numeros[i];
		}
		vector<char> operadores(4);
		if (esPosible(numeros, 0, operadores, resultado)) {
			cout << "SI" << endl;
			/*string dev;
			cout << "((((";
			for (int i = 0; i < 4; i++) {
				cout << numeros[i];
				cout << ") ";
				cout << operadores[i];
				cout << " ";
			}
			cout << numeros[4];
			cout << ") =";
			cout<<resultado << endl << endl;*/
		}
		else {
			cout << "NO" << endl;
		}
		return true;
	}
}


int main() {
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/
	while(resuelveCaso());
	

/*#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	return 0;
}
bool esPosible(const vector<int>& numeros, int k, vector<char>& operadores, int resultado) {
	bool posible = false;
	for (int i = 0; i < operadores.size(); i++) {
		operadores[k] = operador(i);
		if (operadores.size() == k + 1) {
			int result=0;
			if (operar(numeros[0], numeros[1], operadores[0], result) && operar(result, numeros[2], operadores[1], result) && operar(result, numeros[3], operadores[2], result) && operar(result, numeros[4], operadores[3], result) && result == resultado) {
				return true;
			}
		}
		else {
			posible=esPosible(numeros, k + 1, operadores, resultado);
			if (posible) {
				break;
			}
		}
	}
	return posible;
}
char operador(int i) {
	if (i == 0) {
		return '+';
	}
	else if (i == 1) {
		return '-';
	}
	else if (i == 2) {
		return '*';
	}
	else {
		return '/';
	}
}
bool operar(int izq, int der, char op, int&result) {
	if (op == '/') {
		if (der != 0 && izq%der == 0) {
			result = izq / der;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (op == '+') {
			result = izq + der;
		}
		else if (op == '-') {
			result = izq - der;
		}
		else {
			result = izq * der;
		}

		return true;
	}
}
