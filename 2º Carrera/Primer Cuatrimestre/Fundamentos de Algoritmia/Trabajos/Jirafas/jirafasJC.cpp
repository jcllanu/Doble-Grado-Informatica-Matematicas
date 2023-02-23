#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;


bool resuelveCaso(ofstream& archivo);
void solucion(const vector<int>& jirafas, int &numCrias, int &superanMedia, int&numSubCrias);
bool hembra(int x);
bool macho(int x);
int cria(int hembra, int macho);


int main() {
	#ifndef DOMJUDGE 
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
	#endif
		ofstream archivo;
		archivo.open("resultados2.txt");
		while (resuelveCaso(archivo));
		archivo.close();
	#ifndef DOMJUDGE 
		std::cin.rdbuf(cinbuf); 
		system("PAUSE");
	#endif
	
		return 0;
}

bool resuelveCaso(ofstream& archivo) {
	bool end = false;
	int N;
	cin >> N;
	if (!cin) {
		end = true;
	}
	else {
		vector<int> jirafas(N);
		for (int i=0; i < N; i++) {
			cin >> jirafas[i];
		}
		int numCrias, numSubCrias, superanMedia;
		
		vector<int> crias(0);
		solucion(jirafas, numCrias, superanMedia, numSubCrias);
		
		cout <<numCrias << " " <<numSubCrias <<" ";
		archivo << numCrias << " " << numSubCrias << " ";
		if (superanMedia == 1) {
			cout << "INCREMENTO";
			archivo << "INCREMENTO";
		}
		else if (superanMedia == 0) {
			cout << "SIN CAMBIOS";
			archivo << "INCREMENTO";
		}
		else {
			cout << "DECREMENTO";
			archivo << "DECREMENTO";
		}
		cout << endl;
		archivo << endl;
	}


	return !end;
}

/*N>=2 && existe i: 0<=i<N : hembra(jirafas[i]) && 
	existe i: 0<=i<N : macho(jirafas[i])*/
