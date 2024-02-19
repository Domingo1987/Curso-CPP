#include <iostream>
#include "Grafo.cpp"


int main() {
    AdjacencyMatrix graph;

    // Cargar grafo de prueba
    graph.createTestGraph();
    graph.printGraph();

    // Opción para cargar grafo desde la consola
    std::cout << "\n¿Desea cargar un grafo desde la consola? (s/n): ";
    char choice;
    std::cin >> choice;
    if (choice == 's' || choice == 'S') {
        graph.loadGraphFromConsole();
        graph.printGraph();
    }

    return 0;
}
