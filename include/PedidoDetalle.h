#ifndef PEDIDODETALLE_H
#define PEDIDODETALLE_H

class PedidoDetalle
{
    private:
        int   _nroPedido, _cantidad;
        char  _codigoProducto[4];
        float _importe;
    public:
        PedidoDetalle();
        ~PedidoDetalle();
//        sets
        void setNroPedido(int);
        void setCantidad(int);
        void setCodigoProducto(char*);
        void setImporte(float);
//        gets
        int getNroPedido();
        int getCantidad();
        char* getCodigoProducto();
        float getImporte();
//        metodos
        void cargar();
        void calcularImporte(float, int);
};

#endif // PEDIDODETALLE_H
