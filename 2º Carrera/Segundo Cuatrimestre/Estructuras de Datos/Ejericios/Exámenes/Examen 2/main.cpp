
// JUAN CARLOS LLAMAS NÚÑEZ
//GRUPO DG ED

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

//En la explicación del algoritmo vamos a usar "rama" como sucesión de nodos en el que cada nodo es padre del siguiente y comienza en la raiz (No tiene porqué terminar en una hoja)
struct tSolucion {
	int ramaMasLarga;//Guardamos la longitud de la rama más larga que está formada únicamento por pares y que incluye a la raiz
	int caminoMasLargo;//Guardamos la longitud del camino de pares más largo (puede o no incluir a la raiz) (Es la solucion que se nos pide)
};


tSolucion caminoPares(bintree<int> arbol) {//Añadimos otro parámetro solamente de salida para permitir que el algoritmo 
										//sea lineal y recoger de los hijos la rama de pares más larga que incluya a la raiz
	tSolucion solucion;
	if (arbol.empty()) {
		//Si el árbol es vacío tanto la longitud del camino más largo de pares como la rama más larga es 0
		solucion.caminoMasLargo = 0;
		solucion.ramaMasLarga = 0;
	}
	else {
		tSolucion solIzq = caminoPares(arbol.left());//Hacemos la recursion
		tSolucion solDer = caminoPares(arbol.right());

		if (arbol.root() % 2 == 0) {//El elemento del nodo raiz es par

			//En este caso, la rama más larga de pares que contiene a la raiz será 1 (longitud de la propia raiz)
			//más el máximo entre las ramas mas largas que contienen a la raiz de sus respectivos hijos
			solucion.ramaMasLarga = 1 + max(solIzq.ramaMasLarga,solDer.ramaMasLarga);

			//Hay tres posibles candidatos al camino más largo de pares:
			//	Que esté completamente contenido en el hijo izquierdo y no incluya por tanto a la raiz -> solIzq.caminoMasLargo
			//	Que esté completamente contenido en el hijo derecho y no incluya por tanto a la raiz -> solDer.caminoMasLargo
			//	Que tenga parte en el hijo derecho y parte en el hijo izquierdo y que sí contenga a la raiz. En este último caso,
			//		de entre todos los posibles caminos que verifican esta condición, el que maximiza la longitud del camino es aquel 
			//		compuesto por la rama más larga de pares del hijo izquierdo que incluye la raiz (del hijo izquierdo), la raiz de el arbol actual y 
			//		la rama más larga de pares del hijo derecho que incluye la raiz(del hijo derecho)

			//De estos tres candidatos escogemos la máxima longitud
			solucion.caminoMasLargo = max(1 + solIzq.ramaMasLarga + solDer.ramaMasLarga,
				max(solIzq.caminoMasLargo, solDer.caminoMasLargo));
		}
		else {//El elemento del nodo raiz es impar

			//Este caso es más sencillo porque la rama más larga de pares que contiene a la raiz será de longiud 0 y 
			// el camino de pares más largo no puede contener a la raiz por lo que está totalmente contenido en alguno de los hijos
			solucion.ramaMasLarga = 0;
			solucion.caminoMasLargo = max(solIzq.caminoMasLargo, solDer.caminoMasLargo);
		}
		
	}
	return solucion;
}
//El orden asíntotico es lineal en el numero de nodos del arbol. Podemos plantear la recurrencia:

//     { k_0  si n=0
//T(n)={
//     {T(n_i)+T(n_j)+k_1 si n>0 donde n_i + n_j = n-1

//Hemos visto en muchas ocasiones que esto pertenece a O(n)




void resuelveCaso() {
   bintree<int> arbol = leerArbol(-1);
   tSolucion solucion = caminoPares(arbol);
   cout << solucion.caminoMasLargo << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0; i < numCasos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
