#include<iostream>
#include<fstream>


using namespace std;
const int k = 31543;
bool resuelveCaso();
int elevar(const int& x, int n);

int main() {
	
	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif*/
	while (resuelveCaso());
	
/*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	return 0;
}

bool resuelveCaso() {
	int x,n;
	cin >> x;
	cin >> n;
	if (n == 0 && x==0) {
		return false;
	}
	else {
		cout << elevar(x,n) << endl;
		return true;
	}

}
 int elevar(const int& x, int n) {
	 if (n == 0) {
		 return 1;
	 }

	 if (n % 2 == 0) {

		 int x1 = elevar(x, n / 2);
		 return (x1 * x1) % k;

	 }
	 else {

		 int x1 = elevar(x, (n - 1) / 2);

		 return (((x1 * x1) % k) * (x % k)) % k;

	 }
}