
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <climits>
#include <string>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;


typedef enum {a,b,c}tLetra;
vector<vector<tLetra>> mult
{
	{b, b, a},
	{c, b, a},
	{a, c, c}
};

struct misLetras {
	tLetra letra;
	tLetra operator*(misLetras const& otro) {
		return mult[this->letra][otro.letra];
	}
};

struct conjuntoLetras{
	unordered_set<tLetra> conj;

	bool esta(tLetra const& letra) {
		return conj.count(letra ) > 0;
	}

	conjuntoLetras operator*(conjuntoLetras const& otro) {
		conjuntoLetras result;
		for (tLetra l : this->conj) {
			for (tLetra m : otro.conj) {
				result.conj.insert(misLetras({ l })*misLetras({ m }));
			}
			if (this->esta(a) && this->esta(b) && this->esta(c)) {
				break;
			}
		}
		return result;
	}

	void union_conj(conjuntoLetras const& otro) {
		for (auto l : otro.conj) {
			this->conj.insert(l);
		}
	}
};
tLetra parse(char l) {
	if (l == 'a') {
		return  a ;
	}
	else if (l == 'b') {
		return  b ;
	}
	else if (l == 'c') {
		return  c ;
	}
}

bool resuelveCaso() {
	string palabra;
	cin >> palabra;
	if (!cin)
		return false;

	int N = palabra.size();

	vector<vector<conjuntoLetras>> producto(N, vector<conjuntoLetras>(N));
	for (int i = 0; i < N; i++) {
		producto[i][i].conj.insert( parse(palabra[i]));
	}
	for (int d = 1; d < N; d++) {
		for (int i = 0; i < N - d; i++) {
			int j = i + d;
			for (int k = i; k < j; k++) {
				producto[i][j].union_conj(producto[i][k] * producto[k + 1][j]);
				if (producto[i][j].esta(a) && producto[i][j].esta(b) && producto[i][j].esta(c)) {
					break;
				}
			}
		}
	}
	if (producto[0][N - 1].esta(a)) {
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
	/*int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}*/
	while (resuelveCaso());


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}

