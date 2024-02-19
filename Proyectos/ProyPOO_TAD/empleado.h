#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <iostream>

struct Fecha {
    int dia;
    int mes;
    int anio;
    void leerFecha() {
        std::cin >> dia >> mes >> anio;
    }
};

class Empleado {
public:
    Empleado() = default;
    Empleado(
        const std::string& nombre, 
        const std::string& apellido, 
        int cedula, 
        const Fecha& fechaNacimiento
    );
    const std::string& getNombre() const;
    const std::string& getApellido() const;
    int getCedula() const;
    void setCedula(int cedula) { cedula_ = cedula; }

    const Fecha& getFechaNacimiento() const;
    void imprimir() const;
    // Métodos
    void leerEmpleado() {
        std::cin.ignore();

        std::cout << "Ingrese el nombre del empleado: ";
        std::getline(std::cin, nombre_);

        std::cout << "Ingrese el apellido del empleado: ";
        std::getline(std::cin, apellido_);

        std::cout << "Ingrese la cedula del empleado: ";
        std::cin >> cedula_;

        std::cout << "Ingrese la fecha de nacimiento (dd mm aaaa): ";
        fechaNacimiento_.leerFecha();

        // Limpiar el buffer de entrada
        std::cin.ignore();
    }
private:
    std::string nombre_;
    std::string apellido_;
    int cedula_;
    Fecha fechaNacimiento_;
};

#endif // EMPLEADO_H
