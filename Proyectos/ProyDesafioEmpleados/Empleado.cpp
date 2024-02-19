#include "Empleado.hpp"
#include <iostream>

Empleado::Empleado(const std::string& nombre, int id, float salarioMensual)
        : nombre(nombre), id(id), salarioMensual(salarioMensual) {}

std::string Empleado::getNombre() const {
    return nombre;
}

int Empleado::getId() const {
    return id;
}

float Empleado::getSalarioMensual() const {
    return salarioMensual;
}

void Empleado::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Empleado::setId(int id) {
    this->id = id;
}

void Empleado::setSalarioMensual(float salarioMensual) {
    this->salarioMensual = salarioMensual;
}

void Empleado::mostrar() const {
    std::cout << "Nombre: " << nombre << "\nID: " << id << "\nSalario mensual: " << salarioMensual << std::endl;
}
