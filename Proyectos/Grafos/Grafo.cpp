//****************************************************************
// Autor: Domingo Perez
// Fecha: 6 de setiembre de 2023
//
// class AdjacencyMatrix
// Esta clase especifica las operaciones básicas para implementar
// un grafo utilizando una matriz de adyacencia.
//****************************************************************

#include <iostream>
#include <vector>

struct DataType {
    int value;  // Puedes agregar más campos si es necesario
};

//podemos considerar tambien... si, ya hablamos de E y A.
struct EdgeData {
    int weight;             // Peso o costo de la arista. En un grafo simple, esto sería 0 o 1.
    std::string label;     // Etiqueta o nombre opcional para la arista.
    
    // Constructor predeterminado para inicializar el peso a 0 y la etiqueta vacía.
    EdgeData(int w = 0, const std::string& l = "") : weight(w), label(l) {}
};

// Entonces los vertices quedan donde?
struct VertexData {
    int value;              // Valor o dato del vértice.
    std::string name;      // Nombre o identificador del vértice.
    
    VertexData(int v = 0, const std::string& n = "") : value(v), name(n) {}
};

class AdjacencyMatrix {
public:
    AdjacencyMatrix(int size = 0);
    ~AdjacencyMatrix();

    bool isEmpty() const;
    void createTestGraph();           // Función para crear un grafo de prueba
    void loadGraphFromConsole();      // Función para cargar grafo desde la consola
    void clearGraph();
    void printGraph() const;


    // Función para agregar un vértice con data específica
    void addVertex(const VertexData& vertexData);

    // Función para agregar una arista con data específica
    void addEdge(int vertex1, int vertex2, const EdgeData& edgeData);


protected:
    int gSize;  // número actual de vértices
    //? std::vector<VertexData> vertices;               // Datos de los vértices
    std::vector<std::vector<DataType>> matrix;  // matriz de adyacencia
};

AdjacencyMatrix::AdjacencyMatrix(int size) {
    gSize = size;
    matrix.resize(gSize, std::vector<DataType>(gSize));
}

AdjacencyMatrix::~AdjacencyMatrix() {
    clearGraph();
}

bool AdjacencyMatrix::isEmpty() const {
    return (gSize == 0);
}

void AdjacencyMatrix::createTestGraph() {
    gSize = 4;  // Un grafo con 4 vértices
    matrix.resize(gSize, std::vector<DataType>(gSize));

    // Conexiones:
    // 0 conectado a 1 y 2
    // 1 conectado a 2 y 3
    // 2 tiene un lazo consigo mismo
    // 3 no está conectado a ningún otro vértice

    matrix[0][1].value = 1;
    matrix[0][2].value = 1;
    matrix[1][2].value = 1;
    matrix[1][3].value = 1;
    matrix[2][2].value = 1;  // Lazo en el vértice 2
}

void AdjacencyMatrix::loadGraphFromConsole() {
    std::cout << "Ingrese el número de vértices: ";
    std::cin >> gSize;

    matrix.clear();
    matrix.resize(gSize, std::vector<DataType>(gSize));
    //matrix.resize(gSize); incorrecto

    std::cout << "Ingrese la matriz de adyacencia (0 o 1 para cada conexión):\n";
    for (int i = 0; i < gSize; ++i) {
        for (int j = 0; j < gSize; ++j) {
            std::cin >> matrix[i][j].value;
        }
    }
}

void AdjacencyMatrix::clearGraph() {
    for (int i = 0; i < gSize; i++) {
        matrix[i].clear();
    }
    matrix.clear();
    gSize = 0;
}

void AdjacencyMatrix::printGraph() const {
    for (int i = 0; i < gSize; i++) {
        for (int j = 0; j < gSize; j++) {
            std::cout << matrix[i][j].value << " ";
        }
        std::cout << std::endl;
    }
}






/*

void AdjacencyMatrix::addVertex(const VertexData& vertexData) {
    vertices.push_back(vertexData);
    
    // Incrementar el tamaño de la matriz
    gSize++;
    matrix.resize(gSize);
    for (int i = 0; i < gSize; i++) {
        matrix[i].resize(gSize);
    }
}

void AdjacencyMatrix::addEdge(int vertex1, int vertex2, const EdgeData& edgeData) {
    if (vertex1 < gSize && vertex2 < gSize) {
        matrix[vertex1][vertex2] = edgeData;
    } else {
        std::cout << "Índices de vértices no válidos." << std::endl;
    }
}


*/
