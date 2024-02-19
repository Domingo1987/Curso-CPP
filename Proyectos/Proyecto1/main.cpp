#include <iostream>
#include "Empleado.hpp"

int main() {
    int var = 0;
    Empleado empleado1("Juan Pérez", 35, 3000.0);

    empleado1.mostrar();
    std::cout << " Aqui va algo "<< std::endl;

    return 0;
}
