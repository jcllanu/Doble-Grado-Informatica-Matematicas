
// JUAN CARLOS LLAMAS N��EZ 3� DG MARP

#include <iostream>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
#include <climits>
using namespace std;

int abs(int n) {
	if (n >= 0)
		return n;
	else
		return -n;
}

struct tSolucion {
	int altura, minimo, maximo;
	bool es_avl;
};


//En cada llamada recursiva calculamos si el arbol es AVL y, adem�s, su altura, elemento m�nimo y elemento m�ximo.
tSolucion es_AVLbis(const bintree<int>& arbol) {
	tSolucion sol;
	if (arbol.empty()) {
		//Para el �rbol vac�o tenemos que su altura es 0, su elemento minimo es el maximo del dominio,
		//su elemento m�ximo es el m�nimo del domino y es trivialmente AVL
		sol.altura = 0;
		sol.maximo = INT_MIN;
		sol.minimo = INT_MAX;
		sol.es_avl = true;
	}
	else {
		//Cuando el arbol no es vac�o llamamos recursivamente a los hijos izquierdo y derecho
		tSolucion solIzq = es_AVLbis(arbol.left());
		tSolucion solDer = es_AVLbis(arbol.right());

		//La altura de este �rbol es 1 (nodo raiz) m�s el m�ximo de las alturas de los hijos
		sol.altura = 1 + max(solIzq.altura, solDer.altura);

		//El elemento m�ximo del �rbol es el m�ximo entre la raiz, el m�ximo del hijo izquierdo y el m�ximo del hijo derecho
		sol.maximo = max(max(arbol.root(), solIzq.maximo), solDer.maximo);

		//El elemento m�nimo del �rbol es el m�nimo entre la raiz, el m�nimo del hijo izquierdo y el m�nimo del hijo derecho
		sol.minimo = min(min(arbol.root(), solIzq.minimo), solDer.minimo);

		//Un arbol es AVL cuando es �rbol binario de b�squeda y est� equilibrado en altura
		//Para ver si est� equilibrado en altura hay que ver que sus hijos est�n equilibrados en altura (lo estar�n si son AVL)
		//y la diferencia entre las alturas de los hijos es como mucho uno.
		//Para ver si es �rbol binario de b�squeda hay que ver que sus hijos son �rboles binarios de b�squeda (lo ser�n si son AVL)
		//y todos los elementos del hijo izquierdo son menores que la raiz (se verifica si el m�ximo del hijo izquierdo es menor que la raiz)
		//y todos los elementos del hijo derecho son mayores que la raiz (se verifica si el m�nimo del hijo izquierdo es mayor que la raiz)

		sol.es_avl = solIzq.es_avl && solDer.es_avl && abs(solIzq.altura - solDer.altura) <= 1 && solIzq.maximo < arbol.root() && arbol.root() < solDer.minimo;
	}
	return sol;
}

//El coste de la funci�n es lineal en el n�mero de nodos ya que tenemos la recurrencia 
//		 {  k_1                   si n = 0 
//T(n) = {
//		 { T(n_1)+ T(n_2) + k_2   si n > 0
//
// Con k_1 y k_2 contantes y n_1 + n_2 = n - 1
// Sabemos que el coste de esta recurrencia esta en el orden de n siendo n el n�mero de nodos del �rbol



bool es_AVL(const bintree<int>& arbol) {
	return es_AVLbis(arbol).es_avl;
}
void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	if (es_AVL(arbol))
		cout << "SI\n";
	else
		cout << "NO\n";
	
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
