
// Juan Carlos Llamas y Adrián Sanjuán

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int profundidad() {
    int aux, maxim=0;
    cin >> aux;
    if (aux == 0) {
        return 1;
    }

    for (int i = 0; i < aux; i++) {
        maxim = max(profundidad(), maxim);
    }
    return maxim + 1;


}

void resuelveCaso() {
    cout << profundidad() << endl;
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
