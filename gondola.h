#ifndef GONDOLA
#define GONDOLA
#include <iostream>
#include "producto.h"

class Gondola{
    private:
        // Variables privadas
        Producto* gondola;
        int productos_ingresados;
        int capacidad = 5;
        // Funcion privada
        void redimensionar(int nueva_capacidad);
        void verificar_redimensionar();
    public:
        // Constructor
        //Pre: 
        //Post: Crea una nueva instancia de la clase Gondola, siendo un vector dinamico de objetos de clase Producto
        Gondola();
        // Destructor
        //Pre: 
        //Post: Libera la memoria asignada dinámicamente para el vector, asegurando que no haya fugas de memoria.
        ~Gondola();

        //Funciones

        //Pre:
        //Post: Agrega un nuevo producto al final del vector.
        void ingresar_producto(string nombre, double precio, bool oferta, int stock);
        
        //Pre: indice debe ser un valor que esté dentro del rango de índices válidos para el vector gondola.
        //Post: Devuelve el producto almacenado en la posición especificada por indice en el vector gondola.
        Producto obtener_producto(int indice);

        //Pre:
        //Post: Devuelve la cantidad de productos ingresados en el vector.
        int obtener_tamano();

        //Pre:
        //Post: Devuelve la capacidad del vector.
        int obtener_capacidad();

        //Pre: nueva_capacidad debe ser mayor a la cantidad de productos ingresados.
        //Post: Redimensiona el vector con la nueva capacidad introducida por parámetro.
        void redimensionar(int nueva_capacidad);

        //Pre: 
        //Post: Verificar si se necesita redimensionar el vector.
        void verificar_redimensionar();

        //Pre: indice dentro de la capacidad de gondola, cantidad debe ser un numero valido.
        //Post: Actualiza el producto almacenado en la posición especificada por indice en el vector gondola.
        void actualizar_producto(int indice, int cantidad);
        
        //Pre: indice debe ser un valor valido.
        //Post: Elimina el producto almacenado en la posición especificada por indice en el vector gondola.
        void eliminar_producto(int indice);

        //Pre:
        //Post: Muestra por consola cada producto dentro del vector gondola.
        void imprimir_productos_gondola();

        //Pre:
        //Post: Actualiza el archivo ingresado por parametro.
        void actualizar_archivo_producto(ostream& archivo);
};

#endif // GONDOLA