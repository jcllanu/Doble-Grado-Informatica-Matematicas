#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int const Tres = 3;
string const Parametro1 = "a";

typedef struct {
	float valor;
	bool parametro;
}tPos;

typedef string tFilaN[Tres];
typedef tFilaN tMatrizN[Tres];
typedef tPos tFila[Tres];
typedef tFila tMatriz[Tres];

string determinante(const tMatrizN& matrizN, bool& parametros, float& a, float& b, float& c, int& grado, tMatriz& matriz);
bool ecuacionSegundoGrado(float a, float b, float c, float& x1, float& x2);
void calcularInversa(tMatriz& matriz, tMatriz& inversa);
void mostrarMatriz(const tMatriz& matriz, const tMatriz& inversa);

int main() {
	system("chcp 1252");
	tMatriz matriz, inversa;
	tMatrizN matrizN;
	string det;
	bool hayParametro = false;
	float a, b, c, x1, x2;
	int grado, op;

	cout << "Programa que calcula la inversa de un matriz 3x3 (1 para empezar / Otra tecla terminar): ";
	cin >> op;
	while (op == 1) {
		for (int i = 0; i < Tres; i++) {
			cout << "Intoduzca la fila " << i + 1 << ": ";
			for (int j = 0; j < Tres; j++) {
				cin >> matrizN[i][j];
				if (matrizN[i][j] >= "a" && matrizN[i][j] <= "z") {
					matrizN[i][j] = Parametro1;
				}
			}
		}
		cout << endl << endl;
		det = determinante(matrizN, hayParametro, a, b, c, grado, matriz);
		if (det >= "0"&& det <= "0.1") {
			cout << "Matriz no invertible" << endl;
		}
		else if (hayParametro) {
			cout << "El determinante de esta matriz es " << det << "." << endl << "La matriz no será invertible para los valores a para los que se cumpla " << det << " = 0" << endl;
			if (grado == 1) {
				cout << "La matriz es invertible salvo para a = " << -c / b << endl;
			}
			else if (grado == 2) {
				if (!ecuacionSegundoGrado(a, b, c, x1, x2)) {
					cout << "La ecuación no tiene solucion en R por lo que el determinante es simpre distinto de 0 y la matriz es invertible para todo a perteneciente a R.";
				}
				else {
					cout << "La matriz es invertible salvo para a = " << x1 << " y a = " << x2 << endl;
				}
			}
		}
		else {
			calcularInversa(matriz, inversa);
		}
		cout << "Programa que calcula la inversa de un matriz 3x3 (1 para empezar / Otra tecla terminar): ";
		cin >> op;
	}
	
	system("pause");
	return 0;
}
string determinante(const tMatrizN& matrizN, bool& parametros, float& a, float& b, float& c, int& grado, tMatriz&matriz) {
	
	string valorDetN;
	bool algunParametro = false;
	bool aux = false;
	float valorDet, parteNumerica=0, parteNumericaParametro;
	float CoefSumandosPrimerGrado=0, CoefSumandosSegundoGrado=0, CoefSumandosTercerGrado=0;
	int parametrosporsumando;
	tPos s1, s2, s3, r1, r2, r3;

	for (int i = 0; i < Tres; i++) {
		for (int j = 0; j < Tres; j++) {
			if (matrizN[i][j] != Parametro1) {
				matriz[i][j].valor = atof(matrizN[i][j].c_str());
				matriz[i][j].parametro = false;
			}
			else {
				matriz[i][j].parametro = true;
				algunParametro = true;
			}
		}
	}
	if (!algunParametro) {
		valorDet = matriz[0][0].valor * matriz[1][1].valor * matriz[2][2].valor + matriz[2][0].valor * matriz[0][1].valor * matriz[1][2].valor + matriz[0][2].valor * matriz[1][0].valor * matriz[2][1].valor - matriz[0][2].valor * matriz[1][1].valor * matriz[2][0].valor - matriz[2][2].valor * matriz[0][1].valor * matriz[1][0].valor - matriz[0][0].valor * matriz[2][1].valor * matriz[1][2].valor;
		valorDetN = to_string(valorDet);
	}
	else {
		if (!matriz[0][0].parametro && !matriz[1][1].parametro && !matriz[2][2].parametro) {
			s1.valor = matriz[0][0].valor * matriz[1][1].valor * matriz[2][2].valor;
			s1.parametro = false;
			parteNumerica += s1.valor;
		}
		else {
			s1.parametro = true;
			parteNumericaParametro = 1;
			parametrosporsumando = 0;
			if (!matriz[0][0].parametro) {
				parteNumericaParametro *= matriz[0][0].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[1][1].parametro) {
				parteNumericaParametro *= matriz[1][1].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[2][2].parametro) {
				parteNumericaParametro *= matriz[2][2].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (parametrosporsumando == 1) {
				CoefSumandosPrimerGrado += parteNumericaParametro;
			}
			else if (parametrosporsumando == 2) {
				CoefSumandosSegundoGrado += parteNumericaParametro;
			}
			else if (parametrosporsumando == 3) {
				CoefSumandosTercerGrado += parteNumericaParametro;
			}
		}
		if (!matriz[2][0].parametro && !matriz[0][1].parametro && !matriz[1][2].parametro) {
			s2.valor = matriz[2][0].valor * matriz[0][1].valor * matriz[1][2].valor;
			s2.parametro = false;
			parteNumerica += s2.valor;
		}
		else {
			s2.parametro = true;
			parteNumericaParametro = 1;
			parametrosporsumando = 0;
			if (!matriz[2][0].parametro) {
				parteNumericaParametro *= matriz[2][0].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[0][1].parametro) {
				parteNumericaParametro *= matriz[0][1].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[1][2].parametro) {
				parteNumericaParametro *= matriz[1][2].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (parametrosporsumando == 1) {
				CoefSumandosPrimerGrado += parteNumericaParametro;
			}
			else if (parametrosporsumando == 2) {
				CoefSumandosSegundoGrado += parteNumericaParametro;
			}
			else if (parametrosporsumando == 3) {
				CoefSumandosTercerGrado += parteNumericaParametro;
			}
		}
		if (!matriz[0][2].parametro && !matriz[1][0].parametro && !matriz[2][1].parametro) {
			s3.valor = matriz[0][2].valor * matriz[1][0].valor * matriz[2][1].valor;
			s3.parametro = false;
			parteNumerica += s3.valor;
		}
		else {
			s3.parametro = true;
			parteNumericaParametro = 1;
			parametrosporsumando = 0;
			if (!matriz[0][2].parametro) {
				parteNumericaParametro *= matriz[0][2].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[1][0].parametro) {
				parteNumericaParametro *= matriz[1][0].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[2][1].parametro) {
				parteNumericaParametro *= matriz[2][1].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (parametrosporsumando == 1) {
				CoefSumandosPrimerGrado += parteNumericaParametro;
			}
			else if (parametrosporsumando == 2) {
				CoefSumandosSegundoGrado += parteNumericaParametro;
			}
			else if (parametrosporsumando == 3) {
				CoefSumandosTercerGrado += parteNumericaParametro;
			}
		}
		if (!matriz[0][2].parametro && !matriz[1][1].parametro && !matriz[2][0].parametro) {
			r1.valor = matriz[0][2].valor * matriz[1][1].valor * matriz[2][0].valor;
			r1.parametro = false;
			parteNumerica -= r1.valor;
		}
		else {
			r1.parametro = true;
			parteNumericaParametro = 1;
			parametrosporsumando = 0;
			if (!matriz[0][2].parametro) {
				parteNumericaParametro *= matriz[0][2].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[1][1].parametro) {
				parteNumericaParametro *= matriz[1][1].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[2][0].parametro) {
				parteNumericaParametro *= matriz[2][0].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (parametrosporsumando == 1) {
				CoefSumandosPrimerGrado -= parteNumericaParametro;
			}
			else if (parametrosporsumando == 2) {
				CoefSumandosSegundoGrado -= parteNumericaParametro;
			}
			else if (parametrosporsumando == 3) {
				CoefSumandosTercerGrado -= parteNumericaParametro;
			}
		}
		if (!matriz[2][2].parametro && !matriz[0][1].parametro && !matriz[1][0].parametro) {
			r2.valor = matriz[2][2].valor * matriz[0][1].valor * matriz[1][0].valor;
			r2.parametro = false;
			parteNumerica -= r2.valor;
		}
		else {
			r2.parametro = true;
			parteNumericaParametro = 1;
			parametrosporsumando = 0;
			if (!matriz[2][2].parametro) {
				parteNumericaParametro *= matriz[2][2].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[0][1].parametro) {
				parteNumericaParametro *= matriz[0][1].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[1][0].parametro) {
				parteNumericaParametro *= matriz[1][0].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (parametrosporsumando == 1) {
				CoefSumandosPrimerGrado -= parteNumericaParametro;
			}
			else if (parametrosporsumando == 2) {
				CoefSumandosSegundoGrado -= parteNumericaParametro;
			}
			else if (parametrosporsumando == 3) {
				CoefSumandosTercerGrado -= parteNumericaParametro;
			}
			
		}
		if (!matriz[0][0].parametro && !matriz[2][1].parametro && !matriz[1][2].parametro) {
			r3.valor = matriz[0][0].valor * matriz[2][1].valor * matriz[1][2].valor;
			r3.parametro = false;
			parteNumerica -= r3.valor;
		}
		else {
			r3.parametro = true;
			parteNumericaParametro = 1;
			parametrosporsumando = 0;
			if (!matriz[0][0].parametro) {
				parteNumericaParametro *= matriz[0][0].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[2][1].parametro) {
				parteNumericaParametro *= matriz[2][1].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (!matriz[1][2].parametro) {
				parteNumericaParametro *= matriz[1][2].valor;
			}
			else {
				parametrosporsumando++;
			}
			if (parametrosporsumando == 1) {
				CoefSumandosPrimerGrado -= parteNumericaParametro;
			}
			else if (parametrosporsumando == 2) {
				CoefSumandosSegundoGrado -= parteNumericaParametro;
			}
			else if (parametrosporsumando == 3) {
				CoefSumandosTercerGrado -= parteNumericaParametro;
			}
		}
		if (parteNumerica != 0) {
			valorDetN = to_string(parteNumerica) + " ";
			aux = true;
		}
		if (CoefSumandosPrimerGrado != 0) {
			valorDetN += "+ (" + to_string(CoefSumandosPrimerGrado) + ")*" + Parametro1+" ";
			parametros = true;
			aux = true;
			grado = 1;
		}
		if (CoefSumandosSegundoGrado != 0) {
			valorDetN += "+ (" + to_string(CoefSumandosSegundoGrado) + ")*" + Parametro1 + "^2 ";
			parametros = true;
			aux = true;
			grado = 2;
		}
		if (CoefSumandosTercerGrado != 0) {
			valorDetN += "+ (" + to_string(CoefSumandosTercerGrado) + ")*" + Parametro1 + "^3 ";
			parametros = true;
			aux = true;
			grado = 3;
		}
		if (!aux) {
			valorDetN = "0.0";
		}
		a = CoefSumandosSegundoGrado;
		b = CoefSumandosPrimerGrado;
		c = parteNumerica;
	}
	
	return valorDetN;
}
bool ecuacionSegundoGrado(float a, float b, float c, float& x1, float& x2) {
	bool ok;
	float discr;
	discr = b * b - 4 * a*c;
	if (discr < 0) {
		ok = false;
	}
	else {
		ok = true;
		x1 = (-b + discr) / (2 * a);
		x2 = (-b - discr) / (2 * a);
	}


	return ok;
}
void calcularInversa(tMatriz& matriz, tMatriz& inversa) {
	float aux;
	for (int i = 0; i < Tres; i++) {
		for (int j = 0; j < Tres; j++) {
			inversa[i][j].valor = 0;
		}
		inversa[i][i].valor = 1;
	}
	if (matriz[0][0].valor == 0) {/*Conseguir 1
											  0
											  0*/
		if (matriz[1][0].valor == 0) {
			for (int i = 0; i < Tres; i++) {
				aux = matriz[2][i].valor;
				matriz[2][i].valor = matriz[0][i].valor;
				matriz[0][i].valor = aux;
				aux = inversa[2][i].valor;
				inversa[2][i].valor = inversa[0][i].valor;
				inversa[0][i].valor = aux;
			}
			aux = matriz[0][0].valor;
			for (int i = 0; i < Tres; i++) {
				matriz[0][i].valor /= aux;
				inversa[0][i].valor /= aux;
			}
			for (int i = 0; i < Tres; i++) {
				for (int j = 0; j < Tres; j++) {
					cout << matriz[i][j].valor << " ";
				}
				for (int j = 0; j < Tres; j++) {
					cout << inversa[i][j].valor << " ";
				}
				cout << endl;
			}
		}
		else {
			for (int i = 0; i < Tres; i++) {
				aux = matriz[1][i].valor;
				matriz[1][i].valor = matriz[0][i].valor;
				matriz[0][i].valor = aux;
				aux = inversa[1][i].valor;
				inversa[1][i].valor = inversa[0][i].valor;
				inversa[0][i].valor = aux;

			}
			aux = matriz[0][0].valor;
			for (int i = 0; i < Tres; i++) {
				matriz[0][i].valor /= aux;
				inversa[0][i].valor /= aux;
			}
			if (matriz[2][0].valor != 0) {
				aux = -matriz[2][0].valor;
				for (int i = 0; i < Tres; i++) {
					matriz[2][i].valor += aux* matriz[0][i].valor;
					inversa[2][i].valor += aux * inversa[0][i].valor;
				}
				for (int i = 0; i < Tres; i++) {
					for (int j = 0; j < Tres; j++) {
						cout << matriz[i][j].valor << " ";
					}
					for (int j = 0; j < Tres; j++) {
						cout << inversa[i][j].valor << " ";
					}
					cout << endl;
				}
			}
			
	
		}
	}
	else {
		aux = matriz[0][0].valor;
		for (int i = 0; i < Tres; i++) {
			matriz[0][i].valor /= aux;
			inversa[0][i].valor /= aux;
		}
		if (matriz[1][0].valor != 0) {
			aux = -matriz[1][0].valor;
			for (int i = 0; i < Tres; i++) {
				matriz[1][i].valor += aux * matriz[0][i].valor;
				inversa[1][i].valor += aux * inversa[0][i].valor;
			}
			mostrarMatriz(matriz, inversa);
		}
		if (matriz[2][0].valor != 0) {
			aux = -matriz[2][0].valor;
			for (int i = 0; i < Tres; i++) {
				matriz[2][i].valor += aux * matriz[0][i].valor;
				inversa[2][i].valor += aux * inversa[0][i].valor;
			}
			mostrarMatriz(matriz, inversa);
		}
	}
	if (matriz[1][1].valor == 0) {/* 1 * *
								     0 1 *
									 0 0 * */

		for (int i = 0; i < Tres; i++) {
			aux = matriz[2][i].valor;
			matriz[2][i].valor = matriz[1][i].valor;
			matriz[1][i].valor = aux;
			aux = inversa[2][i].valor;
			inversa[2][i].valor = inversa[1][i].valor;
			inversa[1][i].valor = aux;
		}
	}
	else {
		aux = matriz[1][1].valor;
		for (int i = 0; i < Tres; i++) {
			matriz[1][i].valor /= aux;
			inversa[1][i].valor /= aux;
		}
		if (matriz[2][1].valor != 0) {
			aux = -matriz[2][1].valor;
			for (int i = 0; i < Tres; i++) {
				matriz[2][i].valor += aux * matriz[1][i].valor;
				inversa[2][i].valor += aux * inversa[1][i].valor;
			}
			mostrarMatriz(matriz, inversa);
		}
	}
	aux = matriz[2][2].valor;
	for (int i = 0; i < Tres; i++) {/* 1 * *
								       0 1 *
									   0 0 1 */
		matriz[2][i].valor /= aux;
		inversa[2][i].valor /= aux;
	}

	if (matriz[1][2].valor != 0) {
		aux = -matriz[1][2].valor;
		for (int i = 0; i < Tres; i++) {
			matriz[1][i].valor += aux * matriz[2][i].valor;
			inversa[1][i].valor += aux * inversa[2][i].valor;
		}
		mostrarMatriz(matriz, inversa);
	}
	if (matriz[0][2].valor != 0) {
		aux = -matriz[0][2].valor;
		for (int i = 0; i < Tres; i++) {
			matriz[0][i].valor += aux * matriz[2][i].valor;
			inversa[0][i].valor += aux * inversa[2][i].valor;
		}
		mostrarMatriz(matriz, inversa);
	}
	if (matriz[0][1].valor != 0) {
		aux = -matriz[0][1].valor;
		for (int i = 0; i < Tres; i++) {
			matriz[0][i].valor += aux * matriz[1][i].valor;
			inversa[0][i].valor += aux * inversa[1][i].valor;
		}
		mostrarMatriz(matriz, inversa);
	}
	mostrarMatriz(matriz, inversa);
}
void mostrarMatriz(const tMatriz& matriz, const tMatriz& inversa) {
	cout << endl << endl;
	for (int i = 0; i < Tres; i++) {
		cout << " | ";
		for (int j = 0; j < Tres; j++) {
			cout << setw(5)<<matriz[i][j].valor << " ";
		}
		cout << " | ";
		for (int j = 0; j < Tres; j++) {
			cout << setw(5) << inversa[i][j].valor << " ";
		}
		cout << " |" << endl;
	}
}