#ifndef PRODUCTO
#define PRODUCTO
#include <iostream>
using namespace std;

class Producto{
    private:
        //variables privadas
        string nombre;
        double precio;
        bool oferta;
        int stock;
        double precio_item;

    public:
        //constructor
        //Pre: 
        //Post: Se crea un nuevo objeto de tipo Producto
        Producto();

        //constructor con valores
        //Pre: 
        //Post: Se crea un nuevo objeto de tipo Producto con los valores asignados.
        Producto(string nombre, double precio, bool oferta, int stock, double precio_item = 0);

        //destructor
        //Pre: 
        //Post
        ~Producto();

        //funciones

        //Pre: 
        //Post: Devuelve el nombre almacenado del producto.
        string obtener_nombre();

        //Pre: 
        //Post: Devuelve el precio del producto.
        double obtener_precio();

        //Pre: 
        //Post: Devuelve true si el producto tiene oferta, de lo contrario devuelve false.
        bool obtener_oferta();

        //Pre: 
        //Post: Devuelve el stock del producto
        int obtener_stock();

        //Pre: 
        //Post: Devuelve el precio total del item, segun la cantidad a adquirir.
        double obtener_precio_item();

        
};

#endif // PRODUCTO