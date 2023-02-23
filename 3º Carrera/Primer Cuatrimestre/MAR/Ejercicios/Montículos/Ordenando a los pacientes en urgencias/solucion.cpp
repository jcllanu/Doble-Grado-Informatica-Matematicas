
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "PriorityQueue.h"
#include <string>
using namespace std;

struct tPaciente {
	string nombre;
	long long int tiempoLlegada;
	long long int gravedad;
};
struct Comparator{
	bool operator()(tPaciente const& a, tPaciente const& b) {
		return a.gravedad>b.gravedad || a.gravedad == b.gravedad && a.tiempoLlegada < b.tiempoLlegada;
	}
};
bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;

	PriorityQueue<tPaciente, Comparator> monticulo;
	tPaciente paciente;
	char c;
	long long int tiempo = 0;
	
	for (int i = 0; i < n; i++) {
		cin.get(c);
		cin.get(c);
		if (c == 'I') {
			cin >> paciente.nombre >> paciente.gravedad;
			paciente.tiempoLlegada = tiempo;
			tiempo++;
			monticulo.push(paciente);
		}
		else {
			cout << monticulo.top().nombre << '\n';
			monticulo.pop();
		}
	}
	cout << "---\n";
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
