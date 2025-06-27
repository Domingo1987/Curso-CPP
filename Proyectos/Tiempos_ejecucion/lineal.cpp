#include <iostream>
#include <chrono>  // Para medir el tiempo
using namespace std;
using namespace chrono;

int busquedaLineal(int arr[], int n, int objetivo) {
    /*
     * Busca un número en la lista revisando cada elemento uno por uno.
     * Complejidad: O(n) en el peor caso.
     */
    for (int i = 0; i < n; i++) {
        if (arr[i] == objetivo)
            return i;  // Retorna la posición donde se encontró
    }
    return -1;  // No encontrado
}

int main() {
    int lista[] = {10, 23, 45, 70, 11, 15};
    int n = sizeof(lista) / sizeof(lista[0]);
    int objetivo = 70;

    auto inicio = high_resolution_clock::now();
    int resultado = busquedaLineal(lista, n, objetivo);
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<nanoseconds>(fin - inicio);

    if (resultado != -1)
        cout << "Encontrado en posición: " << resultado << endl;
    else
        cout << "No encontrado" << endl;

    cout << "Tiempo de ejecución: " << duracion.count() << " nanosegundos" << endl;

    return 0;
}
