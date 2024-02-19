#ifndef EMPRESA_H
#define EMPRESA_H

#include <array>
#include "empleado.h"

class Empresa {
public:
    void agregarEmpleado(const Empleado& empleado);
    void quitarEmpleado(int cedula);
    void imprimirEmpleadosCumpleanios(const Fecha& fecha) const;
private:
    std::array<Empleado, 100> empleados_{};
    int cantidadEmpleados_ = 0;
};

#endif // EMPRESA_H
