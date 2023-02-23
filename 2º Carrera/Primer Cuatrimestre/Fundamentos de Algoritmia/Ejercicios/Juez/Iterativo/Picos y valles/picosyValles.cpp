/*Juan Carlos Llamas Núñez
2º DG*/
#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

/*A={1<=N<=10.000 ^para todo i: 0<=i<=N-1: -274<v[i]<=1.000}*/

int numPicos(vector<int> v) {
	int num;
	if (v.size() == 1) {
		num = 0;
	}
	else {
		/*{2<=N<=10.000 ^para todo i: 0<=i<=N-1: -274<v[i]<=1.000}*/
		num = 0;
		int n = 2;
		/*I=(num=#i: 1<=i<=n-2: v[i-1]<v[i] && v[i+1]<v[i] && 2<=n<=N)
		  C=N-n
		 */
		while (n != v.size()) {
			if (v[n - 2] < v[n - 1] && v[n] < v[n - 1]) {
				num++;
			}
			n++;
		}
	}
	return num;
}
/*numPicos= #i: 1<=i<=N-2 : v[i-1]<v[i] && v[i+1]<v[i]
 Coste: O(N)*/




/*A={1<=N<=10.000 ^para todo i: 0<=i<=N-1: -274<v[i]<=1.000}*/

int numValles(vector<int> v) {
	int num;
	if (v.size() == 1) {
		num = 0;
	}
	else {
		/*{2<=N<=10.000 ^para todo i: 0<=i<=N-1: -274<v[i]<=1.000}*/
		num = 0;
		int n = 2;
		/*I=(num=#i: 1<=i<=n-2: v[i-1]>v[i] && v[i+1]>v[i] && 2<=n<=N)
		  C=N-n
		  */
		while (n != v.size()) {
			if (v[n - 2] > v[n - 1] && v[n] > v[n - 1]) {
				num++;
			}
			n++;
		}
	}
	return num;
}
/*numPicos= #i: 1<=i<=N-2 : v[i-1]>v[i] && v[i+1]>v[i]

Coste: O(N)*/



void resuelveCaso() {
	long long int N;

	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	
	cout << numPicos(v)<< " " << numValles(v)  << endl;
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