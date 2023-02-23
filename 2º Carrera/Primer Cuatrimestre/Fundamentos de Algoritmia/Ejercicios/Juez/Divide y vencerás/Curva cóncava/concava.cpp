// Juan Carlos Llamas y Adrián Sanjuán 2ºDG FAL

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*N>0*/
void resolver(int& mitad, int& ini, int& fin, int& val,const vector<int> & v) {
	
		mitad = (ini + fin) / 2;
		if (mitad == 0) {
			if (fin == 1) {
				val = min(v[0], v[1]);
			}
			else {
				val = v[0];
			}
		}
		else if(mitad == v.size()-1){
				val = min(v[mitad],v[mitad-1]);
		}
		else {
			if (v[mitad] < v[mitad + 1] && v[mitad] < v[mitad - 1]) {
				val = v[mitad];
			}
			else if (v[mitad] > v[mitad + 1]) {
				ini = mitad + 1;
				resolver(mitad, ini, fin, val, v);
			}
			else if (v[mitad] > v[mitad - 1]) {
				fin = mitad - 1;
				resolver(mitad, ini, fin, val, v);
			}
		}
	

}
/*val=min i: 0<=i<N: v[i]*/


bool resuelveCaso() {
	int N,ini = 0,mitad,val,fin;
	cin >> N;
	fin = N - 1;
	vector<int> v(N);
	if (!std::cin) // fin de la entrada
		return false;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	resolver(mitad, ini, fin,val,v);
	cout << val << endl;
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
