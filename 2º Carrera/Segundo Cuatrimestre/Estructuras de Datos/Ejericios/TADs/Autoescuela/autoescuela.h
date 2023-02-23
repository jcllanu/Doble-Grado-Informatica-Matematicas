//JUAN CARLOS LLAMAS NÚÑEZ


#ifndef autoescuela_h
#define autoescuela_h

#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <list>


using alumno = std::string;
using profesor = std::string;


class autoescuela {
	std::unordered_map<profesor, std::set<alumno>> mapProfesores;//Asocia a cada profesor su conjunto de alumnos(conjunto ordenado por nombre de alumno)
	std::unordered_map<alumno, int> mapPuntos;//Asocia a cada alumno su puntuacion
	std::unordered_map<alumno, profesor> mapAlumnos;//Asocia a cada alumno su profesor
public:
	//Para el analisis del coste definimos MA como el numero máximo de alumnos que tiene un profesor

	void alta(alumno const& a, profesor const& p){//O(log(MA))
		//Todas las operaciones son constantes salvo la inserción/borrado del alumno en el conjunto de alumnos de un profesor que es logaritmica en el número de alumons de un profesor (en el caso peor es MA).
		if (mapAlumnos.count(a) == 0) {
			mapAlumnos[a] = p;
			mapProfesores[p].insert(a);
			mapPuntos.insert({ a, 0 });
		}
		else {
			mapProfesores[mapAlumnos[a]].erase(a);
			mapProfesores[p].insert(a);
			mapAlumnos[a] = p;
		}
	}

	bool es_alumno(alumno const& a, profesor const& p) {//O(1)
		//Como estamso trabajando con diccionarios no ordenados estas operaciones son constantes
		auto it = mapAlumnos.find(a);
		return it != mapAlumnos.end() && it->second == p;
	}

	int puntuacion(alumno const& a) {//O(1)
		auto it = mapPuntos.find(a);
		if (it == mapPuntos.end()) {
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		}
		else {
			return it->second;
		}
	}

	void actualizar(alumno const& a, int n) {//O(1)
		auto it = mapPuntos.find(a);
		if (it == mapPuntos.end()) {
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		}
		else {
			it->second += n;
		}

	}

	std::vector<alumno> examen(alumno const& p, int n) {//O(MA)
		//En el caso peor nos piden examinar a los alumnos del profesor que más alumnos tiene y hay que recorrerlos todos para comprobar si superan la puntuacion limite
		//Obs: ya están ordenados alfabéticamente
		std::vector<alumno> dev;
		auto itProfesor = mapProfesores.find(p);
		if (itProfesor != mapProfesores.end()) {
			for (alumno a : itProfesor->second)
				if (mapPuntos[a] >= n)
					dev.push_back(a);
		}
		return dev;
	}

	void aprobar(alumno const& a) {//O(log(MA))
		//Todas las operaciones salvo el erase del alumno del conjunto son constantes. El erase es logaritmico en el tamaño del conjunto (que en el caso peor es MA)
		auto it = mapPuntos.find(a);
		if (it == mapPuntos.end()) {
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		}
		else {
			mapPuntos.erase(it);
			profesor p = mapAlumnos[a];
			mapProfesores[p].erase(a);
			if (mapProfesores[p].empty()) {
				mapProfesores.erase(p);
			}
			mapAlumnos.erase(a);
		}
	}
};
#endif