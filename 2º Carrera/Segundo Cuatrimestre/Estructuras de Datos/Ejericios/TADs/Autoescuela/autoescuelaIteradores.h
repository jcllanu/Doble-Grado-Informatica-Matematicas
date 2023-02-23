//JUAN CARLOS LLAMAS NÚÑEZ


#ifndef autoescuela_h
#define autoescuela_h

#include <unordered_map>
#include <vector>
#include <set>


using alumno = std::string;
using profesor = std::string;


class autoescuela {
	std::unordered_map<alumno, profesor> alumnoProfesor;
	std::unordered_map<alumno, int> alumnoPuntos;
	std::unordered_map<alumno, std::set<alumno>::iterator> alumnoIterador;
	std::unordered_map<profesor, std::set<alumno>> profesorAlumnos;

public:
	
	void alta(alumno const& a, profesor const& p) {
		if (alumnoProfesor.count(a) > 0) {
			profesorAlumnos[alumnoProfesor[a]].erase(alumnoIterador[a]);
			auto it = profesorAlumnos[p].insert(a);//logaritmico
			alumnoIterador[a] = it.first;
			alumnoProfesor[a] = p;
		}
		else {
			alumnoProfesor[a] = p;
			auto it = profesorAlumnos[p].insert(a);//logaritmico
			alumnoIterador[a] = it.first;
			alumnoPuntos[a] = 0;
		}
	}

	bool es_alumno(alumno const& a, profesor const& p) {
		if (alumnoProfesor.count(a) > 0) {
			return alumnoProfesor[a] == p;
		}
		return false;
	}

	int puntuacion(alumno const& a) {
		auto it = alumnoPuntos.find(a);
		if (it != alumnoPuntos.end()) {
			return it->second;
		}
		else {
			std::string message = "El alumno ";
			throw std::domain_error(message.append(a).append(" no esta matriculado"));
		}
	}

	void actualizar(alumno const& a, int n) {
		auto it = alumnoPuntos.find(a);
		if (it != alumnoPuntos.end()) {
			it->second += n;
		}
		else {
			std::string message = "El alumno ";
			throw std::domain_error(message.append(a).append(" no esta matriculado"));
		}
	}

	std::vector<alumno> examen(alumno const& p, int n) {//lineal
		std::vector<alumno> dev;
		auto it = profesorAlumnos.find(p);
		if (it != profesorAlumnos.end()) {
			for (alumno a : it->second)
				if (alumnoPuntos[a] >= n)
					dev.push_back(a);
		}
		else {
			//std::string message = "El profesor ";
			//throw std::domain_error(message.append(p).append(" no esta registrado"));
		}
		return dev;
	}

	void aprobar(alumno const& a) {
		auto it = alumnoPuntos.find(a);
		if (it != alumnoPuntos.end()) {
			alumnoPuntos.erase(a);
			profesorAlumnos[alumnoProfesor[a]].erase(alumnoIterador[a]);
			alumnoIterador.erase(a);
			alumnoProfesor.erase(a);
		}
		else {
			std::string message = "El alumno ";
			throw std::domain_error(message.append(a).append(" no esta matriculado"));
		}
	}
};
#endif