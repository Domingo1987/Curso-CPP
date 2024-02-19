#include "empresa.h"
#include <iostream>

void Empresa::agregarEmpleado(const Empleado& empleado) {
    empleados_[cantidadEmpleados_] = empleado;
    cantidadEmpleados_++;
}

void Empresa::quitarEmpleado(int cedula) {
    for (int i = 0; i < cantidadEmpleados_; i++) {
        if (empleados_[i].getCedula() == cedula) {
            for (int j = i; j < cantidadEmpleados_ - 1; j++) {
                empleados_[j] = empleados_[j + 1];
            }
            cantidadEmpleados_--;
            break;
        }
    }
}

void Empresa::imprimirEmpleadosCumpleanios(const Fecha& fecha) const {
    for (int i = 0; i < cantidadEmpleados_; i++) {
        if (empleados_[i].getFechaNacimiento().dia == fecha.dia && empleados_[i].getFechaNacimiento().mes == fecha.mes) {
            empleados_[i].imprimir();
            std::cout << std::endl;
        }
    }
}
