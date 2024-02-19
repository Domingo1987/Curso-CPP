/**
 * @file Empleado.hpp
 * @brief Definición de la clase Empleado.
 */

#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

/**
 * @class Empleado
 * @brief Clase que representa a un empleado con su nombre, id y salario mensual.
 */
class Empleado {
private:
    std::string nombre; /**< Nombre del empleado */
    int id; /**< Identificación única del empleado */
    float salarioMensual; /**< Salario mensual del empleado */

public:
    /**
     * @brief Constructor vacío de la clase Empleado.
     */
    Empleado() : nombre(""), id(0), salarioMensual(0.0) {}

    /**
     * @brief Constructor de la clase Empleado.
     * @param nombre Nombre del empleado.
     * @param id ID del empleado.
     * @param salarioMensual Salario mensual del empleado.
     */
    Empleado(const std::string& nombre, int id, float salarioMensual);

    /**
     * @brief Método que devuelve el nombre del empleado.
     * @return Nombre del empleado.
     */
    std::string getNombre() const;

    /**
     * @brief Método que devuelve la ID del empleado.
     * @return ID del empleado.
     */
    int getId() const;

    /**
     * @brief Método que devuelve el salario mensual del empleado.
     * @return Salario mensual del empleado.
     */
    float getSalarioMensual() const;

    /**
     * @brief Método que establece el nombre del empleado.
     * @param nombre Nuevo nombre del empleado.
     */
    void setNombre(const std::string& nombre);

    /**
     * @brief Método que establece la ID del empleado.
     * @param id Nueva ID del empleado.
     */
    void setId(int id);

    /**
     * @brief Método que establece el salario mensual del empleado.
     * @param salarioMensual Nuevo salario mensual del empleado.
     */
    void setSalarioMensual(float salarioMensual);

    /**
     * @brief Método que muestra la información del empleado por consola.
     */
    void mostrar() const;
};

#endif // EMPLEADO_HPP
