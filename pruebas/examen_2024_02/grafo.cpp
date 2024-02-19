#include "grafo.hpp"
#include <iostream>

Grafo::Grafo(bool esDiri) : esDirigido(esDiri) {}

Grafo::~Grafo() {}

bool Grafo::agregarVertice(Estudiante v) {
		if (listaDeAdyacencia.find(v) != listaDeAdyacencia.end()) return false;
		listaDeAdyacencia[v] = std::list<std::pair<Estudiante, int>>();
		return true;
}

bool Grafo::agregarArista(Estudiante va, Estudiante vb, int peso) {

		if(listaDeAdyacencia.find(va) == listaDeAdyacencia.end() ||listaDeAdyacencia.find(vb) == listaDeAdyacencia.end()) return false;
	listaDeAdyacencia[va].push_back({vb,peso});
	 if (!esDirigido) listaDeAdyacencia[vb].push_back({va, peso});
		return true;

}

void Grafo::obtenerAdyacentes(Estudiante v, std::list<std::pair<Estudiante, int>>& adyacentes) const {
		adyacentes.clear();
		if (listaDeAdyacencia.find(v) == listaDeAdyacencia.end()) return;
		adyacentes = listaDeAdyacencia.at(v);
}

void Grafo::obtenerIncidentes(Estudiante v, std::list<std::pair<Estudiante, int>>& incidentes) const {
		incidentes.clear();

		if (listaDeAdyacencia.find(v) == listaDeAdyacencia.end()) return;

		for(const auto& entrada : listaDeAdyacencia) {
				for (const auto& par : entrada.second) {
						if (par.first == v) {
								incidentes.push_back({entrada.first, par.second});
						}
				}
		}
}


void Grafo:: mostrarVertices(){
	std::cout << std::endl << "Lista de estudiantes: " << std::endl;
	 for(const auto& entrada : listaDeAdyacencia) {
			std::cout << entrada.first.getNombre() << std::endl;
		}
		std::cout  << std::endl;
}

bool Grafo:: esSimple(){
	/*
Si un vertice tiene mas de 1 adyacentes o salientes no es simple
Si un vertice se conecta con si mismo ya no es simple.
	*/

	//"Para cada elemento de mi lista de adyacencia...."
	for(const auto &entrada :listaDeAdyacencia){
		Estudiante v = entrada.first;

		//Verificamos si el grafo se conecta a si mismo. (bucle)
		for(const auto &par : listaDeAdyacencia[v]){
			if(par.first==v){
				std::cout << "Un vertice tiene un bucle. No es simple." << std::endl;
				return false;
			} 
		}

		//Verificamos si un vertice tiene mas de 2 adyacentes.
		if(listaDeAdyacencia[v].size() >1 ){
				std::cout << "Hay un vertice que tiene mas de 1 adyacente. No es simple." << std::endl;
				return false;
		}
	}
	//Sino hay problemas es simple
	std::cout << "El grafo es simple." << std::endl;
	return true;
}

bool Grafo::esConexo(){
	//Si cada par de vertices esta conectado por un camino el grafo es conexo.

	//Primero busco cuantos vertices estan conectados entre caminos mediante DFS
	Estudiante primerEstudiante = listaDeAdyacencia.begin()->first;
	std::set <Estudiante> visitados;
	DFS(primerEstudiante, visitados);

	if(visitados.size() != listaDeAdyacencia.size())  
	return false;
	return true;
}

bool Grafo::esCompleto(){
	//Determino si se cumple la relacion Cantidad Vertices - Cantidad aristas
	int cantidad_vertices = listaDeAdyacencia.size();
	int cantidad_aristas = 0;

	for (const auto& entrada : listaDeAdyacencia) {
				cantidad_aristas += entrada.second.size();
		}

		// Calcular el número máximo de aristas en un grafo completo
		int numMaximoAristas = cantidad_vertices * (cantidad_vertices - 1) / 2;

		// Comparar el número de aristas con el número máximo de aristas
		if(cantidad_aristas == numMaximoAristas){
			std::cout << "Grafo completo." <<std::endl;
			return true;
		} else{
			std::cout << "Grafo incompleto." <<std::endl;
			return false;
		}

}

bool Grafo::esRegular(){
		// Calcula el grado del primer vértice en el grafo.
	//Accedo a mi primer vertice, veo el tamanio de la lista de vertices (adyacentes)
		int grado = listaDeAdyacencia.begin()->second.size();

		// Itera a través de los vértices y compara sus grados con el grado del primer vértice.
		for (const auto& entrada : listaDeAdyacencia) {
				if (entrada.second.size() != grado) {
					std::cout << "El grafo no es regular." << std::endl;
						return false; 
				} else {
						// Si todos los vértices tienen el mismo grado, el grafo se considera regular.
						std::cout << "El grafo es regular." << std::endl;
						return true;
					}
		} 
	return true;
}

void Grafo::DFS(Estudiante raiz, std::set <Estudiante>& visitados){
	//Agrego mi vertice raiz al conjunto
	visitados.insert(raiz);

	//Recorro la lista de adyacencia del grafo
	for(const auto &elem : listaDeAdyacencia[raiz]){
		Estudiante adyacente = elem.first; //Declaro un estudiante "adyacente", cada uno del grafo

		/*Si el estudiante actual NO esta en mi conjunto vuelvo a llamar esta funcion.
		Tomo al nodo adyacente como raiz, y sigo trabajando con mi conjunto */
		if(visitados.find(adyacente) == visitados.end()){
			DFS(adyacente, visitados);
		}
	}
}

int Grafo::contarAislados() {
		int contadorAislados = 0;
		std::list<std::pair<Estudiante, int>> adyacentes;

		for (const auto& par : listaDeAdyacencia) {
				const Estudiante& estudiante = par.first;
				obtenerAdyacentes(estudiante, adyacentes);

				if (adyacentes.empty()) {
						contadorAislados++;
				}
		}
		return contadorAislados;
}

int Grafo::contarSubgrupos() {
		std::set<Estudiante> visitados;
		int contadorSubgrupos = 0;

		// Iteramos sobre todos los vértices del grafo
		for (const auto& par : listaDeAdyacencia) {
				const Estudiante& estudiante = par.first;

				// Si el estudiante no ha sido visitado, realizamos DFS desde ese nodo
				if (visitados.find(estudiante) == visitados.end()) {
						DFS(estudiante, visitados);
						contadorSubgrupos++; // Cada llamada a DFS que comienza en un nodo no visitado identifica un nuevo subgrupo
				}
		}
		return contadorSubgrupos;
}
