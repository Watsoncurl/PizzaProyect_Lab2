#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"

// nro pedido de PedidosCabecera
// DNI de cliente en clase Cliente
// precio total de PedidosCabecera
class Venta
{
    private:
        int   _id, _nroPedido, _dniCliente;
        float _precioVenta;
        Fecha _fechaVenta;
    public:
        Venta();
        ~Venta();
//        sets
        void setId(int);
        void setNroPedido(int);
        void setDniCliente(int);
        void setPrecioVenta(float);
        void setFechaVenta(int, int, int);
//        gets
        int   getId();
        int   getNroPedido();
        int   getDniCliente();
        float getPrecioVenta();
        Fecha getFechaVenta();
//        metodos
        void cargar();
};

#endif // VENTA_H
