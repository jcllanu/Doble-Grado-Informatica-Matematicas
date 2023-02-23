#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

const int NUM_CASOS1 = 200;
const int MAX_JIRAFAS1 = 20;
const int MIN_ALTURA1 = 400;
const int MAX_ALTURA1 = 600;


const int NUM_CASOS2 = 300;
const int MAX_JIRAFAS2 = 1000;
const int MIN_ALTURA2 = 400;
const int MAX_ALTURA2 = 600;
int main() {
	srand(time(NULL));
	ofstream archivo("casos.txt");
	for (int i = 0; i < NUM_CASOS1; i++) {
		int n = 2 + rand() % (MAX_JIRAFAS1 - 2);
		vector<int> x(n);
		archivo << n << endl;
		for (int j = 0; j < n; j++) {
			x[j] = MIN_ALTURA1 + rand() % (MAX_ALTURA1 - MIN_ALTURA1);
		}
		int pos = rand() % n;
		x[pos] = (MIN_ALTURA1 / 2 + rand() % (MAX_ALTURA1 / 2 - MIN_ALTURA1 / 2)) * 2;
		int pos2 = pos;
		while (pos2 == pos) {
			pos2 = rand() % n;
		}
		x[pos2] = (MIN_ALTURA1 / 2 + rand() % (MAX_ALTURA1 / 2 - MIN_ALTURA1 / 2)) * 2 + 1;
		for (int k = 0; k < n; k++) {
			archivo << x[k] << " ";
		}
		archivo << endl;
	}
	for (int i = 0; i < NUM_CASOS2; i++) {
		int n = 2 + rand() % (MAX_JIRAFAS2 - 2);
		vector<int> x(n);
		archivo << n << endl;
		for (int j = 0; j < n; j++) {
			x[j] = MIN_ALTURA2 + rand() % (MAX_ALTURA2 - MIN_ALTURA2);
		}
		int pos = rand() % n;
		x[pos] = (MIN_ALTURA2/2 + rand() % (MAX_ALTURA2/2 - MIN_ALTURA2/2)) * 2;
		int pos2 = pos;
		while (pos2 == pos) {
			pos2 = rand() % n;
		}
		x[pos2] = (MIN_ALTURA2 / 2 + rand() % (MAX_ALTURA2 / 2 - MIN_ALTURA2 / 2)) * 2 + 1;
		for (int k = 0; k < n; k++) {
			archivo << x[k] << " ";
		}
		archivo << endl;
	}
	archivo.close();
	return 0;
}