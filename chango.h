#ifndef CHANGO
#define CHANGOs
#include <iostream>
#include "producto.h"
#include "gondola.h"

class Chango{
    private:
        Producto* chango;
        int capacidad;
        int productos_ingresados_chango;
        int indice_encontrado;
    public:
        // Constructor
        //Pre: 
        //Post: Crea una nueva instancia de la clase Chango, siendo un vector dinamico de objetos de clase Producto.
        Chango(int capacidad);
        // Destructor
        //Pre: 
        //Post: Libera la memoria asignada dinámicamente para el vector, asegurando que no haya fugas de memoria.
        ~Chango();
        // Funciones

        //Pre: nombre_producto debe ser un nombre almacenado en un producto dentro de gondola.
        //Post: Devuelve el producto encontrado.
        Producto encontrar_producto(string nombre_producto, Gondola& gondola);

        //Pre: 
        //Post: Agrega al vector chango un producto.
        void agregar_al_carrito(Producto& product, int cantidad);

        //Pre: indice debe estar dentro de la capacidad del vector chango.
        //Post: Devuelve el producto almacenado en el indice ingresado del vector chango. 
        Producto obtener_producto_chango(int indice);

        //Pre: 
        //Post: Devuelve la cantidad de productos ingresados en el chango, siendo esta el tamaño ocupado en el vector.
        int obtener_tamano_chango();

        //Pre: 
        //Post: Devuelve el indice en el que se encontro el producto buscado.
        int obtener_indice_encontrado();

        //Pre: 
        //Post: Muestra por pantalla los productos dentro del vector chango.
        void imprimir_productos_chango();

};


#endif // CHANGO