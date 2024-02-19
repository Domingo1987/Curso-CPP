#include <iostream>
#include "empleado.h"

Empleado::Empleado(const std::string& nombre, const std::string& apellido, int cedula, const Fecha& fechaNacimiento)
    : nombre_(nombre), apellido_(apellido), cedula_(cedula), fechaNacimiento_(fechaNacimiento) {}

const std::string& Empleado::getNombre() const {
    return nombre_;
}

const std::string& Empleado::getApellido() const {
    return apellido_;
}

int Empleado::getCedula() const {
    return cedula_;
}

const Fecha& Empleado::getFechaNacimiento() const {
    return fechaNacimiento_;
}

void Empleado::imprimir() const {
    std::cout << "Nombre: " << nombre_ << std::endl;
    std::cout << "Apellido: " << apellido_ << std::endl;
    std::cout << "Cedula: " << cedula_ << std::endl;
    std::cout << "Fecha de nacimiento: " << fechaNacimiento_.dia << "/" << fechaNacimiento_.mes << "/" << fechaNacimiento_.anio << std::endl;
}



