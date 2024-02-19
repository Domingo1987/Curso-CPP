#include <iostream>
#include <array>

int main() {
    // Inicializamos el array con las ventas
    //int ventas[5] = {10, 20, 15, 25, 30};
    std::array <int,5> ventas = {10, 20, 15, 25,30};
    // Imprimimos las ventas
    for(auto i = 0; i < ventas.size(); i++) {
        std::cout << "Las ventas del producto "<< i+1 <<" son: "<< ventas[i] << std::endl;
    }
    return 0;
}
