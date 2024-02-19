#include <iostream>
#include <algorithm>
#include "Empleado.hpp"
#include "FileHandler.hpp"

int main()
{
    // Crear una lista de empleados vacía
    std::list<Empleado> lista;

    // Cargar la lista de empleados desde el archivo
   

    int opcion = 0;

    while (opcion != 6)
    {
        std::cout << "--- MENU ---" << std::endl;
        std::cout << "1. Agregar un nuevo empleado" << std::endl;
        std::cout << "2. Modificar un empleado existente" << std::endl;
        std::cout << "3. Eliminar un empleado" << std::endl;
        std::cout << "4. Buscar un empleado" << std::endl;
        std::cout << "5. Mostrar la lista completa de empleados" << std::endl;
        std::cout << "6. Salir del programa" << std::endl;
        std::cout << "Ingrese una opcion: ";

        std::cin >> opcion;

        // Realizar la acción correspondiente según la opción seleccionada
        switch (opcion)
        {
            case 1:{
                // Pedir información del empleado
                std::string nombre;
                int id;
                float salario;

                std::cout << "Ingrese el ID del empleado: ";
                std::cin >> id;
                std::cin.ignore();

                
                std::cout << "Ingrese el nombre del empleado: ";
                std::getline(std::cin, nombre);

                std::cout << "Ingrese el salario mensual del empleado: ";
                std::cin >> salario;

                // Crear el objeto Empleado y agregarlo a la lista
                Empleado empleado(nombre, id, salario);
                lista.push_back(empleado);

                std::cout << "Empleado agregado correctamente." << std::endl;                break;
                break;
            }
            case 2:{
                // Aquí hay que modificar un empleado existente de la lista
                int id;
                std::cout << "Ingrese la ID del empleado que desea modificar: ";
                std::cin >> id;

                // Buscar el empleado por su ID
                auto it = std::find_if(lista.begin(), lista.end(), [id](const Empleado& emp) {
                    return emp.getId() == id;
                });

                if (it == lista.end()) {
                    std::cout << "No se encontró un empleado con la ID ingresada." << std::endl;
                } else {
                    std::string nuevoNombre;
                    float nuevoSalario;

                    // Pedir los nuevos datos del empleado
                    std::cout << "Ingrese el nuevo nombre del empleado: ";
                    std::cin >> nuevoNombre;

                    std::cout << "Ingrese el nuevo salario mensual del empleado: ";
                    std::cin >> nuevoSalario;

                    // Modificar los atributos del empleado
                    it->setNombre(nuevoNombre);
                    it->setSalarioMensual(nuevoSalario);

                    std::cout << "Empleado modificado exitosamente." << std::endl;
                }

            }
            case 3:{
                // Aquí hay que eliminar un empleado de la lista
                
                break;
            }
            case 4:{
                // Aquí hay que buscar un empleado en la lista
                break;
            }
                

            case 5:{
                std::cout << "Lista completa de empleados:\n\n";
                if (lista.empty()) {
                    std::cout << "No hay empleados registrados.\n\n";
                } else {
                    for (const auto& empleado : lista) {
                        std::cout << "ID: " << empleado.getId() << "\n";
                        std::cout << "Nombre: " << empleado.getNombre() << "\n";
                        std::cout << "Salario mensual: " << empleado.getSalarioMensual() << "\n\n";
                    }
                }
                break;
            }
                

            case 6:{
                // Aquí hay que salir del programa y guardar la lista de empleados en el archivo
                break;
            }
                

            default:
                std::cout << "\nOpcion invalida. Intente de nuevo." << std::endl;
                break;
        }
    }

    return 0;
}
