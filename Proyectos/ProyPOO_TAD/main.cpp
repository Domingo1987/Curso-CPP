#include <iostream>
#include <array>
#include "empresa.h"

int main() {
    Empresa empresa;
    Empleado empleado;
    int opcion;
    Fecha fecha;

    // Menú interactivo
    while (1) {
        std::cout << std::endl;
        std::cout << "1. Agregar empleado" << std::endl;
        std::cout << "2. Quitar empleado" << std::endl;
        std::cout << "3. Imprimir empleados que cumplen años en una fecha dada" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                // Leer datos del empleado y agregarlo a la empresa
                empleado.leerEmpleado();
                empresa.agregarEmpleado(empleado);
                break;
            case 2:
                // Pedir cédula y eliminar el empleado con dicha cédula
                int cedula;
                std::cout << "Ingrese la cedula del empleado: ";
                std::cin >> cedula;
                empresa.quitarEmpleado(cedula);
                break;
            case 3:
                // Pedir fecha y mostrar empleados que cumplen años en dicha fecha
                std::cout << "Ingrese la fecha (dd mm aaaa): ";
                std::cin >> fecha.dia >> fecha.mes >> fecha.anio;
                empresa.imprimirEmpleadosCumpleanios(fecha);
                break;
            case 4:
                // Salir del programa
                return 0;
            default:
                std::cout << "Opción no válida." << std::endl;
        }
    }

    return 0;
}
