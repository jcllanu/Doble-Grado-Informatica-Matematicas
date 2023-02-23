/*Juan Carlos Llamas y Adrián Sanjuán
2º DG*/
#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

/*A={1<=N<=10.000 ^para todo i: 0<=i<=N-1: 0<v[i]<=10^18}*/

void resolver(vector<long long int> v, long long int & max, long long int & maxveces, long long int& min, long long int &minveces){
	int n = 1;
	max = v[0];
	min = v[0];
	minveces = 1;
	maxveces = 1;
	/*I=(max= max i: 0<=i<n: V[i]) &&
		(min= min i: 0<=i<n: V[i]) &&
		(maxveces=#i: 0<=i<n: V[i]=max) &&
		(minveces=#i: 0<=i<n: V[i]=min) &&
		(1<=n<=N)
		
	C=N-n*/
	while (n!=v.size()) {
		if (max < v[n]) {
			max = v[n];
			maxveces = 1;
		}
		else if (max == v[n]) {
			maxveces++;
		}
		if (min > v[n]) {
			min = v[n];
			minveces = 1;
		}
		else if (min == v[n]) {
			minveces++;
		}
		n++;
	}
}
/*B = (max = max i : 0 <= i < N : v[i]) ^ (min = min i : 0 <= i < N : v[i]) ^
(maxveces = #i: 0 <= i < N: v[i] = max) ^ (minveces = #i: 0 <= i < N : v[i] = min) */

void resuelveCaso() {
	long long int a;
	vector<long long int> v(0);
	long long int cont = 0;
	long long int max, maxveces, min, minveces;

	cin >> a;
	while (a != 0) {
		v.resize(v.size()+1);
		v[cont] = a;
		cin >> a;
		cont++;
	}
	resolver(v, max, maxveces, min, minveces);
	cout << min << " " << minveces << " " << max << " " << maxveces << endl;
}




int main() {
	int numCasos;
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}