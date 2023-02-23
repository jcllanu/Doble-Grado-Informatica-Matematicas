/*Marta Gago Macias y Juan Carlos Llamas Núñez 2º DG FAL*/
#include<iostream>
#include<fstream>

using namespace std;

bool resuelveCaso(int& pesoI, int& pesoD);

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int pesoI, pesoD;
		if (resuelveCaso(pesoI, pesoD)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}



/*true*/
bool resuelveCaso(int& pesoI, int& pesoD) {
	int  longI, longD, pesoIant, pesoDant;/*pesoDant es el peso derecho de la linea siguiente en caso de que alguno de los pesoI/pesoD sea 0
										  pesoIant análogo*/
	bool b1 = true, b2 =true;
	cin >> pesoI;
	cin >> longI;
	cin >> pesoD;
	cin >> longD;

	if (pesoI == 0) {
		b1=resuelveCaso(pesoIant,pesoDant);
		pesoI = pesoIant + pesoDant;
	}
	if (pesoD == 0) {
		b2 = resuelveCaso(pesoIant, pesoDant);
		pesoD = pesoIant + pesoDant;
	}
	return b1 && b2 && (pesoI * longI == pesoD * longD);
}
/*dev=  pesoI==0->((ant(pesoI)* longI == ant(pesoD)*longD) && resuelveCaso(pesoIant,pesoDant)) &&
	pesoD==0->((ant(pesoI)* longI == ant(pesoD)*longD) && resuelveCaso(pesoIant,pesoDant)) &&
	&& ant(pesoI)* longI == ant(pesoD)*longD
		
			  { peso si peso!=0
	ant(peso)={
			  { ant(pesoIant)+ant(pesoDant) en cc

			  
			  */