/* Viva FAL:	Alberto Almagro
				Juan Carlos Llamas
				Jaime Martínez
				Santiago Mourenza
				Pedro Palacios
				Enrique Rey 
	*/


#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef struct {
	int numCrias;
	int numSubCrias;
	string cadena;
}Solucion;


bool resuelveCaso();
Solucion solucion(const vector<int>& jirafas);
bool hembra(int x);
bool macho(int x);
int cria(int hembra, int macho);


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

bool resuelveCaso() {
	bool end = false;
	Solucion sol;
	
	int N;
	cin >> N;
	if (!cin) {
		end = true;
	}
	else {
		vector<int> jirafas(N);
		for (int i=0; i < N; i++) {
			cin >> jirafas[i];
		}
	
		sol = solucion(jirafas);
		cout << sol.numCrias << " " << sol.numSubCrias << " " << sol.cadena << endl;
		
	}

	return !end;
}

/*N>=2 && existe i: 0<=i<N : hembra(jirafas[i]) && existe i: 0<=i<N : macho(jirafas[i])*/


Solucion solucion(const vector<int>& jirafas) {
	int n = 1, numCrias = 0, numSubCrias = 0, sumaJirafas = jirafas[0], sumaCrias = 0, nuevaCria;
	bool criaMacho = false, criaHembra = false;
	
	if (hembra(jirafas[0]) && macho(jirafas[1])) {
		numCrias++;
		nuevaCria = cria(jirafas[0], jirafas[1]);
		sumaCrias += nuevaCria;
		if (macho(nuevaCria)) {
			criaMacho = true;
		}
		else {
			criaHembra = true;
		}
	}
	
	/* INVARIANTE : a) numCrias = #i: 0<=i<n && hembra(jirafas[i]) && machoAdyacente(jirafas, i) : i
					b) 1<=n<=N-1
					c) sumaJirafas = suma i : 0 <= i < n : jirafa[i]
					d) sumaCrias = suma i : 0 <= i < numCrias : crias[i]
					e) numSubCrias = #i: 0<=i<numCrias && hembra(crias[i]) && machoAdyacente(crias, i) : i
					f) criaMacho= para todo i: i>=0 && i=numCrias-1: macho(cria[i])
					g) criaHembra= para todo i: i>=1 && i=numCrias-1: hembra(cria[i]) && hembra(cria[i-1])

				machoAdyacente(v, i) =(Def)  existe j: 0<=j<N && (j=i-1 || j=i+1): macho(v[i])

		COTA: C= N-1-n
	*/
	while (n != jirafas.size() - 1) {

		if (hembra(jirafas[n]) && (macho(jirafas[n - 1]) || macho(jirafas[n + 1]))) {
			if (!macho(jirafas[n - 1])) {
				nuevaCria = cria(jirafas[n], jirafas[n + 1]);
			}
			else if (!macho(jirafas[n + 1])) {
				nuevaCria = cria(jirafas[n], jirafas[n - 1]);
			}
			else {
				nuevaCria = cria(jirafas[n], max(jirafas[n - 1], jirafas[n + 1]));
			}
			sumaCrias += nuevaCria;
			numCrias++;
			if (macho(nuevaCria)) {
				if (criaHembra) {
					criaHembra = false;
					numSubCrias++;
				}
				criaMacho = true;
			}
			else {
				if (criaMacho) {
					criaMacho = false;
					numSubCrias++;
				}
				else {
					criaHembra = true;
				}
			}
		}
		sumaJirafas += jirafas[n];
		n++;
	}
	/* POSTCONDICIÓN :  a) numCrias = #i: 0<=i<N-1 && hembra(jirafas[i]) && machoAdyacente(jirafas, i) : i
						b) n=N-1
						c) sumaJirafas = suma i : 0 <= i < N-1 : jirafa[i]
						d) sumaCrias = suma i : 0 <= i < numCrias : crias[i]
						e) numSubCrias = #i: 0<=i<numCrias && hembra(crias[i]) && machoAdyacente(crias, i) : i
						f) criaMacho= para todo i: i>=0 && i=numCrias-1: macho(cria[i])
						g) criaHembra= para todo i: i>=1 && i=numCrias-1: hembra(cria[i]) && hembra(cria[i-1])

	*/
	if (hembra(jirafas[jirafas.size() - 1]) && macho(jirafas[jirafas.size() - 2])) {
		
		nuevaCria = cria(jirafas[jirafas.size() - 1], jirafas[jirafas.size() - 2]);
		sumaCrias += nuevaCria;
		numCrias++;

		if (macho(nuevaCria)) {
			if (criaHembra) {
				criaHembra = false;
				numSubCrias++;
			}
			criaMacho = true;
		}
		else {
			if (criaMacho) {
				criaMacho = false;
				numSubCrias++;
			}
			else {
				criaHembra = true;
			}
		}
	}
	sumaJirafas += jirafas[jirafas.size() - 1];

	/* POSTCONDICIÓN :  a) numCrias = #i: 0<=i<N && hembra(jirafas[i]) && machoAdyacente(jirafas, i) : i
						b) sumaJirafas = suma i : 0 <= i < N : jirafa[i]
						d) sumaCrias = suma i : 0 <= i < numCrias : crias[i]
						e) numSubCrias = #i: 0<=i<numCrias && hembra(crias[i]) && machoAdyacente(crias, i) : i

	*/
	Solucion sol= {numCrias, numSubCrias, "" };
	if (double(sumaJirafas)/jirafas.size() < double(sumaCrias)/numCrias) {
		sol.cadena = "INCREMENTO";
	}
	else if (double(sumaJirafas) / jirafas.size() == double(sumaCrias) / numCrias) {
		sol.cadena = "SIN CAMBIOS";
	}
	else {
		sol.cadena = "DECREMENTO";
	}
	return sol;
}


/*	sol.numCrias = #i: 0<=i<N-1 && hembra(jirafas[i]) && machoAdyacente(jirafas, i) : i
	sol.numSubCrias = #i: 0<=i<numCrias && hembra(crias[i]) && machoAdyacente(crias, i) : i

	machoAdyacente(v, i)=  existe j: 0<=j<N && (j=i-1 || j=i+1): macho(v[i])

	*/


bool hembra(int x) {
	return (x % 2 == 1);
}

bool macho(int x) {
	return !hembra(x);
}

int cria(int hembra, int macho) {
	int altura;

	if (hembra > macho) {
		altura = (hembra + macho) / 2 + (hembra + macho) % 2;
	}
	else {
		altura = (hembra + macho)/ 2;
	}
	return altura;

}