#include <iostream>
#include "grafo.hpp"

int main() {
		std::cout << "Hola Sociograma!\n";
		Grafo miGrafo = Grafo(false);

		// Crear 10 estudiantes
		Estudiante estudiantes[10];
		for (int i = 0; i < 10; ++i) {
				estudiantes[i] = Estudiante(100 + i, "Estudiante" + std::to_string(i), 20 + i, (i % 2 == 0) ? Sexo::MASCULINO : Sexo::FEMENINO);
				miGrafo.agregarVertice(estudiantes[i]);
		}

		// Conectar algunos estudiantes para formar subgrupos
		miGrafo.agregarArista(estudiantes[0], estudiantes[1]);
		miGrafo.agregarArista(estudiantes[1], estudiantes[2]);
		miGrafo.agregarArista(estudiantes[2], estudiantes[4]);
		miGrafo.agregarArista(estudiantes[5], estudiantes[6]);
		miGrafo.agregarArista(estudiantes[6], estudiantes[7]);
		miGrafo.agregarArista(estudiantes[8], estudiantes[9]);

		// Los estudiantes 8 y 9 están aislados

		// Mostrar resultados
		std::cout << "Hay " << miGrafo.contarAislados() << " estudiantes aislados en el grafo." << std::endl;
		std::cout << "El grafo tiene " << miGrafo.contarSubgrupos() << " subgrupos." << std::endl;

		return 0;
}
