
// Juan Carlos Llamas Núñez  (DG18)

// Necesitamos una funcion que dado un arbol nos devuelva si esta o no pareado 
// y ademas la cantidad de nodos con numero par que tien. Esto ultimo lo usara
// el padre que haya realizado la  llamada recursiva para ver si es o no 
// pareado (el padre)


// Para analizar el coste de la solucion plantemaos la recurrencia siendo N el
// numero de nodos del arbol:
//
//      { k_0                   si   N=0
// T(N)={
//      { T(N_1) + T(N_2) + k_1   si   N>0

// Con k_0 y k_1 constantes y N_1 + N_2 = N - 1

//En clase hemo podido ver en varias ocasiones que el coste asintotico de esta
//recurrencia es lineal en N. Por tanto el coste de la solucion es lineal en el
//numero de nodos del arbol

//s24253

#include <iostream>                                                            
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que necesites

int absoluto(int n) {
	if (n < 0)
		return -n;
	else
		return n;
}

pair<bool, int> es_pareado(bintree<int> const& arbol) {//Se devuelven 2 cosas: 
	//El buleano que indica si el arbol esta pareado o no y el entero que
	//indica la cantidad de numeros pares que hay en el arbol
	if (arbol.empty()) {
		//El arbol vacio esta trivialmente pareado
		//y no tiene ningun nodo con numeros pares
		return { true,0 };
	}
	else {
		//Si el arbol no es vacio hacemos las llamadas recursivas a los hijos
		pair<bool, int> solIzq = es_pareado(arbol.left());
		pair<bool, int> solDer = es_pareado(arbol.right());

		//El primer argumento que se devuelve es si el arbol esta pareado.
		//Segun la definicion, lo estara si sus dos hijos lo estan y la 
		//diferencia en valor absoluto entre el numero de nodos pares de sus
		//hijos es menor que dos

		//El segundo argumento es la cantidad de numeros pares que hay en el
		//arbol, y es la suma de la cantidad de pares de los hijos más uno 
		//si la raiz es par

		return{ solIzq.first && solDer.first && absoluto(solIzq.second - solDer.second) <= 1,
		solIzq.second + solDer.second + (arbol.root() % 2 == 0 ? 1 : 0) };
	}

}


bool pareado(bintree<int> const& arbol) {
	return es_pareado(arbol).first;
}

void resuelveCaso() {
   auto arbol = leerArbol(-1);
   if (pareado(arbol))
      cout << "SI\n";
   else
      cout << "NO\n";
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
   // system("PAUSE");
#endif
   return 0;
}
