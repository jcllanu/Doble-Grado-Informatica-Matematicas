// Juan Carlos Llamas Núñez 2º DG FAL

#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

bool BajoArboles(int a, int b, int h, vector<int> v);
int longitud(int a, int b);
void resolver(int h, vector<int> v, int &a, int &b);



void resuelveCaso() {
	int N, h, a, b;

	cin >> N;
	cin >> h; 
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	resolver(h, v, a, b);
	cout << a <<" "<< b << endl;
	
}
/*{N >= 1 && existe i : 0 <= i<N : v[i]>h}
long(a,b)=b-a;
BajoArboles(a,b)= para todo k: a<=k<b: v[k]>h
*/


void resolver(int h, vector<int> v, int &a, int &b) {
	a = 0, b = 0;
	int n = 0, max_long = 0, s = 0, c = 0;
	
	/*I = (max_long = max i, j:(0 <= i <= j <= n && BajoArboles(i, j)) : long(i, j) &&
		0 <= n <= N &&
		max_long = long(a, b) &&
		0 <= a <= b <= n &&
		BajoArboles(a, b) &&
		s = min i: 0<=i<=n && BajoArboles(i,n): i 

	 C=N-n*/
	while (n != v.size()) {

		if (v[n] <= h) {
			s = n + 1;
		}
		if (max_long < n + 1 - s) {
			b = n + 1;
			a = s;
			max_long = n + 1 - s;
		}
		n++;
	}
	b--;
	
}
/*long(a,b)=max i,j: 0<=i<=j<=N && BajoArboles(i,j): long(i,j) &&
	0<=a<=b<=N && BajoArboles(a,b)

	Coste: O(N)*/

int longitud(int a, int b) {
	return b - a;
}
bool BajoArboles(int a, int b, int h, vector<int> v) {
	bool bajo = true;
	int n = a;
	while (n != b) {
		bajo = bajo && v[n] > h;
		n++;
	}

	return bajo;
}




int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
