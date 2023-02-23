
// Juan Carlos Llamas

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include<set>
#include <cctype>

using namespace std;


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	map<string, set<int>> referencias;
	cin.ignore(100, '\n');
	string line;
	string valorString;
	for (int i = 1; i <= n; i++) {
		getline(cin, line);
		stringstream ss(line);
		while (ss >> valorString) {
			transform(valorString.begin(), valorString.end(), valorString.begin(),[](unsigned char c) { return std::tolower(c); });//Solución buscada para convertir todo a minúsculas
			if (valorString.length() > 2) {
				referencias[valorString].insert(i);
			}	
		}
	}
	for (auto elem : referencias) {
		cout << elem.first<<' ';
		for (auto elemento : elem.second) {
			cout << elemento << ' ';
		}
		cout << '\n';
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
	while(resuelveCaso());
	
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}