
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "PriorityQueue.h"
#include <string>
using namespace std;

struct tTarea {
	long long int tiempoInicio;
	long long int tiempoFin;
	long long int periodo;
	bool periodica;
};
struct ComparatorMenor{
	bool operator()(int const& a, int const& b) {
		return a < b;
	}
};
struct ComparatorMayor {
	bool operator()(int const& a, int const& b) {
		return a > b;
	}
};
bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin)
		return false;

	PriorityQueue<int, ComparatorMenor> monticuloGrandes;
	PriorityQueue<int, ComparatorMayor> monticuloPequenos;
	int aux;
	//monticuloPequenos.size()>=monticulograndes.size()
	for (int i = 0; i < n; i++) {
		cin >> aux;
		if (aux == 0) {
			if (monticuloPequenos.empty()) {
				cout << "ECSA ";
			}
			else {
				cout << monticuloPequenos.top() << ' ';
				monticuloPequenos.pop();
				if (monticuloPequenos.size() < monticuloGrandes.size()) {
					monticuloPequenos.push(monticuloGrandes.top());
					monticuloGrandes.pop();
				}
			}
		}
		else {
			if (monticuloPequenos.empty()) {
				monticuloPequenos.push(aux);
			}
			else if (monticuloGrandes.empty()) {
				if (aux < monticuloPequenos.top()) {
					monticuloGrandes.push(monticuloPequenos.top());
					monticuloPequenos.pop();
					monticuloPequenos.push(aux);
				}
				else {
					monticuloGrandes.push(aux);
				}
		
			}
			else {
				if (aux < monticuloPequenos.top()) {
					if (monticuloPequenos.size() == monticuloGrandes.size()) {
						monticuloPequenos.push(aux);
					}
					else {
						monticuloGrandes.push(monticuloPequenos.top());
						monticuloPequenos.pop();
						monticuloPequenos.push(aux);
					}
				}
				else if (aux > monticuloGrandes.top()) {
					if (monticuloPequenos.size() == monticuloGrandes.size()) {
						monticuloPequenos.push(monticuloGrandes.top());
						monticuloGrandes.pop();
						monticuloGrandes.push(aux);
					}
					else {
						monticuloGrandes.push(aux);
					}
				}
				else {
					if (monticuloPequenos.size() == monticuloGrandes.size()) {
						monticuloPequenos.push(aux);
					}
					else {
						monticuloGrandes.push(aux);
					}
				}
			}
		}
	}
	cout << endl;
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
