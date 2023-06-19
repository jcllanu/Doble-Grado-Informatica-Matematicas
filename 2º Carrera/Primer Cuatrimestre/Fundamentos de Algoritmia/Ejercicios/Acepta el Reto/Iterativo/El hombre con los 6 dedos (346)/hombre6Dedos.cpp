#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

bool resuelveCaso();
int resolver(vector<int> v, int A);

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
	int N, A;
	cin >> N;
	cin >> A;
	if (N == 0 && A==0) {
		return false;
	}
	else {
		vector<int> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		cout << resolver(v, A) << endl;
		return true;
	}

}
int resolver(vector<int> v, int A) {
	int maximo = 0;
	int aux = 0;
	for (int i = 0; i < v.size(); i++) {
		while (v[i] - v[aux] >= A) {
			aux++;
		}
		maximo = max(maximo, i-aux+1);
	}
	return maximo;

}