#include <iostream>
#include <chrono>  // Para medir el tiempo
using namespace std;
using namespace chrono;

bool existeSuma(int arr[], int n, int sumaObjetivo) {
    /*
     * Verifica si hay un subconjunto cuya suma sea igual al objetivo.
     * Complejidad: O(2^n) en el peor caso.
     */
    if (sumaObjetivo == 0)
        return true;
    if (n == 0)
        return false;

    // No incluir el último elemento
    if (arr[n - 1] > sumaObjetivo)
        return existeSuma(arr, n - 1, sumaObjetivo);

    // Probar con y sin el último elemento
    return existeSuma(arr, n - 1, sumaObjetivo - arr[n - 1]) ||
           existeSuma(arr, n - 1, sumaObjetivo);
}

int main() {
    int subconjunto[] = {3, 34, 4, 12, 5, 2};
    int sumaObjetivo = 9;
    int n = sizeof(subconjunto) / sizeof(subconjunto[0]);

    auto inicio = high_resolution_clock::now();
    bool resultado = existeSuma(subconjunto, n, sumaObjetivo);
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio); // Medición en milisegundos

    if (resultado)
        cout << "Existe subconjunto con la suma objetivo" << endl;
    else
        cout << "No existe subconjunto con la suma objetivo" << endl;

    cout << "Tiempo de ejecución: " << duracion.count() << " milisegundos" << endl;

    return 0;
}
