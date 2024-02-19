/*
 * Usa un std::map para contar la frecuencia de palabras en un texto.
*/

#include <iostream>
#include <map>
#include <forward_list>
#include <string>

int main(){
    //Creamos el std::map
    std::map <std::string, int> contador_palabras;
    std::map <std::string, int>::iterator it_cont;
    
    std::forward_list <std::string> palabras;
    std::forward_list <std::string>::iterator it;

    std::string texto= "Hola, mi dia fue muy bueno. Yo me llamo Marlon.";

    palabras = {"hola", "chau", "prueba", "hola", "ayer", "manana", "manzana", "Ayer", "carlos"};

    it = palabras.begin();
    while(it!= palabras.end()){
        std::cout << "Palabra: " << *it << std::endl;
        /*if(contador_palabras.contains(*it)){
            contador_palabras[*it]=contador_palabras[*it]+1; 
        } else {
            contador_palabras.insert({*it, 1});
        }*/

        it++;
    }

    it_cont = contador_palabras.begin();
    while(it_cont!= contador_palabras.end()){
        std::cout << "Palabra: " << it_cont->first << " Cantidad: " << it_cont->second << std::endl;
        it_cont++;
    }

    /*
    //Agregamos productos
    ListaProductos.insert({"Papel Higienico", "$100"});
    ListaProductos.insert({"Shampoo", "$200"});
    ListaProductos.insert({"Jabón liquido", "$300"});
    ListaProductos.insert({"Auto de Juguete", "$120"});

    //Modificar
    ListaProductos.insert_or_assign("Jabón liquido", "$250");//Disponible desde la version c++17
    //ListaProductos["Jabón liquido"]="$330";    
    ListaProductos.insert({"Jabón liquido", "$333"}); //No esta realizando ninguna función, ya que Jabón liquido ya existe y el modificador insert inserta pero no modifica

    std::cout<< "El nuevo precio del jabón liquido es "<< ListaProductos["Jabón liquido"] << std::endl;
    //Eliminar
    ListaProductos.erase("Jabón liquido");

    if(ListaProductos.contains("Jabon Liquido")){
        std::cout << "Se encontró el jabón líquido" << std::endl;
    } else std::cout << "No se encontró el jabón líquido" << std::endl;


    auto ite = ListaProductos.find("Jabon Liquido");
    if ( ite == ListaProductos.end()){
        std::cout << "No se encontró el jabón líquido" << std::endl;
    } else {
        std::cout << "Se encontró el jabón líquido" << std::endl;
    } 
    
    
    it = ListaProductos.begin();
    while(it!= ListaProductos.end()){
        std::cout << "Nombre del producto: " << it->first << " Precio del producto: " << it->second << std::endl;
        it++;
    }*/



    return 0;
}