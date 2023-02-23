
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO


#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class EntremezclarListas : public deque<int> {
public:
   // imprime la lista
   void print(std::ostream& o = std::cout) const {
      // rellenar
   }

   // modifica this para entremezclar sus elementos con los de other
   void entremezclar(EntremezclarListas & other) {
      // rellenar
   }
   
};


/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, EntremezclarListas const& a) {
   a.print(o);
   return o;
}

EntremezclarListas leerLista() {
   EntremezclarListas lista;
   int n, val;
   cin >> n; // tamaño
   while (n--) {
      cin >> val;
      lista.push_back(val);
   }
   return lista;
}

void resuelveCaso() {
   auto lista1 = leerLista();
   auto lista2 = leerLista();
   
   lista1.entremezclar(lista2);
   
   cout << lista1 << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int casos;
   cin >> casos;
   for (int i = 0; i < casos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
 //  system("PAUSE");
#endif
   return 0;
}
