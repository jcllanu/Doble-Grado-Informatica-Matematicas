
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;


void resuelveCaso() {
	int lineaOriginal, lineaNueva=10;
	string instr;
	unordered_map<int, int> mapaNumLineas;
	vector<string> instrucciones;
	vector<int> numerosGoTo;

	cin >> lineaOriginal;
	while (lineaOriginal != 0) {
		mapaNumLineas[lineaOriginal] = lineaNueva;
		cin >> instr;
		instrucciones.push_back(instr);
		if (instr != "RETURN") {
			cin >> lineaOriginal;
			numerosGoTo.push_back(lineaOriginal);
		}
		else {
			numerosGoTo.push_back(-1);
		}
		lineaNueva += 10;
		cin >> lineaOriginal;
	}
	lineaNueva = 10;
	for (int i = 0; i < instrucciones.size(); i++) {
		cout << lineaNueva << ' ' << instrucciones[i];
		if(instrucciones[i] != "RETURN") {
			cout << ' ' << mapaNumLineas[numerosGoTo[i]];
		}
		cout << '\n';
		lineaNueva += 10;
	}
	cout << "---\n";

}




int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}