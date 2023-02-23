
// JUAN CARLOS LLAMAS NUÑEZ (DG18)

#include <iostream>               
#include <fstream>               
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Necesitamos un diccionario (no es necesario que sea ordenado) que asocie a cada juego las veces que ha sido jugado,
// y para cada vez que ha sido jugado, el día en el que ha sido jugado la k-ésima vez. Podemos implementar la solución mediante
// un diccionario de clave un string que representa el nombre del juego y el valor una estructura que nos permita dado la k-esima vez que se ha jugado a ese juego,
// el día en el que se jugó esa k-esima partida. Esta estructura puede ser un vector o un diccionario no ordenado,
// al que se accede por la vez. El coste de acceso al día en el que se jugó por k-esima vez a un juego es constante en ambas implementaciones así que el
// coste asintótico es lineal respecto al máximo entre el número de preguntas hechas y el número de noches en que el abuelo se ha conectado desde que empezó a jugar. 

//s16336

bool resuelveCaso() {
int N, M, k;
   cin >> N;
   if (!cin)
      return false;
   string juego;
   unordered_map<string, unordered_map < int, int>> partidas; //La clave representa el nombre del juego, y el valor es un diccionario (no ordenado)
   //de clave la k-ésima vez que ha jugado a ese juego y valor el día que esa partida ocurrió
   //unordered_map<string, vector<int>> partidasV; //La clave representa el nombre del juego, y el valor es un vector donde el índice es la vez menos uno y el contenido es el día 

   int dia = 1;
   for (int i = 0; i < N; i++) {
	   cin >> juego;
	   int vez = partidas[juego].size() + 1;
	   partidas[juego][vez] = dia;
	   //partidasV[juego].push_back(dia);
	   dia++;
   }
   cin >> M;
   for (int i = 0; i < M; i++) {
	   cin >> k >> juego;
	   if (partidas.count(juego) == 0 || partidas[juego].count(k) == 0/*partidasV.count(juego) == 0 || partidasV[juego].size()<k*/) {
		   cout << "NO JUEGA\n";
	   }
	   else {
		  cout << partidas[juego][k] << '\n';
		  //cout << partidasV[juego][k-1] << '\n';
	   }
   }
   cout << "---\n";
   return true;
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
