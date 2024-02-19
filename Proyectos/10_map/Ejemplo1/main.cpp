#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> calificaciones;
    calificaciones["Juan"] = 50;
    calificaciones.insert({"Maria", 90});
    calificaciones.insert({"Enzo", 56});
    calificaciones.insert({"Carlos", 77});
    calificaciones.insert({"Laura", 99});

    std::cout << "Cantidad de calificaciones: " << calificaciones.size() << std::endl;
    std::cout << "La calificación de Juan es: " << calificaciones["Juan"] << std::endl;
    
    std::string nombre = "Laura";
    auto it = calificaciones.find(nombre);
    if (it != calificaciones.end()) {
        std::cout << "La calificacion de " << nombre << " es: " << it->second << std::endl;
    } else {
        std::cout << nombre << " no está en el curso." << std::endl;
    }

    calificaciones.erase(nombre);

    std::cout << "Cantidad de calificaciones: " << calificaciones.size() << " (despues de borrar a "<< nombre<<")"<<std::endl;
    std::cout << "La calificación de "<< nombre <<" es: " << calificaciones[nombre] << std::endl;

   if (calificaciones.contains("Laura")) {
        // hacer algo si "apple" está en el mapa
        std::cout << nombre << " se encuentra " << std::endl;

    } else {
        std::cout << nombre << " NO se encuentra " << std::endl;
    }



    return 0;
}