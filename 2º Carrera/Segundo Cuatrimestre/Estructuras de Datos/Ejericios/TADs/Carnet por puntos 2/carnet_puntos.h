//JUAN CARLOS LLAMAS N��EZ


#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>


using DNI = std::string;
using puntos = int;


//MODIFICACI�N CON MAPA DICCIONARIO DE ITERADORES

//Se plantean dos implementaciones distintas para solucionar el problema (principalmente la funci�n lista_por_puntos(puntos) ): 

// -Mantener la implementaci�n ya hecha donde todo era constante con un diccionario no ordenado de DNI a puntos y 
// un diccionario no ordenado de puntos a conjunto no ordenado de DNIs. Para ver si un DNI ha llegado antes o 
// despu�s a un conjunto de DNIs con los mismos puntos se le asocia a cada DNI un tiempo (tiempo de su �ltima 
// inserci�n en un conjunto de DNIs) y esta informaci�n se guarda en un diccionario no ordenado. De eta manera todas las 
// operaciones son constantes salvo lista_por_puntos(puntos) que tiene que ordenar el conjunto por tiempo (ayudado del 
// diccionario no ordenado mapaDNI) y por tanto tiene orden de complejidad O(Nlog(N)) siendo N el n�mero de DNIs


// -Cambiar el conjunto no ordenado de la implementaci�n inicial por una lista que mantendremos ordenada por el momento de la insercci�n.
// B�sicamente es una modificaci�n del TAD pila en el queremos a�adir la operaci�n de borrar un elemento (no necesariamente el que est� en top)
// Para ello lo implementamos como una lista en la que insertamos siempre por delante. La complejidad de nuevo(dni), consultar(dni) y
// cuantos_con_puntos(puntos) sigue siendo constante porque en nuevo se inserta por el principio(constante), consultar no accede a mapaPuntos y
// cuantos_con_puntos(puntos) llama al metodo size de lista que es constante. Ademas, con la introducci�n de un diccionario no ordenado de iteradores, 
// podemos seguir manteniendo constantes las eliminaciones de las listas y as� quitar y recuperar se mantienen constantes. Ahora, lista_por_puntos(puntos const& p)
// solo tiene que devolver una copia de  mapaPuntos[p] (que es una lista que ya est� ordenada como queremos) por lo que la complejidad es
// lineal en el n�mero de DNIs (en el caso peor)


// Como hay una solcui�n que es claramente mejor sera la que subamos aunque dejamos la implementaci�n de la otra

//Segunda implementaci�n


class carnet_puntos {

	std::unordered_map<DNI, puntos> mapaCarnet;
	std::unordered_map<puntos, std::list<DNI>> mapaPuntos;
	std::unordered_map<DNI, std::list<DNI>::iterator> mapaIteradores;
public:


	void nuevo(DNI const& d) {// O(1) insert y operator[] son constantes en diccionarios no ordenados y puch_back es constante en list
		if (!mapaCarnet.insert(make_pair(d, 15)).second)
			throw std::domain_error("Conductor duplicado");
		else {
			mapaPuntos[15].push_front(d);
			mapaIteradores[d] = mapaPuntos[15].begin();
		}
	}

