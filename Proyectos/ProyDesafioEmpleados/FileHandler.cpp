#include "FileHandler.hpp"

int FileHandler::guardar_lista_empleados(const std::list<Empleado>& lista) {
    std::ofstream archivo(filename, std::ios::out | std::ios::binary);
    if (!archivo) {
        return -1;
    }
    int cantidad = lista.size();
    archivo.write((char*)&cantidad, sizeof(int));
    for (const auto& empleado : lista)
    {
        archivo.write((char*)&empleado, sizeof(Empleado));
    }
    archivo.close();
    return 0;
}

int FileHandler::cargar_lista_empleados(std::list<Empleado>& lista) {
    std::ifstream archivo(filename, std::ios::in | std::ios::binary);
    if (!archivo) {
        return -1;
    }
    int cantidad;
    archivo.read((char*)&cantidad, sizeof(int));
    for (int i = 0; i < cantidad; i++)
    {
        Empleado empleado;
        archivo.read((char*)&empleado, sizeof(Empleado));
        lista.push_back(empleado);
    }
    archivo.close();
    return 0;
}
