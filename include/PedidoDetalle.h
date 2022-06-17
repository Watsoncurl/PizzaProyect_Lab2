#ifndef PEDIDODETALLE_H
#define PEDIDODETALLE_H

class PedidoDetalle {
    private:
        int   _nroPedido, _cantidad;
        char  _codigoProducto[4];
        float _importe;
        bool  _estado;
    public:
        PedidoDetalle(int _nroPedido=0, int _cantidad=0, const char _codigoProducto[4]="", float _importe=0, bool estado=true);
        ~PedidoDetalle();
// sets
        void setNroPedido(int);
        void setCantidad(int);
        void setCodigoProducto(char codigo[4]);
        void setImporte(float);
        void setEstado(bool);
// gets
        int   getNroPedido();
        int   getCantidad();
        char* getCodigoProducto();
        float getImporte();
        bool  getEstado();
// metodos
        int  cargar(int, char*);
        void mostrar();
        int  escribirArchivo();
        int  leerArchivo(int);
        void calcularImporte(float, int);
};

void mostrarPedidosDetallesPorNroPedido(int);
void mostrarDetallesDelPedido();
#endif // PEDIDODETALLE_H
