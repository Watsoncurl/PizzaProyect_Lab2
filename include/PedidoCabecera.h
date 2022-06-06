#ifndef PEDIDOCABECERA_H
#define PEDIDOCABECERA_H
#include "Fecha.h"

// si el DNI no está registrado, registrar nuevo cliente
class PedidoCabecera
{
    private:
        int   _nroPedido, _dniCliente;
        float _precioTotal;
        Fecha _fechaPedido;
        bool  _entregado;
    public:
        PedidoCabecera();
        ~PedidoCabecera();
//        sets
        void setNumeroPedido(int);
        void setDniCliente(int);
        void setPrecioTotal(float);
        void setFechaPedido(int, int, int);
        void setEnregado(bool);
//        gets
        int getNumeroPedido();
        int getDniCliente();
        float getPrecioTotal();
        Fecha getFechaPedido();
        bool getEnregado();
//        metodos
        void cargar();

};

#endif // PEDIDOCABECERA_H
