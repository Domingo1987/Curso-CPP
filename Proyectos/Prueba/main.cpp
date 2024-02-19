#include <iostream>
#include <list>

int main(){
    std::cout<< "Hola como estas hoy\n\n" << std::endl;
    std::list<int> miLista;
    std::list<int>::iterator it;

    miLista.push_front(4);
    miLista.push_front(3);
    miLista.push_back(2);
    miLista.push_front(1);
    miLista.push_front(0);
    
    it=miLista.begin();

    while(it!=miLista.end()){
        std::cout << *it << std::endl;
        it++;
    }

    return 0;
}