#include <iostream> //contiene libreria stdio.h
#include <array>
#include <numeric> //std::accumulate
#include <algorithm> //std::sort


int main() {
    int total = 0;
    // Inicializamos el array con las ventas
    std::array <int,6> ventas = {10, 20, 15, 50, 25,30};
    // Imprimimos las ventas
    /*for(auto i = 0; i < ventas.size(); i++) {
        std::cout << "Las ventas del producto "<< i+1 <<" son: "<< ventas[i] << std::endl;
        // total += ventas[i] // total = total + ventas[i]
    }*/

    //Sumar todos los numeros excepto el mayor
    // extra, ordeno de menor a mayor y luego en el accumulate en "ventas.end()-1" no sumo el último valor(el mayor)
    std::sort(ventas.begin(), ventas.end());
    total = std::accumulate(ventas.begin(), ventas.end()-1, 0);
    std::cout<<"El total de ventas es: " <<total<< std::endl;

    return 0;
}
