//JUAN CARLOS LLAMAS NÚÑEZ


#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <unordered_map>
#include <unordered_set>

using DNI = std::string;
using puntos = int;

class carnet_puntos {
	std::unordered_map<DNI, puntos> mapaCarnet;
	std::unordered_map<puntos, std::unordered_set<DNI>> mapaPuntos;
public:


	void nuevo(DNI const& d) {// O(1) insert y operator[] son constantes en diccionarios no ordenados e insert es constante en unordered_set
		if (!mapaCarnet.insert(make_pair(d, 15)).second)
			throw std::domain_error("Conductor duplicado");
		else
			mapaPuntos[15].insert(d);
	}

	void quitar(DNI const& d, puntos const& p) {// O(1) find y operator[] son constantes en diccionarios no ordenados e insert y erase son constantes en unordered_set
		auto it = mapaCarnet.find(d);
		if (it == mapaCarnet.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		else {
			mapaPuntos[it->second].erase(d);
			it->second -= p;
			if (it->second < 0)
				it->second = 0;
			mapaPuntos[it->second].insert(d);
		}
	}

	puntos consultar(DNI const& d) {// O(1) find es constantes en diccionarios no ordenados
		auto it = mapaCarnet.find(d);
		if (it == mapaCarnet.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		else {
			return it->second;
		}
	}

	int cuantos_con_puntos(puntos const& p) {//O(1)
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
	
	//Solo con un mapa no ordenado de <DNI, puntos> perdemos que la funcion int cuantos_con_puntos(puntos const& p) tiene
	//coste lineal en el numero de DNIs insertados en el caso peor porque si todos tienen el mismo número de puntos p habrá que mirar en todos los DNIs

	/*void nuevo(DNI const& d) {// O(1) 
		if (!mapaCarnet.insert(make_pair(d, 15)).second)
			throw std::domain_error("Conductor duplicado");
	}

	void quitar(DNI const& d, puntos const& p) {// O(1)
		auto it = mapaCarnet.find(d);
		if (it == mapaCarnet.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		else {
			it->second -= p;
			if (it->second < 0)
				it->second = 0;
		}
	}

	puntos consultar(DNI const& d) {// O(1)
		auto it = mapaCarnet.find(d);
		if (it == mapaCarnet.end()) {
			throw std::domain_error("Conductor inexistente");
		}
		else {
			return it->second;
		}
	}

	int cuantos_con_puntos(puntos const& p) {// 0(N) siendo N el número de DNIs insertados
		int dev = 0;
		for (auto par : mapaCarnet)
			if (par.second == p)
				dev++;
		return dev;
	}*/
};

#endif
