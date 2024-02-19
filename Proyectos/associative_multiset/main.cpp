#include <iostream>
#include <set>

void mostrarBolsa(const std::multiset<int>& bolsa) {
    for (const int& elemento : bolsa) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;
}


std::multiset<int> cargarBolsa(int n){
    std::multiset<int> conj;
    int elemento;
    for (int i = 0; i < n; i++) {
        std::cin >> elemento;
        conj.insert(elemento);
    }

    return conj;
}


int main() {
  int n;
  std::cout << "Hola multiset!\n";
	std::multiset <int> miBolsa;
  
  std::cout << "Ingrese el número de elementos para la bolsa A: ";
  std::cin >> n;
  std::cout << "Ingrese " << n << " elementos para A:\n";
 
  miBolsa = cargarBolsa(n);
	mostrarBolsa(miBolsa);
	
	return 0;
}