void solucion(const vector<int>& jirafas, int &numCrias, int &superanMedia, int&numSubCrias){
	int n = 1;
	double mediaCrias = 0;
	numCrias = 0;
	numSubCrias = 0;
	vector<int> crias(0);
	double mediaJirafas = jirafas[0];
	/*mediaJirafas = (suma i : 0 <= i < n : jirafa[i]) / n
		Lo calculamos eficientemente de manera iterativa considerando 
		la definicion recursiva de media. Si tenemos un conjunto
		{ x_0, x_1, x_2, ..... ,x_(N-1)}
		la media de los primeros n>0 viene dada por 
		media_n= [(n-1)*media_n-1 +x_(n-1)]/n
		
		)*/



	if (hembra(jirafas[0]) && macho(jirafas[1])) {
		numCrias++;
		crias.push_back(cria(jirafas[0], jirafas[1]));
		mediaCrias = crias[0];
	}
	
	/* INVARIANTE : a) numCrias = #i: 0<=i<n && hembra(jirafas[i]) && machoAdyacente(jirafas, i) : i
					b) 1<=n<=N-1
					c) mediaJirafas = (suma i : 0 <= i < n : jirafa[i]) / n
					d) mediaCrias = (suma i : 0 <= i < numCrias : jirafa[i]) / numCrias
					Consideramos que la media del conjunto vacío está definido y es 0.
					e) numSubCrias = #i: 0<=i<numCrias && hembra(crias[i]) && machoAdyacente(crias, i) : i

		COTA: C= N-1-n
	*/
	while (n != jirafas.size() - 1) {

		if (hembra(jirafas[n]) && (macho(jirafas[n - 1]) || macho(jirafas[n + 1]))) {
			if (!macho(jirafas[n - 1])) {
				crias.push_back(cria(jirafas[n], jirafas[n + 1]));
			}
			else if (!macho(jirafas[n + 1])) {
				crias.push_back(cria(jirafas[n], jirafas[n - 1]));
			}
			else {
				crias.push_back(cria(jirafas[n], max(jirafas[n - 1], jirafas[n + 1])));
			}
			
			mediaCrias = (mediaCrias*numCrias + crias[numCrias]) / (numCrias + 1);
			numCrias++;
			if (numCrias == 2 && ((hembra(crias[0]) && macho(crias[1]))|| (hembra(crias[1]) && macho(crias[0])))) {
				numSubCrias++;
			}
			if (numCrias >= 3) {
				if (hembra(crias[numCrias - 1])){
					if (macho(crias[numCrias - 2])) {
						numSubCrias++;
					}
				}
				else if (hembra(crias[numCrias - 2]) && !macho(crias[numCrias - 3])) {
					numSubCrias++;
				}
			}
		}
		mediaJirafas = (mediaJirafas*n + jirafas[n]) / (n+1);
		n++;
	}
	/* POSTCONDICIÓN : a) numCrias = #i: 0<=i<N-1 && hembra(jirafas[i]) && machoAdyacente(jirafas, i) : i
					   b) n=N-1
					   c) mediaJirafas = (suma i : 0 <= i < N-1 : jirafa[i]) / N-1
					   d) mediaCrias = (suma i : 0 <= i < numCrias : jirafa[i]) / numCrias
					   Consideramos que la media del conjunto vacío está definido y es 0.
					   e) numSubCrias = #i: 0<=i<numCrias && hembra(crias[i]) && machoAdyacente(crias, i) : i

	*/
	if (hembra(jirafas[jirafas.size() - 1]) && macho(jirafas[jirafas.size() - 2])) {

		crias.push_back(cria(jirafas[jirafas.size() - 1], jirafas[jirafas.size() - 2]));
		mediaCrias = (mediaCrias*numCrias + crias[numCrias]) / (numCrias + 1);
		numCrias++;

		if (numCrias == 2 && ((hembra(crias[0]) && macho(crias[1])) || (hembra(crias[1]) && macho(crias[0])))) {
			numSubCrias++;
		}
		if (numCrias >= 3) {
			if (hembra(crias[numCrias - 1])) {
				if (macho(crias[numCrias - 2])) {
					numSubCrias++;
				}
			}
			else if (hembra(crias[numCrias - 2]) && !macho(crias[numCrias - 3])) {
				numSubCrias++;
			}
		}
		
	}
	mediaJirafas = (mediaJirafas*(jirafas.size() - 1) + jirafas[jirafas.size() -1]) / jirafas.size();

	if (mediaCrias > mediaJirafas) {
		superanMedia = 1;
	}
	else if (mediaCrias == mediaJirafas) {
		superanMedia = 0;
	}
	else {
		superanMedia = -1;
	}
}


/*	numCrias = #i: 0<=i<N && hembra(jirafas[i]) && machoAdyacente(jirafas, i) : i

	numSubCrias = #i: 0<=i<numCrias && hembra(crias[i]) && machoAdyacente(crias, i) : i

	machoAdyacente(v, i)=  existe j: 0<=j<N && (j=i-1 || j=i+1): macho(v[i])

					·  1 si mediaCrias > mediaJirafas
	superanMedia=	·  0 si mediaCrias = mediaJirafas
					· -1 si mediaCrias < mediaJirafas

	Lo usamos a modo de booleano "ternario" para no tener que devolver los 2 valores de las medias


	mediaCrias= (suma i: 0<=i<numCrias: cria[i])/numCrias 

	numCrias es setrictamnete mayor que ceroya sabemos que hay al menos un macho y al menos una hembra,
	por tanto debe haber al menos un macho y una hembra adyacentes

	mediaJirafas=(suma i: 0<=i<N: jirafa[i])/N
	Lo calculamos eficientemente de manera iterativa

	 
	 

	
	
	
	
	
	*/


bool hembra(int x) {
	return (x % 2 == 1);
}

bool macho(int x) {
	return !hembra(x);
}

int cria(int hembra, int macho) {
	int altura;

	if (hembra > macho) {
		altura = (hembra + macho) / 2 + (hembra + macho) % 2;
	}
	else {
		altura = (hembra + macho)/ 2;
	}
	return altura;

}