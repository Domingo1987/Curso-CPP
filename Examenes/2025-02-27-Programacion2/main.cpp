#include "RedEntrega.h"
#include <iostream>

int main() {
    RedEntrega red;
    
    // Datos de prueba: se definen 3 rutas con dos puntos de origen.
    // Ruta 1: A → B → C
    red.rutas["A"].push_back({"B", 7});
    red.rutas["B"].push_back({"C", 3});
    
    // Ruta 2: A → D → E
    red.rutas["A"].push_back({"D", 4});
    red.rutas["D"].push_back({"E", 2});
    
    // Ruta 3: F → G
    red.rutas["F"].push_back({"G", 4});
    
    // H es un punto aislado (sin tramo).
    red.rutas["H"];
    
    // Funciones pendientes de implementación (placeholders)
    int puntosOrigen = red.contarPuntosOrigen();
    int maxRuta = red.maxLongitudRutaEntrega();
    
    // Funciones implementadas
    int totalTramos = red.calcularNumeroTotalDeTramos();
    int costoPromedio = red.obtenerCostoPromedioDeTramos();
    
    // Mostrar resultados: si los placeholders retornan -1, se muestra "aun no implementado"
    if (puntosOrigen == -1)
        std::cout << "contarPuntosOrigen: aun no implementado" << std::endl;
    else
        std::cout << "Puntos de origen: " << puntosOrigen << std::endl;
    
    if (maxRuta == -1)
        std::cout << "maxLongitudRutaEntrega: aun no implementado" << std::endl;
    else
        std::cout << "Longitud máxima de ruta: " << maxRuta << std::endl;
    
    std::cout << "Número total de tramos: " << totalTramos << std::endl;
    std::cout << "Costo promedio de tramos: " << costoPromedio << std::endl;
    
    return 0;
}
