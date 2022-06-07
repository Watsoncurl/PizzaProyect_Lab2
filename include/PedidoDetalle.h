#ifndef PEDIDODETALLE_H
#define PEDIDODETALLE_H

class PedidoDetalle {
    private:
        int   _nroPedido, _cantidad;
        char  _codigoProducto[4];
        float _importe;
    public:
        PedidoDetalle(int _nroPedido=0, int _cantidad=0, const char _codigoProducto[4]="", float _importe=0);
        ~PedidoDetalle();
// sets
        void setNroPedido(int);
        void setCantidad(int);
        void setCodigoProducto(char codigo[4]);
        void setImporte(float);
// gets
        int  getNroPedido();
        int  getCantidad();
        char *getCodigoProducto();
        float getImporte();
// metodos
        int  cargar(int);
        void mostrar();
        int  escribirArchivo();
        int  leerArchivo(int);
        void calcularImporte(float, int);
};

#endif // PEDIDODETALLE_H
