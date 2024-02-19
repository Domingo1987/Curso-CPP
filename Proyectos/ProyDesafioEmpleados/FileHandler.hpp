/**
 * @file FileHandler.hpp
 * @brief Definición de la clase FileHandler.
 */

#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <string>
#include <fstream>
#include <list>
#include "Empleado.hpp"

/**
 * @class FileHandler
 * @brief Clase que maneja la lectura y escritura de la lista de empleados desde y hacia un archivo.
 */
class FileHandler {
private:
    std::string filename; /**< Nombre del archivo en el que se guardará y se cargará la lista de empleados. */

public:
    /**
     * @brief Constructor de la clase FileHandler.
     * @param filename Nombre del archivo en el que se guardará y se cargará la lista de empleados.
     */
    FileHandler(const std::string& filename) : filename(filename) {}

    /**
     * @brief Guarda la lista de empleados en un archivo.
     * @param lista Objeto de la clase std::list<Empleado>.
     * @return int Retorna 0 si la operación fue exitosa, -1 si hubo un error al abrir el archivo.
     */
    int guardar_lista_empleados(const std::list<Empleado>& lista);

    /**
     * @brief Carga la lista de empleados desde un archivo.
     * @param lista Objeto de la clase std::list<Empleado>.
     * @return int Retorna 0 si la operación fue exitosa, -1 si hubo un error al abrir el archivo.
     */
    int cargar_lista_empleados(std::list<Empleado>& lista);
};

#endif // FILE_HANDLER_HPP
