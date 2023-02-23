//JUAN CARLOS LLAMAS NÚÑEZ


#ifndef consultorio_h
#define consultorio_h

#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>

using medico = std::string;
using paciente = std::string;
using dia = int;
using hora = std::string;
/*
struct hora {
	int h, m;
	bool operator<(hora const& otra) {
		return this->h < otra.h || (this->h == otra.h && this->m < otra.m);
	}
};
*/
struct fecha {
	hora h;
	dia d;
	bool operator<(fecha const& otra) {
		return this->d < otra.d || (this->d == otra.d && this->h < otra.h);
	}
};

//Para el comentario sobre el coste llamamos MD al max{dias distintos cuando m tiene alguna consulta| m medico} y llamamos MH al numero máximo de horas para un día 
class consultorio {
	std::unordered_map <medico, std::map<dia, std::map<hora, paciente>>> consultorio;//Diccionario no ordenado de medico a diccionario no ordenado de dias. 
																				//Para cada dia de un medico el valor es un diccionario ordenado de horas donde el valor es el paciente
public:

	void nuevoMedico(medico const& m) {//O(1) insertar en un diccionario no ordenado
		consultorio[m];
	}

	void pideConsulta(paciente const& p, medico const& m, fecha const& f) {//O(log(MD)) + O(log(MF)) 
		//Buscar en el diccionario de medicos (no ordenado) es constate, operator[] es logaritmico en el numero de días del medico m (MD en el caso peor) por ser un diccionario ordenado por días 
		//e insert es logaritmico en el numero de horas para un día (en el caso peor es MH) por ser un diccionario ordenado por horas
		auto itMedico = consultorio.find(m);
		if (itMedico == consultorio.end()) {
			throw std::domain_error("Medico no existente");
		}
		else {
			auto dev = itMedico->second[f.d].insert({ f.h,p });
			if (!dev.second) {
				throw std::domain_error("Fecha ocupada");
			}
		}
	}

	paciente siguientePaciente(medico const& m) {//O(1) 
		//Buscar es constante en el diccionario de medicos(no ordenado) y los accesos a los iteradores también son constantes
		auto itMedico = consultorio.find(m);
		if (itMedico == consultorio.end()) {
			throw std::domain_error("Medico no existente");
		}
		else {
			auto itDia = itMedico->second.begin();
			if (itDia == itMedico->second.end()) {
				throw std::domain_error("No hay pacientes");
			}
			else {
				auto itFecha=itDia->second.begin();
				if (itFecha == itDia->second.end()) {
					throw std::domain_error("No hay pacientes");
				}
				else {
					return itFecha->second;
				}
			}
		}
	}

	void atiendeConsulta(medico const& m) {//O(1)
		//Buscar es constante en el diccionario de medicos(no ordenado),  los accesos a los iteradores también son constantes y erase dado un iterador es constante en diccionarios ordenados 
		auto itMedico = consultorio.find(m);
		if (itMedico == consultorio.end()) {
			throw std::domain_error("Medico no existente");
		}
		else {
			auto itDia = itMedico->second.begin();
			if (itDia == itMedico->second.end()) {
				throw std::domain_error("No hay pacientes");
			}
			else {
				auto itFecha = itDia->second.begin();
				if (itFecha == itDia->second.end()) {
					throw std::domain_error("No hay pacientes");
				}
				else {
					itDia->second.erase(itFecha);
					if (itDia->second.size() == 0)
						itMedico->second.erase(itDia);
				}
			}
		}
	}

	std::vector<std::pair<hora, paciente>> listaPacientes(medico const& m, dia const& d) {//O(log(MD)) + O(MH)) 
		//Buscar en el diccionario de medicos (no ordenado) es constate, buscar es logaritmico en el numero de días del medico m (MD en el caso peor) por ser un diccionario ordenado por días 
		//y luego para un día recorrerse las horas para un día es lineal en el numero de horas(MH en el caso peor)
		std::vector<std::pair<hora, paciente>> dev;
		auto itMedico = consultorio.find(m);
		if (itMedico == consultorio.end()) {
			throw std::domain_error("Medico no existente");
		}
		else {
			auto itDia = itMedico->second.find(d);
			if (itDia != itMedico->second.end()) {
				for (auto par : itDia->second)
					dev.push_back(par);
			}	
		}
		return dev;
	}
};
#endif