#ifndef PRODUCTO_H
#define PRODUCTO_H


class Producto
{
    private:
        char  _codigo[4], _nombre[20];
        float _precioUnit;
        int   _stock; // reponer stock de pizzas diariamente
    public:
        Producto();
        ~Producto();
//          sets
        void setCodigo(char*);
        void setNombre(char*);
        void setPrecioUnit(float);
        void setStock(int);
//          gets
        char* getCodigo();
        char* getNombre();
        float getPrecioUnit();
        int   getStock();
//          metodos
        void cargar();
        void sumarStock(int);
        void restarStock(int);
};

#endif // PRODUCTO_H
