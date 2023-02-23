//JUAN CARLOS LLAMAS NÚÑEZ


#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <algorithm>
#include <unordered_map>
#include <map>
#include <map>
#include <unordered_set>
#include <vector>
#include <list>

using producto = std::string;
using cliente = std::string;


class  OutletaGoGo {
	std::map<producto, int> productoVentas;
	std::unordered_map<producto, int> productosOfertaUnidades;
	std::unordered_map<producto, std::list<cliente>> productosListaClientes;
	std::unordered_map <cliente, std::unordered_map<producto, std::list<cliente>::iterator>> clientesinfo;
public:
	
	void an_oferta(producto const& p, int num_unidades) {//O(log(n))
		if (productosOfertaUnidades.count(p)==1 || num_unidades <= 0) {
			throw std::domain_error("EAnnadirOferta");
		}
		else {
			productosOfertaUnidades.insert({ p,num_unidades });
			productoVentas.insert({ p,0 });//Si ya había una oferta anterior del mismo producto que ya ha acabado no modifica nada
			productosListaClientes[p];
		}
	}
	void pon_en_espera(cliente const& c, producto const& p) {//O(1)
		auto it = productosOfertaUnidades.find(p);
		if (it == productosOfertaUnidades.end()) {
			throw std::domain_error("ENoExisteProducto");
		}
		else {
			if (clientesinfo[c].count(p) == 0) {//No esta esperando a ese producto
				productosListaClientes[p].push_back(c);
				clientesinfo[c][p] = --productosListaClientes[p].end();

			}
		}
	}
	void cancela_espera(cliente const& c, producto const& p) {//O(1)
		auto it = productosListaClientes.find(p);
		if (it == productosListaClientes.end()) {
			throw std::domain_error("ENoExisteProducto");
		}
		else {
			if (clientesinfo.count(c)==1 && clientesinfo[c].count(p) == 1) {//Esta esperando a ese producto
				it->second.erase(clientesinfo[c][p]);
				clientesinfo[c].erase(p);
				if (clientesinfo[c].empty()) {
					clientesinfo.erase(c);
				}
			}
		}
	}
	int num_en_espera(producto const& p) {//O(1)
		auto it = productosListaClientes.find(p);
		if (it == productosListaClientes.end()) {
			throw std::domain_error("ENoExisteProducto");
		}
		else {
			return it->second.size();
		}
	}
	void venta(producto const& p, int num_unidades) {//O(log(n))
		auto it = productosListaClientes.find(p);
		if (it == productosListaClientes.end()) {
			throw std::domain_error("ENoExisteProducto");
		}
		else {
			if (it->second.size() == 0) {
				throw std::domain_error("ENoHayEspera");
			}
			else {
				if (productosOfertaUnidades[p] < num_unidades) {
					throw std::domain_error("ENoHaySuficientesUnidades");
				}
				else {
					productosOfertaUnidades[p] -= num_unidades;
					clientesinfo[it->second.front()].erase(p);
					if (clientesinfo[it->second.front()].empty()) {
						clientesinfo.erase(it->second.front());
					}
					it->second.pop_front();
					productoVentas[p] += num_unidades;
					if (productosOfertaUnidades[p] == 0) {
						for (cliente c : it->second) {
							clientesinfo[c].erase(p);
							if (clientesinfo[c].empty()) {
								clientesinfo.erase(c);
							}
						}
						productosOfertaUnidades.erase(p);
						productosListaClientes.erase(p);
					}
				}
			}
		}
	}

	cliente primero_en_espera(producto const& p) {//O(1)
		auto it = productosListaClientes.find(p);
		if (it == productosListaClientes.end()) {
			throw std::domain_error("ENoExisteProducto");
		}
		else {
			if (it->second.size() == 0) {
				throw std::domain_error("ENoHayEspera");
			}
			else {
				return it->second.front();
			}
		}
	}
	std::list<std::pair<producto, int>> lista_ventas() {//O(n)
		std::list<std::pair<producto, int>> dev;
		for (auto par : productoVentas) {
			dev.push_back({ par.first,par.second });
		}
		return dev;
	}
};

#endif
