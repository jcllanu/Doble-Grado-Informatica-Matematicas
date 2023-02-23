#include <iostream>
using namespace std;

void miFuncion()
{
	cout << "Hola, esta es mi funcion" << endl;
}

int main()
{
	int i,suma;

	i = 1;
	suma = 0;
	miFuncion();
	while (i<=5)
	{
		suma = suma + i;
		i++;
	}
	

	cout << "El total es " << suma << endl;
	system("pause");
	return 0;
}