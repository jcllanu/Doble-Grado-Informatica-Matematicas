#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

bool solucion(vector<int> v, int D);

bool resuelveCaso() {
	int D, N;
	cin >> D;
	if (!std::cin) {
		return false;
	}
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	if (solucion(v, D)) {
		cout << "APTA" << endl;
	}
	else {
		cout << "NO APTA" << endl;
	}

		return true;

}


int main() {
	#ifndef DOMJUDGE 
		std::ifstream in("casos.txt"); 
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
	#endif

		while (resuelveCaso());

	#ifndef DOMJUDGE 
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}

bool solucion(vector<int> v, int D) {
	int n = 1, d = 0, p=0, s=v[0];
	while (n != v.size()) {
		if (v[n - 1] >= v[n]) {
			p = n;
			s = v[n];
		}
		d = max(d, v[n] - s);
		n++;
	}
	return D >= d;
}