#include<iostream>
#include<fstream>
#include<vector>


using namespace std;

bool resuelveCaso();
long long int resolver(vector<long long int> v);

int main() {
	/*
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/
	while (resuelveCaso());
	/*
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	return 0;
}

bool resuelveCaso() {
	long long int N;
	cin >> N;
	if (N == 0) {
		return false;
	}
	else {
		vector<long long int> v(N);
		for (long long int i = 0; i < N; i++) {
			cin >> v[i];
		}

		cout << resolver(v) << endl;
		return true;
	}

}
long long int resolver(vector<long long int> v) {
	long long int suma = 0, resultado = 0;

	for (int i = 0; i < v.size(); i++) {
		suma += v[i];
	}

	for (long long int i = 0; i < v.size() - 1; i++) {
		suma -= v[i];
		resultado += v[i] * suma;
	}
	return resultado;
}