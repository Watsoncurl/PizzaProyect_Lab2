#include "Producto.h"
#include <string.h>

Producto::Producto()
{
    //ctor
}

Producto::~Producto()
{
    //dtor
}

//          sets
void Producto::setCodigo(char* codigo){strcpy(this->_codigo,codigo);}
void Producto::setNombre(char* nombre){strcpy(this->_nombre,nombre);}
void Producto::setPrecioUnit(float precioUnit){this->_precioUnit = precioUnit;}
void Producto::setStock(int stock){this->_stock = stock;}
//          gets
char* Producto::getCodigo(){return this->_codigo;}
char* Producto::getNombre(){return this->_nombre;}
float Producto::getPrecioUnit(){return this->_precioUnit;}
int   Producto::getStock(){return this->_stock;}
//          metodos
void Producto::cargar()
{

}
void Producto::sumarStock(int cantidad)
{
    this->_stock += cantidad;
}
void Producto::restarStock(int cantidad)
{
    if(this->_stock - cantidad >= 0)
    {
        this->_stock -= cantidad;
    }
}
