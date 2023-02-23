/*Juan Carlos Llamas Núñez
2º DG FAL*/

#include <iostream>
#include<fstream>
#include <vector>
#include<algorithm>

using namespace std;

bool  resuelveCaso();
bool parcialmenteOrdenado(vector<long long int> v, long long int a, long long int b, long long int& maxim, long long int& minim);



bool resuelveCaso() {
	long long int aux;
	bool ok;
	cin>>aux;
	if (aux == 0) {
		ok = false;
	}
	else {
		ok = true;
		vector<long long int> v(1);
		v[0] = aux;
		cin >> aux;
		while (aux != 0) {
			v.push_back(aux);
			cin >> aux;
		}
		long long int maxim, minim;
		if (parcialmenteOrdenado(v, 0, v.size(), maxim, minim)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return ok;
}
int main() {
#ifndef DOMJUDGE 
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}


bool parcialmenteOrdenado(vector<long long int> v, long long int a, long long int b, long long int& maxim, long long int& minim) {

	if (b - a == 1) {
		maxim = v[a];
		minim = v[a];
		return true;
	}
	else {
		long long int max1, min1, max2, min2;
		if (!parcialmenteOrdenado(v, a, (a + b) / 2, max1, min1) || !parcialmenteOrdenado(v, (a + b) / 2, b, max2, min2)) {
			return false;
		}
		maxim = max(max2, max1);
		minim = min(min2, min1);
		return max1 <= max2 && min1 <= min2;
		
	}
}

/*
								{	true																	(Si b-a=1)
								{
parcialmenteOrdenado(v, a, b)=	{ parcialmenteOrdenado(v, a, a+b/2) && parcialmenteOrdenado(v, a+b/2, b)    (Si b-a>1)
								{	&& (max i: a<=i<a+b/2: v[i]) <=(max i: a<=i<a+b/2: v[i])
								{	&& (min i: a<=i<a+b/2: v[i]) <=(min i: a<=i<a+b/2: v[i])
*/