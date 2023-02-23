#include<iostream>
#include<fstream>
#include<vector>


using namespace std;

bool resuelveCaso();
int resolver(vector<int> v);

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
		vector<int> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		cout << resolver(v) << endl;
		return true;
	}

}
int resolver(vector<int> v) {
	int monasterios = 1;
	int maximo = v[v.size() - 1];
	for (int i = v.size() - 2; i >= 0; i--) {
		if (v[i] > maximo) {
			maximo = v[i];
			monasterios++;
		}
	}
	return monasterios;
}