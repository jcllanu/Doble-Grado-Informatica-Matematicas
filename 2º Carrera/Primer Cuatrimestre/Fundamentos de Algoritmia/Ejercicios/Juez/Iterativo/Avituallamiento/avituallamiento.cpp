/*Juan Carlos Llamas Núñez  2º DG FAL*/



#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

void tamSegmentoMaximo(vector<int> v, int &a, int&b);
int longitud(int a, int b);
bool iguales(vector<int> v, int a, int b);

bool resuelveCaso() {
	int aux;
	cin >> aux;
	if (aux == -1) {
		return false;
	}
	else {
		vector<int> v;
		v.push_back(aux);
		cin >> aux;
		while (aux != -1) {
			v.push_back(aux);
			cin >> aux;
		}
		int a, b;
		tamSegmentoMaximo(v, a, b);
		int tam = longitud(a, b);
		if (tam == 1) {
			cout << "HOY NO COMEN";
		}
		else {
			cout << b-a-1;
		}
		cout << endl;
		return true;
	}
}


/*{N>=2}*/

void tamSegmentoMaximo(vector<int> v, int &a, int&b) {
	int n = 1, tam=1, t = 1, c = 0;
	a = 0;
	b = 1;
	
	/*{I= tam=max i, j: 0<=i<j<=n && iguales(v,i,j): longitud(i,j) &&
	tam=long(a,b) && 
	0<=a<b<=n<=N && 
	iguales(v,a,b) &&
	t=max i: 0<=i<n && iguales(i,n): longitud(i, n) &&
	c=min i: 0<=i<n && iguales(i,n): i
	
	Cota=N-n*/
	while (n != v.size()) {
		if (iguales(v, n-1, n+1)) {
			t++;
			if (b == n) {
				b++;
			}
			else if (tam < t) {
				tam = t;
				b=n+1;
				a = c;
			}
		}else{
			t = 1;
			c = n;
		}

		n++;
	}
}
/*{longitud(a,b)=max i, j: 0<=i<=j<=N && iguales(v,i,j): longitud(i,j) &&
	0<=a<=b<=n<=N && iguales(v,a,b)

	Coste: O(N)
*/

int longitud(int a, int b) {
	return b - a;
}

/*{0<=a<=b<=N}*/
bool iguales(vector<int> v, int a, int b) {
	bool same = true;
	int n = a;
	while (n != b) {
		same = same && v[n] == v[a];
		n++;
	}
	return same;
}
/*{same=para todo k: a<=k<b: v[k]=v[a]}*/

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
