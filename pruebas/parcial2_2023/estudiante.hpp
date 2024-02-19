#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include <string>

enum class Sexo {
		MASCULINO,
		FEMENINO
};

class Estudiante {
private:
		int cedula;
		std::string nombre;
		int edad;
		Sexo sexo;

public:
		// Constructor
		Estudiante(int cedula, const std::string& nombre, int edad, Sexo sexo);
		Estudiante() {}
		
		// Métodos get
		int getCedula() const;
		std::string getNombre() const;
		int getEdad() const;
		Sexo getSexo() const;

		// Métodos set
		void setCedula(int cedula);
		void setNombre(const std::string& nombre);
		void setEdad(int edad);
		void setSexo(Sexo sexo);
//Operaciones necesarias para realizar comparaciones mediante objetos (comparamos atributos de los mismos)
		friend bool operator<(const Estudiante& e1, const Estudiante& e2);
		friend bool operator ==(const Estudiante &e1, const Estudiante &e2);
};

#endif // ESTUDIANTE_HPP

