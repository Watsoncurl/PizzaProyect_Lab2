#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
    private:
        char  _codigo[4], _descripcion[20];
        float _precioUnit;
        int   _stock; // reponer stock de pizzas diariamente
        bool  _estado;
    public:
        Producto(const char _codigo[4]="", const char _descripcion[20]="", float _precioUnit=0, int _stock=0, bool _estado=true);
        ~Producto();
// sets
        void setCodigo(char codigo[4]);
        void setDescripcion(char descripcion[20]);
        void setPrecioUnit(float);
        void setStock(int);
        void setEstado(bool);
// gets
        char *getCodigo();
        char *getDescripcion();
        float getPrecioUnit();
        int   getStock();
        bool  getEstado();
// metodos
        void cargar(char*);
        void mostrar();
        int  escribirArchivo();
        int  leerArchivo(int);
        int  verificarCodigo(char codigo[4], int *p=nullptr);
        void sumarStock(int);
        void restarStock(int);
};

void menuProductos();
void cargarProductos();
void modifProductos(char*);
void verProductos();
void borrarProductos(char*);
void reemplProductos(Producto);

#endif // PRODUCTO_H
