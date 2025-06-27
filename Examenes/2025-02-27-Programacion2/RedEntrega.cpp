#include "RedEntrega.h"

// Funciones que el estudiante debe implementar: por ahora retornan -1.
/*int RedEntrega::contarPuntosOrigen() {
    return -1;  // No implementado
}

int RedEntrega::maxLongitudRutaEntrega() {
    return -1;  // No implementado
}*/

// Función implementada: calcula el número total de tramos en la red.
int RedEntrega::calcularNumeroTotalDeTramos() {
    int total = 0;
    for (const auto &par : rutas) {
        total += par.second.size();
    }
    return total;
}

// Función implementada: calcula el costo promedio de los tramos.
// Si no hay tramos, retorna 0.
int RedEntrega::obtenerCostoPromedioDeTramos() {
    int totalCost = 0;
    int count = 0;
    for (const auto &par : rutas) {
        for (const auto &destino : par.second) {
            totalCost += destino.second;
            count++;
        }
    }
    if (count == 0) return 0;
    return totalCost / count;
}

// Función auxiliar DFS que calcula la distancia acumulada (en términos de costo) desde 'inicio' hasta el final de la ruta.
int RedEntrega::DFSMaxRuta(const std::string& inicio, std::set<std::string>& visitados) {
    visitados.insert(inicio);
    int maxDistancia = 0;
    for (const auto &tramo : rutas[inicio]) {
        if (visitados.find(tramo.first) == visitados.end()) {
            // Suma el costo del tramo actual y la distancia de la ruta a partir del destino.
            int distancia = tramo.second + DFSMaxRuta(tramo.first, visitados);
            maxDistancia = std::max(maxDistancia, distancia);
        }
    }
    visitados.erase(inicio);
    return maxDistancia;
}

// Funciones que el estudiante debe implementar

int RedEntrega::contarPuntosOrigen() {
    // Se recorre el grafo para identificar todos los nodos que son destinos.
    std::set<std::string> destinos;
    for (const auto &par : rutas) {
        for (const auto &tramo : par.second) {
            destinos.insert(tramo.first);
        }
    }
    // Se cuentan aquellos nodos que tienen rutas salientes y NO aparecen en el conjunto de destinos.
    int count = 0;
    for (const auto &par : rutas) {
        if (destinos.find(par.first) == destinos.end() && !par.second.empty())
            count++;
    }
    return count;
}

int RedEntrega::maxLongitudRutaEntrega() {
    std::set<std::string> visitados;
    int maxRuta = 0;
    for (const auto &par : rutas) {
        int distancia = DFSMaxRuta(par.first, visitados);
        maxRuta = std::max(maxRuta, distancia);
    }
    return maxRuta;
}

