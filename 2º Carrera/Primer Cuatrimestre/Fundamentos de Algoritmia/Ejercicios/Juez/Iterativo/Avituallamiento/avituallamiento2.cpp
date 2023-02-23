/*Juan Carlos Llamas Núñez  2º DG FAL*/



#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int tamSegmentoMaximo(vector<int> v);

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
		
		int tam = tamSegmentoMaximo(v);
		if (tam == 1) {
			cout << "HOY NO COMEN";
		}
		else {
			cout << tam-1;
		}
		cout << endl;
		return true;
	}
}


/*{N>=2}*/

int tamSegmentoMaximo(vector<int> v) {
	int n = 1, tam = 1, s = 0;
	
	
	/*{I= tam = max i, j: 0<=i<j<=n && iguales(v,i,j): longitud(i,j) && 
	0<=n<=N && 
	s=min i: 0<=i<n && iguales(i,n): i
	
	Cota=N-n*/
	while (n != v.size()) {
		if (v[n] != v[s]) {
			s = n;
		}
		tam = max(tam, n + 1 - s);
		n++;
	}
	return tam;
}
/*{tam=max i, j: 0<=i<=j<=N && iguales(v,i,j): longitud(i,j) &&
	0<=n<=N

	Coste: O(N)
*/

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
