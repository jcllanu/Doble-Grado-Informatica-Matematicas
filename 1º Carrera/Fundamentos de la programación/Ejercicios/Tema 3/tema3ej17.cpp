#include <iostream>
using namespace std;

//Contador blancos letras digitos
int main()
{
	char a;
	int letras = 0, espacios = 0, digitos = 0;
	bool zona = false , aux=true;
	cout << "Escribe la frase: ";
	cin.get(a);
	while (a != '.') {
		while (!zona) {
			if (a == '(') {
				zona = true;
			}
			if (a == '.') {
				zona = true;
				aux = false;
			}
			cin.get(a);
		}
		while(aux){
			while (zona) {
				if (a == ' ') {
					espacios++;
					cin.get(a);
				}

				if (a >= '0' && a <= '9') {
					digitos++;
					cin.get(a);
				}

				if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
					letras++;
					cin.get(a);
				}

				if (a == ')' || a == '.') {
					zona = false;
					aux = false;
					cin.ignore(100, '\n');
				}
			}

		}
		
		cout << "Blancos: " << espacios << " Letras: " << letras << " Digitos: " << digitos << endl;
		letras = 0;
		espacios = 0; 
		digitos = 0;
		zona = false;
		aux = true;
		cout << "Escribe la frase: ";
		cin.get(a);
	}
			
	system("pause");
	return 0;
}

