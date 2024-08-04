#include <iostream>
#include <fstream>
#include "producto.h"

//Pre: 
//Post: Crea un nuevo objeto de tipo Producto
Producto::Producto(){
    //constructor
}

//Pre: 
//Post: Crea un nuevo objeto de tipo Producto con los valores asignados.
Producto::Producto(string nombre, double precio, bool oferta, int stock, double precio_item){
    this->nombre = nombre;
    this->precio = precio;
    this->oferta = oferta;
    this->stock = stock;
    this->precio_item = precio_item;
}

//Pre: 
//Post: Libera cualquier recurso utilizado por el objeto Producto.
Producto::~Producto(){
    //destructor
}

//Pre: 
//Post: Devuelve el nombre almacenado del producto.
string Producto::obtener_nombre(){
    return nombre;
}

//Pre: 
//Post: Devuelve el precio del producto.
double Producto::obtener_precio(){
    return precio;
}

//Pre: 
//Post: Devuelve true si el producto tiene oferta, de lo contrario devuelve false.
bool Producto::obtener_oferta(){
    return oferta;
}

//Pre: 
//Post: Devuelve el stock del producto
int Producto::obtener_stock(){
    return stock;
}

//Pre: 
//Post: Devuelve el precio total del item, segun la cantidad a adquirir.
double Producto::obtener_precio_item(){
    return precio_item;
}



