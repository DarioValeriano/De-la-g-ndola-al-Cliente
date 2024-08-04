#include <iostream>
#include <fstream>
#include "producto.h"
#include "gondola.h"
#include "chango.h"

//Pre:
//Post: Crea una nueva instancia de la clase Gondola, siendo un vector dinamico de objetos de clase Producto.
Gondola:: Gondola(): productos_ingresados(0){
        // Constructor
        gondola = new Producto[capacidad];
    }

//Pre:
//Post: Libera la memoria asignada dinámicamente para el vector, asegurando que no haya fugas de memoria.
Gondola::~Gondola() {
        // Destructor
        delete[] gondola;
    }

//Pre:
//Post: Agrega un nuevo producto al final del vector.
void Gondola:: ingresar_producto(string nombre, double precio, bool oferta, int stock) {
        verificar_redimensionar();
        gondola[productos_ingresados++] = Producto(nombre, precio, oferta, stock);
    }

//Pre: indice debe ser un valor que esté dentro del rango de índices válidos para el vector gondola.
//Post: Devuelve el producto almacenado en la posición especificada por indice en el vector gondola.
Producto Gondola:: obtener_producto(int indice){
        return gondola[indice];
    }

//Pre:
//Post: Devuelve la cantidad de productos ingresados en el vector.
int Gondola:: obtener_tamano(){
        return productos_ingresados;
    }

//Pre:
//Post: Devuelve la capacidad actual del vector.
int Gondola:: obtener_capacidad(){
        return capacidad;
    }

//Pre: nueva_capacidad debe ser mayor a la cantidad de productos ingresados.
//Post: Redimensiona el vector con la nueva capacidad introducida por parámetro.
void Gondola:: redimensionar(int nueva_capacidad) {
        // Crear nuevo vector
        Producto* nuevo_vector = new Producto[nueva_capacidad];
        // Copiar los elementos actuales al nuevo vector
        for (int i = 0; i < productos_ingresados; ++i) {
            nuevo_vector[i] = gondola[i];
        }
        // Liberar la memoria del vector anterior
        delete[] gondola;
        // Actualizar el vector y la capacidad
        gondola = nuevo_vector;
        capacidad = nueva_capacidad;
    }

//Pre: 
//Post: Verificar si se necesita redimensionar el vector.
void Gondola:: verificar_redimensionar(){
    if (productos_ingresados == capacidad) {
        redimensionar(capacidad * 2);  // Duplicar la capacidad
    } else if (capacidad != 5 && productos_ingresados < int(capacidad/2)){
        redimensionar(int(capacidad / 2)); // Dividir por la mitad la capacidad
    }
}

//Pre: indice debe estar dentro de la capacidad de la góndola y cantidad debe ser un número válido.
//Post: Actualiza el producto almacenado en la posición especificada por indice en el vector gondola.
void Gondola:: actualizar_producto(int indice, int cantidad){
    gondola[indice] = Producto(gondola[indice].obtener_nombre(), gondola[indice].obtener_precio(), gondola[indice].obtener_oferta(), gondola[indice].obtener_stock()-cantidad);
}

//Pre: indice debe ser un valor valido.
//Post: Elimina el producto almacenado en la posición especificada por indice en el vector gondola. 
void Gondola:: eliminar_producto(int indice){
    for(int i = indice; i < capacidad - 1; ++i){
        gondola[i]= gondola[i+1];
    }
    --productos_ingresados;
    verificar_redimensionar();
}

//Pre:
//Post: Muestra por consola cada producto dentro del vector gondola.
void Gondola:: imprimir_productos_gondola(){
    for(int i = 0; i < productos_ingresados; i++){
        std::cout << gondola[i].obtener_nombre() << " $" << gondola[i].obtener_precio() << " " << gondola[i].obtener_oferta() << " " << gondola[i].obtener_stock() << " " << std::endl;
    }
}

//Pre:
//Post: Actualiza el archivo ingresado por parametro.
void Gondola:: actualizar_archivo_producto(ostream& archivo){
    for (int i = 0; i < productos_ingresados; i++){
        archivo << gondola[i].obtener_nombre()<<" "<<gondola[i].obtener_precio()<<" "<<gondola[i].obtener_oferta()<<" "<<gondola[i].obtener_stock()<< std::endl; 
    }
}