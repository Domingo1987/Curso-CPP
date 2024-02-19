#include <iostream>
#include <set>

// Función para mostrar el contenido de un conjunto
void mostrarConjunto(const std::set<int>& conjunto) {
    for (const int& elemento : conjunto) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;
}

std::set<int> cargarConjuntos(int n){
    std::set<int> conj;
    int elemento;
    /*for (int i = 0; i < n; i++) {
        std::cin >> elemento;
        conj.insert(elemento);
    }*/
    while(conj.size()!=n){
        std::cin >> elemento;
        conj.insert(elemento);
    }

    return conj;
}

// Función para la unión de dos conjuntos
std::set<int> unionConjuntos(const std::set<int>& A, const std::set<int>& B) {
    std::set<int> unionAB = A; // Copia todos los elementos de A
    unionAB.insert(B.begin(), B.end()); // Inserta todos los elementos de B
    return unionAB;
}

// Función para la intersección de dos conjuntos
std::set<int> interseccionConjuntos(const std::set<int>& A, const std::set<int>& B) {
    std::set<int> interseccionAB;
    for (const int& elemento : A) {
        if (B.find(elemento) != B.end()) {
            interseccionAB.insert(elemento);
        }
    }
    return interseccionAB;
}

int main() {
    std::set<int> A, B;
    int n, elemento;

    // Recibir elementos del conjunto A
    std::cout << "Ingrese el número de elementos para el conjunto A: ";
    std::cin >> n;
    std::cout << "Ingrese " << n << " elementos para A:\n";
    /*for (int i = 0; i < n; i++) {
        std::cin >> elemento;
        A.insert(elemento);
    }*/
    A = cargarConjuntos(n);

    // Recibir elementos del conjunto B
    std::cout << "Ingrese el número de elementos para el conjunto B: ";
    std::cin >> n;
    std::cout << "Ingrese " << n << " elementos para B:\n";
    B = cargarConjuntos(n);

    // Mostrar conjuntos
    std::cout << "Conjunto A: ";
    mostrarConjunto(A);

    std::cout << "Conjunto B: ";
    mostrarConjunto(B);

    // Mostrar unión de conjuntos
    std::cout << "Unión de A y B: ";
    mostrarConjunto(unionConjuntos(A, B));

    // Mostrar intersección de conjuntos
    std::cout << "Intersección de A y B: ";
    mostrarConjunto(interseccionConjuntos(A, B));

    // Chequear pertenencia de un elemento
    std::cout << "Ingrese un elemento para verificar si pertenece a A y/o B: ";
    std::cin >> elemento;
    if (A.find(elemento) != A.end()) {
        std::cout << "El elemento " << elemento << " pertenece al conjunto A." << std::endl;
    } else {
        std::cout << "El elemento " << elemento << " no pertenece al conjunto A." << std::endl;
    }
    if (B.find(elemento) != B.end()) {
        std::cout << "El elemento " << elemento << " pertenece al conjunto B." << std::endl;
    } else {
        std::cout << "El elemento " << elemento << " no pertenece al conjunto B." << std::endl;
    }

    return 0;
}