#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

bool resuelveCaso();
long long int inversiones(const vector<int>& v, vector<int>& aux, int ini, int fin);
long long int merge(const vector<int>& v, const vector<int>& aux1, const vector<int>& aux2, vector<int>& aux);

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
	int N;
	cin >> N;
	if (N == 0) {
		return false;
	}
	else {
		vector<int> v(N);
		vector<int> aux(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		cout << inversiones(v,aux,0,v.size()) << endl;
		
		return true;
	}

}
long long int inversiones(const vector<int>& v, vector<int>& aux, int ini, int fin) {
	long long int invers = 0;
	if (fin - ini <= 1) {
		aux[0] = v[ini];
		return invers;
	}
	else {
		int mitad = (ini + fin) / 2;
		vector<int> aux1(mitad - ini);
		vector<int> aux2(fin - mitad);
		invers = inversiones(v, aux1, ini, mitad);
		invers += inversiones(v, aux2, mitad, fin);
		invers += merge(v,aux1, aux2, aux);
		return invers;
	}
}


long long int merge(const vector<int>& v, const vector<int>& aux1, const vector<int>& aux2, vector<int>& aux) {
	long long int invers = 0;
	int contaux1 = 0, contaux2 = 0, contaux = 0;

	while (contaux1 < aux1.size() && contaux2 < aux2.size()) {
		if (aux1[contaux1] > aux2[contaux2]) {
			aux[contaux] = aux2[contaux2];
			contaux2++;
			invers += (aux1.size() - contaux1);
		}
		else {
			aux[contaux] = aux1[contaux1];
			contaux1++;
		}
		contaux++;
	}
	if (contaux1 == aux1.size()) {
		while (contaux2 < aux2.size()) {
			aux[contaux] = aux2[contaux2];
			contaux2++;
			contaux++;
		}
	}
	if (contaux2 == aux2.size()) {
		while (contaux1 < aux1.size()) {
			aux[contaux] = aux1[contaux1];
			contaux1++;
			contaux++;
		}
	}
	return invers;
}