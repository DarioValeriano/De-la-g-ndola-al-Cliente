#include <iostream>
#include <fstream>
#include "producto.h"
#include "gondola.h"
#include "chango.h"

//Pre: 
//Post: Crea una nueva instancia de la clase Chango, siendo un vector dinamico de objetos de clase Producto.
Chango:: Chango(int capacidad): productos_ingresados_chango(0){
        //Constructor
        chango = new Producto[capacidad];
    }

//Pre: 
//Post: Libera la memoria asignada dinámicamente para el vector, asegurando que no haya fugas de memoria.
Chango::~Chango() {
    //destructor
    delete[] chango;
    }

//Pre: nombre_producto debe ser un nombre almacenado en un producto dentro de gondola.
//Post: Devuelve el producto encontrado.
Producto Chango:: encontrar_producto(string nombre_producto, Gondola& gondola){
    int i = 0;
    bool no_encontrado = true;
    Producto respuesta;
    while(i < gondola.obtener_tamano() && no_encontrado){
        if((gondola.obtener_producto(i)).obtener_nombre() == nombre_producto){
            indice_encontrado = i;
            respuesta = gondola.obtener_producto(i);
            no_encontrado = false;
        };
        i+=1;
    }
    return respuesta;
}

//Pre: 
//Post: Agrega al vector chango un producto.
void Chango:: agregar_al_carrito(Producto& product, int cantidad) {
        double precio_unitario= product.obtener_precio();
        double precio_item_actual = (cantidad * precio_unitario);
        if (product.obtener_oferta()){
            precio_item_actual -= (precio_item_actual * 0.1);
        }
        chango[productos_ingresados_chango++] = Producto(product.obtener_nombre(), precio_unitario, product.obtener_oferta() , cantidad, precio_item_actual);
        std::cout <<"-Se agrego " << product.obtener_nombre() <<" correctamente" << std::endl; 
    }

//Pre: indice debe estar dentro de la capacidad del vector chango.
//Post: Devuelve el producto almacenado en el indice ingresado del vector chango. 
Producto Chango:: obtener_producto_chango(int indice){
    return chango[indice];
}

//Pre: 
//Post: Devuelve la cantidad de productos ingresados en el chango, siendo esta el tamaño ocupado en el vector.
int Chango:: obtener_tamano_chango(){
    return productos_ingresados_chango;
}

//Pre: 
//Post: Devuelve el indice en el que se encontro el producto buscado.
int Chango:: obtener_indice_encontrado(){
    return indice_encontrado;
}

//Pre: 
//Post: Muestra por pantalla los productos dentro del vector chango.
void Chango:: imprimir_productos_chango(){
    double total = 0;
    for(int i = 0; i < productos_ingresados_chango; i++){
        string oferta;
        if(chango[i].obtener_oferta()){
            oferta = "S";
        } else {
            oferta = "N";
        }
        std::cout << chango[i].obtener_nombre() << " $" << chango[i].obtener_precio() << " " << chango[i].obtener_stock() << " " << oferta << " $" << chango[i].obtener_precio_item() << std::endl;
        total += chango[i].obtener_precio_item();
    }
    std::cout << "-Total: $"<< total << std::endl;
};



