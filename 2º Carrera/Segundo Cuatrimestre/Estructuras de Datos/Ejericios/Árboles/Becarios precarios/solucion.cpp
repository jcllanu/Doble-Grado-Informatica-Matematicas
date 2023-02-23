
// Juan Carlos Llamas y Adrián Sanjuán

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int becarios_precarios(const int& k, const int altura) {
    int aux, total=0;
    cin >> aux;
    if (aux == 0) {
        if (altura > k) {
            return 1;
        }
        else {
            return 0;
        }
       
    }
    
    for (int i = 0; i < aux; i++) {
        total += becarios_precarios(k, altura+1);
    }
    return total;


}

bool resuelveCaso() {
    int k;
    cin >> k;
    if (!cin) {
        return false;
    }
    cout << becarios_precarios(k,1) << endl;
    return true;
}
int main() {
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while(resuelveCaso());
    
    

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
