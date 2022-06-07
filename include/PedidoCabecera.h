#ifndef PEDIDOCABECERA_H
#define PEDIDOCABECERA_H
#include "Fecha.h"

// si el DNI no está registrado, registrar nuevo cliente
class PedidoCabecera {
    private:
        int   _nroPedido, _dniCliente;
        float _precioTotal;
        Fecha _fechaPedido;
        bool  _entregado;
    public:
        PedidoCabecera();
        ~PedidoCabecera();
// sets
        void setNumeroPedido(int);
        void setDniCliente(int);
        void setPrecioTotal(float);
        void setFechaPedido(int, int, int);
        void setEntregado(bool);
// gets
        int   getNumeroPedido();
        int   getNumeroPedidoUlt();
        int   getDniCliente();
        float getPrecioTotal();
        Fecha getFechaPedido();
        bool  getEntregado();
// metodos
        int  cargar();
        void mostrar();
        int  escribirArchivo();
        int  leerArchivo(int);
        int  verificarNumero(int numero, int *p=nullptr);
};

void menuPedidos();
void cargarPedidos();
void modifPedidos();
void verPedidosActivos();
void verPedidosTodos();
void borrarPedidos();

#endif // PEDIDOCABECERA_H
