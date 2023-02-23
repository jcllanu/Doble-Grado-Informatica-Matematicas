#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

const int NUM_CASOS = 500;
const int MAX_JIRAFAS = 1000;
const int MIN_ALTURA = 400;
const int MAX_ALTURA = 600;
int main() {
	srand(time(NULL));
	ofstream archivo("casos.txt");
	for (int i = 0; i < NUM_CASOS; i++) {
		int n = 2 + rand() % (MAX_JIRAFAS - 2);
		vector<int> x(n);
		archivo << n << endl;
		for (int j = 0; j < n; j++) {
			x[j] = MIN_ALTURA + rand() % (MAX_ALTURA - MIN_ALTURA);
		}
		int pos = rand() % n;
		x[pos] = (MIN_ALTURA/2 + rand() % (MAX_ALTURA/2 - MIN_ALTURA/2)) * 2;
		int pos2 = pos;
		while (pos2 == pos) {
			pos2 = rand() % n;
		}
		x[pos2] = (MIN_ALTURA / 2 + rand() % (MAX_ALTURA / 2 - MIN_ALTURA / 2)) * 2 + 1;
		for (int k = 0; k < n; k++) {
			archivo << x[k] << " ";
		}
		archivo << endl;
	}
	archivo.close();
	return 0;
}