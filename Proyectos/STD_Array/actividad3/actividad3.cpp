#include <iostream>
#include <array>
#include <algorithm>



int main() {
    int max_index = 0;
   
    // Inicializamos el array con las ventas
    std::array <int,5> ventas = {10, 400, 50, 20,30};
    // Imprimimos las ventas
    /*for(auto i = 0; i < ventas.size(); i++) {
        std::cout << "Las ventas del producto "<< i+1 <<" son: "<< ventas[i] << std::endl;
        // total += ventas[i]
    }*/
    
    max_index = std::distance(ventas.begin(), std::max_element(ventas.begin(), ventas.end()));
    std::cout << "El id del producto mas vendido es: " << max_index+1 << std::endl;

    return 0;
}