	void quitar(DNI const& d, puntos const& p) {// O(1) con el dicionario de iterador cnonseguimos no tener que hacer una b�squeda lineal del iterador para despu�s borrar el elemento con erase
		auto it = mapaCarnet.find(d);
		if (it == mapaCarnet.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		else if(p!=0 && it->second > 0) {//si p fuera 0 o quitamos a alguien que tiene 0 se estar�a insertando de nuevo perdiendo el orden
			mapaPuntos[it->second].erase(mapaIteradores[d]);
			it->second -= p;
			if (it->second < 0)
				it->second = 0;
			mapaPuntos[it->second].push_front(d);
			mapaIteradores[d] = mapaPuntos[it->second].begin();
		}
	}

	puntos consultar(DNI const& d) {// O(1) find es constante en diccionarios no ordenados
		auto it = mapaCarnet.find(d);
		if (it == mapaCarnet.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		else {
			return it->second;
		}
	}

	int cuantos_con_puntos(puntos const& p) {//O(1) find es constante en diccionarios no ordenados
		if (p < 0 || p>15)
			throw std::domain_error("Puntos no validos");
		else {
			auto it = mapaPuntos.find(p);
			if (it == mapaPuntos.end())
				return 0;
			else
				return it->second.size();
		}
	}

	void recuperar(DNI const& d, puntos const& p) {// O(1) (igual que quitar)
		auto it = mapaCarnet.find(d);
		if (it == mapaCarnet.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		else if(p!=0 && it->second < 15) {//si p fuera 0 o sumamos a alguien que tiene 15 se estar�a insertando de nuevo perdiendo el orden
			mapaPuntos[it->second].erase(mapaIteradores[d]);
			it->second += p;
			if (it->second > 15)
				it->second = 15;
			mapaPuntos[it->second].push_front(d);
			mapaIteradores[d] = mapaPuntos[it->second].begin();
		}
	}

	//Con esta soluci�n (manteniendo una lista de llegada ordenada de menor a mayor por el momento en el que el conductor pas� a tener esos puntos)
	//conseguimos que esta funcion tenga orden lineal (la lista ya est� ordenada y solo hay que copiarla en un vector)

	std::vector<DNI> lista_por_puntos(puntos const& p) {//O(N)
		if (p < 0 || p>15)
			throw std::domain_error("Puntos no validos");
		else {
			std::vector<DNI> dev;
			auto it = mapaPuntos.find(p);
			if (it == mapaPuntos.end())
				return dev;
			else {

				for (DNI d : it->second) {//Nos recorremos la lista de a�adiendo los DNIs al vector
					dev.push_back(d);
				}
				return dev;
			}
		}
	}
};

/*
//Primera implementaci�n

class carnet_puntos {
	struct tDNI{
		DNI dni;
		long long int tiempo;
		bool operator<(tDNI const& otro) const{
			return this->tiempo > otro.tiempo;
		}
	};
	std::unordered_map<DNI, puntos> mapaCarnet;
	std::unordered_map<puntos, std::unordered_set<DNI>> mapaPuntos;
	std::unordered_map<DNI, int> mapaDNI; //Mapa DNI tiempo
	long long int time = 0;
public:


	void nuevo(DNI const& d) {// O(1) insert y operator[] son constantes en diccionarios no ordenados e insert es constante en unordered_set
		if (!mapaCarnet.insert(make_pair(d, 15)).second)
			throw std::domain_error("Conductor duplicado");
		else {
			mapaPuntos[15].insert(d);
			mapaDNI[d] = time++;
		}	
	}

	void quitar(DNI const& d, puntos const& p) {// O(1) find y operator[] son constantes en diccionarios no ordenados e insert y erase son constantes en unordered_set
		auto it = mapaCarnet.find(d);
		if (it == mapaCarnet.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		else if(p!=0 && it->second > 0) {//si p fuera 0 o quitamos a alguien que tiene 0 se estar�a insertando de nuevo perdiendo el orden
			mapaPuntos[it->second].erase(d);
			it->second -= p;
			if (it->second < 0)
				it->second = 0;
			mapaPuntos[it->second].insert(d);
			mapaDNI[d] = time++;
		}
	}

	puntos consultar(DNI const& d) {// O(1) find es constante en diccionarios no ordenados
		auto it = mapaCarnet.find(d);
		if (it == mapaCarnet.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		else {
			return it->second;
		}
	}

	int cuantos_con_puntos(puntos const& p) {//O(1) find es constante en diccionarios no ordenados
		if (p < 0 || p>15) 
			throw std::domain_error("Puntos no validos");
		else {
			auto it = mapaPuntos.find(p);
			if (it == mapaPuntos.end())
				return 0;
			else
				return it->second.size();
		}			
	}

	void recuperar(DNI const& d, puntos const& p) {// O(1) (igual que quitar)
		auto it = mapaCarnet.find(d);
		if (it == mapaCarnet.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		else if (p != 0 && it->second < 15) {//si p fuera 0 o sumamos a alguien que tiene 15 se estar�a insertando de nuevo perdiendo el orden
			mapaPuntos[it->second].erase(d);
			it->second += p;
			if (it->second > 15)
				it->second = 15;
			mapaPuntos[it->second].insert(d);
			mapaDNI[d] = time++;
		}
	}

	//Con esta soluci�n (creando un diccionario no ordenado de clave DNI y valor tiempo que para cada DNI indica la ultima insercci�n en mapaPuntos que ha tenido)
	//mantenemos el resto de funciones constantes a costa de que esta funci�n cuesta como ordenar un vector
	//(ordenar por tiempo el conjunto no ordenado de mapaPuntos[p])

	std::vector<DNI> lista_por_puntos(puntos const& p) {//O(Nlog(N))
		if (p < 0 || p>15)
			throw std::domain_error("Puntos no validos");
		else {
			std::vector<DNI> dev;
			auto it = mapaPuntos.find(p);
			if (it == mapaPuntos.end())
				return dev;
			else {
				std::vector<tDNI> aux;
				for (DNI d : it->second)
					aux.push_back({ d,mapaDNI[d] });
				std::sort(aux.begin(), aux.end());
				for (tDNI d : aux)
					dev.push_back(d.dni);
				return dev;
			}
		}
	}	
};
*/
#endif
