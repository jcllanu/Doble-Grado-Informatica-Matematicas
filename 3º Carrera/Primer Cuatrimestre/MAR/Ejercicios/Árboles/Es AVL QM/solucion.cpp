
// JUAN CARLOS LLAMAS NÚÑEZ 3º DG MARP

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


//En cada llamada recursiva calculamos si el arbol es AVL y, además, su altura, elemento mínimo y elemento máximo.
tSolucion es_AVLbis(const bintree<int>& arbol) {
	tSolucion sol;
	if (arbol.empty()) {
		//Para el árbol vacío tenemos que su altura es 0, su elemento minimo es el maximo del dominio,
		//su elemento máximo es el mínimo del domino y es trivialmente AVL
		sol.altura = 0;
		sol.maximo = INT_MIN;
		sol.minimo = INT_MAX;
		sol.es_avl = true;
	}
	else {
		//Cuando el arbol no es vacío llamamos recursivamente a los hijos izquierdo y derecho
		tSolucion solIzq = es_AVLbis(arbol.left());
		tSolucion solDer = es_AVLbis(arbol.right());

		//La altura de este árbol es 1 (nodo raiz) más el máximo de las alturas de los hijos
		sol.altura = 1 + max(solIzq.altura, solDer.altura);

		//El elemento máximo del árbol es el máximo entre la raiz, el máximo del hijo izquierdo y el máximo del hijo derecho
		sol.maximo = max(max(arbol.root(), solIzq.maximo), solDer.maximo);

		//El elemento mínimo del árbol es el mínimo entre la raiz, el mínimo del hijo izquierdo y el mínimo del hijo derecho
		sol.minimo = min(min(arbol.root(), solIzq.minimo), solDer.minimo);

		//Un arbol es AVL cuando es árbol binario de búsqueda y está equilibrado en altura
		//Para ver si está equilibrado en altura hay que ver que sus hijos estén equilibrados en altura (lo estarán si son AVL)
		//y la diferencia entre las alturas de los hijos es como mucho uno.
		//Para ver si es árbol binario de búsqueda hay que ver que sus hijos son árboles binarios de búsqueda (lo serán si son AVL)
		//y todos los elementos del hijo izquierdo son menores que la raiz (se verifica si el máximo del hijo izquierdo es menor que la raiz)
		//y todos los elementos del hijo derecho son mayores que la raiz (se verifica si el mínimo del hijo izquierdo es mayor que la raiz)

		sol.es_avl = solIzq.es_avl && solDer.es_avl && abs(solIzq.altura - solDer.altura) <= 1 && solIzq.maximo < arbol.root() && arbol.root() < solDer.minimo;
	}
	return sol;
}

//El coste de la función es lineal en el número de nodos ya que tenemos la recurrencia 
//		 {  k_1                   si n = 0 
//T(n) = {
//		 { T(n_1)+ T(n_2) + k_2   si n > 0
//
// Con k_1 y k_2 contantes y n_1 + n_2 = n - 1
// Sabemos que el coste de esta recurrencia esta en el orden de n siendo n el número de nodos del árbol



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
