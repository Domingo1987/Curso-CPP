#ifndef REDENTREGA_H
#define REDENTREGA_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

class RedEntrega {
public:
    // 'rutas' almacena, para cada punto (representado como std::string),
    // un vector de pares (destino, costo) que indican tramos de entrega.
    std::map<std::string, std::vector<std::pair<std::string, int>>> rutas;
    
    // Funciones a implementar por el estudiante (placeholders):
    // Deben retornar -1 hasta que se completen.
    int contarPuntosOrigen();         // (Contar puntos de origen)
    int maxLongitudRutaEntrega();      // (Calcular la longitud máxima de una ruta de entrega)
    int DFSMaxRuta(const std::string& inicio, std::set<std::string>& visitados);

    // Funciones implementadas (no dependen de las anteriores):
    // Calcula el número total de tramos en la red.
    int calcularNumeroTotalDeTramos();
    // Calcula el costo promedio de los tramos; si no hay tramos, retorna 0.
    int obtenerCostoPromedioDeTramos();
};

#endif // REDENTREGA_H
