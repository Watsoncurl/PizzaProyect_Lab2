#ifndef PEDIDOCABECERA_H
#define PEDIDOCABECERA_H
#include "Fecha.h"

#include "PedidoDetalle.h"

class PedidoCabecera {
    private:
        int   _nroPedido, _dniCliente;
        float _precioTotal;
        bool  _entregado;
        PedidoDetalle *_pedidoDetalle;
        int   _contDetalle;
        Fecha _fechaPedido;
        bool  _estado;
    public:
/// sets
        void setNumeroPedido(int);
        void setDniCliente(int);
        void setPrecioTotal(float);
        void setFechaPedido(int, int, int);
        void setEntregado(bool);
        void setEstado(bool);
/// gets
        int   getNumeroPedido();
        int   getNumeroPedidoUlt();
        int   getDniCliente();
        float getPrecioTotal();
        Fecha getFechaPedido();
        bool  getEntregado();
        bool  getEstado();
/// metodos
        void Cargar();
        void Mostrar();
        void MostrarDetalles();
        int  escribirArchivo();
        int  leerArchivo(int);
        int  verificarNumero(int numero, int *p=nullptr);
};

void  menuPedidos();
void  cargarPedidos();
void  modifPedidos();
void  verPedidosActivos();
void  verPedidosEntregados();
void  borrarPedidos();
float CalcularImporteTotal(int NroPedido);

#endif /// PEDIDOCABECERA_H
