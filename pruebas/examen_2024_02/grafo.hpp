#include <vector>
#include <map>
#include <list>
#include <set>
#include "estudiante.hpp"

class Grafo {
private:
	//Declaracion de atributos
		bool esDirigido;
	/*Creamos un map que reconoce a un vertice ESTUDIANTE, con una lista de pares de otros vectores que 
	son adyacentes al primero. Ademas el peso de la arista.*/
		std::map<Estudiante, std::list<std::pair<Estudiante, int>>> listaDeAdyacencia;
		std::map<Estudiante, int> v_a_i; // Vértices a índices
		std::vector<Estudiante> i_a_v; // Índices a vértices

public:
		Grafo(bool esDiri = true);
		virtual ~Grafo(); //Deconstructor de la clase

//Declaracion de metodos
		virtual bool agregarVertice(Estudiante v);

		virtual bool agregarArista(Estudiante va, Estudiante vb, int peso = 1);
//Debemos cambiar: vector de pares de vertices adyacentes a la lista (list)
		virtual void obtenerAdyacentes(Estudiante v, std::list<std::pair<Estudiante, int>>& adyacentes) const; //Modificamos vector por list
		virtual void obtenerIncidentes(Estudiante v, std::list<std::pair<Estudiante, int>>& incidentes) const;
		virtual void mostrarVertices();

	//Funciones para la categorizacion.
	virtual bool esSimple();
	virtual bool esConexo();
	virtual bool esCompleto();
	virtual bool esRegular();
/*
DFS. 
Toma un estudiante que es el nodo raiz (por donde comienza la busqueda)
Toma un conjunto de estudiantes, no nos importa el peso. Ya que aqui se guardan
los vertices del grafo.
*/
	virtual void DFS(Estudiante raiz, std::set <Estudiante>& nodosVisitados);
	
	//Desafios
	virtual int contarAislados();
	virtual int contarSubgrupos();
};