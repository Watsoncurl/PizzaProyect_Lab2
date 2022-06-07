#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
    private:
        char  _codigo[4], _nombre[20];
        float _precioUnit;
        int   _stock; // reponer stock de pizzas diariamente
    public:
        Producto(const char _codigo[4]="", const char _nombre[20]="", float _precioUnit=0, int _stock=0);
        ~Producto();
// sets
        void setCodigo(char codigo[4]);
        void setNombre(char nombre[20]);
        void setPrecioUnit(float);
        void setStock(int);
// gets
        char *getCodigo();
        char *getNombre();
        float getPrecioUnit();
        int   getStock();
// metodos
        void cargar();
        void mostrar();
        int  escribirArchivo();
        int  leerArchivo(int);
        int  verificarCodigo(char codigo[4], int *p=nullptr);
        void sumarStock(int);
        void restarStock(int);
};

void menuProductos();
void cargarProductos();
void modifProductos();
void verProductos();
void borrarProductos();

#endif // PRODUCTO_H
