#ifndef PEDIDODETALLE_H
#define PEDIDODETALLE_H

class PedidoDetalle {
    private:
        int   _nroDetalle;
        char  _codigoProducto[4];
        int   _cantidad;
        float _importe;
    public:
// sets
        void setNroDetalle(int);
        void setCantidad(int);
        void setCodigoProducto(const char codigo[4]);
        void setImporte(float);
// gets
        int  getNroDetalle();
        int  getCantidad();
        char *getCodigoProducto();
        float getImporte();
// metodos
        int  Cargar(int*);
        void Mostrar();
        int  escribirArchivo();
        int  leerArchivo(int);
        float calcularImporte(float, int);
};



#endif // PEDIDODETALLE_H
