/*
 * Crea un std::map para almacenar una lista de productos y sus precios. 
 * Agrega, modifica y elimina productos y muestra los resultados.
*/

#include <iostream>
#include<map>

int main(){
    //Creamos el std::map
    std::map <std::string, std::string> ListaProductos;
    std::map <std::string, std::string>::iterator it;
    
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


    /*auto ite = ListaProductos.find("Jabon Liquido");
    if ( ite == ListaProductos.end()){
        std::cout << "No se encontró el jabón líquido" << std::endl;
    } else {
        std::cout << "Se encontró el jabón líquido" << std::endl;
    } */
    
    
    it = ListaProductos.begin();
    while(it!= ListaProductos.end()){
        std::cout << "Nombre del producto: " << it->first << " Precio del producto: " << it->second << std::endl;
        it++;
    }



    return 0;
}