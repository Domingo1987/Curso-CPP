#include <iostream>
#include <algorithm>  // Para std::sort
#include <chrono>     // Para medir el tiempo

using namespace std;
using namespace chrono;

int busquedaBinaria(int arr[], int izquierda, int derecha, int objetivo) {
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == objetivo)
            return medio;  // Se encontró el número
        else if (arr[medio] < objetivo)
            izquierda = medio + 1;  // Buscar en la mitad derecha
        else
            derecha = medio - 1;  // Buscar en la mitad izquierda
    }
    return -1;  // No encontrado
}

int main() {
    int lista[] = {10, 23, 45, 70, 11, 15};  // Lista desordenada
    int n = sizeof(lista) / sizeof(lista[0]);
    int objetivo = 70;

    // Ordenar la lista antes de hacer la búsqueda binaria
    sort(lista, lista + n);

    // Tomar tiempo de inicio
    auto inicio = high_resolution_clock::now();

    int resultado = busquedaBinaria(lista, 0, n - 1, objetivo);

    // Tomar tiempo de finalización
    auto fin = high_resolution_clock::now();

    // Calcular la duración en nanosegundos
    auto duracion = duration_cast<nanoseconds>(fin - inicio);

    if (resultado != -1)
        cout << "Encontrado en posición: " << resultado << endl;
    else
        cout << "No encontrado" << endl;

    cout << "Tiempo de ejecución: " << duracion.count() << " nanosegundos" << endl;

    return 0;
}
