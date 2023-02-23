
// JUAN CARLOS LLAMS NÚÑEZ DG18

// Necesitamos un diccionario no ordenado para acceder por la clave paciente 
// a la informacion del paciente (operaciones como gravedad_actual o mejorar).
// No necesitamos que este ordenado porque no se nos pide que lo esté.
// En dicha información de cada paciente se puede pensar, al menos en un
// principio, que solo necesitamos guardar la gravedad de dicho paciente.

// También necesitamos una estructura lineal que mantenga el orden de
// preferencia del turno para ser atendido. Usamos para ello un vector de
// gravedades (0=leve, 1=media, 2=grave) porque el primer criterio de 
// preferencia es la gravedad. Dentro de cada una de las gravedades necesitamos
// una estructura lineal porque se nos habla de un orden de llegada. Podriamos
// pensar en una cola (o una cola doble si consideramos la operación mejorar).
// Sin embargo, el hecho de que la operación mejorar pueda cambiar a uno de
// los pacientes de una determinada gravedad a otra nos obliga a tener que
// eliminar  de una estructura lineal. La manera de que esta eliminación sea
// eficiente es mediante la operación de erase de una lista. Por eso decidimos
// la implementación de un vector de tamaño el número de gravedes distintas
// (en este caso 3) y que en cada posición tiene una lista de pacientes. Para
// que la operaión erase sea eficiente le tenemos que dar el iterador al
// elemento a borrar. Esta información la guardamos en cada paciente, es decir,
// para cada paciente guardamos la gravedad y el iterador a la posición la lista
// de esa gravedad.


// Por último necesitamos una estructura donde almacenar los pacientes que
// se han recuperado por esperar. Esta debe preservar el orden alfabetico, por
// lo que lo más natural es elegir un conjunto oredenado de pacientes. El
// orden es el de pacientes, que como se representan por strings, el conjunto 
// estará ordenado alfabeticamente.


#ifndef URGENCIAS
#define URGENCIAS

#include <iostream>          
#include <string>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>

using namespace std;

using paciente = string;

class urgencias {

	struct info_paciente {
		int gravedad;
		list<paciente>::iterator iterador;
	};

	unordered_map<paciente, info_paciente> pacientes;
	set<paciente> recup;
	vector<list<paciente>> gravedades;//0 leve, 1 media, 2 grave
public:

	urgencias() :gravedades(3) {//O(1) 
	}

	void nuevo_paciente(paciente const& p, int gravedad) {//O(1)
		//Buscar/insertar en un diccionario no ordenado es constante 
		//e insertar en una lista por el final es constante
		if (pacientes.count(p) == 0) {
			if (gravedad >= 1 && gravedad <= 3) {
				pacientes.insert({ p,{gravedad,
					gravedades[gravedad - 1].insert(gravedades[gravedad - 1].end(),p)} });
			}
			else {
				throw domain_error("Gravedad incorrecta");
			}
		}
		else {
			throw domain_error("Paciente repetido");
		}
	}

	int gravedad_actual(paciente const& p) const {//O(1)
		//Find es constante en diccionarios no ordenados
		auto it = pacientes.find(p);

		if (it != pacientes.end()) {
			return it->second.gravedad;
		}
		else {
			throw domain_error("Paciente inexistente");
		}
	}

	paciente siguiente() {//O(1)
		//Buscar el paciente que hay que atender es constante
		//porque es el primer elemento de una de las 3 listas
		//Eliminar dicho paciente de la lista es constante y
		//elimniar una clave de un diccionario no  ordenado es constante

		//Obs: NO es const (observadora) porque el paciente abandona la sala de espera
		if (gravedades[2].empty() && gravedades[1].empty() && gravedades[0].empty()) {
			throw domain_error("No hay pacientes");
		}
		else {
			for (int i = 2; i >= 0; i--) {
				if (!gravedades[i].empty()) {
					paciente p = gravedades[i].front();
					pacientes.erase(p);
					gravedades[i].pop_front();
					return p;
				}
			}
		}
	}

	void mejora(paciente const& p) {//O(log(N)) donde N es el numero de pacientes recuperados por esperar
		//Los accesos/eliminar de diccionario son constantes, borrar con iterador
		//en una lista es constante pero insertar en un conjunto ordenado es log(N)
		auto it = pacientes.find(p);

		if (it != pacientes.end()) {
			info_paciente & info = it->second;
			if (info.gravedad == 1) {//paciente leve
				gravedades[0].erase(info.iterador);
				recup.insert(p);
				pacientes.erase(it);
			}
			else {//paciente medio o grave
				gravedades[info.gravedad-1].erase(info.iterador);
				info.iterador = gravedades[info.gravedad - 2].insert(gravedades[info.gravedad - 2].begin(), p);
				info.gravedad--;
			}
		}
		else {
			throw domain_error("Paciente inexistente");
		}
	}

	list<paciente> recuperados() const {//O(N) donde N es el numero de pacientes recuperados por esperar
		list<paciente> dev;
		for (paciente p : recup)
			dev.push_back(p);
		return dev;
	}
};


#endif
