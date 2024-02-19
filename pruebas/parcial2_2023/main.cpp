#include <iostream>
#include "grafo.hpp"

int main() {
		std::cout << "Hola Grafo!\n";
		Grafo miGrafo = Grafo(true);
		Estudiante estudiante1 = Estudiante(111, "Carlos", 26, Sexo::MASCULINO);
		Estudiante estudiante2 = Estudiante(222, "Stephen", 30, Sexo::MASCULINO);
		Estudiante estudiante3 = Estudiante(333, "Jennifer", 90, Sexo::FEMENINO);
		Estudiante estudiante4 = Estudiante(444, "August", 43, Sexo::MASCULINO);
		Estudiante estudiante5 = Estudiante(555, "Como", 47, Sexo::MASCULINO);

		miGrafo.agregarVertice(estudiante1);
		miGrafo.agregarVertice(estudiante2);
		miGrafo.agregarVertice(estudiante3);
		miGrafo.agregarVertice(estudiante4);
		miGrafo.agregarVertice(estudiante5);

		miGrafo.agregarArista(estudiante3, estudiante4);
		miGrafo.agregarArista(estudiante4, estudiante3);
		miGrafo.agregarArista(estudiante2, estudiante1);
		miGrafo.agregarArista(estudiante1, estudiante2);
		miGrafo.agregarArista(estudiante5, estudiante5);

  	//Pruebas de bucles.
    miGrafo.agregarArista(estudiante1, estudiante1);
    miGrafo.agregarArista(estudiante3, estudiante3);
	//Agregamos un bucle, para probar la funcion esSimple
	//miGrafo.agregarArista(estudiante1,estudiante1);

		//Mostramos los adyacentes a un cierto vertice.
		Estudiante vertice = estudiante3;
		std::list<std::pair<Estudiante, int>> adyacentes;
		miGrafo.obtenerAdyacentes(vertice, adyacentes);
		std::list<std::pair<Estudiante, int>>::iterator it = adyacentes.begin();

		std::cout << "Adyacentes de " << vertice.getNombre() << std::endl;
		while (it != adyacentes.end()) {
				std::cout << it->first.getNombre() << "\t";
				it++;
		}
		std::cout << std::endl;

		//Mostramos los incidentes a un cierto vertice.
		std::list<std::pair<Estudiante, int>> incidentes;
		miGrafo.obtenerIncidentes(vertice, incidentes);
		std::list<std::pair<Estudiante, int>>::iterator it2 = incidentes.begin();

		std::cout << "Incidentes de " << vertice.getNombre() << std::endl;
		while (it2 != incidentes.end()) {
				std::cout << it2->first.getNombre() << "\t";
				it2++;
		}
		std::cout << std::endl;

	//Categorizacion de mi grafo
	miGrafo.mostrarVertices();
	miGrafo.esSimple();
	if(miGrafo.esConexo()) {std::cout << "Es conexo" <<std::endl;} else std::cout << "No es conexo." <<std::endl;
	miGrafo.esCompleto();
	miGrafo.esRegular();

	if(miGrafo.tieneCicloHamiltoniano() ==true){ std::cout << "Tiene Ciclo Hamiltoniano" << std::endl;}
	else {std::cout << "No tiene Ciclo Hamiltoniano" << std::endl;}

	std::cout << "El grafo tiene " << miGrafo.contarIslas() << " Islas (Componentes Conexas)" << std::endl; 

	
	
	
	
	
	
	//Pruebo funcion contar bucles.
  	std::cout << std::endl << "PRUEBA PARCIAL." << std::endl;
  	std::cout << "El grafo tiene " << miGrafo.contarBucles() << " bucles." << std::endl;

	// Muestro vertice mayor grado
	Estudiante verticeMayorGrado = miGrafo.verticeConMayorGrado();
  	std::cout << "El vertice con mayor grado es: " << verticeMayorGrado.getNombre() << std::endl;


	return 0;
}
