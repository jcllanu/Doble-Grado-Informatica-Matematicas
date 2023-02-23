#include<iostream>
#include<fstream>
#include<vector>


using namespace std;

void resuelveCaso();
void segSumaMax(vector<int> v, int &a, int& b);

int main() {
	/*
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}/*
#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	return 0;
}

void resuelveCaso() {
	int N; 
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int a, b;
	segSumaMax(v,a ,b);
	cout << a + 1 << " " << b << endl;
}


void segSumaMax(vector<int> v, int &a, int& b) {
	int n = 1, r = v[0], s = v[0], c = 0;
	a = 0;
	b = 1;
	while (n != v.size()) {
		if (s > 0) {
			s += v[n];
		}
		else {
			s = v[n];
			c = n;
		}
		if (r < s || (r==s && n+1-c<b-a)) {
			r = s;
			a = c;
			b = n + 1;
		}
		n++;
	}
}