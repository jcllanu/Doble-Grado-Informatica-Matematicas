
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;


bool resuelveCaso() {
	int N,aux;
	unordered_map<int, int> mapaNumeros;//el primer entero indica el numero y el segundo la multiplicidad
	vector<int> numerosOrdenados;
	cin >> N;
	if (!cin) {
		return false;
	}
	for (int i = 0; i < N; i++) {
		cin >> aux;
		if (mapaNumeros.count(aux) == 0) {
			numerosOrdenados.push_back(aux);
		}
		mapaNumeros[aux]++;
	}
	for (int elem : numerosOrdenados) {
		cout << elem << ' ' << mapaNumeros[elem] << '\n';
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