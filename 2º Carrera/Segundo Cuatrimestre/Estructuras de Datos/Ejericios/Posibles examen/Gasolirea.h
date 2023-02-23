//JUAN CARLOS LLAMAS NÚÑEZ


#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>

using surtidor = std::string;
using coche = std::string;
using combustible = std::string;

struct result{
	coche c;
	int num_litros;
};

class GestorSurtidores {
	std::unordered_map<surtidor, std::list<coche>> surtCoches;
	std::unordered_map<surtidor, std::unordered_map<combustible,int>> surtGasolina;
	std::unordered_map <coche, std::pair<std::list<coche>::iterator,surtidor>> cochesEsperaIt;


public:
	void an_surtidor(surtidor const& s) {
		if (surtCoches.count(s) == 0) {
			surtCoches[s];
			surtGasolina[s];
		}
		else {
			throw std::domain_error("ESurtidorDuplicado");
		}
	}

	void carga(surtidor const& s, combustible const& c, int num_litros) {
		auto it = surtGasolina.find(s);
		if (it == surtGasolina.end()) {
			throw std::domain_error("ESurtidorNoExiste");
		}
		else {
			it->second[c] += num_litros;
		}
	}
	void pon_en_espera(coche const& c, surtidor const& s) {
		if (cochesEsperaIt.count(c) == 1) {
			throw std::domain_error("ELlegadaVehiculo");
		}
		else {
			auto it = surtCoches.find(s);
			if (it == surtCoches.end()) {
				throw std::domain_error("ELlegadaVehiculo");
			}
			else {//Existe el surtidor y el coche no está esperando en otra lista;
				auto itAlista = it->second.end();
				itAlista = it->second.insert(itAlista, c);
				cochesEsperaIt[c].first = itAlista;
				cochesEsperaIt[c].second = s;
			}
		}

	}
	result vende(surtidor const& s, combustible const& c, int num_litros) {
		auto it = surtCoches.find(s);
		if (it == surtCoches.end()) {
			throw std::domain_error("EErrorVenta");
		}
		else {//Existe el surtidor
			if(it->second.size()==0)
				throw std::domain_error("EErrorVenta");
			else {//Hay coches esperando
				if(num_litros<=0)
					throw std::domain_error("EErrorVenta");
				else {//Los litros son positivos
					auto itGasolina=surtGasolina[s].find(c);
					if (itGasolina == surtGasolina[s].end() || itGasolina->second<num_litros)
						throw std::domain_error("EErrorVenta");
					else {//Hay suficientes litros
						coche car = it->second.front();
						cochesEsperaIt.erase(it->second.front());
						it->second.pop_front();
						itGasolina->second -= num_litros;
						return { car, itGasolina->second };
					}
				}
			}
		}
	}

	void abandona(coche const& c) {
		auto it = cochesEsperaIt.find(c);
		if (it != cochesEsperaIt.end()) {
			surtCoches[it->second.second].erase(it->second.first);
		}
	}

};

#endif
