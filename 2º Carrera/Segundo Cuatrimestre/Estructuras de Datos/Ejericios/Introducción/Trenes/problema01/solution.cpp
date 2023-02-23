
// ALBERTO VERDEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#include "horas.h"
#include "pelicula.h"


bool resuelveCaso() {
    int nPeliculas;
    cin >> nPeliculas;
	if (nPeliculas == 0) {
		return false;
	}
    
    vector<pelicula> peliculas(nPeliculas);
	for (pelicula& p : peliculas) {
		cin >> p;
	}
    
	sort(peliculas.begin(), peliculas.end());
	for (pelicula& p : peliculas) {
		cout << p << "\n";
	}
	cout << "---\n";
   return true;
}
int main() {
   // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());
   
   // restablecimiento de cin
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("pause");
#endif
   return 0;
}
