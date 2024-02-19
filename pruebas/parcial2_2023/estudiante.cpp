#include "estudiante.hpp"

// Constructor
Estudiante::Estudiante(int cedula, const std::string& nombre, int edad, Sexo sexo)
		: cedula(cedula), nombre(nombre), edad(edad), sexo(sexo) {}

// Métodos get
int Estudiante::getCedula() const {
		return cedula;
}

std::string Estudiante::getNombre() const {
		return nombre;
}

int Estudiante::getEdad() const {
		return edad;
}

Sexo Estudiante::getSexo() const {
		return sexo;
}

// Métodos set
void Estudiante::setCedula(int cedula) {
		this->cedula = cedula;
}

void Estudiante::setNombre(const std::string& nombre) {
		this->nombre = nombre;
}

void Estudiante::setEdad(int edad) {
		this->edad = edad;
}

void Estudiante::setSexo(Sexo sexo) {
		this->sexo = sexo;
}

bool operator<(const Estudiante& e1, const Estudiante& e2) {
		return e1.getCedula() < e2.getCedula(); // Comparar habitacions por cédula
}

bool operator ==(const Estudiante &e1, const Estudiante &e2){
	return e1.getCedula() == e2.getCedula();
}
