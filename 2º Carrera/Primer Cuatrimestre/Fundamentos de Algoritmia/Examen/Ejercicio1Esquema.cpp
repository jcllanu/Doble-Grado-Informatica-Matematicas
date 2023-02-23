// NOMBRE Y APELLIDOS: JUAN CARLOS LLAMAS NÚÑEZ

// Comentario general sobre la solucion,
// explicando como se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//ESPECIFICA la funcion que resuelve el problema
//Precondicion:{N>0} (El caso de N=0 lo tratamos por separado)

int resolver(vector<int> const& v) {
	int r = 1;
	int n = 1;
	int s = 0;
	int longEstrictCrec = 1;
    //Aqui tu codigo
    //...
    //Funcion de cota: N-n>=0;
    /*Invariante: r = max i,j: 0<=i<=j<=n && !Subseg(i,j):long(i,j)
				  1<=n<=N
				  s = min i: 0<=i<=n && !Subseg(i,n):i
				  longEstrictCrec=long(s,n)
	*/

	while (n != v.size()) {
		if (v[n - 1] < v[n]) {
			longEstrictCrec++;
		}
		else {
			longEstrictCrec = 1;
		}
		if (longEstrictCrec == 3) {
			s = n - 1;
			longEstrictCrec--;
		}
		r = max(r, n+1-s);
		n++;
	}
	if (v.size() == 0) {
		r = 0;
	}
    return r;
  
}
    
//Postcondicion: llama r al resultado
/*r=max i,j: 0<=i<=j<=N && !Subseg(i,j):long(i,j)
Subseg(i,j)= exist. a,b: i<=a<=b<=j && long(a,b)>=3: estricCrec(a,b)
estricCrec(a,b)= pt k: a<=k<b: v[k]<v[k+1];
long(i,j)=j-i*/


//Analisis justificado del coste
//El coste es lineal respecto a la longitud del vector ya que hay que recorreselo por completo en el caso peor.
/*En el caso peor, el segmento máximo tal que no contiene ningún subsegmento estrictamente creciente de longitud tres es cuando el vector no contiene ningun subsegmento estrictamente creciente de longitud 3, por lo que la solución es la longitud del vector*/

// Esta funcion resuelve un caso de prueba
void resuelveCaso() {
	int numElems = 0; 
	cin >> numElems;
	vector<int> v(numElems);
	for (int& i : v) cin >> i;
	int sol = resolver(v);
	cout << sol <<"\n";
}

int main() {
	// Para la entrada por fichero
	#ifndef DOMJUDGE
	ifstream in("sample1.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
	#endif
	
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) 
		resuelveCaso();

	#ifndef DOMJUDGE 
	cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif
	
	return 0;
}
