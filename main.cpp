#include <iostream>
#include <fstream>
#include "chango.h"
#include "gondola.h"
using namespace std;

string leer_dato(ifstream& archivo){
    string dato;
    archivo >> dato;
    return dato;
};

int main(){
    ifstream archivo_productos("productos.txt");
    ifstream archivo_compra("compra.txt");
    Gondola gondola;
    string linea;
    int cantidad_productos = 0;
    while(!archivo_productos.eof()){
        cantidad_productos += 1;
        string nombre = leer_dato(archivo_productos);
        double precio = stod(leer_dato(archivo_productos));
        bool oferta = stoi(leer_dato(archivo_productos));
        int stock = stoi(leer_dato(archivo_productos));
        gondola.ingresar_producto(nombre, precio, oferta, stock);
    }
    archivo_productos.close();
    std:: cout << std::endl << "::::: BIENVENIDO :::::" << std:: endl;
    std:: cout << std::endl << "::::: CATALOGO DE PRODUCTOS EN GONDOLA :::::" << std:: endl;
    gondola.imprimir_productos_gondola();
    std::cout << std::endl <<"::::: AGREGADO DE PRODUCTOS AL CHANGO :::::" << std::endl; 
    Chango chango(cantidad_productos);
    while(!archivo_compra.eof()){
        string nombre = leer_dato(archivo_compra);
        double cantidad_a_comprar = stod(leer_dato(archivo_compra));
        Producto producto = chango.encontrar_producto(nombre, gondola);
        int stock_producto =  producto.obtener_stock();
        if(stock_producto == 0){
            std:: cout << "-No hay stock del producto " << producto.obtener_nombre() << std::endl;
            gondola.eliminar_producto(chango.obtener_indice_encontrado());
        } else if(stock_producto < cantidad_a_comprar){
            std:: cout << "-Del producto "<< producto.obtener_nombre()<< " solo hay " << producto.obtener_stock() <<" unidades" << std::endl;
            chango.agregar_al_carrito(producto, stock_producto);
            gondola.eliminar_producto(chango.obtener_indice_encontrado());
        }else if(stock_producto == cantidad_a_comprar){
            chango.agregar_al_carrito(producto, cantidad_a_comprar);
            gondola.eliminar_producto(chango.obtener_indice_encontrado());
        } else{
            gondola.actualizar_producto(chango.obtener_indice_encontrado(), cantidad_a_comprar);
            chango.agregar_al_carrito(producto, cantidad_a_comprar);
        }
    }
    ofstream archivo_productos_1("productos.txt");
    gondola.actualizar_archivo_producto(archivo_productos_1);
    archivo_productos_1.close();
    archivo_compra.close();
    std:: cout << std::endl << "::::: PRODUCTOS EN CHANGO :::::" << std:: endl;
    chango.imprimir_productos_chango();
    std:: cout << std::endl << "::::: PRODUCTOS EN GONDOLA ACTUALIZADOS :::::" << std:: endl;
    gondola.imprimir_productos_gondola();
    std::cout << std::endl <<"::::: GRACIAS POR SU COMPRA :::::" << std::endl; 
    return 0;
}