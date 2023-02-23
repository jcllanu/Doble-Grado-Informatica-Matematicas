#include<iostream>
#include<fstream>
#include<vector>


using namespace std;

bool resuelveCaso();
int resolver(vector<bool> v);

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
	int N;
	cin >> N;
	if (N == 0) {
		return false;
	}
	else {
		vector<bool> v(N,false);
		int aux;
		for (int i = 0; i < N - 1; i++) {
			cin >> aux;
			v[aux-1] = true;
		}

		cout <<resolver(v)<< endl;
		return true;
	}
	
}
int resolver(vector<bool> v) {
	int cont=0;
	while (cont < v.size() && v[cont]) {
		cont++;
	}
	return cont + 1;
}