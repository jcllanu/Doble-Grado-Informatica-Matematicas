//JUAN CARLOS LLAMAS NÚÑEZ


#ifndef autoescuela_h
#define autoescuela_h

#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>

using cancion = std::string;
using artista = std::string;

class ipud {
	using info_cancion = std::pair< std::list<cancion>::iterator, std::list<cancion>::iterator>;
	std::unordered_map<cancion, info_cancion> cancionesiPud;//Para cada cancion guarda un iterador a su posicion en la lista de reproduccion (end() si no esta)
	//y un iterador a su posicion en la lista de ya reproducidas(end() si no esta). Se garantiza que una cancion aparece solo una vez en la lista de reproduccion y una vez 
	//en la lista de ya reproducidas (la más cercana temporalmente)
	std::list<cancion> listaReproduccion;
	std::unordered_map<cancion, int> tiempoCancion;
	std::list<cancion> reproducidas;
	int tiempoPlayList = 0;
public:

	void addSong(cancion const& c, artista const& a, int d) {//O(1)
		auto dev = cancionesiPud.insert({ c,{listaReproduccion.end(),reproducidas.end() } });
		if (!dev.second)
			throw std::domain_error("Ya hay una cancion llamada " + c);
		else
			tiempoCancion[c] = d;
	}

	void addToPlaylist(cancion const& c) {//O(1)
		auto it = cancionesiPud.find(c);
		if (it == cancionesiPud.end()) {
			throw std::domain_error("No hay una cancion llamada " + c);
		}
		else {
			if (it->second.first == listaReproduccion.end()) {//La cancion no estaba
				listaReproduccion.push_back(c);
				tiempoPlayList += tiempoCancion[c];
				--it->second.first;
			}
		}
	}
	cancion current() {//O(1)
		if (listaReproduccion.size() == 0) {
			throw std::domain_error("La lista de reproduccion es vacia");
		}
		else {
			return listaReproduccion.front();
		}
	}
	void play() {//O(1)
		if (listaReproduccion.size() > 0) {
			cancion c = listaReproduccion.front();
			cancionesiPud[c].first = listaReproduccion.end();
			tiempoPlayList -= tiempoCancion[c];
			reproducidas.push_front(c);
			if (cancionesiPud[c].second != reproducidas.end()) {//Estaba en reproducidas
				reproducidas.erase(cancionesiPud[c].second);
			}
			cancionesiPud[c].second = reproducidas.begin();
			listaReproduccion.pop_front();

		}
	}
	int totalTime() {//O(1)
		return tiempoPlayList;
	}

	std::vector<cancion> recent(int n) {//O(n)
		std::vector<cancion> dev;
		if (reproducidas.size()>0) {
			auto it = reproducidas.begin();
			for (int i = 0; i < n; i++) {
				dev.push_back(*it);
				++it;
				if (it == reproducidas.end())
					break;
			}
		}
		return dev;
	}
	void deleteSong(cancion const& c) {//O(1)
		auto it = cancionesiPud.find(c);
		if (it != cancionesiPud.end()) {
			if (it->second.first != listaReproduccion.end()) {
				listaReproduccion.erase(it->second.first);
				tiempoPlayList -= tiempoCancion[c];
			}
			if (it->second.second != reproducidas.end()) {
				reproducidas.erase(it->second.second);
			}
			tiempoCancion.erase(c);
			cancionesiPud.erase(c);
		}
	}
};
#endif